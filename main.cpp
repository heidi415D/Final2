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

// muffin booth (deque)
void printDeque (const deque<Customer>& dq, const string& label){
    cout << "[" << label << " size=" << dq.size() << "] ";
    for (const auto& c : dq) {
    cout << c.name << "(" << c.order << ") ";
    }
    cout << "\n";
}

// bracelet booth (vector)
void printVector (const vector<Customer>& v, const string& label){
    cout << "[" << label << " size=" << v.size() << "] ";
    for (const auto& c : v) {
    cout << c.name << "(" << c.order << ") ";
    }
    cout << "\n";
}




int main(){
    srand((unsigned)time(nullptr));

    vector<string> names = { "Ava","Leo","Mia","Noah","Sofia","Eli","Nina","Omar","Ivy","Kai"
    };

    vector<string> coffeeOrders = {"Latte","Americano","ColdBrew","Mocha","Cappuccino","Chai","Espresso"
    };

    vector<string> muffinOrders = {"Blueberry","ChocolateChip","BananaNut","Corn","Bran","LemonPoppy"
    };

    CoffeeQueue coffee;
    deque<Customer> muffins;

    // initialize both queues w/ 3 customers

    for (int i = 0; i < 3; i++) {
    coffee.enqueue(makeCustomer(names, coffeeOrders));
    muffins.push_back(makeCustomer(names, muffinOrders));
    }


    cout << "\n=== Coffee + Muffin Booths (10 rounds) ===\n";

    for (int round = 1; round <= 10; round++) {
        cout << "\nRound " << round << ":\n";

        // arrivals

        if (fiftyFifty()) {
            Customer c = makeCustomer(names, coffeeOrders);
            cout << "Arrives coffee: " << c.name << " wants " << c.order << "\n";
            coffee.enqueue(c);
    }

    if (fiftyFifty()) {
            Customer c = makeCustomer(names, muffinOrders);
            cout << "Arrives muffin: " << c.name << " wants " << c.order << "\n";
            muffins.push_back(c);
        }

        // serve 
        if (!coffee.empty()) {
            Customer c = coffee.dequeue();
            cout << "Serves coffee: " << c.name << " with " << c.order << "\n";
        } else {
            cout << "No one served coffee\n";
        }

        if (!muffins.empty()) {
            Customer c = muffins.front();
            muffins.pop_front();
            cout << "Serves muffin: " << c.name << " with " << c.order << "\n";
        } else {
            cout << "No one served muffins\n";
        }

        
     // print queues

        coffee.print();
        printDeque(muffins, "Muffins");

    }
    return 0;
}
 




