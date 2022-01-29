/* quiero insertar a una lista 5 numeros enteros
despues quiero eliminar uno de esos numeros
por ultimo quiero imprimir los restantes */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int dato;
	struct nodo *sig;
}Nodo;

typedef struct lista{
	Nodo *first;
	Nodo *last;
	int longitud;
}Lista;

Lista* CrearLista(){
	Lista * lista
	lista = (Lista*)malloc(sizeof(Lista));
	lista->first = NULL;
	lista->last = NULL;
	return lista;
}

void DestruirLista(Lista* lista){
	//vaciar la lista
	while(lista->first){
		//eliminar nodo	
	}
	free(lista);
}

int Menu (){
	int opc;
	printf("Programa que administra una lista.\n");
	printf("Elige una opcion: \n");
	printf("1.- Insertar un elemento a la lista.\n");
	printf("2.- Eliminar un elemento de la lista.\n");
	printf("3.- Imprimir la lista completa.\n\t>>>");
	scanf("%i", &opc);
	return opc;
}

Nodo* CrearNodo(int dato){
	Nodo* nodo;
	nodo = (Nodo*) malloc(sizeof(Nodo));
	nodo->dato = dato;
	nodo->sig = NULL;
	return nodo;
}

void Insertar(Lista* lista, int dato, int pos){
	Nodo *nuevo, *aux;
	int i;
	nuevo = CrearNodo (dato);
	
	if (lista->longitud){
		if (pos > 0 && pos <= (lista->longitud + 1)){//validando pos
			if(pos == 1){
				//insertar al inicio
				nuevo->sig = lista->first; //ligar el elemento nuevo
				lista->first = nuevo; //actualizar el first
			}else if(pos == lista->longitud+1){
				//insertar al final
				lista->last->sig = nuevo; //ligar el elemento nuevo
				lista->last = nuevo; //actualizar last
			}else{
				//insertar en la posicion
				aux = lista->first;
				for (i=1; i<pos-1; i++){//recorrer con un for hasta pos -1 
					aux = aux->sig;
				}
			
				nuevo->sig = aux->sig;//ligar el elemento
				aux->sig = nuevo;//actualizar anterior
			}			
		}else{
			//no esta correcto pos
			puts("POSICION INCORRECTA");
			if(pos<=0){
				printf("¿Quieres insertar al inicio?\t1.-SI  2.-NO\n");
				scanf("%d", &opc_pos);
				if(opc_pos==1){
					//insertar al inicio
					nuevo->sig = lista->first; //ligar el elemento nuevo
					lista->first = nuevo; //actualizar el first
				}				
			}else{
				printf("¿Quieres insertar al final?\t1.-SI  2.-NO\n");
				scanf("%d", &opc_pos);
				if(opc_pos==1){
					//insertar al final
					lista->last->sig = nuevo; //ligar el elemento nuevo
					lista->last = nuevo; //actualizar last
				}	
			}
			
		}
	}else{//insertar cuando esta vacia la lista
		lista->first = nuevo;
		lista->last = nuevo;
	}		
}

int main (){
	Lista *a;
	int opc;
	a = CrearLista();
	//*************************************
	opc = Menu();
	//*************************************
	
	//pedir dato
	Insertar(a, dato, pos);
	
	
	//*************************************
	DestruirLista(a);
	/*
	*1. crear la lista
		*1.1 tener la estructura de lista 
		*1.2 crear lista
			+1.2.1 Reservar la memoria para la lista
			*1.2.2 Hacer NULL el primero
			*1.2.3 Hacer null el ultimo
	
	*3.- menu
		*3.1 dar las opciones
		*3.2 obtener la opcion que quiere el usuario
	
	*4.- insertar
		*4.1 Crear nodo a insertar
			*4.1.1 reservar la memoria para el nodo
			*4.1.2 ponerle el dato a dato
			*4.1.3 ponerle null al siguiente
		*4.2 insertar con lista vacia
			*4.2.1 al insertar el nuevo elemento va a ser first y last
		*4.3 insertar en una lista con elementos
			*4.3.1 insertar al inicio
				*i.- igualar first a nuevo
				*ii.- nuevo en la parte sig tiene que enlazar al que era primer elemento
			*4.3.2 insertar al final
				*i.- el siguiente de last va a ser nuevo
				*ii.- last se iguala a nuevo
			*4.3.3 insertar en medio
				*i.- buscamos el lugar donde va a ir el nuevo nodo
				*ii.- nuevo en sig va a ser el de adelante del lugar
				*iii.- el anterior en la pos sig va a ser el nuevo
	
	5.- eliminar nodo
		5.1 Buscar el que quiero eliminar
			5.1.1 recorrer mi lista hasta llegar al elemento
		5.2 Eliminarlo
			5.2.1 Elimine el que esta en first
				i.- Nodo a eliminar le ponemos el first
				ii.- first va a ser igual a first siguiente
				ii.- destruir nodo (liberar la memoria)
			5.2.2 Elimine el que esta en last
				i.- Nodo a eliminar le ponemos el last
				ii.- anterior va a ser el last
				iii.- destruir nodo
			5.2.3 Elimine cualquiera en medio
				i.- Escogemos el nodo a eliminar
				ii.- el sig del anterior va a ser el sig del nodo a eliminar
				iii.- destruir nodo
	6.- imprimir
		6.1 Recorrer la lista
			6.1.1 desde el primero y avanzamos hasta encontrar el ultimo
				(buscando el null)
		
	2. destruir la lista
		*2.1 vaciar toda la lista
			2.1.1 destruir todos los nodos (liberar la memoria)
		*2.2 destruir la lista (liberar la memoria)
	*/	 
	return 0;
}
