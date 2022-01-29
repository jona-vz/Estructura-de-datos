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
void EliminarArbol (Nodo *nodo){
	
	
	if(nodo!=NULL){
		EliminarArbol(nodo->izquierda);
		EliminarArbol(nodo->derecha);
		printf("\nEliminando=%i",nodo->dato);
		nodo->izquierda=NULL;
		nodo->derecha=NULL;
		free(nodo);
	}
	
}
void EliminarNodo(Nodo *nodo){

		printf("\nEliminando=%i",nodo->dato);
		nodo->izquierda=NULL;
		nodo->derecha=NULL;
		free(nodo);
}
Nodo *getmin(Nodo* actual){
	
	
	while (actual && actual->izquierda){
		actual=actual->izquierda;
	}
	return (actual);
}
Nodo *BorrarNodo(Nodo *actual,int dato){
	if(actual==NULL){
		return actual;
	}
	if (dato < actual->dato){//es menor,va a la izquierda
		actual->izquierda=BorrarNodo(actual->izquierda,dato);
	}else if(dato > actual->dato){//es mayor, va a la derecha
		actual->derecha=BorrarNodo(actual->derecha,dato);
	}else{ //cuando es igual
		if (actual->izquierda==NULL){
			Nodo *temp=actual->derecha;
			EliminarNodo(actual);
			return temp;
		}
		else if(actual->derecha==NULL){
			Nodo *temp=actual->izquierda;
			EliminarNodo(actual);
			return (temp);
		}
		Nodo* temp=getmin(actual->derecha);
		
		actual->dato=temp->dato;
		actual->derecha=BorrarNodo(actual->derecha,temp->dato);
		
	}
	return actual;
}
Nodo *BuscarNodo(Nodo *actual,int dato,int *i){
	
		if(actual==NULL){
			return actual;
		}
		if (dato < actual->dato){//es menor,va a la izquierda
			*i++;
			printf("izq mov %i\n",*i);

			actual->izquierda=BuscarNodo(actual->izquierda,dato);
		}else if(dato > actual->dato){//es mayor, va a la derecha
			*i++;
			printf("derecha mov %i\n",*i);
			actual->derecha=BuscarNodo(actual->derecha,dato);
		}else{ //cuando es igual
			printf("found it %i",actual->dato);
			
		}
		return actual;
	/*if( dato < actual->dato){
		printf("mov %d ... ",i);
		i++;
		actual->izquierda=BuscarNodo(actual->izquierda,dato);
	
		
	}else if(dato > actual->dato){
		printf("mov %d",i);
		i++;
		actual->derecha=BuscarNodo(actual->derecha,dato);
		
	
	}else{
		printf("num encontrado %i",actual->dato);
	}*/
	
}
int Menu(){
	int opc;
	
	printf("Que desea hacer? \n");
	printf("1.-Insertar elemento \n");
	printf("2.-Borrar elemento \n");
	printf("3.-Encontrar \n");
	printf("4.-Recorrido Preorden \n");
	printf("5.-Recorrido Entreorden \n");
	printf("6.-Recorrido Postorden \n");
	printf("7.-Salir");
	scanf("%i",&opc);
	
	return (opc);
}
void Default(){
	Nodo *actual;
	Insertar(actual,1);
	Insertar(actual,3);
	Insertar(actual,6);
	Insertar(actual,15);
	Insertar(actual,7);
	Insertar(actual,9);
	Insertar(actual,4);
	Insertar(actual,5);
}
int main(){
	Nodo *raiz=CrearNodo(5);
	int dato,opc,i=0;
	
	
	
	do{
		opc=Menu();
		switch(opc){
			case 0:
				Default();
			break;
			case 1:
				printf("Dame el dato a insertar:  \n");
				scanf("%i",&dato);
				Insertar(raiz,dato);
				//system("pause");
			break;
			case 2://borrar
				printf("Que dato quieres borrar:  \n");
				scanf("%i",&dato);
				BorrarNodo(raiz,dato);
				system("pause");
			break;
			case 3://encontrar
				printf("Que dato quieres encontrar: \n");
				scanf("%i",&dato);
				BuscarNodo(raiz,dato,&i);
				system("pause");
			break;
			case 4://preorden
				Preorden(raiz);
				system("pause");
			break;
			case 5://entreorden
				Entreorden(raiz);
				system("pause");
			break;
			case 6://postorden
				Postorden(raiz);
				system("pause");
			break;
			case 7://salir
				printf("salir");
			break;
			default:
				printf("opcion no valida");
		}
		system("cls");
	}while(opc!=7);

	


	
	printf("\n");
	EliminarArbol(raiz);
}


