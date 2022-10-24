/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

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

//--**funcion principal**--


//--declaracion de funciones
void abrirArticulosLectura(){
	//vf_xxxxs = fopen("xxxxs.dat", "rb");
	
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



void cerrarArchivoArticulos(){
	//fclose( vf_xxxxs );
	
}
