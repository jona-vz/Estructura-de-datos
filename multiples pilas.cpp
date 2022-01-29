#include <stdio.h>

typedef struct nodo{
	int dato;
	struct nodo *sig;
	
}Nodo;

typedef struct pila{
	Nodo* tope;
	int cont;
}Pila;
Nodo* CrearNodo(int dato){
	//asignar espacio
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
void insertar(Pila* pila,int dato){//doble * porque se va a modificar el tope del main con ->siguiente
	//asignar espacio
	Nodo *nuevo;
	nuevo=CrearNodo(dato);
	
	
	//asignar siguiente a tope
	nuevo->sig=pila->tope;
	
	//tope apunta a nuevo
	pila=nuevo;
	pila->cont++;
	
}

void DestruirNodo(Nodo* nodo){
	nodo->sig=NULL;
	free(nodo);
}
Pila* CrearPila(){
	Pila *pila=(Pila*)malloc(sizeof(Pila));
	pila->tope=NULL;
	pila->cont=0;
	return pila;
}

void DestruirPila(Pila *pila){
	while(pila->tope!=NULL){
		eliminar(pila);
	}
	free(pila);
}
void eliminar(Pila* pila){
	//crear variable temporal donde se va a guardar el ultimo elemento a eliminar
	
	int num;
	if(pila->tope!=NULL){
		Nodo *temp;
		//asignar el tope a la temporal
		temp=pila->tope;
		//mover el tope al penultimo elemento
		pila->tope=pila->tope->sig;
		//liberar la memoria
		DestruirNodo(temp);
		pila->cont--;
	}else{
		printf("la pila esta vacia");
	}
	
}
int Cima(Pila *pila){
	if(pila->tope==NULL){
		return NULL;
	}else{
		return pila->tope->dato;
	}
}
int Longitud(Pila*pila){
	return pila->cont;
}
int Vacia(Pila *pila){
	return pila->cont==0;//significa qu esta vacia
}
int main(){
	Pila *pila1,*pila2;

	pila1=CrearPila();
	pila2=CrearPila();
}
