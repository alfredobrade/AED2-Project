/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

//#include "ArticuloPersistencia.h"

//--declaracion de tipos de datos personalizados
typedef char String[255];

typedef struct Articulo{
	String id_articulo;
	String descripcion;
	//int stock;
	//int stockMin;
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

//persistencia
void CrarArchivoArticulos();
void abrirArticulosLectura();
void leerRegistroArticulos();
void abrirArticulosAdd();
void grabarRegistroArticulos();
void recorrerArchivoArticulos();
void imprimirListaArticulos();
void cerrarArchivoArticulos();



//--declaracion de variables globales
tArticulo rArticulo;
FILE * Articulos;


//--**funcion principal**--


//--declaracion de funciones de persistencia
void CrarArchivoArticulos(){
	Articulos = fopen("Articulos.dat", "wb");
}

void abrirArticulosLectura(){
	Articulos = fopen("Articulos.dat", "rb");
	
}
void leerRegistroArticulos(){
	fread( &rArticulo, sizeof(tArticulo), 1, Articulos );
}
void abrirArticulosAdd(){
	Articulos = fopen("Articulos.dat", "ab");
}
void grabarRegistroArticulos(){
	fwrite( &rArticulo, sizeof( tArticulo ), 1, Articulos );
}

void cerrarArchivoArticulos(){
	fclose( Articulos );
	
}


//--declaracion de funciones
void imprimirListaArticulos(){
	//String artBuscado; 
	
	leerRegistroArticulos();
	while ( !feof(Articulos) ) {
		
		printf("\n %s	| %s	|  %2.f	\n", rArticulo.id_articulo, rArticulo.descripcion, rArticulo.precio);
		
		
		leerRegistroArticulos();
	}
	
	printf("Ingrese ID del producto que desea");
	//scanf("%s", &artBuscado); 
	
	//busquedaId(artBuscado);
}

void busquedaId (String pIdBuscado){
	float acumCosto, acumPrecio;	//estas variables la declare local, pero deben ser globales
	
	leerRegistroArticulos();

	while ( ! feof(Articulos) ){
		if(	pIdBuscado  == rArticulo.id_articulo ){
			
			acumCosto = acumCosto + rArticulo.costo;
			acumPrecio = acumPrecio + rArticulo.precio;
		}
	
		leerRegistroArticulos();

	}
}
