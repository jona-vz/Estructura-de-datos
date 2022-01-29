#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *sig;
	
}Nodo;
int menu(){
	int opc;
	
	printf("Que desea hacer?\n");
	printf("1.-Insertar\n");
	printf("2.-Imprimir todos los elementos\n");
	printf("3.-Eliminar\n");
	printf("4.-Imprimir el ultimo elemento\n");
	printf("5.-Salir\n");
	scanf("%i",&opc);
	
	return (opc);
}

int vacia(Nodo *tope){
	int band=0;
	if(tope==NULL){
		band=1;
	}
	
	return band;
}
void insertar(Nodo **tope,int dato){//doble * porque se va a modificar el tope del main con ->siguiente
	//asignar espacio
	Nodo *nuevo;
	nuevo=(Nodo*)malloc(sizeof(Nodo));
	
	//llenar datos
	nuevo->dato=dato;
	
	//asignar siguiente a tope
	nuevo->sig=*tope;
	
	//tope apunta a nuevo
	*tope=nuevo;
	
}
void imprimir(Nodo *tope){
	//no modificar tope
	Nodo *save_t;
	save_t=tope;
	
	if(vacia(tope)==0){
		printf("la pila entera:\n");
		while(save_t!=NULL){
			printf("Dato: %i\n",save_t->dato);
			save_t=save_t->sig;
		}
	}else{
		printf("la pila esta vacia");
	}
	
	
}
int eliminar(Nodo **tope){
	//crear variable temporal donde se va a guardar el ultimo elemento a eliminar
	Nodo *temp;
	int num;
	if(vacia(*tope)==0){
		//asignar el tope a la temporal
		temp=*tope;
		//obtener el dato dentro de tope
		num=temp->dato;
		//mover el tope al penultimo elemento
		*tope=(*tope)->sig;
		//liberar la memoria
		free(temp);
	}else{
		printf("la pila esta vacia");
	}
	
	
	return num;
	
}

void imprimir_ult(Nodo *tope){
	
	if(vacia(tope)==0){
		printf("Dato: %i\n",tope->dato);
	}else{
		printf("la pila esta vacia");
	}
	

}

int main(){
	Nodo *tope=NULL;
	int dato;
	int num_elim;
	int opc;
	
	
	do{
		opc=menu();
		switch(opc){
			case 1:
				do{
					printf ("Dame el entero positivo para agregar a la pila (-1 para salir):\t");
					scanf("%d", &dato);
					if(dato > 0){
						insertar(&tope, dato); 
						imprimir(tope);
					}else{
						puts ("te dije que entero positivo!!");
					}
					
				}while(dato!=-1);
			break;
			
			case 2:
				system("cls");
				
				imprimir(tope);
				system("pause");
			break;
			
			case 3:
				num_elim=eliminar(&tope);
				printf("el numero eliminado fue:%d",num_elim);
				system("pause");
			break;
			
			case 4:
				imprimir_ult(tope);
			case 5:
				printf("Salir\n");
			break;
			default:
				printf("opcion no valida\n");
		}
		
			
	}while(opc!=5);
	
	
	
	
	
	
	
	
	
	
	
	/*system("cls");
	printf("la pila entera:\n");
	imprimir(tope);
	system("pause");
	
	num_elim=eliminar(&tope);
	printf("el numero eliminado fue:%d",num_elim);
	system("pause");
	num_elim=eliminar(&tope);
	printf("el numero eliminado fue:%d",num_elim);
	system("pause");
	
	system("cls");
	printf("la pila entera:\n");
	imprimir(tope);
	system("pause");*/
	
}
