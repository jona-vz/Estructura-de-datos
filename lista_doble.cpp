#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo *sig;
	struct Nodo *ant;
}Nodo;

typedef struct Lista{
	Nodo *first;
	Nodo *last;
	int longitud;
}Lista;
Lista *CrearLista(){
	Lista*lista;
	lista=(Lista*)malloc(sizeof(Lista));
	
	lista->first=NULL;
	lista->last=NULL;
	lista->longitud=0;
	
	return lista;
	
}
Nodo *CrearNodo(int dato){
	Nodo *nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	
	nodo->dato=dato;
	nodo->sig=NULL;
	nodo->ant=NULL;
	
	return nodo;
	
}

int Menu(){
	int opc;
	
	printf("CHOOSE YOUR FIGHTER \n");
	printf("1.-Insertar elemento\n");
	printf("2.-Eliminar elemento\n");
	printf("3.-Imprimir Lista\n");
	printf("4.-Imprimir Lista Inversa\n");
	printf("5.-Salir\n");
	scanf("%d",&opc);
	return opc;
}
void Insertar(Lista *lista,int pos,int dato){
	Nodo *nuevo,*med;
	nuevo=CrearNodo(dato);
	int i,opc_med;
	
	
	if(lista->longitud>0){//para ver si esta vacia
		if(pos>0 && pos<=lista->longitud+1){
			if(pos==1){
				nuevo->sig=lista->first;
				nuevo->ant=NULL;
				lista->first->ant=nuevo;
				lista->first=nuevo;
			}else if(pos==lista->longitud+1){
				lista->last->sig=nuevo;
				nuevo->ant=lista->last;
				nuevo->sig=NULL;
				lista->last=nuevo;
			}else{
				//falta el recorrido
				med=lista->first;
				for(i=1;i<pos-1;i++){
					med=med->sig;
				}
				nuevo->sig=med->sig;
				med->sig=nuevo;
				nuevo->ant=med;
				nuevo->sig->ant=nuevo;					
				
			}
			lista->longitud++;
		}else{
			puts("posicion no valida");
			if(pos<=0){
				printf("quieres insertar al inicio?\t 1.-Si  2.-No");
				scanf("%d",&opc_med);
				if(opc_med==1){
					nuevo->sig=lista->first;
					nuevo->ant=NULL;
					lista->first->ant=nuevo;
					lista->first=nuevo;
				}
			}else{
				printf("quieres insertar al final?\t 1.-Si 2.-No");
				scanf("%d",&opc_med);
				if(opc_med==1){
					lista->last->sig=nuevo;
					nuevo->ant=lista->last;
					nuevo->sig=NULL;
					lista->last=nuevo;
				}
			}
		}
	
	}else{
		lista->first=nuevo;
		lista->last=nuevo;
		lista->longitud++;
	}
}
void DestruirNodo(Nodo *nodo){
	nodo->sig=NULL;
	nodo->ant=NULL;
	free(nodo);
}
int Eliminar(Lista *lista,int pos){
	Nodo *elim,*med;
	int eliminado,i;
	
	if(lista->longitud){//si esta vacia
		if(pos>0 && pos<=lista->longitud){
			if(pos==1){
				elim=lista->first;
				lista->first=lista->first->sig;
				lista->first->ant=NULL;
			
			}else if(pos==lista->longitud){
				elim=lista->last;
				lista->last=lista->last->ant;
				lista->last->sig=NULL;
			
			}else{
				elim=lista->first;
				for(i=1;i<pos;i++){
					elim=elim->sig;
				}
				elim->ant->sig=elim->sig;
				elim->sig->ant=elim->ant;
			
			}
			lista->longitud--;
			eliminado=elim->dato;
			DestruirNodo(elim);
			return (eliminado);
		}else{
			printf("posicion invalida\n");
		}
	}else{
		printf("la lista esta vacia\n");
		return -1;
	}
	

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
void ImprimirInverso(Lista *lista){
	Nodo *nodo;
	
	nodo=lista->last;
	
	while(nodo!=NULL){
		printf("%d\t",nodo->dato);
		nodo=nodo->ant;
	}
	printf("\n");
}
void DestruirLista(Lista *lista){
	int eliminado=0;
	
	while(lista->first){
		eliminado=Eliminar(lista,1);
	}
	free(lista);
}
int main(){
	Lista *doble;
	int opc,pos,dato,eliminado;
	doble=CrearLista();
	
	do{
		system("cls");
		opc=Menu();
		Imprimir(doble);

		switch(opc){
			case 1://insertar
				printf("Dame el dato\n");
				scanf("%i",&dato);				
				printf("Dame la posicion\n");
				scanf("%i",&pos);

				Insertar(doble,pos,dato);
			break;
			case 2://eliminar
				printf("Dame la posicion del elemento a eliminar\n");
				scanf("%i",&pos);
				eliminado=Eliminar(doble,pos);
				if(eliminado==-1){
					printf("error al eliminar");
				}else{
					printf("El dato eliminado fue:%i\t\n",eliminado);	
				}
			
				
			break;
			case 3://imprimir
				Imprimir(doble);
			break;
			case 4://imprimir inverso
				ImprimirInverso(doble);
			break;
			case 5://salir
				printf("Salir");
			break;
			default:
				printf("opcion no valida");
		}
		Imprimir(doble);
		system("pause");
	}while(opc!=5);
	DestruirLista(doble);
}
