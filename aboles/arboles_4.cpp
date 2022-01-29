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
	
	K1=actual;
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
	if(NuevaAltura(actual->derecha)-NuevaAltura(actual->izquierda)){
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
void Eliminar (Nodo *nodo){
	
	
	if(nodo!=NULL){
		Eliminar(nodo->izquierda);
		Eliminar(nodo->derecha);
		printf("\nEliminando=%i",nodo->dato);
		nodo->izquierda=NULL;
		nodo->derecha=NULL;
		free(nodo);
	}
	
}

Nodo *getmin(Nodo* actual){
	Nodo *actual;
	
	while (actual && actual->izquierda){
		actual=actual->izquierda;
	}
	return (actual);
}
Nodo *BorrarNodo(Nodo *actual,int dato){
	if(actual==NULL){
		return actual
	}
	if (dato<actual->dato){
		actual->izquierda=BorrarNodo(actual->izquierda,dato);
	}else if{
		actual->derecha=BorrarNodo(actual->derecha,dato);
	}else{
		if (actual->izquierda==NULL){
			Nodo *temp=actual->derecha;
			delete(actual);
			return temp;
		}
		else if(actual->derecha==NULL){
			Nodo *temp=actual->izquierda;
			delete(actual);
			return (temp);
		}
		Nodo* temp=getmin(actual->derecha);
		
		actual->dato=temp->dato;
		actual->derecha=BorrarNodo(actual->derecha,temp->dato);
		
	}
	return actual;
}
Nodo *BorrarHoja(Nodo *actual, int dato){
	if(actual!=NULL){
		if(actual->dato==dato){
			if(actual->izquierda==NULL && actual->derecha==NULL){
				actual=NULL;
			}else if(actual->izquierda==NULL){
				actual=actual->derecha;
			}else if(actual->derecha==NULL){
				actual=actual->izquierda;
			}else{
				actual->dato= delete_min(actual->derecha);
			}
		}
	}else if(dato<actual->dato){
		actual->izquierda=BorrarHoja(actual->derecha,dato);
	
	}else{
		actual->derecha=BorrarHoja(actual->derecha,dato);
	}
	actual=Balanceo(actual);
	actual->altura=NuevaAltura(actual);
	return actual;
}
int Menu(){
	int opc;
	
	printf("Que desea hacer?");
	printf("1.-Insertar elemento");
	printf("2.-Borrar elemento");
	printf("3.-Encontrar");
	printf("4.-Recorrido Preorden");
	printf("5.-Recorrido Entreorden");
	printf("6.-Recorrido Postorden");
	printf("7.-Salir");
	scanf("%i",&opc);
	
	return (opc);
}
int main(){
	Nodo *raiz=CrearNodo(28);
	int dato,opc;
	
	
	
	do{
		opc=Menu();
		switch(opc){
			case 1:
				printf("Dame el dato a insertar:  \n");
				scanf("%i",&dato);
				Insertar(raiz,dato);
			break;
			case 2://borrar
				printf("Que dato quieres borrar:  \n");
				
			break;
			case 3://encontrar
				
			break;
			case 4://preorden
				Preorden(raiz);
			break;
			case 5://entreorden
				Entreorden(raiz);
			break;
			case 6://postorden
				Postorden(raiz);
			break;
			case 7://salir
				printf("salir");
			break;
			default:
				printf("opcion no valida");
		}
	}while(opc!=7);

	


	
	printf("\n");
	Eliminar(raiz);
}
