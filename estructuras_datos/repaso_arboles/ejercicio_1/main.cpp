/*
Evaluar, por medio de árboles binarios expresiones algebráicas
*/
#include <iostream>
#include <vector>
#include "../../librerias/utilities/utilities.h"

using namespace std;

int main() {
    TreeTools<char> miArbol;

    string my_expression = "+ 2 + 1 44";

    StringTools stringDriver;
    vector<string> my_splitted_expression = stringDriver.splitString(my_expression, ' ');

    for (auto i : my_splitted_expression) {
        
    }


    return 0;
}