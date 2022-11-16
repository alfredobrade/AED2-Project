/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

//#include "Articulo.h"

//--declaracion de tipos de datos personalizados

//--prototipos de funciones
void abrirArticulosLectura();
void leerRegistroArticulos();
void abrirArticulosEscritura();
void grabarRegistroArticulos();
void recorrerArchivoArticulos();
void imprimirListaArticulos();
void cerrarArchivoArticulos();

//--declaracion de variables globales
/*
tArticulo rArticulo;
FILE * Articulos;
*/
//--**funcion principal**--


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
