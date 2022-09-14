/*
 trabajo integrador de AED2
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
void iniciarProceso();
void grabarProducto();
void finalizarProceso();
void ingresarDatosProducto();
void mostrarDatos();

/* Variables globales */
tRegProductos regProductos;
FILE * archUsuarios;

int main() {
	iniciarProceso();
	grabarProducto();
	finalizarProceso();
	//Hola Oscarsito
	//mostrarDatos();
	return 0;
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
	scanf("%.2f", &regProductos.precioUnitario);
}

void finalizarProceso() {
	fclose(archUsuarios);
	printf("Arhivo cerrado...\n");
}


//modificando el main y la forma de apertura del archivo, se puede visualizar el contenido del archivo binario
/*void mostrarDatos() {
	iniciarProceso();
	
	fread(&regProductos, sizeof(tRegProductos), 1, archUsuarios);
	while(!feof(archUsuarios)) {
		printf("%s\n", regProductos.descProducto);
		fread(&regProductos, sizeof(tRegProductos), 1, archUsuarios);
	}
	
	finalizarProceso();
}*/
	
	
