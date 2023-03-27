#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int* ptr; // declaramos el puntero
    int n = 5; // numero de elementos a almacenar
    
    // asignamos la memoria dinamicamente con malloc()
    ptr = (int*) malloc(n * sizeof(int));
    
    // verificamos si la asignaci�n fue exitosa
    if (ptr == NULL)
    {
        cout << "Error: Memoria no asignada." << endl;
        exit(1);
    }
    
    // asignamos valores a los elementos del arreglo din�mico
    for (int index = 0; index < n; index++)
    {
        int i = index;
        *(ptr + i) = i*i*i;
    }
    
    // imprimimos los valores del arreglos din�mico
    for (int index = 0; index < n; index++)
    {
        cout << *(ptr + index) << " ";
    }
    cout << endl;
    
    // liberamos la memoria asignada usando free()
    free(ptr);
    
    return 0;
}
