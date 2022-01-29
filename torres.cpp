/*Torres de hanoi: 
objetivo:mover las piezas de un palito a otro ordenadas.
la mas grande abajo y la mas peque;a arriba.
reglas: 1.-solo se mueve un elemento a la vez
2.- abajo siempre tiene que estar el mas grande.*/

#include <stdio.h>

#include <stdlib.h>

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
	pila->tope=nuevo;
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
void eliminar(Pila* pila){
	//crear variable temporal donde se va a guardar el ultimo elemento a eliminar
	
	
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
void DestruirPila(Pila *pila){
	while(pila->tope!=NULL){
		eliminar(pila);
	}
	free(pila);
}
int Cima(Pila *pila){
	if(pila->tope==NULL){
		return NULL;
	}else{
		return pila->tope->dato;
	}
}
void ImprimirPila(Pila *pila){
	int i;
	Nodo *temp;
	
	//todos los guiones que se ocupan
	for(i=0;i<(4-pila->cont);i++){
		printf("-");
	}
	
	
	temp=pila->tope;
	
	while(temp!=NULL){
		printf("%i",temp->dato);
		temp=temp->sig;
	}
	
	printf("|\n");
}
void ImprimirEdo(Pila* top,Pila* centro,Pila* down){
	//imprimir la pila 
	system("cls");
	ImprimirPila(top);
	ImprimirPila(centro);
	ImprimirPila(down);
	
}
int vacia(Pila *pila){
	if(pila->cont==0){
		return 1;
	}else{
		return 0;
	}
	
}
void Movimiento(Pila *origen,Pila*destino){
	
	if( vacia(destino) || destino->tope->dato  >  origen->tope->dato  ){
		//insertar el dato en la pila destino
		insertar(destino,origen->tope->dato);
		//eliminar de la pila origen
		eliminar(origen);
	}else{
		puts("movimiento invalido");
		system("pause");
	}
	
}
int Ganar(Pila *centro,Pila *abajo){
	
	//cualquiera de los dos tiene los tres elementos
	if(centro->cont==3){
		return 1;
	}
	if(abajo->cont==3){
		return 1;
	}
	return 0;
}
int main(){
	Pila *top,*centro,*down;
	int origen,destino;
	
	//creamos las tres pilas
	top=CrearPila();
	centro=CrearPila();
	down=CrearPila();
	
	//a;aden los tres elementos iniciales	
	insertar(top,3);
	insertar(top,2);
	insertar(top,1);
	
	

	//***juego del usuario***
	
	do{
		//imprimir estado actual de las 3 palitos
		ImprimirEdo(top,centro,down);
		
		printf("Dame la pila de origen: (1.top,2.centro,3.down,-1 salir)");
		scanf("%d",&origen);
		printf("Dame la pila de destino: (1.top,2.centro,3.down)");
		scanf("%d",&destino);
		
		if(origen!=destino ){
			
			switch(origen){
				case 1://origen-top
					if(vacia(top)){
						puts("la de origen esta vacia");
					}else{
						if(destino==2){
							Movimiento(top,centro);
						}else{
							Movimiento(top,down);
						}
					}
					
					
				break;
				case 2://origen centro
					if(vacia(centro)){
						puts("la de origen esta vacia");
					}else{
						if(destino==1){
							Movimiento(centro,top);
						}else{
							Movimiento(centro,down);
						}
					}
				break;
				case 3://origen abajo
					if(vacia(down)){
						puts("la de origen esta vacia");
					}else{
						if(destino==3){
							Movimiento(down,top);
						}else{
							Movimiento(down,centro);
						}
					}
				break;
				case -1:
					puts("perdiste");
				break;
				default:
					puts("opcion no valida");
			}//switch
			
		}/*if*/ else{
			puts("el origen no puede ser igual al destino");
		}
		
		//checar si ya gano
		if(Ganar(centro,down)){
			//imprimir estado actual de las 3 palitos
			
			printf("\nya ganaste\n");
			origen=-1;
		}
		
	}/*do*/ while(origen!=-1);
	system("pause");
	ImprimirEdo(top,centro,down);
	
	//cerrar el juego
	DestruirPila(top);
	DestruirPila(centro);
	DestruirPila(down);
	
	return (0);
}
