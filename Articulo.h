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

//--declaracion de variables globales

tArticulo rArticulo;
FILE * Articulos;

//--**funcion principal**--



//--declaracion de funciones

