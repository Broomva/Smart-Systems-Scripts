#include <stdio.h>
#include <conio.h>

struct nodo {
   int valor;
   struct nodo *padre;
   struct nodo *izq;
   struct nodo *der;
};

struct nodo *crear_nodo(struct nodo *, int);
void agregar_valor(struct nodo *, int );


int main()
{
	struct nodo *arbol;

	arbol=crear_nodo(NULL,100);
	agregar_valor(arbol,90);
	agregar_valor(arbol,200);
	agregar_valor(arbol,60);
	agregar_valor(arbol,120);
	agregar_valor(arbol,300);
	agregar_valor(arbol,500);
	return 0;
}

struct nodo *crear_nodo(struct nodo *padre, int valor)
{
	struct nodo *n=NULL;
	n=malloc(sizeof(struct nodo));
	n->padre=padre;
	n->valor=valor;
	return n;
}


void agregar_valor(struct nodo *arbol, int valor)
{
	int derecho,izquierdo;
	struct nodo *temp, *pivote;
	if (arbol!=NULL)
	{
		temp=arbol;
		while(temp!=NULL)
		{
			pivote=temp;
			if(valor>temp->valor)
			{
				//Lado derecho
				temp=temp->der;
				derecho=1;
			}
			else
			{
				//Izquierdo
				temp=temp->izq;
				derecho=0;
			}
		}
		temp=crear_nodo(pivote,valor);
		if(derecho)
		{
			printf("insertando %d al lado derecho de %d\n",valor, pivote->valor );
			pivote->der=temp;
		}
		else
		{
				printf("insertando %d al lado izquierdo de %d\n",valor, pivote->valor );
			pivote->izq=temp;
		}


	}
	else
	{
		printf("No inicializado");

	}

}
