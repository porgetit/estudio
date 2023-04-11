#include <iostream>
#include "../../utilities.h"

using namespace std;

int main() {
    RandomTools randomTools;

    cout << "Número aleatorio entre 1 y 10: " << randomTools.randomInt(1, 10) << endl;

    vector<int> vec = randomTools.randomIntVector(5, 1, 10);
    cout << "Vector de enteros aleatorios: ";
    for (auto i: vec) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Número aleatorio entre 1.0 y 2.0: " << randomTools.randomFloat(1.0, 2.0) << endl;

    vector<float> vec2 = randomTools.randomFloatVector(5, 1.0, 2.0);
    cout << "Vector de flotantes aleatorios: ";
    for (auto i: vec2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Carácter aleatorio: " << randomTools.randomChar() << endl;

    cout << "Cadena aleatoria de longitud 5: " << randomTools.randomString(5) << endl;

    cout << "Booleano aleatorio: " << randomTools.randomBool() << endl;

    return 0;
}