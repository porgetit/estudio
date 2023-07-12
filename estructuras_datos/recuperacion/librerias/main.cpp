#include <iostream>
#include "./lib/DynamicStack.h"

int main() {
    DynamicStack<int> stack;

    int opcion;
    do {
        std::cout << "---------- MENU ----------" << std::endl;
        std::cout << "1. Insertar elemento" << std::endl;
        std::cout << "2. Extraer elemento" << std::endl;
        std::cout << "3. Obtener tamaño" << std::endl;
        std::cout << "4. Verificar si está vacía" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int elemento;
                std::cout << "Ingrese el elemento a insertar: ";
                std::cin >> elemento;
                stack.insert(elemento);
                std::cout << "Elemento insertado correctamente." << std::endl;
                break;
            }
            case 2: {
                if (!stack.empty()) {
                    int elemento = stack.pop();
                    std::cout << "Elemento extraído: " << elemento << std::endl;
                } else {
                    std::cout << "La pila está vacía. No se puede extraer ningún elemento." << std::endl;
                }
                break;
            }
            case 3: {
                int tamano = stack.size();
                std::cout << "El tamaño de la pila es: " << tamano << std::endl;
                break;
            }
            case 4: {
                bool estaVacia = stack.empty();
                if (estaVacia) {
                    std::cout << "La pila está vacía." << std::endl;
                } else {
                    std::cout << "La pila no está vacía." << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            }
            default:
                std::cout << "Opción inválida. Por favor, ingrese una opción válida." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcion != 5);

    return 0;
}