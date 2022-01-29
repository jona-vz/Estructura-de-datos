#include <stdio.h>
#include <stdlib.h>

#include "funciones-colas.h"

int main(){
	int opc,dato,sec;
	int NumElem,destino;
	Cola* cola;
	//creamos la cola
	
	cola=CrearCola();
	
	//2.-procesos
	do{
		system("cls");
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
				puts("salir");
			break;
			default:
				puts("opcion no valida");
		}
		if(opc>0 &&opc<8)
			ImprimirCola(cola);
			
		system("pause");
		system("cls");	
		
	}while(opc!=8);
	
	
	
	//3.-destruir cola;
	DestruirCola(cola);
	
	return 0;
}
