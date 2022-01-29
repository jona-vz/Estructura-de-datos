#include <stdio.h>
#include <string.h>
typedef struct books{
	char titulo[30];
	char tema[20];
	int id;
}books;

void imprimir(books *book){
	printf("titulo:%s\n",book->titulo);
	printf("tema:%s\n",book->tema);
	printf("id:%i\n",book->id);
}
int main(){
	books libro1;
	books libro2;

	strcpy(libro1.titulo,"progrmacion basica");
	strcpy(libro1.tema,"programacion");
	libro1.id=100;
	
	strcpy(libro2.titulo,"progrmacion avanzada");
	strcpy(libro2.tema,"programacion");
	libro2.id=200;
	
	
	imprimir(&libro1);
	printf("\n\n");
	imprimir(&libro2);	
}
