# Documentación de la librería Utilities.h para C++

## Introducción
La librería Utilities.h para C++ contiene tres clases útiles para manipular pilas dinámicas, colas dinámicas y cadenas. Estas clases son StackTools, QueueTools y StringTools, respectivamente.

## Clase StackTools
La clase StackTools se utiliza para manipular pilas dinámicas. Permite realizar operaciones como agregar elementos a la pila, sacar elementos de la pila y obtener el tamaño actual de la pila, entre otros.

### Métodos

- Empilar un elemento :arrow_right: ```void push(DataType)```
- Desempilar la cabecera :arrow_right: ```DataType pop()```
- Obtener la longitud de la pila :arrow_right: ```int size()```
- Verificar si la pila está vacía :arrow_right: ```bool empty()``` 
- Limpiar la pila :arrow_right: ```void clear()```
- Obtener el elemento de la cabecera :arrow_right: ```DataType peek()```
- Obtener toda la pila :arrow_right: ```vector<DataType> return_stack()```

### Implementación

El siguiente código es un archivo de implementación que enseña el uso de la clase StackTools y sus métodos:

```cpp
#include <iostream>
#include "utilities.h"

using namespace std;

int main() {
    StackTools<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Tamaño de la pila: " << myStack.size() << endl;
    cout << "Contenido de la pila: ";
    for (int val : myStack.return_stack()) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Valor en la parte superior de la pila: " << myStack.peek() << endl;

    int poppedVal = myStack.pop();
    cout << "Elemento extraído de la pila: " << poppedVal << endl;

    myStack.clear();
    cout << "La pila está vacía: " << myStack.empty() << endl;
    cout << "Tamaño después de limpiar: " << myStack.size() << endl; // Debería imprimir "0"

    return 0;
}
```

## Clase QueueTools
La clase QueueTools se utiliza para manipular colas dinámicas. Permite realizar operaciones como agregar elementos a la cola, sacar elementos de la cola y obtener el tamaño actual de la cola.

### Métodos

- Encolar un elemento :arrow_right: ```void push(DataType)```
- Desencolar un elemento :arrow_right: ```DataType pop()```
- Obtener la longitud de la cola :arrow_right: ```int size()```
- Verificar si la cola está vacía :arrow_right: ```bool empty()```
- Limpiar la cola :arrow_right: ```void clear()```
- Obtener toda la cola :arrow_right: ```vector<DataType> return_queue()```
- Obtener el primer elemento de la cola :arrow_right: ```DataType firstIn()```
- Obtener el último elemento de la cola :arrow_right: ```DataType lastIn()```

### Implementación

El siguiente código es un archivo de implementación que enseña el uso de la clase QueueTools y sus métodos:

```cpp
#include <iostream>
#include "utilities.h"

using namespace std;

int main() {
    QueueTools<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    cout << "Tamaño: " << queue.size() << endl; // Debería imprimir "3"

    cout << "Primer elemento: " << queue.firstIn() << endl; // Debería imprimir "10"

    cout << "Último elemento: " << queue.lastIn() << endl; // Debería imprimir "30"

    cout << "Elementos: ";
    for (int elem : queue.return_queue()) {
        cout << elem << " "; // Debería imprimir "10 20 30"
    }
    cout << endl;

    int first = queue.pop();
    cout << "Primer elemento desencolado: " << first << endl; // Debería imprimir "10"

    cout << "Elemetos: ";
    for (int elem : queue.return_queue()) {
        cout << elem << " "; // Debería imprimir "20 30"
    }
    cout << endl;

    queue.clear();

    cout << "Tamaño después de limpiar: " << queue.size() << endl; // Debería imprimir "0"

    return 0;
}
```

## Clase StringTools
La clase StringTools se utiliza para manipular cadenas. Permite realizar operaciones como convertir una cadena a mayúsculas o minúsculas, obtener la longitud de una cadena y dividir una cadena en subcadenas.

### Métodos

- Filtrar una cadena :arrow_right: ```void filterString(string& input, const vector<char>& allowed_chars)```
- Obtener una cadena seccionada :arrow_right: ```vector<string> splitString(const string& input, char splitter)```
- Verifica si una cadena es un número :arrow_right: ```bool isNumber(string input)```
- Verificar si una cadena es un operador binario :arrow_right: ```bool isBinaryOperator(string input)```
- Convertir una cadena en mayúsculas :arrow_right: ```void toUpperCase(string& input)```
- Convertir una cadena en minúsculas :arrow_right: ```void toLowerCase(string& input)```

### Implementación

El siguiente código es un archivo de implementación que enseña el uso de la clase StringTools y sus métodos:

```cpp
#include <iostream>
#include "utilities.h"

using namespace std;

int main() {
    StringTools tools;
    string input = "Hello, World!";
    vector<char> allowed_chars = {'H', 'l', 'o', ','};
    tools.filterString(input, allowed_chars);
    cout << input << endl;

    string input2 = "this,is,a,test";
    vector<string> result = tools.splitString(input2, ',');
    for (auto& str : result) {
        cout << str << endl;
    }

    string input3 = "123.45";
    if (tools.isNumber(input3)) {
        cout << "Input is a number" << endl;
    } else {
        cout << "Input is not a number" << endl;
    }

    string input4 = "&&";
    if (tools.isBinaryOperator(input4)) {
        cout << "Input is a binary operator" << endl;
    } else {
        cout << "Input is not a binary operator" << endl;
    }

    string input5 = "hello world";
    tools.toUpperCase(input5);
    cout << input5 << endl;

    string input6 = "HELLO WORLD";
    tools.toLowerCase(input6);
    cout << input6 << endl;

    return 0;
}
```
## Clase RandomTools
La clase RandomTools proporciona herramientas para generar números aleatorios en diferentes rangos y formatos. Permite obtener enteros y vectores de enteros aleatorios, así como números de punto flotante y vectores de punto flotante. Además, es capaz de generar caracteres aleatorios y cadenas de caracteres de longitud arbitraria. También ofrece la posibilidad de generar valores booleanos aleatorios.

### Métodos

- Obtener un número entero aleatorio dentro de una rango :arrow_right: ```int randomInt(int cota_a, int cota_b)```
- Obtener un ventor de número enteros aleatorios dentro de una rango :arrow_right: ```vector<int> randomIntVector(int len, int cota_a, int cota_b)```
- Obtener un número con coma flotante aleatorio dentro de un rango :arrow_right: ```float randomFloat(float cota_a, float cota_b)```
- Obtener un vector de números con coma flotante aleatorios dentro de una rango :arrow_right: ```vector<float> randomFloatVector(int len, float cota_a, float cota_b)```
- Obtener una letra minúscula aleatoria :arrow_right: ```char randomChar()```
- Obtener una cadena de letras minúsculas aleatorias de longitud especificada :arrow_right: ```string randomString(int len)```
- Obtener un valor booleano aleatorio :arrow_right: ```bool randomBool()```

### Implementación
```cpp
#include <iostream>
#include "utilities.h"

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
```