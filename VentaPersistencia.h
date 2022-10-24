/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

//--declaracion de tipos de datos personalizados

//--prototipos de funciones
void abrirVentasLectura();
void leerRegistroVenta();
void abrirVentasEscritura();
void grabarRegistroVenta();
void recorrerArchivoVentas();
void cerrarArchivoVentas();



//--declaracion de variables globales

//--**funcion principal**--


//--declaracion de funciones
void abrirVentasLectura(){
	//vf_xxxxs = fopen("Ventas.dat", "rb");
	
	
}
void leerRegistroVentas(){
	//fread( &vr_xxxx, sizeof(tr_xxxx), 1, vf_xxxxs );
}
void abrirVentasEscritura(){
	//vf_xxxxs = fopen("xxxx.dat", "wb");
}
void grabarRegistroVentas(){
	//fwrite( &vr_xxxx, sizeof( tr_xxxx ), 1, vf_xxxxs );
}
void recorrerArchivoVentas(){
	//leerRegistro();
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

void cerrarArchivoVentas(){
	//fclose( vf_xxxxs );
	//printf("\n\nCantidad de xxxxs registrados: %d\n", contxxxxs);
}
