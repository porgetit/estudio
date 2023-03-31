/*
Balanceo de paréntesis: 

Se debe desarrollar un programa que tenga las siguientes responsabilidades :

    - Ingresar una fórmula que contenga paréntesis, corchetes y llaves. 
    - Validar que los () [] y {} estén correctamente balanceados.
*/
#include <iostream>
#include <string>
#include <vector>
#include "./utilities/utilities.h"

using namespace std;

int main() {
    // Definimos nuestra expresión
    string cadena = "()(()())()";

    // Definimos los caracteres que nos sirven
    vector<char> util_chars = {'(', ')'};

    // Eliminamos todo lo que no nos sea útil
    string_tools strings_driver;
    strings_driver.filterString(cadena, util_chars);

    // Creamos una pila contenedor y analizamos el balance de paréntesis
    stack_tools<char> stacks_driver;
    stack_tools<char>::Stack contenedor = stacks_driver.init_stack();

    for (int index = 0; index < cadena.size(); index++) {
        try
        {
            if (cadena[index] == '(') {
                stacks_driver.push(&contenedor, '(');
            } else {
                stacks_driver.pop(&contenedor);
            }
        }
        catch(runtime_error& e)
        {   
            cerr << "Falta un paréntesis de apertura." << endl;
            exit(1);
        }        
    }

    if (!stacks_driver.empty(&contenedor)) {
        cerr << "Falta un paréntesis de cierre." << endl;
        stacks_driver.clear(&contenedor);
    } else {
        cout << "La expresión esta balanceada." << endl;
    }

    return 0;
}