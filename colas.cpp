#ifndef funciones-cola_h
#define cola_h

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* sig;
}Nodo;

typedef struct cola{
	Nodo* first;
	Nodo* last;
	int longitud;
}Cola;

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
void Insertar(Cola* cola,int dato){
	Nodo *nuevo;
	nuevo=CrearNodo(dato);
	if(!Vacia(cola)){//si esta vacio
		cola->first=nuevo;
		cola->last=nuevo;
	}else{
		cola->last->sig=nuevo;
		cola->last=nuevo;
	}
}
void DestruirNodo(Nodo* nodo){
	nodo->sig=NULL;
	free(nodo);
}
Cola* CrearCola(){
	Cola *cola = (Cola*)malloc(sizeof(Cola));
	cola->last = NULL;
	cola->first = NULL;
	cola->longitud=0;
	return cola;
}
void Eliminar(Cola* cola){
	if(!Vacio(cola){//si esta vacio
		Nodo eliminado=cola->first;
		cola->first = cola->first->sig;
		DestruirNodo(eliminado);
		if(!cola->first)//si first esta en NULL
			cola->last=NULL;
	}else{
		puts("La cola esta vacia");
	}
}
void DestruirCola(Cola* cola){
	while(cola->first){
		eliminar(cola);
	}
	free(cola);
}
int DatoAdelante (Cola * cola){
	if(!Vacia(cola)){
		if (cola->first == NULL){
			return NULL;
		}else{
			return cola->first->dato;
		}
	}
	
}
int DatoAtras (Cola * cola){
	if(!Vacia(cola)){
		if (cola->last == NULL){
			return NULL;
		}else{
			return cola->last->dato;
		}
	}
		
}
void ImprimirCola(Cola *cola){
	
	if(!Vacia(cola)){
		Nodo *temp;
		temp=cola->last;
		while(temp!=NULL){
			printf("%i",temp->dato);
			temp=temp->sig;
		}
	}
		
}
int Vacia(Cola* cola){
	if(cola->first){
		return 0;
	}else{
		puts("la cola sta vacia");
		return 1;
	}
}
int Menu(){
	int opc;
	
	printf("Que desea hacer?\n");
	printf("1.-Agregar elementos.\n");//insertar
	printf("2.-Eliminar elementos.\n");//Eliminar
	printf("3.-Cambiar la prioridad de los elementos\n");
	printf("4.-Eliminar cola completa\n");//destruir cola
	printf("5.-Imprimir cola\n");//imprimir cola
	printf("6.-Salir");
	scanf("%i",&opc);
	return opc;
	
}

#endif /*funciones-cola_h*/
