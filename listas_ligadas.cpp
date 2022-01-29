#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo *sig;
}Nodo;

typedef struct lista{
	Nodo *first;
	Nodo *last;
	int longitud;
}Lista;

Nodo *CrearNodo(int dato){
	Nodo *nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->dato=dato;
	nodo->sig=NULL;
	
	return nodo;
}
Lista *CrearLista(){
	Lista *lista;
	
	lista=(Lista*)malloc(sizeof(Lista));
	lista->first=NULL;
	lista->last=NULL;
	lista->longitud=0;
	return lista;
}

int Menu(){
	int opc;
	
	printf("Elegir una opcion\n");
	printf("1.-Insertar dato a la lista\n");
	printf("2.-Eliminar dato de la lista\n");
	printf("3.-Imprimir lista\n");
	printf("4.-Salir\n");
	scanf("%d",&opc);
	
	return opc;
}
void Insertar(Lista*lista,int dato,int pos){
	Nodo*nuevo,*aux;
	nuevo=CrearNodo(dato);
	int i,opc_pos;
	
	
	if(lista->longitud>0){//si ya tiene elementos
		if(pos>0 && pos<=lista->longitud+1){
			if(pos==1){
				//insertar al inicio
				nuevo->sig=lista->first;
				lista->first=nuevo;
			}else if(pos==lista->longitud+1){
				//insertar en el ultimo
				lista->last->sig=nuevo;
				lista->last=nuevo;
			}else{
				//insertar en medio
				aux=lista->first;
				for(i=1;i<pos-1;i++){
					aux=aux->sig;
				}
				nuevo->sig=aux->sig;
				aux->sig=nuevo;
			}
			lista->longitud++;
		}else{
			puts("posicion incorrecta");
			if(pos<=0){
				
				
				printf("quieres insertar al inicio?\t 1.-Si 2.-No \n");
				scanf("%d",&opc_pos);
				if(opc_pos==1){
					nuevo->sig=lista->first;
					lista->first=nuevo;
					lista->longitud++;
				}
			}else{
				
					printf("quieres insertar al final?\t 1.-Si 2.-No \n");
					scanf("%d",&opc_pos);
					if(opc_pos==1){
						lista->last->sig=nuevo;
						lista->last=nuevo;
						lista->longitud++;
					}
				
				
			}
		}
	
	}else{//si esta vacia
		lista->first=nuevo;
		lista->last=nuevo;
		lista->longitud++;
	}
	
}
void DestruirNodo(Nodo*nodo){
	nodo->sig=NULL;
	free(nodo);
}
int Eliminar(Lista *lista,int pos){
	Nodo *nodo,*aux;
	int eliminado,i;
		
	if(lista->longitud){//si tiene elementos
	
		if(pos>0 && pos<=lista->longitud){
			if(pos==1){//eliminar el primero
				nodo=lista->first;
				lista->first=lista->first->sig;
	
				
			}else if(pos==lista->longitud){//eliminar el ultimo
				nodo=lista->last;
				aux=lista->first;
				for(i=1;i<pos-1;i++){
					aux=aux->sig;
				}
				lista->last=aux;
				lista->last->sig=NULL;
	
			}else{//eliminar en medio
				aux=lista->first;
				for(i=1;i<pos-1;i++){
					aux=aux->sig;
				}
				nodo=aux->sig;
				aux->sig=nodo->sig;
				
			}
			lista->longitud--;
			eliminado=nodo->dato;
			DestruirNodo(nodo);
		}else{
			printf("Posicion invalida\n");
			return -1;
		}
	
 	}else{
 		printf("La lista esta vacia\n");
 		return -1;
	 }
	
	
	return eliminado;
	
}
void DestruirLista(Lista *lista){
	int eliminado=0;
	//vaciar la lista
	while(lista->first){
		eliminado=Eliminar(lista,1);
	}
	//liberar memoria de la lista
	free(lista);
	
}
void Imprimir(Lista *lista){
	Nodo *nodo;
	
	nodo=lista->first;
	
	while(nodo!=NULL){
		printf("%d\t",nodo->dato);
		nodo=nodo->sig;		
	}
	printf("\n");

}
int main(){
	//crear lista
		//tener struct de lista
		//tener crear
			//hacer null first
			//hacer null last
	Lista *a;
	int opc,eliminado,dato,pos;
	
	a=CrearLista();
	
	do{
		system("cls");
		opc=Menu();
		Imprimir(a);
		switch(opc){
			case 1:
				printf("Dame el dato:\n");
				scanf("%d",&dato);
				printf("Dame la posicion:\n");
				scanf("%d",&pos);
				Insertar(a,dato,pos);
			break;
			case 2:
				printf("Dame la posicion:\t\n");
				scanf("%d",&pos);
				eliminado=Eliminar(a,pos);
				if(eliminado==-1){
					printf("\nerror en la eliminacion");
				}else{
					printf("El nodo con el dato %d ha sido eliminado\n",eliminado);
				}
				
			break;
			case 3:
				Imprimir(a);
			break;
			case 4:
				printf("Salir\n");
			break;
			default:
				puts("opcion invalida");
			
		}
		Imprimir(a);
		system("pause");
	}while(opc!=4);
	
	
	
	
	//pedir dato
	Insertar(a,dato,pos);
	eliminado=Eliminar(a,pos);
	
	DestruirLista(a);
	//menu
		//dar las opciones
		//obtener la opcion que quiere el usuario
	
	//insertar
		//crear nodo
			//reservar la memoria
		//isertar insertar en lista vacia
			//el nuevo elemento es igual a first y las
		//insertar en lista con elementos
			//insrtar al inicio
				//igualar first a nuevo
				//nuevo en siguiente es lista-<first
			//is=nsertar al final
				//el siguiente de last va a ser nuevo
				//last se iguala a nuevo
			//insertar en medio
				//se busca el lugar para insertar
				//nuevo en sig va a ser el de adelante de la posicion
				//el anterior a posicion va a ser nuevo
	
	/*
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
