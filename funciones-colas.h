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
int Vacia(Cola* cola){
	if(cola->first){
		return 0;
	}else{
		puts("la cola esta vacia");
		return 1;
	}
}
void Insertar(Cola* cola,int dato){
	Nodo *nuevo;
	nuevo=CrearNodo(dato);
	if(!cola->first){//si esta vacio
		cola->first=nuevo;
		cola->last=nuevo;
	}else{
		cola->last->sig=nuevo;
		cola->last=nuevo;
	}
	cola->longitud++;
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
	if(!Vacia(cola)){//si esta vacio
		Nodo* eliminado=cola->first;
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
		Eliminar(cola);
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
		temp=cola->first;
		while(temp!=NULL){
			printf("%i\t",temp->dato);
			temp=temp->sig;
		}
		printf("\n");
		
	}		
	
}
void ImprimirPrimero(Cola *cola){

	if(!Vacia(cola))
		printf("El primer elemento es: %i\n",cola->first->dato);

}
void ImprimirUltimo(Cola *cola){
	if(!Vacia(cola))
		printf("El ultimo elemento es:%i\n",cola->last->dato);
	
}
void CambiarPrioridad(Cola* cola, int NumElem, int destino){
	Nodo *temp, *temp2, *aux;
	temp = cola->first;
	int i;
	
	//Enconatrar y separar el elemento
	if(NumElem == 1){//moviendo el primer elemento
		cola->first = temp->sig;
		printf("Dato temp: %i\n", temp->dato);
				
	}else{//moviendo cualquier elemento
		for (i=1; i<NumElem; i++){
			printf("Dato %i: %i\n", i, temp->dato);
			aux = temp;
			temp = temp->sig;
			fflush(stdin);getchar();
		}
		if(NumElem == cola->longitud){//en caso de mover el ultimo
			cola->last = aux;
			aux->sig = NULL;
		}else{
			aux->sig = temp->sig;
		}
		
		printf("Dato temp: %i\n", temp->dato);
		printf("Dato aux: %i\n", aux->dato);
		printf("Dato adelante de aux: %i\n", aux->sig->dato);
	}
	
	//Encontarr en donde va el dato
	temp2 = cola->first;
		
	if(destino == 1){
		temp->sig = cola->first;
		cola->first = temp;
	}else{
		
		if(destino == cola->longitud){
			temp2 = cola->last;	
			temp2->sig = temp;
			cola->last = temp;
			temp->sig = NULL;
		}else{
			for (i=1; i<destino; i++){
				printf("Dato %i: %i\n", i, temp2->dato);
				aux = temp2;
				temp2 = temp2->sig;
				fflush(stdin);getchar();
			}
			temp->sig = temp2;
			aux->sig = temp;
		}
	}	
	
	printf("Dato temp: %i\n", temp->dato);
	printf("Dato temp2: %i\n", temp2->dato);
	printf("Dato aux: %i\n", aux->dato);
	
}
int Menu(){
	int opc;
	
	
	printf("Que desea hacer?\n");
	printf("1.-Agregar elementos.\n");//insertar
	printf("2.-Eliminar elementos.\n");//Eliminar
	printf("3.-Cambiar la prioridad de los elementos\n");
	printf("4.-Eliminar cola completa\n");//destruir cola
	printf("5.-Imprimir cola\n");//imprimir cola
	printf("6.-Imprimir el primer elemento de la cola\n");
	printf("7.-Imprimir el ultimo elemento de la cola\n");
	printf("8.-Salir\t");
	scanf("%i",&opc);
	return opc;
	
}

#endif /*funciones-cola_h*/
