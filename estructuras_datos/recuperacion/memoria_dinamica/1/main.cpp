#include <iostream>

using namespace std;

void displayList(int* list, int size) {
    cout << "Lista: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

int* addElement(int* list, int& size, int element) {
    int* newList = static_cast<int*>(realloc(list, (size + 1) * sizeof(int)));
    if (newList == nullptr) {
        cerr << "Error: Fallo en la asignación de memoria." << endl;
        return list; // Devuelve la lista original si la realocación falla
    }
    newList[size] = element;
    size++;
    cout << "Asignación de memoria exitosa." << endl;
    return newList;
}

int main() {
    int* list = nullptr;
    int size = 0;

    while (true) {
        cout << "Menú:" << endl;
        cout << "1. Agregar elemento" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Salir" << endl;

        int option;
        cout << "Ingrese una opción: ";
        cin >> option;

        if (option == 1) {
            int element;
            cout << "Ingrese el elemento: ";
            cin >> element;

            list = addElement(list, size, element);
        } else if (option == 2) {
            displayList(list, size);
        } else if (option == 3) {
            break;
        } else {
            cout << "Opción inválida. Por favor, intente nuevamente." << endl;
        }

        cout << endl;
    }

    free(list); // Libera la memoria

    return 0;
}
