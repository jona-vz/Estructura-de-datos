#include <stdio.h>
#include <string.h>
#define TAM	10

typedef struct Pila{
	int tope;
	int elementos[TAM];
}Pila;

/*void insertar (Pila *pilaT, int dato);  
int eliminar (Pila * pilaT);
int llena(Pila pilaT);
int vacia(Pila pilaT);
void imprimir (Pila *pilaT);*/



void insertar (Pila *pilaT, int dato){
	if(llena(pilaT)){//Si llena devuelve 1
		puts("Ya esta llena la pila");
	}else{//si devuelve 0
		pilaT->tope++;
		pilaT->elementos[pilaT->tope]=dato;
	}
	
}

void imprimir (Pila *pilaT){
	int i;
	if (vacia(pilaT)){//devuelve 1 
		puts ("la pila está vacia");
	}else{//devuelve 0
		for (i=-1; i<pilaT->tope; i++)
			printf ("%d\n", pilaT->elementos[i+1]);
	}
	
	printf ("\n\n");
	system("pause");
	system ("cls");
}

int eliminar (Pila * pilaT){  
	int dato;
	if (vacia(pilaT)){//devuelve 1
		puts("no puedo eliminar de una pila vacia");
		dato=-9999;
	}else{//devuelve 0
		dato=pilaT->elementos[pilaT->tope];
		pilaT->tope--;  
	}
	return dato;
}

int llena(Pila *pila){  
	int bandera=0;
	if (pila->tope==TAM-1)  
		bandera = 1;
	return bandera;
}
	
int vacia(Pila *pila) {
	int bandera=0;
	if (pila->tope==-1)
		bandera = 1;
	return bandera;
}


int main(){
	int dato;
	
	Pila pila={-1,{0}};
	imprimir (&pila);
	
	//insertar(&pila, 4); imprimir (&pila);
	//insertar(&pila,2); imprimir (&pila);
	
	do{
		printf ("Dame el entero positivo para agregar a la pila (-1 para salir):\t");
		scanf("%d", &dato);
		if(dato > 0){
			insertar(&pila, dato); imprimir(&pila);
		}else{
			puts ("te dije que entero positivo!!");
		}
		
	}while(dato!=-1);
	
	printf("El dato eliminado es: %d\n", eliminar(&pila));
	
	imprimir (&pila);
	
	return 0;
}
