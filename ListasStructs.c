#include <stdio.h>
#include <stdlib.h>

//EJEMPLO DE LISTAS Y ESTRUCTURAS
//*******************************
struct nodo
{
    int dato;
    struct nodo *sig;
};



int main()
{
    // creacion de apuntadores lista,aux y el total
    struct nodo *lista=NULL,*aux,*total;
    /*Definir una lista vacia*/
    lista=malloc(sizeof(struct nodo)); // reservacion de espacio para la lista con tamaño de la estructura

    /**<Llenado de datos de la estructura*/
    lista->dato=18;
    lista->sig=NULL;

    /**<añadir nueva lista por la cabeza*/
    aux=lista;//dos apuntadores apuntan al mismo espacio
    lista=malloc(sizeof(struct nodo));// se crea un nuevo espacio para llenar datos, aux queda apuntando a la lista anterior
    lista->dato=30;
    lista->sig=aux; //el final de la nueva lista queda apuntando a la anterior se une con la lista anterio, por eso se axenza por la cabeza
    /**sig y aux apunta a la lista inicial*/

    /**<anadir nueva lista por la cola */
    aux=malloc(sizeof(struct nodo)); //creacion de espacio para la nueva lista
    aux->dato=20;//nuevo dato
    aux->sig=NULL;//la cola no quda apuntando a nada (final de la lista)
    lista->sig->sig=aux;//el final de la lista se pone a apontar en la nueva estructura







    /**visualizar datos de la lista**/
    printf("visualizacion de  datos de la lista\n");
    printf("**************************************\n\n");
    total=lista;//total queda apuntando a la lista
    int i=1; //variable para iterar y pasar por todas las structturas nodos
    while(i<=3) // como son tres nodos se itera 3 veces
    {
        printf("dato %d -- %d\n",i,total->dato); // se muestra el dato de la cabeza a la cola
        total=total->sig; //se pasa al sigueinte nodo
        i++;
    }

    printf("**************************************\n\n");
//    system("PAUSE");
    return 0;
}
