/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// 	printf("\n");
/* Declaración de tipos de datos personalizados */
typedef char tString[25];

/* 
faltaria definir un tipo de dato para cada entidad e ir pasandole a una lista 
para poder guardar en los archivos
*/
typedef struct { 
	int codigo;
	tString descripcion;	
} tElem;

typedef struct nodo {
	tElem info;
	struct nodo * siguiente;
} tLista;

/* 	Declaración de prototipos de funciones 
	asociadas a las operaciones que se puede realizar 
	con la lista */
void inicializarLista( tLista ** );
bool listaVacia( tLista * );

void insertarPrimero( tElem, tLista ** );
void insertarAdelante( tElem, tLista ** );
void insertarElemento( tElem, tLista ** );

void eliminarPrimero( tLista ** );

void visualizarElementos( tLista * );

void insertarEnPos( int, tElem, tLista ** );

void eliminarEnPos( int, tLista ** );

int cantidadNodos( tLista * );

/* Declaración de variables globales*/
tLista * lista, * lista2;


/* Implementación de funciones */
void inicializarLista( tLista ** pLista ) {}
	*pLista = NULL;
	printf("Lista inicializada\n");
}

bool  listaVacia( tLista * pLista ) {}

void insertarPrimero( tElem pElem, tLista ** pLista ) {}

void insertarAdelante( tElem pElem, tLista ** pLista ) {}

void insertarElemento( tElem pElem, tLista ** pLista ) {}

void eliminarPrimero( tLista ** pLista ) {}

void visualizarElementos( tLista * pLista ) {}

void insertarEnPos( int pos, tElem nuevoDato, tLista ** pLista ) {}

void eliminarEnPos( int pos, tLista ** pLista ) {}

int cantidadNodos( tLista * pLista ) {}

