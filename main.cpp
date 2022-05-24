#include <iostream>

#include "Daoi.h"
#include "DaoiException.h"
using namespace std;

int main() {
    Daoi first = Daoi();
    Daoi second = Daoi(5);
    Daoi third = Daoi(5, 0);
    Daoi copying = Daoi(third);
    Daoi moving = third;

    cout << "get size length first array: " << first.getSize() << endl;
    cout << first;
    cout << "get size length second array: " << second.getSize() << endl;
    cout << second;
    cout << "get size length third array: " << third.getSize() << endl;
    cout << third;
    cout << "get size length copying array: " << copying.getSize() << endl;
    cout << copying;
    cout << "get size length moving array: " << moving.getSize() << endl;
    cout << "get size length third array: " << third.getSize() << endl;
    Daoi a = Daoi(5);
    for(int i = 0;i < 5;i++) a[i] = i;

    Daoi b = Daoi(6);
    for(int i = 0;i < 6;i++) b[i] = i;
    bool res1 = (a > b);
    cout << " > ? "<<res1 << endl;
    res1 = (a < b);
    cout << " < ? "<<res1 << endl;

    return 0;
}
