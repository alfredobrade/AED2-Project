/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

//--declaracion de tipos de datos personalizados
typedef char String[255];

typedef struct Articulo{
	String id_articulo;
	String descripcion;
	int stock;
	int stockMin;
	float costo;
	float precio;
}tArticulo;

//--prototipos de funciones

void sumarStock(String, int);
void restarStock(String, int);
int consultarStock(String);
int consultarStockMin(String);
void imprimirListaArticulos();
void busquedaId (String);

//--declaracion de variables globales

tArticulo rArticulo;
FILE * Articulos;

//--**funcion principal**--



//--declaracion de funciones
void imprimirListaArticulos(){
	String artBuscado; 
	
	leerRegistro();
	while ( ! feof(articulos) ) {
		
		printf("\n %s	| %s	|  %2.f	\n", articulo.id_articulo, articulo.descripcion, articulo.precio);
		
		
		leerRegistro();
	}
	
	printf("Ingrese ID del producto que desea");
	scanf("%s", &artBuscado); 
	
	busquedaId(artBuscado);
}

void busquedaId (String pIdBuscado){
	float acumCosto, acumPrecio;	//estas variables la declare local, pero deben ser globales
	
	leerRegistro();

	while ( ! feof(articulos) ){
		if(	pIdBuscado  == articulo.id_articulo ){
			
			acumCosto=acumCosto+articulo.costo;
			acumPrecio=acumPrecio+articulo.precio;
		}
	
		leerRegistro();

	}
}
