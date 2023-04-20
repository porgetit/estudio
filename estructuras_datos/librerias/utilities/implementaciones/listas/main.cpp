#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../utilities.h"

using namespace std;

int main() {
    srand(time(nullptr));

    ListTools<int> myList;

    for (int i = 0; i < 10; i++) {
        myList.append(i);
    }

    for (auto i : myList.completeList()) {
        cout << i << " ";
    }

    cout << endl;

    myList.clear();

    for (int i = 0; i < 10; i++) {
        myList.append((rand() % 11) + 0);
    }

    for (auto i : myList.completeList()) {
        cout << i << " ";
    }

    cout << endl;

    myList.bubbleSort('>');

    for (auto i : myList.completeList()) {
        cout << i << " ";
    }

    cout << endl;

    myList.bubbleSort('<');

    for (auto i : myList.completeList()) {
        cout << i << " ";
    }
}