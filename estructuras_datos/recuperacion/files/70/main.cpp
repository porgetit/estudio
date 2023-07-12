#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

typedef struct {
    unsigned long clave;
    char descripcion[50];
    double cred;
} asignatura;

void listarAsignaturas(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    cout << "Listado de asignaturas:" << endl;

    try {
        asignatura subject;
        while (file.read(reinterpret_cast<char*>(&subject), sizeof(asignatura))) {
            cout << "Clave: " << subject.clave << endl;
            cout << "Descripción: " << subject.descripcion << endl;
            cout << "Créditos: " << subject.cred << endl;
            cout << "------------------------" << endl;
        }
    } catch (const std::exception& e) {
        cerr << "An error occurred while reading the file: " << e.what() << endl;
    }

    file.close();
}

void agregarAsignatura(const string& filename, const asignatura& subject) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    try {
        file.write(reinterpret_cast<const char*>(&subject), sizeof(asignatura));
    } catch (const std::exception& e) {
        cerr << "An error occurred while writing to the file: " << e.what() << endl;
    }

    file.close();
}

void exportarAsignaturas(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file" << endl;
        inputFile.close();
        return;
    }

    try {
        asignatura subject;
        while (inputFile.read(reinterpret_cast<char*>(&subject), sizeof(asignatura))) {
            outputFile << "Clave: " << subject.clave << endl;
            outputFile << "Descripción: " << subject.descripcion << endl;
            outputFile << "Créditos: " << subject.cred << endl;
            outputFile << "------------------------" << endl;
        }
    } catch (const std::exception& e) {
        cerr << "An error occurred while exporting the file: " << e.what() << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Asignaturas exported to '" << outputFilename << "' successfully." << endl;
}

void modificarAsignatura(const string& filename, unsigned long clave) {
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    asignatura subject;
    bool found = false;

    while (!found && file.read(reinterpret_cast<char*>(&subject), sizeof(asignatura))) {
        if (subject.clave == clave) {
            found = true;

            cout << "Ingrese la nueva descripción: ";
            cin.ignore();
            cin.getline(subject.descripcion, 50);

            cout << "Ingrese los nuevos créditos: ";
            cin >> subject.cred;

            file.seekp(file.tellg() - sizeof(asignatura));
            file.write(reinterpret_cast<const char*>(&subject), sizeof(asignatura));
        }
    }

    if (!found) {
        cout << "Asignatura no encontrada." << endl;
    }

    file.close();
}

int main() {
    string filename = "asignaturas.bin";

    while (true) {
        cout << "1. Agregar asignatura" << endl;
        cout << "2. Listar asignaturas" << endl;
        cout << "3. Exportar asignaturas" << endl;
        cout << "4. Modificar asignatura" << endl;
        cout << "5. Salir" << endl;

        int option;
        cout << "Ingrese una opción: ";
        cin >> option;

        if (option == 1) {
            asignatura subject;

            cout << "Ingrese la clave: ";
            cin >> subject.clave;

            cout << "Ingrese la descripción: ";
            cin.ignore();
            cin.getline(subject.descripcion, 50);

            cout << "Ingrese los créditos: ";
            cin >> subject.cred;

            agregarAsignatura(filename, subject);
        } else if (option == 2) {
            listarAsignaturas(filename);
        } else if (option == 3) {
            string outputFilename = "asignaturas.txt";

            exportarAsignaturas(filename, outputFilename);
        } else if (option == 4) {
            unsigned long clave;
            cout << "Ingrese la clave de la asignatura a modificar: ";
            cin >> clave;

            modificarAsignatura(filename, clave);
        } else if (option == 5) {
            break;
        } else {
            cout << "Opción inválida. Intente nuevamente." << endl;
        }

        cout << endl;
    }

    return 0;
}
