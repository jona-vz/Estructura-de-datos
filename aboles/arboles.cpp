#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo *izquierda;
	struct Nodo *derecha;
}Nodo;

Nodo *CrearNodo(int dato){
	Nodo *nuevo;
	
	nuevo=(Nodo*)malloc(sizeof(Nodo));
	
	nuevo->dato=dato;
	nuevo->izquierda=NULL;
	nuevo->derecha=NULL;
	
	return nuevo;
}

void Insertar(Nodo *nodo,int dato){
	
	if(dato>nodo->dato){//si el dato es mayor al dato en el nodo
		//se va a la derecha
		if(nodo->derecha==NULL){
			nodo->derecha=CrearNodo(dato);
		}else{
			Insertar(nodo->derecha,dato);
		}
	}else{
		if(nodo->izquierda==NULL){
			nodo->izquierda=CrearNodo(dato);
		}else{
			Insertar(nodo->izquierda,dato);
		}
	}
}
void Preorden(Nodo *nodo){
	//Nodo *nodo;
	
	if(nodo!=NULL){
		printf("%i  ",nodo->dato);
		Preorden(nodo->izquierda);
		Preorden(nodo->derecha);
	}
	
}
void Entreorden(Nodo *nodo){
	
	
	if(nodo!=NULL){
		Entreorden(nodo->izquierda);
		printf("%i  ",nodo->dato);
		Entreorden(nodo->derecha);
		
	}
}
void Postorden(Nodo *nodo){

	
	if(nodo!=NULL){
		Postorden(nodo->izquierda);
		Postorden(nodo->derecha);
		printf("%i  ",nodo->dato);
	}
}
void Eliminar (Nodo *nodo){
	
	
	if(nodo!=NULL){
		Eliminar(nodo->izquierda);
		Eliminar(nodo->derecha);
		printf("\nEliminando=%i",nodo->dato);
		nodo->izquierda=NULL;
		nodo->derecha=NULL;
		free(nodo);
	}
	
}
int main(){
	Nodo *raiz=CrearNodo(28);
	
	Insertar(raiz,11);
	Insertar(raiz,96);
	Insertar(raiz,21);
	Insertar(raiz,6);
	Insertar(raiz,97);
	Insertar(raiz,1);
	Insertar(raiz,30);
	Insertar(raiz,10);
	Insertar(raiz,2);
	
	printf("\nPreorden\t\t");
	Preorden(raiz);
	printf("\nEntreorden\t\t");
	Entreorden(raiz);
	printf("\nPostorden\t\t");
	Postorden(raiz);
	
	printf("\n");
	Eliminar(raiz);
}


