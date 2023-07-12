#include <iostream>
#include <string>

using namespace std;

int main() {
    int number = 42;
    int* pNumber = &number;

    cout << "Valor de number: " << number << endl;
    cout << "Dirección de number: " << &number << endl;
    cout << "Valor de pNumber: " << pNumber << endl;
    cout << "Dereferenciando pNumber: " << *pNumber << endl;

    cout << endl;

    string name = "John";
    string* pName = &name;

    cout << "Valor de name: " << name << endl;
    cout << "Dirección de name: " << &name << endl;
    cout << "Valor de pName: " << pName << endl;
    cout << "Dereferenciando pName: " << *pName << endl;

    cout << endl;

    int* pDynamicNumber = new int;
    *pDynamicNumber = 99;

    cout << "Valor de pDynamicNumber: " << pDynamicNumber << endl;
    cout << "Dereferenciando pDynamicNumber: " << *pDynamicNumber << endl;

    delete pDynamicNumber;

    return 0;
}