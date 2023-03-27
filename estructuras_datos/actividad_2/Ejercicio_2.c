// Punto 2. Sumas secuenciales de complejidad computacional.
#include <stdio.h>

void primerCaso(int *, int *, int*);
void segundoCaso(int *, int *, int *);
void tercerCaso();

int main() {
	int op, x, y, sum;
	x = y = sum = 0;
	printf("Seleccione una opción:\n");
	printf("1) Caso 1\n");
	printf("2) Caso 2\n");
	printf("3) Caso 3\n");
	printf("Caso elegido: ");

	scanf("%d", &op);

	switch (op) {
		// Caso 1: Dados dos números naturales x y y. Sumar x a si mismo (y - 1) veces.
		case 1:
			printf("Ingrese el primer número: ");
			scanf("%d", &x); fflush(stdin);
			printf("Ingrese el segundo número: ");
			scanf("%d", &y); fflush(stdin);

			primerCaso(&x, &y, &sum);

			printf("\nEl resultado es: %d", sum);
			x = y = sum = 0;
			break;

		// Caso 2: Dados dos números naturales x y y. Sumar el número mayor x, y veces al número menor y.
		case 2:
			printf("Ingrese el primer número: ");
			scanf("%d", &x); fflush(stdin);
			printf("Ingrese el segundo número: ");
			scanf("%d", &y); fflush(stdin);

			segundoCaso(&x, &y, &sum);

			printf("\nEl resultado es: %d", sum);
			x = y = sum = 0;
			break;
		// Caso 3: Dados dos números naturales x = A * 10^B y y = C * 10^D.
		case 3:
			tercerCaso();
			break;
	}
	return 0;
}

void primerCaso(int *x, int *y, int *sum){
	for (int i = 0; i <= (*y)-1; i++)
	{
		*sum += *x;
		// printf("Suma %d \n", i);
	}
}

void segundoCaso(int *x, int *y, int *sum){
	if (*x < *y) {
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	for (int i = 0; i <= (*y)-1; i++){
		*sum += *x;
		// printf("Suma %d \n", i);
	}
}

void tercerCaso(){
	// Pedir los valores de x y y
    int A, B, C, D, S, E, n;
    printf("Ingrese dos números naturales x e y en el formato x = A * 10^B y y = C * 10^D: ");
    scanf("%d * 10^%d %d * 10^%d", &A, &B, &C, &D); fflush(stdin);

    // Calcular el valor de S y E
    segundoCaso(&A, &C, &S);
    E = B + D;

    // Imprimir el resultado
    printf("El resultado es: %d * 10^%d\n", S, E);
}