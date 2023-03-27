/*
Crea un programa que pida al usuario un número entero n y luego cree un arreglo dinámico de caracteres de tamaño n utilizando malloc. Luego, pide al usuario que ingrese una cadena de caracteres (de longitud menor o igual a n) y almacena la cadena en el arreglo dinámico. Muestra la cadena almacenada en la consola.
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int longitud;
    char* cadena;

    // Pedimos la longitud de la cadena y asignamos el espacio necesario
    cout << "Ingrese la longitud maxima de la cadena: ";
    cin >> longitud; fflush(stdin);
    longitud++; // <-- por lo del '\0'

    cadena = (char*) malloc((longitud) * sizeof(char));

    if (cadena == NULL) {
        cout << "Error: Memoria no disponible." << endl;
        exit(1);
    }


    // Pedimos la cadena y eliminamos el salto de línea final, si este existe
    cout << "Ingrese una cadena de " << longitud -1 << " caracteres: ";
    fgets(cadena, longitud, stdin);

    int len = strlen(cadena);
    if (len > 0 && cadena[len-1] == '\n') {
        cadena[len-1] = '\0';
    }

    // Mostrar la cadena ingresada
    cout << "Cadena ingresada: " << cadena << endl;

    // Liberamos el espacio en memoria
    free(cadena);

    return 0;
}