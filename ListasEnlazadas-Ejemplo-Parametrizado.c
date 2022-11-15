/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// 	printf("\n");
/* Declaración de tipos de datos personalizados */
typedef char tString[25];

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

/* Función principal */
int main() {	
	tElem data;
	
	inicializarLista( &lista );
	inicializarLista( &lista2 );
	
	
	data.codigo = 1000;
	strcpy(data.descripcion, "otro producto");	
	insertarElemento(data, &lista2 );
	
	
	printf("Esta vacia? %s\n", listaVacia(lista) == true ? "si" : "no" );
	
	data.codigo = 111;
	strcpy(data.descripcion, "Papas fritas");	
	insertarElemento(data, &lista );
	
	data.codigo = 222;
	strcpy(data.descripcion, "Hamburguesa");	
	insertarElemento(data, &lista);
	
	printf("Esta vacia? %s\n", listaVacia(lista) == true ? "si" : "no" );
	
	visualizarElementos(lista);
	
	/* eliminarPrimero(); */
	
	data.codigo = 333;
	strcpy(data.descripcion, "Milanesa");
	insertarElemento(data, &lista);
	
	data.codigo = 444;
	strcpy(data.descripcion, "Coca Cola");
	insertarElemento(data, &lista);
	visualizarElementos(lista);
	
	data.codigo = 555;
	strcpy(data.descripcion, "Alfajor");
	insertarEnPos(4, data, &lista);
	
	visualizarElementos(lista);
	
	data.codigo = 558;
	strcpy(data.descripcion, "Alikal");
	insertarEnPos(3, data, &lista);
	
	visualizarElementos(lista);
	
	eliminarEnPos(3, &lista);
	
	visualizarElementos(lista);
	
	eliminarEnPos(1, &lista);
	visualizarElementos(lista);
	
	visualizarElementos(lista2);
	
	return 0;
}

/* Implementación de funciones */
void inicializarLista( tLista ** pLista ) {	
	*pLista = NULL;
	printf("Lista inicializada\n");
}

bool  listaVacia( tLista * pLista ) {
	return ( pLista == NULL );
}

void insertarPrimero( tElem pElem, tLista ** pLista ) {
	/* 1. Se crea el nodo que se va a insertar */
	tLista * nuevoNodo;
	
	/* 2. Se asigna memoria al nodo */
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	
	/* 3. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->info = pElem;
	
	/* 4. Se indica que el primer nodo apunta a NULL */
	nuevoNodo->siguiente = NULL;
	
	/* 5. Se agrega el nodo a la lista la lista debe apuntar al nuevo nodo */
	*pLista = nuevoNodo;
	
	printf("Primer elemento insertado: %d-%s\n", pElem.codigo, pElem.descripcion);	
}

void insertarAdelante( tElem pElem, tLista ** pLista ) {
	/* 1. 	Se crea el nodo que se va a insertar */
	tLista * nuevoNodo;
	
	/* 2. 	Se asigna memoria al nodo */
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	
	/* 3. 	Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->info = pElem;
	
	/* 4. 	Como la inserción es por la parte de adelante de la lista, 
			se indica que al nuevo nodo le sigue el resto de la lista */
	nuevoNodo->siguiente = *pLista;
			
	/* 5. 	Como en el nuevo nodo quedó la lista completa, nos queda indicar que la lista que se recibe 
			como parámetro es igual a nuevo nodo */
	*pLista = nuevoNodo;
	
	printf("Elemento insertado: %d-%s\n", pElem.codigo, pElem.descripcion);	

}

void insertarElemento( tElem pElem, tLista ** pLista ) {
	if ( listaVacia( *pLista ) ) {
		insertarPrimero( pElem, &(*pLista) );
	}else {
		insertarAdelante( pElem, &(*pLista) );
	}		
}

void eliminarPrimero( tLista ** pLista ) {
	if ( listaVacia( *pLista ) ) {
		printf("No hay elementos para quitar!\n");
	} else {
		/* 1. Se guarda en una variable auxiliar el primer nodo de la lista */
		tLista * nodoSuprimir = *pLista;
	
		/* 2. Se avanza el puntero una vez, es decir se pasa al siguiente nodo de la lista */
		*pLista = (*pLista)->siguiente;
		
		printf("Primer elemento eliminado: %d-%s\n", nodoSuprimir->info.codigo, nodoSuprimir->info.descripcion );	
	
		/* 3. Se libera la memoria del nodo a suprimir que contenía el primer elemento de la lista */
		free(nodoSuprimir);
		
		/* 4. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
		nodoSuprimir = NULL;
	}
	
}

void visualizarElementos( tLista * pLista ) {
	tLista * aux;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		/* Hay elementos para mostrar */
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			printf("%d-%s\n", aux->info.codigo, aux->info.descripcion);
			aux = aux->siguiente;
		}
		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
}

void insertarEnPos( int pos, tElem nuevoDato, tLista ** pLista ) {
	int i;
	tLista * aux, * nuevoNodo;
	
	/* 1.Se debe utilizar una lista auxiliar aux */
	aux = *pLista;
	
	/* 2. Utilizar un bucle para avanzar aux hasta el nodo que se encuentra en pos-1 */
	for(i=1; i<pos-1; i++ ) {
		aux = aux->siguiente;
	}
	
	/* 3. Reservar memoria para el nodo a insertar */
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	
	/* 4. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->info = nuevoDato;

	/* 5. Se actualizan los punteros */
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
	
	printf("Elemento insertado: %d-%s\n", nuevoDato.codigo, nuevoDato.descripcion);	
}

void eliminarEnPos( int pos, tLista ** pLista ) {
	int i, cantNodos;
	tLista * aux, * nodoSuprimir;
	
	/* 0. Validar posición */
	cantNodos = cantidadNodos( *pLista );
	
	if( pos <= cantNodos && pos > 0 ) {
		
		if( pos == 1 ) {
			eliminarPrimero( &lista );
		} else {
			/* 1. Se debe utilizar una lista auxiliar aux */
			aux = *pLista;
			
			/* 2. Utilizar un bucle para avanzar aux hasta el nodo que se encuentra en pos-1 */
			for(i=1; i<pos-1; i++ ) {
				aux = aux->siguiente;
			}
			
			/* 3. Se resguarda el nodo que se va a suprimir en una variable auxiliar */
			nodoSuprimir = aux->siguiente;
		
			/* 4. Se indica a qué nodo tiene que apuntar aux: al siguiente del que se va a eliminar */
			aux->siguiente = nodoSuprimir->siguiente;
			
			printf("Elemento eliminado: %d-%s\n", nodoSuprimir->info.codigo, nodoSuprimir->info.descripcion );	
				
			/* 5. Se libera la memoria del nodo a suprimir que contenía el elemento de la posición pos de la lista */
			free(nodoSuprimir);
				
			/* 6. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
			nodoSuprimir = NULL;
		}	
	} else {
		printf("\nPosicion invalida\n");
	}	
}

int cantidadNodos( tLista * pLista ) {
	tLista * aux;
	int contador = 0;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		while(aux != NULL) {
			contador++;
			aux = aux->siguiente;
		}		
	}
	return contador;
}

