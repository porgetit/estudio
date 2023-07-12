#include <iostream>
#include <cstring>

using namespace std;

typedef struct {
    char name[50];
    int age;
} Person;

void displayList(Person* list, int size) {
    cout << "Lista de Personas:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Persona " << i + 1 << ":" << endl;
        cout << "Nombre: " << list[i].name << endl;
        cout << "Edad: " << list[i].age << endl;
        cout << "------------------------" << endl;
    }
}

Person* addPerson(Person* list, int& size, const char* name, int age) {
    Person newPerson;
    strncpy(newPerson.name, name, sizeof(newPerson.name) - 1);
    newPerson.name[sizeof(newPerson.name) - 1] = '\0';
    newPerson.age = age;

    Person* newList = static_cast<Person*>(realloc(list, (size + 1) * sizeof(Person)));
    if (newList == nullptr) {
        cerr << "Error: Fallo en la asignación de memoria." << endl;
        return list; // Devuelve la lista original si la realocación falla
    }

    newList[size] = newPerson;
    size++;
    cout << "Asignación de memoria exitosa." << endl;
    return newList;
}

int main() {
    Person* personList = nullptr;
    int size = 0;

    while (true) {
        cout << "Menú:" << endl;
        cout << "1. Agregar persona" << endl;
        cout << "2. Mostrar lista de personas" << endl;
        cout << "3. Salir" << endl;

        int option;
        cout << "Ingrese una opción: ";
        cin >> option;

        if (option == 1) {
            char name[50];
            int age;

            cout << "Ingrese el nombre: ";
            cin.ignore();
            cin.getline(name, sizeof(name));

            cout << "Ingrese la edad: ";
            cin >> age;

            personList = addPerson(personList, size, name, age);
        } else if (option == 2) {
            displayList(personList, size);
        } else if (option == 3) {
            break;
        } else {
            cout << "Opción inválida. Por favor, intente nuevamente." << endl;
        }

        cout << endl;
    }

    free(personList); // Libera la memoria

    return 0;
}
