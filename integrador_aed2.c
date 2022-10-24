/*
 trabajo integrador de AED2
 Sistema de control de stock _ StockearX
 El sistema constara de un modulo principal dedicado a la gestion de compras y ventas
 con este modulo se agregaran y quitaran unidades del campo Stock
 Además, tendrá¡ un módulo accesorio dedicado al calculo del stock mÃ­nimo.
 
 aa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ListasEnlazadas.h"

#include "Venta.h"
#include "VentaPersistencia.h"
#include "Articulo.h"
#include "ArticuloPersistencia.h"




/* Tipos de datos personalizados */
typedef char String[255];
/*
typedef struct Articulo{
	String id_articulo;
	String descripcion;
	int stock;
	int stockMin;
	float costo;
	float precio;
}tArticulo;



/* Prototipos */
void menu();
void iniciarProceso();
void grabarProducto();
void finalizarProceso();
void ingresarDatosProducto();
void mostrarDatos();

// funciones de archivos


/* Variables globales */

/*
tArticulo rArticulo;
FILE * archUsuarios;
*/


int main() {
		menu();
	
	
	return 0;
}



void menu(){
	int opcion;
	printf("\t***Menu Inicial***\n");
	printf("\n1 - Cargar Datos de Stock\n2 - Ver Stock\n3 - Ventas\n4 - Imprimir Ticket\n0 - Salir\n\n");
	scanf("%d", &opcion);
	
	switch(opcion){
	case 1: 
		break;
	case 2: 
			
		break;
	case 3:
		break;
	case 4:
		break;
	}	

}


