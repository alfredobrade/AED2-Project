/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

#include "Articulo.h"

//--declaracion de tipos de datos personalizados


//--declaracion de variables globales
tArticulo rArticulo;
FILE * Articulos;

//--declaracion de prototipos de funciones
void cargarArticulo();

//-*-* funcion principal *-*-
int main() {
	//cargarArticulo();
	
	leerRegistroArticulos();
	printf("art %s %s %.2f", rArticulo.id_articulo , rArticulo.descripcion , rArticulo.precio);

	return 0;
}


//--implementacion de funciones
void cargarArticulo(){
	abrirArticulosEscritura();
	strcpy(rArticulo.id_articulo,"001");
	strcpy(rArticulo.descripcion, "primero");
	rArticulo.costo = 100;
	rArticulo.precio = 150;
	grabarRegistroArticulos();
	
	
}


