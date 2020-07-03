/***************************************************************

PROGRAMA MISIONEROS - CANIBALES


***************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct  Nodo		/* DEFINICION DE CADA ESTADO */
{
char ILadoa[6];		/*POSICIONES A UN LADO DEL RIO */
char ILadob[6];		/*POSICIONES AL OTRO LADO DEL RIO*/
int Numero;			// CANTIDAD DE ELEMENTOS EN EL LADO B
struct Nodo *Sig;	/*APUNTADOR AL SIGUIENTE ESTADO*/
struct Nodo *Ant;	/*APUNTADOR AL ESTADO ANTERIOR */
};


int LADOA=0,LADOB=0,Band=0; //BANDERAS PARA EVALUAR LAS CONDICIONES


struct Nodo* Crear(struct Nodo *,struct Nodo *);
void Evaluacion(struct Nodo *);
void Imprime(struct Nodo *);
void Inicializar(struct Nodo *,struct Nodo *);
//***OPERADORES****
void mueve_mis(struct Nodo *);
void mueve_mis(struct Nodo *);
void mueve_com(struct Nodo *,struct Nodo *,int);
void devuelve_com(struct Nodo *,struct Nodo *,int);


int main(void)
{

	int i;
	struct Nodo *Inicio,*Copia;

	srand((unsigned)time(NULL)); //inicializaci�n del rand


	printf("\t\t******************************");
	printf("\n\t\t MISIONEROS(M)-CANIBALES(C)\n");
	printf("\t\t******************************\n\n\n\n\n\n");
	printf("\t\tPRESIONE ENTER PARA CONTINUAR");
	getch();

	//CREACION DEL NODO CABEZA
	Inicio=(struct Nodo*)malloc(sizeof(struct Nodo*));

	//inicializaci�n nodo
	for(i=0;i<3;i++)
	{
		Inicio->ILadoa[i]='C';		//3 CANIBALES
		Inicio->ILadoa[i+3]='M';	//3 MISIONEROS A UN LADO DEL RIO
		Inicio->ILadob[i]=' ';		// 6 VACIOS AL OTRO LADO DEL RIO
		Inicio->ILadob[i+3]=' ';
	}


	Inicio->Numero=0;		//INICIALMENTE 0 ELEMENTOS EN EL LADO B

	Inicio->Ant=NULL;
	Inicio->Sig=NULL;

	Imprime(Inicio);

	Copia=Crear(Inicio->Sig,Inicio);

	printf("\n\t\t/////////");
	printf("\n\t\t///FIN///");
	printf("\n\t\t/////////\n\n");
	getch();
return 0;
}


struct Nodo* Crear(struct Nodo *Actual,struct Nodo *Anterior)
{

	int Num;


	if(Actual==NULL)
	{
		//CREA RECURSIVAMENTE LOS NODOS APARTIR DEL NODO CABEZA

		Actual =(struct Nodo*)malloc(sizeof(struct Nodo*));
		Actual-> Ant=Anterior;
		Actual-> Sig=NULL;


		Inicializar(Actual,Anterior); // VA A TERMINAR DE LLENAR EL NODO


		Num=rand()%5;	//SE ASIGNA UN NUMERO ALEATORIO A Num

		printf("aleatorio=%d",Num);

		//*****LLAMADO A OPERADORES*******

		if(Band==0)		//INDICA QUE EL MISIONERO 3 ESTA EN EL LADO A
		{

			mueve_mis(Actual);	//MUEVE EL MISIONERO 3 AL LADO B
			while (Anterior->ILadoa[Num]==' ')	//SELECCIONA CON QUIEN SE VA EL MISIONERO 3
				Num=rand()%5;

			mueve_com(Actual,Anterior,Num);		//VA A MOVER LA COMPA�IA QUE FUE SELECCIONADA
		}
		else		//SI EL MISIONERO 3 YA ESTA EN EL LADO B
		{

			if(LADOB==1||LADOA==1)		// SE REGRESA AL ESTADO ANTERIOR PORQUE EL
			{							// ACTUAL NO ES UN ESTADO VALIDO

				while (Anterior->ILadob[Num]==' ')	//SELECCIONA A QUIEN DEVOLVER
						Num=rand()%5;

				devuelve_com(Actual,Anterior,Num);

			}
			else
			{
				Actual->ILadob[5]=' ';		//COMO SE CUMPLIO LA FUNCION DE EVALUACION
				Actual->ILadoa[5]='M';		//RETORNA EL MISIONERO AL LADO A
			}


		}

		LADOA=0;
		LADOB=0;


	Evaluacion(Actual);

	Imprime(Actual);

		if(Actual->Numero==5)	// YA ESTAR�AN TODOS AL OTRO LADO Y SE TERMINAR�A
				return(Actual);

		return(Crear(Actual->Sig,Actual));



	}
}


void Inicializar(struct Nodo *Actual,struct Nodo *Anterior)
{
	int i;

	if(Anterior->ILadoa[5]=='M')
		Band=0;
	else
		Band=1;

	for(i=0;i<5;i++)
	{
		Actual->ILadoa[i]=Anterior->ILadoa[i];
		Actual->ILadob[i]=Anterior->ILadob[i];
	}

	Actual->Numero=0;
}

void mueve_mis(struct Nodo *Actual)
{
	Actual->ILadob[5]='M';		//PASA EL MISIONERO "3" AL LADO B
	Actual->ILadoa[5]=' ';

}

void mueve_com(struct Nodo *Actual,struct Nodo *Anterior,int Num)	//MUEVE OTRO ELEMENTO AL LADO B
{
	Actual->ILadob[Num]=Anterior->ILadoa[Num];
	Actual->ILadoa[Num]=' ';

}

void devuelve_com(struct Nodo *Actual,struct Nodo *Anterior,int Num)
{
	Actual->ILadoa[Num]=Anterior->ILadob[Num];
	Actual->ILadob[Num]=' ';
	Actual->ILadob[5]=' ';
	Actual->ILadoa[5]='M';

}


void Evaluacion(struct Nodo *Actual)	//FUNCION DE EVALUACION
{
	int i,caniA=0,misiA=0,caniB=0,misiB=0;
	int malo1=0,malo2=0;

	for(i=0;i<5;i++)
	{
		if(Actual->ILadoa[i]=='C')		//CUENTA CANTIDAD DE CANIBALES EN EL LADO A
			caniA++;
		if(Actual->ILadoa[i]=='M')		//CUENTA CANTIDAD DE MISIONEROS EN EL LADO A
			misiA++;
		if(Actual->ILadob[i]=='C')		//CUENTA CANTIDAD DE CANIBALES EN EL LADO B
			caniB++;
		if(Actual->ILadob[i]=='M')		//CUENTA CANTIDAD DE MISIONEROS EN EL LADO B
			misiB++;
	}


	if((caniA>misiA)&&misiA!=0)			//EVALUA CONDICION NO VALIDA
		malo1=1;
	if((caniB>misiB)&&misiB!=0)
		malo2=1;

	for(i=0;i<5;i++)			//evalua cantidad de objetos que hay en la orilla B
	{
		if(Actual->ILadob[i]!=' ')
			Actual->Numero++;

	}


	if(malo1==1)
		LADOA=1;
	if(malo2==1)
		LADOB=1;





}


void Imprime(struct Nodo *sCopy)
{

	int i=0;
	printf("\n\t\t/////////////");
	printf("\n\t\t//OPERACION//");
	printf("\n\t\t/////////////\n\n");

		printf("\t\t");

		for(i=0;i<6;i++)
		printf("/%c",sCopy->ILadoa[i]);
		printf("\n\t\t************");
		printf("\n\t\t----RIO-----");
		printf("\n\t\t************\n");

		printf("\t\t");
		for(i=0;i<6;i++)
			printf("/%c",sCopy->ILadob[i]);
		printf("\n\n");


		printf("\n**PRESIONE ENTER PARA CONTINUAR**\n");
		getch();


}
