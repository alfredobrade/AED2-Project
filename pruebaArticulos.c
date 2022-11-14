/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

#include "Articulo.h"

//--declaracion de tipos de datos personalizados


//--declaracion de variables globales
/*
tArticulo rArticulo;
FILE * Articulos;
*/
//--declaracion de prototipos de funciones
void cargarArticulo();
/*
//--declaracion de tipos de datos personalizados
typedef char tString[255];

typedef struct Articulo{
	tString id_articulo;
	tString descripcion;
	//int stock;
	//int stockMin;
	float costo;
	float precio;
}tArticulo;

//--prototipos de funciones

void sumarStock(tString, int);
void restarStock(tString, int);
int consultarStock(tString);
int consultarStockMin(tString);
void imprimirListaArticulos();
void busquedaId (tString);

//persistencia
void abrirArticulosLectura();
void leerRegistroArticulos();
void abrirArticulosEscritura();
void grabarRegistroArticulos();
void recorrerArchivoArticulos();
void imprimirListaArticulos();
void cerrarArchivoArticulos();



//--declaracion de variables globales
tArticulo rArticulo;
FILE * Articulos;


*/







//-*-* funcion principal *-*-
int main() {
	/*
	abrirArticulosEscritura();
	cargarArticulo();
	cargarArticulo();
	cargarArticulo();
	cargarArticulo();
	
	cerrarArchivoArticulos();
	*/
	abrirArticulosLectura();
	imprimirListaArticulos();
	cerrarArchivoArticulos();
	//leerRegistroArticulos();
	//printf("art %s %s %.2f", rArticulo.id_articulo , rArticulo.descripcion , rArticulo.precio);

	return 0;
}


//--implementacion de funciones
void cargarArticulo(){
	//abrirArticulosEscritura();
	strcpy(rArticulo.id_articulo,"001");
	strcpy(rArticulo.descripcion, "primero");
	rArticulo.costo = 100;
	rArticulo.precio = 150;
	grabarRegistroArticulos();
	
	
	
}


/*
//--declaracion de funciones de persistencia
void abrirArticulosLectura(){
	Articulos = fopen("Articulos.dat", "rb");
	
}
void leerRegistroArticulos(){
	fread( &rArticulo, sizeof(tArticulo), 1, Articulos );
}
void abrirArticulosEscritura(){
	Articulos = fopen("Articulos.dat", "wb");
}
void grabarRegistroArticulos(){
	fwrite( &rArticulo, sizeof( tArticulo ), 1, Articulos );
}

void cerrarArchivoArticulos(){
	fclose( Articulos );
	
}


//--declaracion de funciones
void imprimirListaArticulos(){
	//tString artBuscado; 
	
	leerRegistroArticulos();
	while ( !feof(Articulos) ) {
		
		printf("\n %s	| %s	|  %2.f	\n", rArticulo.id_articulo, rArticulo.descripcion, rArticulo.precio);
		
		
		leerRegistroArticulos();
	}
	
	printf("Ingrese ID del producto que desea");
	//scanf("%s", &artBuscado); 
	
	//busquedaId(artBuscado);
}

void busquedaId (tString pIdBuscado){
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
*/
