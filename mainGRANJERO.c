/***************************************************************

PROGRAMA GRANJERO-ZORRO-CABRA-PASTO 


***************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct  Nodo		/* DEFINICION DE CADA ESTADO */
{
char ILadoa[4];		/*POSICIONES A UN LADO DEL RIO */
char ILadob[4];		/*POSICIONES AL OTRO LADO DEL RIO*/
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
	
	srand((unsigned)time(NULL)); //inicialización del rand


	printf("\t\t******************************");
	printf("\n\t\t GRANJERO-ZORRO-CABRA-PASTO\n");
	printf("\t\t******************************\n\n\n\n\n\n");
	printf("\t\tPRESIONE ENTER PARA CONTINUAR");
	getch();
	
	//CREACION DEL NODO CABEZA
	Inicio=(struct Nodo*)malloc(sizeof(struct Nodo*));

	//inicialización nodo
	
	Inicio->ILadoa[0]='P';	// PASTO	
	Inicio->ILadoa[1]='C';	// CABRA	
	Inicio->ILadoa[2]='Z';		// ZORRO
	Inicio->ILadoa[3]='G';		// GRANJERO
	
	for(i=0;i<4;i++)
	{
		Inicio->ILadob[i]=' ';		// 6 VACIOS AL OTRO LADO DEL RIO
		
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
		

		Num=rand()%3;	//SE ASIGNA UN NUMERO ALEATORIO A Num
		
		printf("aleatorio=%d",Num);

		//*****LLAMADO A OPERADORES*******

		if(Band==0)		//INDICA QUE EL GRANJERO ESTA EN EL LADO A
		{
			
			mueve_mis(Actual);	//MUEVE EL GRANJERO AL LADO B		
			while (Anterior->ILadoa[Num]==' ')	//SELECCIONA CON QUIEN SE VA EL GRANJERO
				Num=rand()%3;
		
			mueve_com(Actual,Anterior,Num);		//VA A MOVER LA COMPAÑIA QUE FUE SELECCIONADA
		}
		else		//SI EL GRANJERO YA ESTA EN EL LADO B
		{
			
			if(LADOB==1||LADOA==1)		// SE REGRESA AL ESTADO ANTERIOR PORQUE EL
			{							// ACTUAL NO ES UN ESTADO VALIDO
			
				while (Anterior->ILadob[Num]==' ')	//SELECCIONA A QUIEN DEVOLVER
						Num=rand()%3;
				
				devuelve_com(Actual,Anterior,Num);

			}
			else
			{
				Actual->ILadob[3]=' ';		//COMO SE CUMPLIO LA FUNCION DE EVALUACION
				Actual->ILadoa[3]='G';		//RETORNA EL GRANJERO AL LADO A
			}

		
		}
		
		LADOA=0;
		LADOB=0;
		
			
	Evaluacion(Actual);

	Imprime(Actual); 
		
		if(Actual->Numero==3)	// YA ESTARÍAN TODOS AL OTRO LADO Y SE TERMINARÍA
				return(Actual);

		return(Crear(Actual->Sig,Actual));
					
		

	}
}


void Inicializar(struct Nodo *Actual,struct Nodo *Anterior)
{
	int i;
	
	if(Anterior->ILadoa[3]=='G')
		Band=0;
	else 
		Band=1;

	for(i=0;i<3;i++)
	{
		Actual->ILadoa[i]=Anterior->ILadoa[i];
		Actual->ILadob[i]=Anterior->ILadob[i];
	}

	Actual->Numero=0;
}

void mueve_mis(struct Nodo *Actual)
{
	Actual->ILadob[3]='G';		//PASA EL GRANJERO AL LADO B
	Actual->ILadoa[3]=' ';

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
	Actual->ILadob[3]=' ';
	Actual->ILadoa[3]='G';

}


void Evaluacion(struct Nodo *Actual)	//FUNCION DE EVALUACION
{
	int i,ZORROa=0,CABRAa=0,PASTOa=0,ZORROb=0,CABRAb=0,PASTOb=0;
	int malo1=0,malo2=0;
	
	

	for(i=0;i<3;i++)
	{
		if(Actual->ILadoa[i]=='Z')		//CUENTA CANTIDAD DE ZORROS EN EL LADO A
			ZORROa++;
		if(Actual->ILadoa[i]=='C')		//CUENTA CANTIDAD DE CABRAS EN EL LADO A
			CABRAa++;
		if(Actual->ILadoa[i]=='P')		//CUENTA CANTIDAD DE PASTOS EN EL LADO A
			PASTOa++;
			
		if(Actual->ILadob[i]=='Z')		//CUENTA CANTIDAD DE ZORROS EN EL LADO B
			ZORROb++;
		if(Actual->ILadob[i]=='C')		//CUENTA CANTIDAD DE CABRAS EN EL LADO B
			CABRAb++;
		if(Actual->ILadob[i]=='P')		//CUENTA CANTIDAD DE PASTOS EN EL LADO B
			PASTOb++;
	}
	

	if((ZORROa==1)&&(CABRAa==1))			//EVALUA CONDICION NO VALIDA PARA ZORRO CON CABRA
		malo1=1;
	if((ZORROb==1)&&(CABRAb==1))
		malo2=1;
		
	if((PASTOa==1)&&(CABRAa==1))			//EVALUA CONDICION NO VALIDA PARA PASTO CON CABRA
		malo1=1;
	if((PASTOb==1)&&(CABRAb==1))
		malo2=1;

	for(i=0;i<3;i++)			//evalua cantidad de objetos que hay en la orilla B
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
		
		for(i=0;i<4;i++)
		printf("/%c",sCopy->ILadoa[i]);
		printf("\n\t\t*********");
		printf("\n\t\t---RIO----");
		printf("\n\t\t*********\n");
		
		printf("\t\t");
		for(i=0;i<4;i++)		
			printf("/%c",sCopy->ILadob[i]);
		printf("\n\n");

		
		printf("\n**PRESIONE ENTER PARA CONTINUAR**\n");
		getch();
		

}

