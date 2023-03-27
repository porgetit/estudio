#include "pila.h"

//crearPila inicializa una pila sin elementos, vacia, pone el indice cima a -1.
void crearPila (Pila* pila)
{
    pila -> cima = -1;
}

// Insertar un elemento en la pila
void insertar (Pila* pila, TipoDato elemento)
{
/* si la pila esta llena, termina el programa */
	if (pilaLlena (*pila) )
	{
		puts ("Desbordamiento pila");
		exit (1);
	}
    pila -> cima++;
    pila -> listaPila[pila->cima] = elemento;
}

/* Quitar un elemento de la pila */
TipoDato quitar (Pila* pila)
{
	TipoDato tem;
	/* si la pila esta vacia, termina el programa */
	if (pilaVacia (*pila) )
	{
        puts(" Se intenta sacar un elemento en pila vacia");
        exit(1);
	}
    tem = pila -> listaPila[pila->cima];
    pila -> cima--;
    return tem;
}

//La operacion cima devuelve el elemento que se encuentra en la cima de la pila, no se modifica la pila.
TipoDato cima (Pila pila)
{
    if (pilaVacia (pila) )
    {
    puts (" Error de ejecucion, pila vacia");
    exit (1);
    }
    return pila.listaPila[pila.cima];
}

/*La funci�n pilaVacia comprueba si la pila no tiene elementos; para que eso ocurra, la cima de
la pila debe ser -1.*/
int pilaVacia (Pila pila)
{
    return pila.cima == -1; 
}

/*La funci�n pilaLlena comprueba si la pila est� llena, seg�n el tama�o del arreglo donde se
guardan sus elementos.*/
int pilaLlena (Pila pila)
{
    return pila.cima == TAMPILA - 1;
}

/*Por ultimo, la operacion limpiarPila vacia integramente la pila, para lo que pone cima al valor
que se corresponde con pila vacia (-1)*/
void limpiarPila (Pila* pila)
{
    pila -> cima = -1;
}
