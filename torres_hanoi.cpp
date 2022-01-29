/*
JUEGO DE LAS TORRES DE HANOI:
OBJETIVO: MOVER LAS PIEZAS DE UN PALITO A OTRO ORDENADAS.
LA MAS GRANDE ABAJO Y LAS MAS PEQUEÑA ARRIBA
REGLAS:
	-SOLO SE MUEVE UN ELEMENTO A LA VEZ
	-SIEMPRE SE TIENE QUE CUMPLIR QUE EL DE ABAJO SEA
	MAS GRANDE QUE EL DE ARRIBA
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *sig;
}Nodo;

typedef struct pila{
	Nodo* tope;
	int longitud;
}Pila;

Nodo* CrearNodo(int dato){
	Nodo *nuevo;
	nuevo=(Nodo*)malloc(sizeof(Nodo));
	
	if(nuevo==NULL){
		puts("No hay suficiente memoria para reservar el nodo");
		return NULL;
	}else{
		nuevo->dato=dato;
		nuevo->sig=NULL;
		return nuevo;
	}
}

void insertar(Pila* pila,int dato){
	Nodo *nuevo;
	nuevo=CrearNodo(dato);
	nuevo->sig=pila->tope;
	pila->tope=nuevo;
	pila->longitud++;
}

void DestruirNodo(Nodo* nodo){
	nodo->sig=NULL;
	free(nodo);
}

Pila* CrearPila(){
	Pila *pila = (Pila*)malloc(sizeof(Pila));
	pila->tope = NULL;
	pila->longitud = 0;
	return pila;
}

void eliminar(Pila* pila){
	if(pila->tope!=NULL){
		Nodo *temp;
		temp=pila->tope;
		pila->tope=pila->tope->sig;
		DestruirNodo(temp);
		pila->longitud--;
	}else{
		printf("la pila esta vacia");
	}
}

void DestruirPila(Pila* pila){
	while(pila->tope != NULL){
		eliminar(pila);
	}
	free(pila);
}

int Cima (Pila * pila){
	if (pila->tope == NULL){
		return NULL;
	}else{
		return pila->tope->dato;
	}
}

void ImprimirPila(Pila *pila){
	int i;
	Nodo *temp;
	
	//imprime guiones
	for (i=0;i<(4-pila->longitud);i++)
		printf("-");
		
	//imprimir los datos en la pila	
	temp = pila->tope;
	while (temp != NULL){
		printf ("%i", temp->dato);
		temp= temp->sig;
	}
	
	//imprimir el signo '|' para terminar
	printf("|\n");
}

void ImprimirEdo (Pila* arriba, Pila* centro, Pila* abajo){
	system("cls");
	ImprimirPila(arriba);
	ImprimirPila(centro);
	ImprimirPila(abajo);	
}

int vacia(Pila* pila){
	if(pila->longitud == 0){
		return 1;
	}else{
		return 0;
	}
}

void Movimiento(Pila* origen, Pila* destino){
	if (vacia(destino) || destino->tope->dato > origen->tope->dato){
		//insertar en la pila destino
		insertar(destino, origen->tope->dato);
		//eliminar de la pila de origen
		eliminar(origen);
	}else{
		puts("MOVIMIENTO INVALIDO");
		system("pause");
	}
		
}

int Ganar (Pila* centro, Pila* abajo){
	if (centro->longitud == 3){
		return 1;
	}
	if (abajo->longitud == 3){
		return 1;
	}
	return 0;
}

int main(){
	int origen, destino;
	//creamos nuestras 3 pilas
	Pila *arriba, *centro, *abajo;
	arriba = CrearPila();
	centro = CrearPila();
	abajo = CrearPila();	
	
	//añadimos los elementos INICIALES.
	insertar(arriba, 3);
	insertar(arriba, 2);
	insertar(arriba, 1);
	
	//****JUEGO DEL USUARIO***********
	
	do{
		//imprima el estado actual de las 3 pilas.
		ImprimirEdo(arriba, centro, abajo);
		
		printf("Dame la pila de origen: (1.ARRIBA, 2.CENTRO, 3.ABAJO, -1.SALIR)");
		scanf("%d", &origen);
		printf("Dame la pila de destino: (1.ARRIBA, 2.CENTRO, 3.ABAJO)");
		scanf("%d", &destino);
		if(origen != destino){
			switch(origen){
				case 1://origen-ARRIBA
					if(vacia(arriba)){
						puts("La de origen esta vacía");
					}else{
						if(destino == 2){
							Movimiento(arriba, centro);
						}else{
							Movimiento(arriba, abajo);
						}
					}	
				break;
				case 2://origen-CENTRO
					if(vacia(centro)){
						puts("La de origen esta vacía");
					}else{
						if(destino == 1){
							Movimiento(centro, arriba);
						}else{
							Movimiento(centro, abajo);
						}
					}
				break;
				case 3://origen-ABAJO
					if(vacia(abajo)){
						puts("La de origen esta vacía");
					}else{
						if(destino == 1){
							Movimiento(abajo, arriba);
						}else{
							Movimiento(abajo, centro);
						}
					}
				break;
				case -1:
					puts("TE RINDES... MALDITO PERDEDOR...?");
				break;
				default:
					puts("OPCION NO VALIDA");
			}
		}else{
			puts("EL ORIGEN NO PUEDE SER IGUAL AL DESTINO");
		}
		//checar si ya ganó
		if(Ganar(centro, abajo)){
			printf("\n\nFELICIDADES! YA GANASTE!\n\n");
			origen = -1;
		}
		
	}while(origen != -1);
	
	ImprimirEdo(arriba, centro, abajo);
	system("pause");
	//*********************************
	//cerrar juego
	DestruirPila(arriba);
	DestruirPila(centro);
	DestruirPila(abajo);
	return(0);
}
