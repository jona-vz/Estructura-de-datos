#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo *izquierda;
	struct Nodo *derecha;
	int altura;
}Nodo;

Nodo *CrearNodo(int dato){
	Nodo *nuevo;
	
	nuevo=(Nodo*)malloc(sizeof(Nodo));
	
	nuevo->dato=dato;
	nuevo->izquierda=NULL;
	nuevo->derecha=NULL;
	nuevo->altura=-1;
	
	return nuevo;
}
int NuevaAltura(Nodo *actual){
	

	if (actual==NULL)
		return -1;
	else{
		int izq,der;
		
		izq=NuevaAltura(actual->izquierda);
		der=NuevaAltura(actual->derecha);
		
		if(izq>der)
			return (izq+1);
		else
			return (der+1);
	}
		
			
		
}
Nodo *RSimpleDer(Nodo *actual){
	Nodo *k1,*k2;
	
	k1=actual;
	k2=k1->derecha;
	k1->derecha=k2->izquierda;
	k2->izquierda=k1;
	
	k1->altura=NuevaAltura(k1);
	k2->altura=NuevaAltura(k2);
	
	return(k2);
}
Nodo *RSimpleIzq(Nodo *actual){
	Nodo *k1,*k2;
	
	k1=actual;
	k2=k1->izquierda;
	k1->izquierda=k2->derecha;
	k2->derecha=k1;
	
	k1->altura=NuevaAltura(k1);
	k2->altura=NuevaAltura(k2);
	
	return (k2);
}
Nodo *RDobleDer(Nodo *actual){
	Nodo *k1;
	
	k1=actual;
	
	k1->derecha=RSimpleIzq(k1->derecha);
	
	
	return (RSimpleDer(k1));
}
Nodo *RDobleIzq(Nodo *actual){
	Nodo *k1;
	
	k1=actual;
	k1->izquierda=RSimpleDer(k1->izquierda);
	
	return (RSimpleIzq(k1));
}
Nodo *Balanceo(Nodo *actual){
	
	if(NuevaAltura(actual->izquierda)-NuevaAltura(actual->derecha)==2){
		if(NuevaAltura(actual->izquierda->izquierda)>=NuevaAltura(actual->izquierda->derecha))
			actual=RSimpleIzq(actual);
		else 
			actual=RDobleIzq(actual);
	}
	if(NuevaAltura(actual->derecha)-NuevaAltura(actual->izquierda)==2){
		if(NuevaAltura(actual->derecha->derecha)>=NuevaAltura(actual->derecha->izquierda))
			actual=RSimpleDer(actual);
		else actual=RDobleDer(actual);
	}
	return (actual);
}

Nodo *Insertar(Nodo *actual,int dato){
	if(actual==NULL){
		//ya no hay mas elementos
		actual=CrearNodo(dato);
	}else{
		//hay elementos
		if(dato<actual->dato){//que lado se inserta
			//izquierda
			actual->izquierda=Insertar(actual->izquierda,dato);
		}else{
			//derecha
			actual->derecha=Insertar(actual->derecha,dato);
		}
		
		actual=Balanceo(actual);
		
	}
	//calcula la nueva altura del nodo
	actual->altura=NuevaAltura(actual);
	return actual;
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
int getmin(Nodo* actual){
	
	
	while (actual && actual->izquierda){
		actual=actual->izquierda;
	}
	return (actual->dato);
}
Nodo *BorrarHoja(Nodo *actual, int dato){
	
	if(actual!=NULL){
		
		if(actual->dato==dato){
			if(actual->izquierda==NULL && actual->derecha==NULL){
				
				free(actual);
				actual=NULL;
				
			}else if(actual->izquierda==NULL){
				actual=actual->derecha;
			}else if(actual->derecha==NULL){
				actual=actual->izquierda;
			}else{
				actual->dato= getmin(actual->derecha);
				actual->derecha=BorrarHoja(actual->derecha,actual->dato);
			}
		
		}else if(dato<actual->dato){
			
			actual->izquierda=BorrarHoja(actual->izquierda,dato);
	
		}else{
			
			actual->derecha=BorrarHoja(actual->derecha,dato);
		}
		if(actual!=NULL){
			
			actual=Balanceo(actual);
			actual->altura=NuevaAltura(actual);		
		}
		
	}
	return actual;
}
Nodo *BuscarNodo(Nodo*actual,int dato){
	if(actual!=NULL){
		if(actual->dato==dato){
			printf("found it %i",actual->dato);
		}else if(dato < actual->dato){
			actual->izquierda=BuscarNodo(actual->izquierda,dato);
	
		}else{
			actual->derecha=BuscarNodo(actual->derecha,dato);
		}
		
	}
	return actual;
}
Nodo *OpcionCero(Nodo *actual){

	actual=Insertar(actual,11);
	actual=Insertar(actual,31);
	actual=Insertar(actual,61);
	actual=Insertar(actual,18);
	actual=Insertar(actual,20);
	actual=Insertar(actual,14);
	actual=Insertar(actual,43);
	actual=Insertar(actual,17);
	actual=Insertar(actual,23);
	actual=Insertar(actual,19);
	actual=Insertar(actual,34);
	actual=Insertar(actual,26);
	actual=Insertar(actual,45);
	actual=Insertar(actual,32);
	actual=Insertar(actual,13);
	
	return (actual);
}
int Menu(){
	int opc;
	
	printf("Que desea hacer?\n");
	printf("1.-Insertar elemento\n");
	printf("2.-Borrar elemento\n");
	printf("3.-Encontrar\n");
	printf("4.-Recorrido Preorden\n");
	printf("5.-Recorrido Entreorden\n");
	printf("6.-Recorrido Postorden\n");
	printf("7.-Salir\n");
	scanf("%i",&opc);
	
	return (opc);
}
int main(){
	Nodo *raiz=NULL;
	int dato,opc;
	
	
	
	do{
		opc=Menu();
		switch(opc){
			case 0:
				raiz=OpcionCero(raiz);
				
			break;
			case 1:
				printf("Dame el dato a insertar:  \n");
				scanf("%i",&dato);
				
				raiz=Insertar(raiz,dato);
				
			break;
			case 2://borrar
				printf("Que dato quieres borrar:  \n");
				scanf("%i",&dato);
				printf("raiz:%i",raiz->dato);
				BorrarHoja(raiz,dato);
			break;
			case 3://encontrar
				printf("Que dato quieres encontrar:\n");
				scanf("%i",&dato);
				BuscarNodo(raiz,dato);
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
	}while(opc!=7);

	


	
	printf("\n");
	EliminarArbol(raiz);
}
