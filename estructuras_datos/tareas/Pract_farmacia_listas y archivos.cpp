#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/************************************************************************\
* Programa: FARMACIA (PUNTEROS)                                          *
* Autores:                     *
\************************************************************************/

// Vamos a introducir medicamentos con la estructura Bloque y trabajaremos desde block
struct Bloque
    {
    char Laboratorio[30];
    char Nombre[25];
    int Cantidad;
    float Precio_Venta;
    char Cobertura[2];
    };
struct Bloque block;

// Trabajamos con la estructura nodo a la cual apuntamos con punteros e introducimos
// distintos datos tipo Bloque en la parte datos y enlacaremos otro nodo en la parte sig
struct Nodo
{
    struct Bloque datos;
    struct Nodo * sig;
};

//    Creamos el inicio de la lista que es un puntero vacio (puntero maestro)
//    Tambien creamos los punteros aux y atras que utilizaremos para distintas funciones
    struct Nodo * inicio;
    struct Nodo * aux, * atras ;

//
int opcion;
int encontrado;
int r;
int opcion1;
char compara [25];
int continuar;
FILE * fp;

//FUNCIONES

/*CREAR MEDICAMENTO*/
int crear(void)
    {
    // Creamos un medicamento en block
    printf("Introduzca el nombre del medicamento: "); scanf("%s",&block.Nombre);
    printf("Introduzca el nombre del laboratorio: "); scanf("%s" ,&block.Laboratorio);
    printf("Se puede solicitar receta? (escribe 'si' o 'no'): "); scanf("%s",&block.Cobertura);
    printf("Introduzca la cantidad de medicamentos disponibles: "); scanf ("%d", &block.Cantidad);
    printf("Introduzca el precio de venta: "); scanf ("%f", &block.Precio_Venta);

    // Se introducen los datos de block en la parte datos del nodo
    aux->datos = block;
    // Reservamos un nuevo espacio de memoria
    aux->sig = (Nodo*)malloc( sizeof(struct Nodo));
    // Nuestro puntero auxiliar apunta a este nuevo espacio.
    aux = aux->sig;
    aux->sig = NULL;

    printf("\n");printf("       *Medicamento Creado*");printf("\n \n");
    system("PAUSE");

    return 0;
    }

//*ELIMINAR*/
int eliminar (void)
{
/* La estructura basica de eliminar trata que mediante el puntero atras (que apunta al anterior que aux)
 vamos a enlazar el nodo al que apunta atras con el siguiente al que apunta aux de forma que se ignorara
 el nodo al que esta apuntando actualmente aux puesto que no lo tenemos enlazado de ninguna forma y
 acto seguido borrraremos todos los datos que se encuentran en el*/

    encontrado=0;
    printf("\n");
  printf(" Que medicamento quieres eliminar?: "); scanf("%s",&compara);

for (atras = NULL, aux=inicio; aux != NULL; atras = aux, aux = aux->sig)
{
    if (strcmp (compara , aux->datos.Nombre)==0 )
    {
        if (atras == NULL)
        {
        inicio = aux->sig;
        free(aux);
        }
        else
        {
        atras->sig = aux->sig;
        free(aux);
        aux=atras->sig;
        }
        printf("\n"); printf("        El medicamento ha sido eliminado correctamente"); printf("\n");
        encontrado=1;
//        return inicio;
    }

}

            if (encontrado==0)
        {
            printf("\n"); printf("*No existe ese medicamento*" ); printf("\n");
        }
    printf("\n \n");
        system("PAUSE");
    return 0;
}

//MOSTRAR TODOS

int mostrar_todos(void)
// Motramos todos los medicamentos haciendo que el puntero aux avance por toda la lista.
{
    printf("\n");
    aux=inicio;
 while (aux->sig!=NULL)
 {
            printf("Nombre: %s ",aux->datos.Nombre); printf("\n");
            printf("Laboratorio: %s ",aux->datos.Laboratorio); printf("\n");
            printf("Receta: %s ",aux->datos.Cobertura); printf("\n");
            printf("Cantidad: %d ",aux->datos.Cantidad); printf("\n");
            printf("Precio: %f ",aux->datos.Precio_Venta); printf("\n");
            printf("\n \n");
            aux = aux->sig;
 }
        //para hacer una pausa en el programa
        system("PAUSE");
    return 0;
}


/*CONSULTAR*/

int consultar(void)
    {

    encontrado=0;
    printf("\n");
    printf(" Que medicamento quieres consultar?: "); scanf("%s",&compara);

    aux=inicio;
    while (aux->sig!=NULL)
    {
        // Mediante un comparador de strings se encontrara el medicamento adecuado por su nombre.
       if (strcmp (compara , aux->datos.Nombre)==0 )
        {
            printf("Nombre: %s ",aux->datos.Nombre); printf("\n");
            printf("Laboratorio: %s ",aux->datos.Laboratorio); printf("\n");
            printf("Receta: %s ",aux->datos.Cobertura); printf("\n");
            printf("Cantidad: %d ",aux->datos.Cantidad); printf("\n");
            printf("Precio: %f ",aux->datos.Precio_Venta); printf("\n");
            //si encuentra el medicamento lo anotamos en la variable encontrado
            encontrado=1;
        }
        aux = aux->sig;
    }

    // Si no encuentra el medicamento

        if (encontrado==0)
        {
            printf("\n"); printf("*No existe ese medicamento*" ); printf("\n");
        }
    printf("\n \n");
        system("PAUSE");
    return 0;
    }

    /*MODIFICAR*/
int modificar(void)
    {
        r=1;
            printf("\n");
            printf(" Que medicamento quieres modificar?: "); scanf("%s",&compara); printf("\n");
    encontrado=0;
    aux=inicio;
    while (aux->sig!=NULL)
            {
            if (strcmp (compara , aux->datos.Nombre)==0 )
                {
                    //R utilizada para volver a modificar dato
                while (r==1)
                    {
            printf("    Nombre: %s ",aux->datos.Nombre); printf("\n");
            printf("    Laboratorio: %s ",aux->datos.Laboratorio); printf("\n");
            printf("    Receta: %s ",aux->datos.Cobertura); printf("\n");
            printf("    Cantidad: %d ",aux->datos.Cantidad); printf("\n");
            printf("    Precio: %f ",aux->datos.Precio_Venta); printf("\n \n");

            printf("            *MENU Modificar* \n \n");
            printf("       1) Cambiar nombre                                \n");
            printf("       2) Cambiar Laboratorio                           \n");
            printf("       3) Cambiar opcion receta                         \n");
            printf("       4) Cambiar cantidad de medicamentos disponibles  \n");
            printf("       5) Cambiar precio                                \n \n");
            printf("       6) Salir del menu                                \n \n \n ");
            printf("            *Fin Menu Modificar* \n \n  ");
            printf("Que desea hacer: ");
            scanf("%d",&opcion1);
            switch (opcion1)
            {
            case 1:
//              Cambiar nombre
                printf("Introduzca el nombre del medicamento: "); scanf("%s",&aux->datos.Nombre);
                break;
            case 2:
//              Cambiar laboratorio
                printf("Introduzca el nombre del laboratorio: "); scanf("%s" ,&aux->datos.Laboratorio);
                break;
            case 3:
//              Cambiar opcion de receta
                printf("Se puede solicitar receta? (escribe 'si' o 'no'): "); scanf("%s",&aux->datos.Cobertura);
                break;
            case 4:
//              Cambiar cantidad de medicamentos disponibles
                printf("Introduzca la cantidad de medicamentos disponibles: "); scanf ("%d", &aux->datos.Cantidad);
                break;
            case 5:
//              Cambiar precio de venta
                printf("Introduzca el precio de venta: "); scanf ("%f", &aux->datos.Precio_Venta);
                break;
            case 6:
//              Sallir del menu
                printf("\n"); printf("  **Saliendo del menu.**");printf("\n");
                break;
            default:
                printf("\n");printf("   Opcion no valida.");printf("\n");
                break;
                }
            printf("\n");
            printf("    Nombre: %s ",aux->datos.Nombre); printf("\n");
            printf("    Laboratorio: %s ",aux->datos.Laboratorio); printf("\n");
            printf("    Receta: %s ",aux->datos.Cobertura); printf("\n");
            printf("    Cantidad: %d ",aux->datos.Cantidad); printf("\n");
            printf("    Precio: %f ",aux->datos.Precio_Venta); printf("\n \n");

            printf("Quieres modificar algun dato mas de este medicamento?(si=1, no=0) :  ");
            scanf("%d",&r);
                //Sale del while
                }
            //Si encuentra el medicamento lo anotamos en la variable encontrado
            encontrado=1;
                }
             aux = aux->sig;
            }
        // Si no encuentra el medicamento
        if (encontrado==0)
        {
            printf("\n"); printf("*No existe ese medicamento*" ); printf("\n");
        }
    printf("\n \n");
    system("PAUSE");
    return 1;
    }


//*GUARDAR*/
int guardar(void)
    {
        // Guardamos nuestros datos en un fichero .dat escrito en binario "wb"
    printf("\n"); 
	printf("Se sobreescribira el fichero DatosFarmacia.dat desea continuar? (si=1 no=0): "); 
	printf("\n");
    scanf("%d",&continuar); 
	printf("\n");
    if (continuar==1)
    {
    fp = fopen("DatosFarmacia.dat","wb");
    aux=inicio;
    while (aux->sig!=NULL)
        {
        fwrite(&aux->datos, sizeof(struct Bloque),1,fp);
        aux=aux->sig;
        }
    fclose(fp);
    printf("\n"); 
	printf("      ****Guardado Correctamente****"); 
	printf("\n");
    printf("\n");
    system("PAUSE");
    }
    return 0;
    }

//*RECUPERAR*/

int recuperar(void)
    {
        // Recuperamos nuestros datos de un fichero .dat escrito en binario "rb"
    fp = fopen("DatosFarmacia.dat", "rb");
    if (fp!=NULL)
    {
    while(feof(fp)==0)
        {
        fread(&aux->datos,sizeof(struct Bloque),1,fp);
        aux->sig = (Nodo*)malloc( sizeof(struct Nodo));
        atras = aux;
        aux=aux->sig;
        }
    fclose(fp);
    free(aux);
    aux=atras;
    aux->sig=NULL;
    printf("\n"); printf("Archivo Recuperado"); printf("\n");
    }
    else{
     printf("\n"); printf("No existe ningun archivo "); printf("\n");
    }

    printf("\n");
    system("PAUSE");
    return 0;
    }

//MENU
int main()

    {
        //definimos la cabecera con el puntero inicio
        inicio=(Nodo*)malloc(sizeof(struct Nodo));
        aux=inicio;
        aux->sig = NULL;

        printf("\n");
        printf("########    ###    ########  ##     ##    ###     ######  ####    ###"); printf("\n");
        printf("##         ## ##   ##     ## ###   ###   ## ##   ##    ##  ##    ## ##"); printf("\n");
        printf("##        ##   ##  ##     ## #### ####  ##   ##  ##        ##   ##   ##"); printf("\n");
        printf("######   ##     ## ########  ## ### ## ##     ## ##        ##  ##     ##"); printf("\n");
        printf("##       ######### ##   ##   ##     ## ######### ##        ##  #########"); printf("\n");
        printf("##       ##     ## ##    ##  ##     ## ##     ## ##    ##  ##  ##     ##"); printf("\n");
        printf("##       ##     ## ##     ## ##     ## ##     ##  ######  #### ##     ##"); printf("\n \n \n");
// Este es nuestro menú principal que se incia al empezar el programa y desde el cual podremos acceder a la funcion que deseemos
        system("PAUSE");

    while (opcion!=8)
        {
        //  cls para limpiar la pantalla
        system("cls");
        //Mostramos menu
        printf("\n");
        printf("                **MENU** \n  \n ");
        printf("     |  1) Crear Medicamento       |  \n ");
        printf("     |  2) Eliminar Medicamento    |  \n ");
        printf("     |  3) Consultar Medicamento   |  \n ");
        printf("     |  4) Modificar Medicamento   |  \n ");
        printf("     |  5) Mostrar Todos           |  \n ");
        printf("     |  6) Guardar                 |  \n ");
        printf("     |  7) Recuperar programa      |  \n ");
        printf("     |  8) Salir del Programa      |  \n \n ");
        printf("             **Fin Menu** \n \n");
        printf("Que desea hacer: ");
        scanf("%d",&opcion);
        switch (opcion)
            {
            case 1:
//              Crear Medicamento
                crear();
                break;
            case 2:
//              Eliminar Medicamento
                eliminar();
                break;
            case 3:
//              Consultar Medicamento
                consultar();
                break;

            case 4:
//              Modificar Datos
                modificar();
                break;
            case 5:
//              Mostrart todos
                mostrar_todos();
                break;
            case 6:
//              Guardar datos
                guardar();
                break;
            case 7:
//              Recuperar Datos
                recuperar();
                break;

            case 8:
//              FIN DEL PROGRAMA
                printf("\n"); printf("      **FIN DEL PROGRAMA.**"); printf("\n \n");
                break;
            default:
                printf("\n");printf("       Opcion no valida.");printf("\n");
                system("PAUSE");
                break;
            };
        };
    };


