# Documentación de la librería Utilities.h para C++

## Introducción
La librería Utilities.h para C++ contiene tres clases útiles para manipular pilas dinámicas, colas dinámicas y cadenas. Estas clases son StackTools, QueueTools y StringTools, respectivamente.

## Clase StackTools
La clase StackTools se utiliza para manipular pilas dinámicas. Permite realizar operaciones como agregar elementos a la pila, sacar elementos de la pila y obtener el tamaño actual de la pila.

### Métodos

- ```void push(DataType)```
- ```DataType pop()```
- ```int size()```
- ```bool empty()```
- ```void clear()```
- ```DataType peek()```
- ```vector<DataType> return_stack()```

### Implementación

El siguiente código es un archivo de implementación que enseña el uso de la clase StackTools y sus métodos:

```cpp:/estructuras_datos/librerias/utilities/implementaciones/pilas/main.cpp
```

## Clase QueueTools
La clase QueueTools se utiliza para manipular colas dinámicas. Permite realizar operaciones como agregar elementos a la cola, sacar elementos de la cola y obtener el tamaño actual de la cola.

### Métodos

- ```void push(U)```
- ```U pop()```
- ```int size()```
- ```bool empty()```
- ```void clear()```
- ```vector<U> return_queue()```
- ```U firstIn()```
- ```U lastIn()```

### Implementación

El siguiente código es un archivo de implementación que enseña el uso de la clase QueueTools y sus métodos:

```cpp:/estructuras_datos/librerias/utilities/implementaciones/colas/main.cpp
```

## Clase StringTools
La clase StringTools se utiliza para manipular cadenas. Permite realizar operaciones como convertir una cadena a mayúsculas o minúsculas, obtener la longitud de una cadena y dividir una cadena en subcadenas.

### Métodos

- ```void filterString(string& input, const vector<char>& allowed_chars)```
- ```bool inVectorFindElement(char element, const vector<char>& container)```
- ```vector<string> splitString(const string& input, char splitter)```
- ```bool isNumber(string input)```
- ```bool isBinaryOperator(string input)```
- ```void toUpperCase(string& input)```
- ```void toLowerCase(string& input)```

### Implementación

El siguiente código es un archivo de implementación que enseña el uso de la clase StringTools y sus métodos:

```cpp:/estructuras_datos/librerias/utilities/implementaciones/strings/main.cpp
```
