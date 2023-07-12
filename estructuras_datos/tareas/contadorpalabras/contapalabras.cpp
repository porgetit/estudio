#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;

typedef struct data {
    char palabra[50];
    int contador;
} Data;

typedef struct nodo {
    Data data;
    struct nodo *izquierda;
    struct nodo *derecha;    
} Nodo;

int leerTeclado();
int leerArchivo();

int main() {

    int option;
    
    while (option != 3) {
        
        cout << "\t\t\tMENÚ" << endl;
        cout << "1.\tAnalizar palabras del archivo data.txt" << endl;
        cout << "2.\tRecibir palabras por teclado" << endl;
        cout << "3.\t\t--> Salir" << endl;
        cout << "\n>> ";
        cin >> option;

        switch (option) {
            case 1:
                leerArchivo();
                break;
            case 2:
                leerTeclado();
                break;
            case 3:
                cout << "Adiós" << endl;
                break;            
            default:
                cout << "Opción inválida" << endl;
                break;
        }
    }
    
    return 0;
}

// Agrega una palabra al árbol binario de búsqueda
void agregar_palabra(Nodo **raiz, char *palabra) {
    if (*raiz == NULL) {
        *raiz = (Nodo*)malloc(sizeof(Nodo));
        strcpy((*raiz)->data.palabra, palabra);
        (*raiz)->data.contador = 1;
        (*raiz)->izquierda = NULL;
        (*raiz)->derecha = NULL;
    } else {
        int cmp = strcmp(palabra, (*raiz)->data.palabra);
        if (cmp == 0) {
            (*raiz)->data.contador++;
        } else if (cmp < 0) {
            agregar_palabra(&((*raiz)->izquierda), palabra);
        } else {
            agregar_palabra(&((*raiz)->derecha), palabra);
        }
    }
}

// Cuenta el número de palabras diferentes en el árbol
int contar_palabras_diferentes(Nodo *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + contar_palabras_diferentes(raiz->izquierda) + contar_palabras_diferentes(raiz->derecha);
    }
}

// Imprime el contenido del árbol en orden ascendente
void imprimir_arbol(Nodo *raiz) {
    if (raiz != NULL) {
        imprimir_arbol(raiz->izquierda);
        printf("%s = %d\n", raiz->data.palabra, raiz->data.contador);
        imprimir_arbol(raiz->derecha);
    }
}

// Libera la memoria asignada al árbol
void liberar_arbol(Nodo *raiz) {
    if (raiz != NULL) {
        liberar_arbol(raiz->izquierda);
        liberar_arbol(raiz->derecha);
        free(raiz);
    }
}

// Lee palabras ingresadas por teclado
int leerTeclado() {
    
    Nodo *arbol = NULL;
    char palabra[50];
    int total_palabras = 0;
    int total_palabras_diferentes = 0;
    int i;    

    while (strcmp(palabra,"!") != 0) {
        cout << "Ingrese sus palabras (Si desea terminar ingrese [!]):";
        cin >> palabra;
        if (strcmp(palabra,"!") == 0) {
            cout << "Ingreso de palabras terminado..." << endl;
            cout << "Frecuencia de palabras:" << endl;
            imprimir_arbol(arbol);
            total_palabras_diferentes = contar_palabras_diferentes(arbol);
            cout << "Total de palabras: " << total_palabras << endl;
            cout << "Total de palabras diferentes: " << total_palabras_diferentes << endl;
            liberar_arbol(arbol);
            return 0;
        }
        total_palabras++;

        for (i = 0; i < strlen(palabra); i++) {
            palabra[i] = tolower(palabra[i]);
        }
        agregar_palabra(&arbol, palabra);
    }
    return 0;
}

// Lee palabras desde un archivo
int leerArchivo() {
        
    Nodo *arbol = NULL;
    char palabra[50];
    int total_palabras = 0;
    int total_palabras_diferentes = 0;
    FILE *archivo = fopen("data.txt", "r");

    if (archivo == NULL) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    while (fscanf(archivo, "%s", palabra) != EOF) {        
        total_palabras++;

        for (int i = 0; i < strlen(palabra); i++) {
            palabra[i] = tolower(palabra[i]);
        }

        agregar_palabra(&arbol, palabra);
    }

    fclose(archivo);
    cout << "Frecuencia de palabras:" << endl;
    imprimir_arbol(arbol);
    total_palabras_diferentes = contar_palabras_diferentes(arbol);
    cout << "Total de palabras: " << total_palabras << endl;
    cout << "Total de palabras diferentes: " << total_palabras_diferentes << endl;
    liberar_arbol(arbol);

    return 0;
}
