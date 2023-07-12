#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream file("quijote.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    ofstream outputFile("quijoteMayus.txt");
    if (!outputFile.is_open()) {
        cerr << "Error al crear el archivo de salida" << endl;
        return 1;
    }

    map<char, int> conteoCaracteres;
    int totalCaracteres = 0;

    // Leer el archivo carácter por carácter y convertir a mayúsculas
    char c;
    while (file.get(c)) {
        if (isalpha(c)) {
            c = toupper(c); // Convertir a mayúscula
            outputFile << c; // Escribir en el nuevo archivo
            conteoCaracteres[c]++;
            totalCaracteres++;
        }
    }

    // Mostrar el conteo y porcentaje de cada letra
    for (char letra = 'A'; letra <= 'Z'; letra++) {
        int conteo = conteoCaracteres[letra];
        double porcentaje = (static_cast<double>(conteo) / totalCaracteres) * 100.0;
        cout << "Letra '" << letra << "': " << conteo << " apariciones ("
             << porcentaje << "%)" << endl;
    }

    file.close();
    outputFile.close();

    return 0;
}
