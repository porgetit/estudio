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
    string cadena = "([2 + 5] * 7 + (3 + 9))";

    // Definimos los caracteres que nos sirven
    vector<char> util_chars = {'(', ')', '{', '}', '[', ']'};

    // Eliminamos todo lo que no nos sea útil
    string_tools strings_driver;
    strings_driver.filterString(cadena, util_chars);

    // Creamos una pila contenedor y analizamos el balance de paréntesis
    stack_tools<char> stacks_driver;
    stack_tools<char>::Stack contenedor = stacks_driver.init_stack();

    for (int index = 0; index < cadena.size(); index++) {
        try
        {
            if (cadena[index] == '(' || cadena[index] == '{' || cadena[index] == '[') {
                stacks_driver.push(&contenedor, cadena[index]);
            } else if ((cadena[index] == ')' && stacks_driver.peek(&contenedor) == '(') || (cadena[index] == '}' && stacks_driver.peek(&contenedor) == '{') || (cadena[index] == ']' && stacks_driver.peek(&contenedor) == '[')) {
                stacks_driver.pop(&contenedor);
            }
        }
        catch(runtime_error& e)
        {   
            if (cadena[index] == ')') {
                cerr << "Falta un paréntesis de apertura." << endl;
            } else if (cadena[index] == '}') {
                cerr << "Falta un corchete de apertura." << endl;
            } else {
                cerr << "Falta un corchete cuadrado de apertura." << endl;
            }
            exit(1);
        }        
    }

    if (!stacks_driver.empty(&contenedor)) {
        char temp = stacks_driver.pop(&contenedor);

        if (temp == '(') {
            cerr << "Falta un paréntesis de cierre." << endl;
        } else if (temp == '{') {
            cerr << "Falta un corchete de cierre." << endl;
        } else {
            cerr << "Falta un corchete cuadrado de cierre." << endl;
        }
        
        exit(1);
    } else {
        cout << "La expresión esta balanceada." << endl;
    }

    /*
    Hasta este punto, existe un error lógico:

        La expresion "()(()()(())))" la evalúa como balanceada. Falta un paréntesis de apertura.
    */

    return 0;
}