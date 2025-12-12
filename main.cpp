#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

string Customer {
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
}
struct CoffeeQueue {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    void enque (const Customer& c) {
        Node* newNode = new Node(c);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    customer deque() {

        Node* old = head;
        Customer c = old->data;
        head = head->next;

        
    }
}




int main(){
    cout << "Simulation starting...\n";
    return 0;
}



