#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo_ca{
	int dato;
	struct Nodo_ca *sig;
	struct Nodo_ca *ant;
}Nodo_ca;
typedef struct Nodo_nom{
	char nom[15];
	struct Nodo_nom *sig;
	struct Nodo_nom *ant;
}Nodo_nom;

typedef struct Lista_c{
	Nodo_ca *first;
	Nodo_ca *last;
	int longitud;
}Lista_c;
typedef struct Lista_n{
	Nodo_nom *first;
	Nodo_nom *last;
	int longitud;
}Lista_n;

Lista_c *CrearLista_c(){
	Lista_c *lista_c;
	lista_c=(Lista_c*)malloc(sizeof(Lista_c));
	
	lista_c->first=NULL;
	lista_c->last=NULL;
	lista_c->longitud=0;
	
	return lista_c;
	
}
Lista_n *CrearLista_n(){
	Lista_n*lista_n;
	lista_n=(Lista_n*)malloc(sizeof(Lista_n));
	
	lista_n->first=NULL;
	lista_n->last=NULL;
	lista_n->longitud=0;
	
	return lista_n;
	
}
Nodo_nom *CrearNodo_Nm(char *nom){
	Nodo_nom *nodo;
	nodo=(Nodo_nom*)malloc(sizeof(Nodo_nom));
	
	strcpy(nodo->nom,nom);
	nodo->sig=NULL;
	nodo->ant=NULL;
	
	return nodo;
	
}
Nodo_ca *CrearNodo_ca(int dato){
	Nodo_ca *nodo;
	nodo=(Nodo_ca*)malloc(sizeof(Nodo_ca));
	
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
void Insertar(Lista_n *alum,Lista_c *calif,int pos,char *nom,int cal){
	Nodo_nom *nuevo_n,*med_n;
	Nodo_ca *nuevo_c, *med_c;
	nuevo_n=CrearNodo_Nm(nom);
	nuevo_c=CrearNodo_ca(cal);
	int i,opc_med;
	
	
	if(alum->longitud>0){//para ver si esta vacia
		if(pos>0 && pos<=alum->longitud+1){
			if(pos==1){
				//nombre
				nuevo_n->sig=alum->first;
				nuevo_n->ant=NULL;
				alum->first->ant=nuevo_n;
				alum->first=nuevo_n;
				
				//calificacion
				nuevo_c->sig=calif->first;
				nuevo_c->ant=NULL;
				calif->first->ant=nuevo_c;
				calif->first=nuevo_c;
				
			}else if(pos==alum->longitud+1){
				//nombre
				alum->last->sig=nuevo_n;
				nuevo_n->ant=alum->last;
				nuevo_n->sig=NULL;
				alum->last=nuevo_n;
				
				//calificacion
				calif->last->sig=nuevo_c;
				nuevo_c->ant=calif->last;
				nuevo_c->sig=NULL;
				calif->last=nuevo_c;
				
			}else{
				//falta el recorrido
				med_n=alum->first;
				med_c=calif->first;
				
				for(i=1;i<pos-1;i++){
					med_n=med_n->sig;
					med_c=med_c->sig;
				}
				//nombre
				nuevo_n->sig=med_n->sig;
				med_n->sig=nuevo_n;
				nuevo_n->ant=med_n;
				nuevo_n->sig->ant=nuevo_n;		
				
				//calificacion
				nuevo_c->sig=med_c->sig;
				med_c->sig=nuevo_c;
				nuevo_c->ant=med_c;
				nuevo_c->sig->ant=nuevo_c;					
				
			}
			alum->longitud++;
			calif->longitud++;
		}else{
			puts("posicion no valida");
			if(pos<=0){
				printf("quieres insertar al inicio?\t 1.-Si  2.-No");
				scanf("%d",&opc_med);
				if(opc_med==1){
					//nombre
					nuevo_n->sig=alum->first;
					nuevo_n->ant=NULL;
					alum->first->ant=nuevo_n;
					alum->first=nuevo_n;
					
					//calificacion
					nuevo_c->sig=calif->first;
					nuevo_c->ant=NULL;
					calif->first->ant=nuevo_c;
					calif->first=nuevo_c;
				}
			}else{
				printf("quieres insertar al final?\t 1.-Si 2.-No");
				scanf("%d",&opc_med);
				if(opc_med==1){
					//nombre
					alum->last->sig=nuevo_n;
					nuevo_n->ant=alum->last;
					nuevo_n->sig=NULL;
					alum->last=nuevo_n;
					
					//calificacion
					calif->last->sig=nuevo_c;
					nuevo_c->ant=calif->last;
					nuevo_c->sig=NULL;
					calif->last=nuevo_c;
				}
			}
		}
	
	}else{
		//nombre
		alum->first=nuevo_n;
		alum->last=nuevo_n;
		alum->longitud++;
		
		//calificacion
		calif->first=nuevo_c;
		calif->last=nuevo_c;
		calif->longitud++;
		
		
	}
}
void DestruirNodo_n(Nodo_nom *nodo_n){
	nodo_n->sig=NULL;
	nodo_n->ant=NULL;
	free(nodo_n);
}
void DestruirNodo_c(Nodo_ca *nodo_c){
	nodo_c->sig=NULL;
	nodo_c->ant=NULL;
	free(nodo_c);
}
void Eliminar(Lista_n *alum,Lista_c *calif,int pos){
	Nodo_nom *elim_n,*med_n;
	Nodo_ca *elim_c,*med_c;
	
	int eliminado_n,eliminado_c,i;
	
	if(alum->longitud){//si esta vacia
		if(pos>0 && pos<=alum->longitud){
			if(pos==1){
				//nombre
				elim_n=alum->first;
				alum->first=alum->first->sig;
				alum->first->ant=NULL;
				
				//calificaciones
				elim_c=calif->first;
				calif->first=calif->first->sig;
				calif->first->ant=NULL;
			
			}else if(pos==alum->longitud){
				//nombre
				elim_n=alum->last;
				alum->last=alum->last->ant;
				alum->last->sig=NULL;
				
				//calificaciones
				elim_c=calif->last;
				calif->last=calif->last->ant;
				calif->last->sig=NULL;
			
			}else{
				elim_n=alum->first;
				elim_c=calif->first;
				for(i=1;i<pos;i++){
					elim_n=elim_n->sig;
					elim_c=elim_c->sig;
				}
				//nombre
				elim_n->ant->sig=elim_n->sig;
				elim_n->sig->ant=elim_n->ant;
				
				//calificaciones
				elim_c->ant->sig=elim_c->sig;
				elim_c->sig->ant=elim_c->ant;
			}
			alum->longitud--;
			calif->longitud--;
			

			
			//actualizar
			DestruirNodo_n(elim_n);
			DestruirNodo_c(elim_c);
		//	return (eliminado);//????
			
		}else{
			printf("posicion invalida\n");
		}
	}else{
		printf("la lista esta vacia\n");
	
	}
	

}
void Imprimir(Lista_n *alum,Lista_c *cal){
	Nodo_nom *nodo_n;
	Nodo_ca *nodo_c;

	nodo_n=alum->first;
	nodo_c=cal->first;
	
	while(nodo_n!=NULL){
		printf("%s\t",nodo_n->nom);
		printf("%d\n",nodo_c->dato);
		
		nodo_n=nodo_n->sig;
		nodo_c=nodo_c->sig;
	}
	printf("\n");
	
}
void ImprimirInverso(Lista_n *alum,Lista_c *cal){
	Nodo_nom *nodo_n;
	Nodo_ca *nodo_c;
	
	nodo_n=alum->last;
	nodo_c=cal->last;
	
	
	while(nodo_n!=NULL){
		printf("%d\t",nodo_n->nom);
		printf("%d\t",nodo_c->dato);
		nodo_n=nodo_n->ant;
		nodo_c=nodo_c->ant;
	}
	printf("\n");
}
//poner las dos listas
void DestruirLista(Lista_n *alum,Lista_c *calif){
	int eliminado=0;
	
	while(alum->first){
		Eliminar(alum,calif,1);
	}
	free(alum);
	free(calif);
}

int main(){
	Lista_n *alum;
	Lista_c *calif;
	int opc,pos,eliminado,grade;
	char nombre[15];
	alum=CrearLista_n();
	calif=CrearLista_c();
	
	do{
		system("cls");
		opc=Menu();
		Imprimir(alum,calif);
		

		switch(opc){
			case 1://insertar
				printf("Dame solo el nombre\n");
				scanf("%s",&nombre);	
				
				printf("Dame la calificacion\n");
				scanf("%i",&grade);
				
				printf("Dame la posicion\n");
				scanf("%i",&pos);
				
				Insertar(alum,calif,pos,nombre,grade);

	
			break;
			case 2://eliminar
				printf("Dame la posicion del elemento a eliminar\n");
				scanf("%i",&pos);
				Eliminar(alum,calif,pos);
				
			
				
			break;
			case 3://imprimir
				Imprimir(alum,calif);
				
			break;
			case 4://imprimir inverso
				ImprimirInverso(alum,calif);
				
			break;
			case 5://salir
				printf("Salir");
			break;
			default:
				printf("opcion no valida");
		}
		Imprimir(alum,calif);
		
		system("pause");
	}while(opc!=5);
	DestruirLista(alum,calif);

}
