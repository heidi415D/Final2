#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

string Customer{
    string name;
    string order;
};

int randInt(int low, int high) {
    return rand() % (high - low + 1) + low;
}

Customer makeCustomer(const vector<string>& names, const vector<>>& orders) {
    Customer c;

    c.name = names[randInt(0, (int)names.size() - 1)];
    c.order = orders[randInt(0, (int)orders.size() - 1)];
    return c;
}

int main(){
    cout << "Simulation starting...\n";
    return 0;
}



