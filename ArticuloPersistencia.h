/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

#include "Articulo.h"

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

tArticulo rArticulo;
FILE * Articulos;

//--**funcion principal**--


//--declaracion de funciones
void abrirArticulosLectura(){
	//Articulos = fopen("Articulos.dat", "rb");
	
}
void leerRegistroArticulos(){
	//fread( &vr_xxxx, sizeof(tr_xxxx), 1, vf_xxxxs );
}
void abrirArticulosEscritura(){
	//vf_xxxxs = fopen("xxxx.dat", "wb");
}
void grabarRegistroArticulos(){
	//fwrite( &vr_xxxx, sizeof( tr_xxxx ), 1, vf_xxxxs );
}
void recorrerArchivoArticulos(){
	
	/*
	leerRegistro();
	while ( ! feof(vf_xxxxs) ) {
		
		if(condicion)  {
			printf("\n%d", vr_xxxx.dni, ....);
			contxxxxs ++;
		}
		
		leerRegistro();
	}
	
	*/
}

void imprimirListaArticulos(){
	/*
	leerRegistro();
	while ( ! feof(vf_xxxxs) ) {
		
		printf("\n%d", vr_xxxx.dni, ....);
		
		
		leerRegistro();
	}
	
	*/
}

//buscar por ID (pId){
//Articulo.id == pId


void cerrarArchivoArticulos(){
	//fclose( vf_xxxxs );
	
}
