/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

//--declaracion de tipos de datos personalizados

//--prototipos de funciones
void abrirLectura();
void leerRegistro();
void abrirEscritura();
void grabarRegistro();
void recorrerArchivo();
void cerrarArchivo();

//--declaracion de variables globales

//--**funcion principal**--


//--declaracion de funciones
void abrirLectura(){
	vf_xxxxs = fopen("xxxxs.dat", "rb");
	
}
void leerRegistro(){
	fread( &vr_xxxx, sizeof(tr_xxxx), 1, vf_xxxxs );
}
void abrirEscritura(){
	vf_xxxxs = fopen("xxxx.dat", "wb");
}
void grabarRegistro(){
	fwrite( &vr_xxxx, sizeof( tr_xxxx ), 1, vf_xxxxs );
}
void recorrerArchivo(){
	leerRegistro();
	while ( ! feof(vf_xxxxs) ) {
		/*
		if(condicion)  {
			printf("\n%d", vr_xxxx.dni, ....);
			contxxxxs ++;
		}
		*/
		leerRegistro();
	}
}

void cerrarArchivo(){
	fclose( vf_xxxxs );
	printf("\n\nCantidad de xxxxs registrados: %d\n", contxxxxs);
}
