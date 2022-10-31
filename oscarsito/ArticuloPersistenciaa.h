#include <stdio.h>


//--declaracion de tipos de datos personalizados
typedef char tString[50];

typedef struct Articulo{
	tString id_articulo;
	tString descripcion;
	int stock;
	int stockMin;
	float costo;
	float precio;
}tr_Articulo;

//--prototipos de funciones
void abrirArticulosLectura(tString pFileName);
void leerRegistroArticulos();
void abrirArticulosEscritura(tString pFileName);
void grabarRegistroArticulos();
void recorrerArchivoArticulos();
void imprimirListaArticulos();
void cerrarArchivoArticulos();

//--declaracion de variables globales
FILE * vf_Articulos;
tr_Articulo vr_Articulo;

//--**funcion principal**--


//--declaracion de funciones

void abrirArticulosLectura(tString pFileName){
	vf_Articulos = fopen("pFileName.dat", "rb");
	
}

void leerRegistroArticulos(){
	fread( &vr_Articulo, sizeof(tr_Articulo), 1, vf_Articulos );
}

void abrirArticulosEscritura(tString pFileName){
	vf_Articulos = fopen("pFileName.dat", "a+b");
}

void grabarRegistroArticulos(){
	fwrite( &vr_Articulo, sizeof( tr_Articulo ), 1, vf_Articulos );
}

void recorrerArchivoArticulos(){
	
	/*
	leerRegistro();
	while ( !feof(vf_Articulos) ) {
		
		if(condicion)  {
			printf("\n%d", vr_xxxx.dni, ....);
			contxxxxs ++;
		}
		
		leerRegistro();
	}
	
	*/
}

void imprimirListaArticulos(){
	
	leerRegistroArticulos();
	while ( ! feof(vf_Articulos) ) {
		
		printf("\n|%s\t|%s\t|%d\t|%d\t|%.2f\t|%.2f\t|", vr_Articulo.id_articulo, vr_Articulo.descripcion, vr_Articulo.stock, vr_Articulo.stockMin, vr_Articulo.costo, vr_Articulo.precio);
		
		
		leerRegistroArticulos();
	}
	
	
}



void cerrarArchivoArticulos(){
	fclose( vf_Articulos );
	
}
