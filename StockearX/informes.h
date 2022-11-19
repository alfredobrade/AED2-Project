/*
Este HeaderFile se creo con el fin de presentar un 
informe con la utilizacion de corte de control, a partir de un archivo
binario precargado con datos de ventas de articulos.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define TITULO1 "\n*** INFORME DE ARTICULOS ***\n"

typedef char tString [20];

 typedef struct {
    int idCategoria;
    tString  descripcion;
    float precio;
    tString mes;
    int dia;
}tr_articulos;


void ejecutarCorteControl();
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unGrupo();
void finCorte();

tr_articulos articulo, articuloAnterior;
int totalVendidos, totalVendidosCategoria;
float totalMontoVendido, subTotalCategoria;
FILE*articulos;



void ejecutarCorteControl(){
	inicializacion();	
	procesoCorte();		
	finalizacion();
	
}


void inicializacion() {

	articulos = fopen("Articulos.dat", "rb");	
	
	if(articulos != NULL ) {
		fread(&articulo, sizeof(tr_articulos), 1, articulos);	
	} else {
		printf("No se encuentra el archivo!\n");
		exit(EXIT_FAILURE);
	}
	
	articuloAnterior = articulo;
	totalVendidos = 0;
	totalMontoVendido=0;
	
	printf("%s", TITULO1);
	
	printf("CATEGORIA\t | ARTICULO	|	MONTO TOTAL\n");
}
void procesoCorte() {
	while (!feof(articulos)) { 
	
		principioCorte(); 
		
	    while(!feof(articulos) && articulo.idCategoria == articuloAnterior.idCategoria) { 
			unGrupo();
			fread(&articulo, sizeof(tr_articulos), 1, articulos);					
		} 
		
		finCorte();
	}
}

void principioCorte() {
			
			subTotalCategoria=0;
			totalVendidosCategoria=0;
}
void unGrupo() {

	printf("%d\t | %s			%2.f\n", 
			articulo.idCategoria , 
			articulo.descripcion,
			articulo.precio);
			
			totalVendidosCategoria++;		

			subTotalCategoria=subTotalCategoria+articulo.precio;
}

void finCorte(){      		
	 			printf("\n");
	printf("---------------------------------------------\n");
	printf("MONTO TOTAL DE VENTA POR CATEGORIA: %2.f\n", subTotalCategoria);
	printf("CANTIDAD DE VENTAS POR CATEGORIA: %d\n", totalVendidosCategoria);
	printf("---------------------------------------------\n");
		 		printf("\n");


	totalMontoVendido = totalMontoVendido + subTotalCategoria;
	totalVendidos=totalVendidos+totalVendidosCategoria;
	
	articuloAnterior = articulo;
}

void finalizacion(){
	
	printf("---------------------------------------------\n");
	printf("Total de articulos vendidos: %d\n", totalVendidos);
	printf("Monto total de venta: %2.f\n", totalMontoVendido);
	printf("---------------------------------------------\n");
	
	fclose(articulos);
}
