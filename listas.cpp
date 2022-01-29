#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{
	int dato;
	struct Nodo *sig;
	
}Nodo;

typedef struct Lista{
	Nodo* first;
	Nodo* last;
	int cont;
}Lista;

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
void Insertar(Lista *lista,int dato){
	Nodo *nuevo;
	
	nuevo=CrearNodo(dato);
	
	nuevo->sig=lista->first;
	lista->first=nuevo;
	
	lista->cont++;
}

Lista* CrearLista(){
	Lista *lista=(Lista*)malloc(sizeof(Lista));
	lista->first=NULL;
	lista->last=NULL;
	lista->cont=0;
	
	return lista;
}
void Imprimir(Lista *lista){
	Nodo *temp;
	
	temp=lista->first;
	while(temp!=NULL){
		printf("%i\t",temp->dato);
		temp=temp->sig;
	}
	
}
void Eliminar(Lista *lista){
	if(lista->last!=NULL){
		
	}
}
int Menu(){
	int opc,dato;
	
	printf("Que desea hacer?\n");
	printf("1.-Insertar dato a la lista\n");
	printf("2.-Imprimir lista\n");
	scanf("%d",&opc);
	return opc;
}
int main(){
	int opc,dato;
	Lista *lista;
	
	lista=CrearLista();
	
	do{
		opc=Menu();
		switch(opc){
			case 1:
				printf("Dame dato para insertar:\t");
				scanf("%d",&dato);
				
				Insertar(lista,dato);
			break;	
			case 2:
				Imprimir(lista);
			break;
		}
	}while (opc!=2);
}

