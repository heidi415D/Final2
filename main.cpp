#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Customer {
    string name;
    string order;
};

int randInt(int low, int high) { return low + (rand() % (high - low + 1)); }
bool fiftyFifty() { return randInt(0, 1) == 1;}

Customer makeCustomer(const vector<string>& names, const vector<string>& orders) {
    Customer c;
    c.name = names[randInt(0, (int)names.size() - 1)];
    c.order = orders[randInt(0, (int)orders.size() - 1)];
    return c;
}

// milsetone 1: linked list node contains customer name and order

struct Node {
    Customer data;
    Node* next;
    Node(const Customer& c) : data(c), next(nullptr) {}
};

struct CoffeeQueue {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    void enqueue (const Customer& c) {
        Node* newNode = new Node(c);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    Customer dequeue() {

        if (!head) return {"", ""};

        Node* old = head;
        Customer c = old->data;
        head = head->next;

        if (!head) tail = nullptr;

        delete old;
        size--;
        return c;

    }

    bool empty() const { 
        return head == nullptr;
    }

    void print() const {
        cout << "[Coffee size=" << size << "] ";
        Node* cur = head;
        while (cur) {
            cout << cur->data.name << "(" << cur->data.order << ") ";
            cur = cur->next;
        }
        cout << endl;
    }
};




int main(){
    srand((unsigned)time(nullptr));

    cout << "Simulation starting...\n";
    vector<string> names = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    vector<string> orders = {"Espresso", "Latte", "Cappuccino"};

    CoffeeQueue coffee;

    return 0;
}



