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
	Nodo *raiz=CrearNodo(30);
	
	/*Insertar(raiz,86);
	Insertar(raiz,65);
	Insertar(raiz,70);
	Insertar(raiz,67);
	Insertar(raiz,73);
	Insertar(raiz,69);
	Insertar(raiz,25);
	Insertar(raiz,66);
	Insertar(raiz,47);
	Insertar(raiz,68);
	Insertar(raiz,62);
	Insertar(raiz,10);
	Insertar(raiz,60);
	Insertar(raiz,93);
	
	printf("******\nPreorden\t\t");
	Preorden(raiz);
	printf("\nEntreorden\t\t");
	Entreorden(raiz);
	printf("\nPostorden\t\t");
	Postorden(raiz);*/
	
	Insertar(raiz,22);
	Insertar(raiz,43);
	Insertar(raiz,56);
	Insertar(raiz,65);
	Insertar(raiz,87);
	Insertar(raiz,93);
	Insertar(raiz,99);
	Insertar(raiz,120);
	Insertar(raiz,130);
	Insertar(raiz,135);
	Insertar(raiz,140);
	
	printf("\nPreorden\t\t");
	Preorden(raiz);
	printf("\nEntreorden\t\t");
	Entreorden(raiz);
	printf("\nPostorden\t\t");
	Postorden(raiz);
	
	
	/*Insertar(raiz,31);
	Insertar(raiz,12);
	Insertar(raiz,20);
	Insertar(raiz,03);
	Insertar(raiz,24);
	Insertar(raiz,23);
	Insertar(raiz,21);
	Insertar(raiz,02);
	Insertar(raiz,19);
	Insertar(raiz,65);
	Insertar(raiz,67);
	
	printf("\nPreorden\t\t");
	Preorden(raiz);
	printf("\nEntreorden\t\t");
	Entreorden(raiz);
	printf("\nPostorden\t\t");
	Postorden(raiz);*/
	
	printf("\n");
	Eliminar(raiz);
}


