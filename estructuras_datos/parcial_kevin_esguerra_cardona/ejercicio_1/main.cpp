#include <iostream>

using namespace std;

int main() {
    int u1, u2, v = 3, *pv;
    pv = &v;
    u1 = 2* (v + 5);
    u2 = 2* (*pv + 5);

    cout << "U1: " << u1 << "\nU2: " << u2 << endl;
    
    return 0;
}