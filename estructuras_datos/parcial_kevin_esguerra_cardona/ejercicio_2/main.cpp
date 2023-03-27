#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX 50

using namespace std;

void load_data(legajo*, int);
void show_data(legajo*, int);

typedef struct {
    unsigned int num_reg;
    char nombre[MAX];
    float nota;
} legajo;

int main() {
    int cantidad_registros;
    legajo *data;

    // Pedimos la cantidad de registros
    cout << "Ingrese la cantidad de registros deseada: ";
    cin >> cantidad_registros; fflush(stdin);

    // Asignamos el espacio en memoria
    data = (legajo*) malloc(cantidad_registros * sizeof(legajo));
    if (data == NULL) {
        cout << "Error: Memoria insuficiente." << endl;
        exit(1);
    }

    // Cargamos los datos al arreglo
    load_data(data, cantidad_registros);

    // Mostramos los datos del arreglo
    show_data(data, cantidad_registros);

    // Liberamos memoria
    free(data);

    return 0;
}

void load_data(legajo *data, int len) {
    for (int index = 0; index < len; index++) {
        // indice del registro
        data->num_reg = index +1;
        cout << "Registro #" << index +1 << " :" << endl;
        
        // nombre del registro
        cout << "Nombre: ";
        fgets(data->nombre, MAX, stdin);

        // nota del registro
        cout << "Nota: ";
        cin >> data->nota;
    }

    cout << "REGISTROS CARGADOS." << endl;
}

void show_data(legajo *data, int len) {
    for (int index = 0; index < len; index++) {
        cout << "[" << data->num_reg << "] Estudiante: " << data->nombre << endl;
        cout << "Calificación: " << data->nota << endl; 
    }
}