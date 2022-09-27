/*
 trabajo integrador de AED2
 Sistema de control de stock _ StockearX
 El sistema constara de un modulo principal dedicado a la gestion de compras y ventas
 con este modulo se agregaran y quitaran unidades del campo Stock
 Además, tendrá un módulo accesorio dedicado al calculo del stock mínimo.
 
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Tipos de datos personalizados */
typedef char tString[25];

typedef struct {
	tString tipoProducto;
	tString descProducto;
	int codProducto;
	int stockActual;
	int stockMinimo;
	float precioUnitario;
}tRegProductos;

/* Prototipos */
void menu();
void iniciarProceso();
void grabarProducto();
void finalizarProceso();
void ingresarDatosProducto();
void mostrarDatos();

/* Variables globales */
tRegProductos regProductos;
FILE * archUsuarios;

int main() {
		menu();
	
	
	return 0;
}



void menu(){
	int opcion;
	printf("\t***Menu Inicial***\n");
	printf("\n1 - Cargar Datos de Stock\n2 - Ver Stock\n3 - Ventas\n4 - Imprimir Ticket\n0 - Salir\n\n");
	scanf("%d", &opcion);
	//martina
	switch(opcion){
	case 1: iniciarProceso();
			grabarProducto();
			finalizarProceso();
			menu();
		break;
	case 2: mostrarDatos();
			menu();
		break;
	case 3:
		break;
	case 4:
		break;
	}	

}







void iniciarProceso() {
	archUsuarios = fopen("stock.dat", "wb");
	if(archUsuarios != NULL) {
		printf("Archivo abierto para escribir ...\n");
	} else {
		printf("Error al crear el archivo!\n");
		exit( EXIT_FAILURE );
	}
}

void grabarProducto() {
	char opcion = 0;
	printf("*** Alta de productos ***\n");
	
	printf("Desea ingresar un producto?");
	fflush(stdin);
	scanf("%c", &opcion);
	
	while (opcion != 'n' && opcion != 'N'){
		ingresarDatosProducto();
		fwrite(&regProductos, sizeof(tRegProductos), 1, archUsuarios);
		
		printf("\nDesea ingresar un producto?");
		fflush(stdin);
		scanf("%c", &opcion);
	}
	
}

void ingresarDatosProducto() {
	printf("\nTipo de Producto: ");	
	fflush(stdin);
	scanf("%[^\n]s", &regProductos.tipoProducto);
	
	printf("Descripcion: ");	
	fflush(stdin);
	scanf("%[^\n]s", &regProductos.descProducto);
	
	printf("Codigo de Producto: ");	
	scanf("%d", &regProductos.codProducto);
	
	printf("Stock Actual: ");	
	scanf("%d", &regProductos.stockActual);
	
	printf("Stock Minimo para el mes: ");	
	scanf("%d", &regProductos.stockMinimo);
	
	printf("Precio unitario:$ ");	
	scanf("%f", &regProductos.precioUnitario);
}

void finalizarProceso() {
	fclose(archUsuarios);
	printf("Arhivo cerrado...\n\n");
}


//modificando el main y la forma de apertura del archivo, se puede visualizar el contenido del archivo binario
void mostrarDatos() {
	archUsuarios = fopen("stock.dat", "rb");
	if(archUsuarios != NULL) {
		fread(&regProductos, sizeof(tRegProductos), 1, archUsuarios);
		printf("\t***Control de Stock***\n");
		while(!feof(archUsuarios)) {
			printf("%s: %s\t||", regProductos.tipoProducto, regProductos.descProducto);
			printf("Codigo de producto: %d||", regProductos.codProducto);
			printf("Cantidad Actual: %d||", regProductos.stockActual);
			printf("Cantidad Minima necesaria por mes: %d||", regProductos.stockMinimo);
			printf("Precio unitario:$ %.2f||\n", regProductos.precioUnitario);
			fread(&regProductos, sizeof(tRegProductos), 1, archUsuarios);
		}
	} else {
		printf("Error al abrir el archivo!\n");
		exit( EXIT_FAILURE );
	}
	
	finalizarProceso();
}
	
	
