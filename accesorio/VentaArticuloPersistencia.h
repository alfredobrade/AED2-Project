/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

//--declaracion de tipos de datos personalizados

//--prototipos de funciones

void abrirVentaArticuloLectura();
void leerRegistroVentaArticulo();
void abrirVentaArticuloEscritura();
void grabarRegistroVentaArticulo();
void recorrerArchivoVentaArticulo();
void cerrarArchivoVentaArticulo();



//--declaracion de variables globales

//--**funcion principal**--


//--declaracion de funciones
void abrirVentaArticuloLectura(){
	//vf_xxxxs = fopen("Ventas.dat", "rb");
	
	
}
void leerRegistroVentaArticulo(){
	//fread( &vr_xxxx, sizeof(tr_xxxx), 1, vf_xxxxs );
}
void abrirVentaArticuloEscritura(){
	//vf_xxxxs = fopen("xxxx.dat", "wb");
}
void grabarRegistroVentaArticulo(){
	//fwrite( &vr_xxxx, sizeof( tr_xxxx ), 1, vf_xxxxs );
}
void recorrerArchivoVentaArticulo(){
	leerRegistro();
	//while ( ! feof(vf_xxxxs) ) {
		/*
		if(condicion)  {
			printf("\n%d", vr_xxxx.dni, ....);
			contxxxxs ++;
		}
		*/
		//leerRegistro();
	//}
}

void cerrarArchivoVentaArticulo(){
	//fclose( vf_xxxxs );
	//printf("\n\nCantidad de xxxxs registrados: %d\n", contxxxxs);
}


//--declaracion de variables globales

//--**funcion principal**--


//--declaracion de funciones

