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

// Candy booth (queue) 
void printQueue(queue<Customer> q, const string& label) { 
    cout << "[" << label << " size=" << q.size() << "] ";
        while (!q.empty()) {                                 
         Customer c = q.front();                           
        cout << c.name << "(" << c.order << ") ";
        q.pop();                                          
    }
    cout << endl;
}




int main(){
    srand((unsigned)time(nullptr));

    vector<string> names = { "Ava","Leo","Mia","Noah","Sofia","Eli","Nina","Omar","Ivy","Kai"
    };

    vector<string> coffeeOrders = {"Latte","Americano","ColdBrew","Mocha","Cappuccino","Chai","Espresso"
    };

    vector<string> muffinOrders = {"Blueberry","ChocolateChip","BananaNut","Corn","Bran","LemonPoppy"
    };

     vector<string> braceletOrders = {"Red","Blue","Green","Purple","Pink","Yellow"};


    CoffeeQueue coffee;
    deque<Customer> muffins;
    vector<Customer> bracelets;

    // initialize  each booth w/ 3 customers

    for (int i = 0; i < 3; i++) {
    coffee.enqueue(makeCustomer(names, coffeeOrders));
    muffins.push_back(makeCustomer(names, muffinOrders));
    bracelets.push_back(makeCustomer(names, braceletOrders));
    }


    cout << "\n=== Coffee + Muffins + Bracelets (10 rounds) ===\n";

    for (int round = 1; round <= 10; round++) {
        cout << "\nRound " << round << ":\n";

       // arrivals
        if (fiftyFifty()) { 
            Customer c = makeCustomer(names, coffeeOrders); 
            cout << "Arrives coffee: " << c.name << " wants " << c.order << "\n"; 
            coffee.enqueue(c);
        } else {
            cout << "No coffee arrival\n"; 
        }

        if (fiftyFifty()) { 
            Customer c = makeCustomer(names, muffinOrders);
            cout << "Arrives muffin: " << c.name << " wants " << c.order << "\n"; 
            muffins.push_back(c);
        } else {
            cout << "No muffin arrival\n"; 
        }

        if (fiftyFifty()) { 
            Customer c = makeCustomer(names, braceletOrders); 
            cout << "Arrives bracelet: " << c.name << " wants " << c.order << "\n"; 
            bracelets.push_back(c);
        } else {
            cout << "No bracelet arrival\n"; 
        }

        // serve coffee
        if (!coffee.empty()) {
            Customer served = coffee.dequeue(); 
            cout << "Serves coffee: " << served.name << " with " << served.order << "\n"; 
        } else {
            cout << "No one served coffee\n"; 
        }

        // serve muffin
        if (!muffins.empty()) { 
            Customer served = muffins.front(); 
            muffins.pop_front();
            cout << "Serves muffin: " << served.name << " with " << served.order << "\n"; 
        } else {
            cout << "No one served muffins\n"; 
        }

        // serve bracelet 
        if (!bracelets.empty()) { 
            Customer served = bracelets.front(); 
            bracelets.erase(bracelets.begin());
            cout << "Serves bracelet: " << served.name << " with " << served.order << "\n"; 
        } else {
            cout << "No one served bracelets\n"; 
        }
        
         coffee.print();
        printDeque(muffins, "Muffins");
        printVector(bracelets, "Bracelets");

    }
    return 0;
}
 




