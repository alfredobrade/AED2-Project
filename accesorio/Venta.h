/*
Entidad venta
*/

#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

//#include "VentaPersistencia.h"
#include "VentaArticuloPersistencia.h"
//#include "ArticuloPersistencia.h"



//--declaracion de tipos de datos personalizados
typedef char String[255];

// este es el tipo de Articulo que va en el array
typedef struct {
	String id_Articulo;
	int cantidad;
}ItemListaArticulos;

typedef ItemListaArticulos ListaArticulos[20]; //esto debe ser una lista o vector

typedef struct Venta{
	//int id_Venta
	String fecha;
	//tring id_Cliente
	//ListaArticulos id_Articulo; //esto lo sacamos de aca 
	/* sacamos la lista de articulos puesto que aca solo cargamos el costo y monto total
	y usamos la lista para cargar en la tabla intermedia VentaArticulo */
	float costo;
	float monto;
}tVenta;


//--prototipos de funciones
void ingresarVenta();
void guardarVenta();
//tArticulo buscarArticulo(String);

void ingresarFecha(); //no me deja retornar un string - la prof me dijo que puedo hacer con puntero a char
void cargarArticulos();
void ElegirArticuloLista(int); //busca el articulo por su posicion en una lista
void listarArticulos();


//--prototipos de funciones de persistencia
void abrirVentasLectura();
void leerRegistroVenta();
void abrirVentasEscritura();
void grabarRegistroVenta();
void recorrerArchivoVentas();
void cerrarArchivoVentas();


//--declaracion de variables globales

tVenta Venta;
FILE * Ventas;

String fecha;

//--**funcion principal**--



//--declaracion de funciones

void menu(){
	/*
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
	*/
}

//despliega un menu de ingreso de articulos y los almacena en db
void ingresarVenta(){
	abrirVentasLectura();
	//buscar el ultimo ID para ingresar uno nuevo
	//Venta.fecha = ingresarFecha(); //llevará strcat?
	cargarArticulos();
	
	
	
	
}

void ingresarFecha(){ //hay una funcion cTime que podemos usar

	String aux;
	printf("ingrese día");
	scanf("%s",&fecha);
	printf("ingrese mes");
	scanf("%s",&aux);
	strcat(fecha,aux);
	printf("ingrese año");
	scanf("%s",&aux);
	strcat(fecha,aux);
	
}

void cargarArticulos(){
	//primero imprimimos una lista para elegir que articulo agregar
	imprimirListaArticulos();
	int opcion = 1;
	int i = 0;
	while (opcion == 1){
		//
		elegirArticuloLista(i);
		
		pritf("Elegir otro articulo?");
		scanf("%d",&opcion);
		
	}
}

//busca el articulo por su posicion en una lista
void elegirArticuloLista(int i){
	printf("ingrese un Articulo por su id\n");
	scanf("%s",ListaArticulos.id_Articulo[i]);
	
}

void listarArticulos(){
	abrirArticulosLectura();
	imprimirListaArticulos();
}


/* retorna el articulo buscado para extraer stock, costo y precio -
se podria hacer metodos donde traiga directamente esos datos
tArticulo buscarArticulo(String idArticulo){
	
	
	return tArticulo;
}
*/


//--declaracion de funciones de persistencia
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

