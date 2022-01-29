#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct{
	int tope;
	int elementos[TAM];
}Pila;

void insertar(Pila *pilaT,int dato){
	pilaT->tope++;//se aumenta tope en 1, tope=0
	pilaT->elementos[pilaT->tope]=dato;//le esta asignando 4 a pila elementos en la posicion 0
	

	
}
int eliminar (Pila *pilaT){
	int dato;
	dato=pilaT->elementos[pilaT->tope];//dato se iguala a lo que haya dentro de pila elementos en ls posicion pila tope
	pilaT->tope--;
	
	
	
	return dato;
}
void imprimir(Pila *pilaT){
	int i;
	for( i=-1; i<pilaT->tope; i++){
		printf("%d\n",pilaT->elementos[i+1]);
	}
	system("pause");
}
int llena(Pila pila){
	int bandera=0;
	
	if(pila.tope==TAM-1)//si pila tope =99 se devuelve 1
		bandera=1;
		
	return bandera;
}
int vacia(Pila pila){
	int bandera=0;
	
	if(pila.tope==-1){
		bandera=1;
		
		return bandera;
	}
}
int main(){
	Pila pila={-1,{0}};//le esta asignando -1 a tope y el arreglo lo rellena con 0
	int lleno,dato;
	
	if (vacia(pila)){
		printf("la pila esta vacia");
	}else{
		imprimir(&pila);
	}
	
	
	
	
	
	/*insertar (&pila,4);//se pasa la dir de memoria de pila y se asigna el 4 a dato
	imprimir(&pila);
	
	insertar(&pila,2);
	imprimir(&pila);*/
	
	do{
		
		lleno=llena(pila);
		if(lleno!=1){
			printf("dame dato a agregar a la pila (-1 para salir)");
			scanf("%d",&dato);
			if(dato>0){
				insertar(&pila,dato);
			}else{
				printf("entero positivo");
			}
		}else{
			printf("pila llena");
			datos=-1;
		}
	
	}while(dato!=-1);
	
	if(vacia(pila)){
		printf("no puedo eiminar");
	}else{
		printf("el dato eliminado es %d ",eliminar(&pila));
		imprimir(&pila);
	}
	
	if(vacia(pila)){
		puts("la pila esta vacia");
	}else{
		imprimir(&pila);
	}
	
	//pila=1,{4,2}
	
	return 0;
} 
