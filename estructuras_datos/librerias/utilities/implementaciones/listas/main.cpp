#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../utilities.h"

#define MAX 11

using namespace std;

int main() {
    srand(time(nullptr));
    ListTools<int> mylist("data.bin");

    for (int i = 0; i < 5; i++) {
        mylist.append(rand() % MAX);
    }

    cout << "Lista original: ";
    for (auto i : mylist.completeList() ) {
        cout << i << " ";
    }
    cout << endl;

    mylist.insert(1, 4);

    cout << "Lista después de insertar 4: ";
    for (auto i : mylist.completeList() ) {
        cout << i << " ";
    }
    cout << endl;

    mylist.pop();

    cout << "Lista después de eliminar el último elemento: ";
    for (auto i : mylist.completeList() ) {
        cout << i << " ";
    }
    cout << endl;

    try
    {
        mylist.remove(2);
        cout << "Lista después de eliminar el elemento 2: ";
        for (auto i : mylist.completeList() ) {
            cout << i << " ";
        }
        cout << endl;
    }
    catch(const std::exception& e)
    {
        cout << "El elemento 2 no está en la lista" << endl;
    }
    

    return 0;
}
