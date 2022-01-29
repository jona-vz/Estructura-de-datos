#include <stdlib.h>

#include "funciones-c.h"

int main(){
	int opc,dato,sec,cola_opc,origen;
	int NumElem,destino;
	Cola* cola,*cola_1,*cola_2,*cola_3;
	//creamos la cola
	
	cola_1=CrearCola();
	cola_2=CrearCola();
	cola_3=CrearCola();
	
	
	
	//2.-procesos
	do{
		system("cls");
		
		ImprimirCola(cola_1);
		ImprimirCola(cola_2);
		ImprimirCola(cola_3);
		
		printf("Escoge una cola: 1-2-3");
		scanf("%d",&cola_opc);
		if(cola_opc==1){
			cola=cola_1;
		}else if(cola_opc==2){
			cola=cola_2;
		}else{
			cola=cola_3;
		}
	
		opc=Menu();
		if(opc>0 &&opc<6)
		ImprimirCola(cola);
		

		switch(opc){
			
			
			case 1://insertar nodo
				
				
				printf("Dame un entero positivo para agregar: ");
				scanf("%d",&dato);
				if(dato>0){
					
					Insertar(cola,dato);
					//ImprimirCola(cola);
					
				}else{
					puts("entero positivo");
				}
				
			break;
			case 2://eliminar nodo
				Eliminar(cola);
			break;
			case 3://cambiar prioridad
				if(cola->longitud>=2){
					printf("Dame el numeo de elemento que quiee cambiar: ");
					scanf("%d",&NumElem);
					if(cola->longitud>NumElem){
						printf("Dame el destino del elemento a cmbiar");
						scanf("%d",&destino);
						CambiarPrioridad(NumElem,destino,cola);
					}else{
						printf("el elemento no existe");
					}
					
				}else{
					printf("elementos insuficientes");
				}
			
				
			break;
			case 4://destruir cola 
				printf("\nSEGURO MQUE QUIERES DESTRUIRM LA COLA?(1.-Si 0.-No)");
				scanf("%d",&sec);
				if(sec==1){
					DestruirCola(cola);
					exit(0);
				}
				
			break;
			case 5://imprimir cola completa
				ImprimirCola(cola);
			break;
			case 6://imprimir primer elemento
				ImprimirPrimero(cola);
			break;
			case 7://imprimir ultimo elemento
				ImprimirUltimo(cola);
			break;
			case 8:
				
				printf("Dame la cola de destino");
				scanf("%d",&destino);
				
				if(cola_opc!=destino){
					switch(cola_opc){
						case 1://origen-cola_1
							if(Vacia(cola)){
								puts("la cola de origen esta vacia");
							}else{
								if(destino==2){
									Cambiardecola(cola,cola_2);
								}else{
									Cambiardecola(cola,cola_3);
								}
							}
						break;
						case 2:
							if(Vacia(cola)){
								puts("la cola de origen esta vacia");
							}else{
								if(destino==1){
									Cambiardecola(cola,cola_1);
								}else{
									Cambiardecola(cola,cola_3);
								}
							}
						break;
						case 3:
							if(Vacia(cola)){
								puts("la cola de origen esta vacia");
							}else{
								if(destino==1){
									Cambiardecola(cola,cola_1);
								}else{
									Cambiardecola(cola,cola_2);
								}
							}
						break;
						default: 
							puts("opcion no valida");
					}//switch
				}//if
			break;
			case 9:
				puts("salir");
			break;
			default:
				puts("opcion no valida");
		}
		if(opc>0 &&opc<9)
			ImprimirCola(cola);
			
		system("pause");
		system("cls");	
		
	}while(opc!=9);
	
	
	
	//3.-destruir cola;
	DestruirCola(cola_1);
	DestruirCola(cola_2);
	DestruirCola(cola_3);
	
	
	return 0;
}
