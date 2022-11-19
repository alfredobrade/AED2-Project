#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// este headerFile llama a un TAD donde se aplica corte de control
#include "informes.h"

typedef char tString [20];

 

typedef struct nodo{
	tr_articulos articulos;
	struct nodo*siguiente;
}tLista;

void iniciarArchivo();
void inicializarLista();
bool listaVacia(tLista*);
void procesarDatos();
void pregunta(char);
void menu();
void insertarVenta ();
void insertarPrimero();
void insertarAdelante();
void grabarDatos(tr_articulos);
void eliminarAdelante();
void visualizar(tLista*);
void finalizarRegistro();


tLista *listaVentas;
int respuestaInt;
char respuestaChar;
tr_articulos vr_articulos;
FILE*vf_registroArticulos;

int main(){
	inicializarLista();
   iniciarArchivo();
   printf("Desea realizar alguna accion? (S/N) \n");
	fflush(stdin);
	scanf("%c", &respuestaChar);
   	pregunta(respuestaChar);
    finalizarRegistro();

	
}
void inicializarLista(){					//inicializacion de la lista enlazada
	listaVentas = NULL;
	printf("lista inicializada!\n");
}
bool listaVacia(tLista * pLista){
	return pLista == NULL;
}
void iniciarArchivo(){										//se realiza la apertura del archivo para su posterior introduccion de los datos ingresados
    vf_registroArticulos=fopen("ventas.dat", "wb");
    if(vf_registroArticulos!=NULL){
        printf("El regisro ha sido encontrado!\n");
    }else{
        printf("OCURRIO UN ERROR!\n");
        finalizarRegistro();
    }
}


void pregunta(char pRespuesta){
  
	if(pRespuesta == 'S' || pRespuesta =='s'){
		
	printf("Que desea realizar? 1-Ingresar elemento//2-Visualizar elementos//3-Eliminar un elemento// 4-Iimprimir informe de ventas");
	fflush(stdin);
	scanf("%d", &respuestaInt);
	
	 menu();
	 
	 printf("Desea realizar alguna accion? (S/N) \n");
	fflush(stdin);
	scanf("%c", &pRespuesta);
	
 	pregunta(pRespuesta);															//se aplica recurvididad al volver a llamar la funcion "pregunta();"

	}else{
			printf("GRACIAS POR USAR NUESTRO SERVICIO!\n");

	}

}

void menu(){
													//menu con todas las opciones disponibles al a eleccion del usuario
	
	switch (respuestaInt){
		
		case 1: insertarVenta( );
		break;
		
		case 2:visualizar(listaVentas);
		break;
			
		case 3: eliminarAdelante();
		break;
			
		case 4: ejecutarCorteControl();				//esta funcion se encuentra dentro del TDA "corteControl.h",que a su vez, como su nombre lo indica, ejecuta el codigo de corte de Control
		break;										//obteniendo asi un informe de la cantidad de ventas de cada categoria de producto, el total general, el subtotal y los montos

	}

}


void insertarVenta ( ){							//funcion propia de la lista enlazada donde dependiendo del estado actual de la lista
	if (listaVacia(listaVentas)){				//es donde se ubicaran los datos ingresados por teclado
		insertarPrimero();
	}else{
		insertarAdelante();
	}
}
void insertarPrimero (){						//Insercaion caso de que la lista se encuentre vacia
	
	tLista * nuevoNodo;
		
	nuevoNodo = (tLista*)malloc(sizeof(tLista));
	
    printf("\nIngrese ID del producto (1-SANITARIOS// 2- BULONERIA//3-HERRAMIENTAS EN GRAL): \n");
	fflush(stdin);
	scanf("%d", &nuevoNodo->articulos.idCategoria);
	
     printf("Ingrese descripcion del mismo: \n");
	fflush(stdin);
	scanf("%s", &nuevoNodo->articulos.descripcion);
	
     printf("Ingrese precio de venta: \n");
	fflush(stdin);
	scanf("%f", &nuevoNodo->articulos.precio);
	
		
	printf("Ingrese mes de venta: \n");
	fflush(stdin);
	scanf("%s", &nuevoNodo->articulos.mes);


    printf("Ingrese dia de venta: \n");
	fflush(stdin);
	scanf("%d", &nuevoNodo->articulos.dia);

		
	
	
	nuevoNodo->siguiente=NULL;
	
	listaVentas=nuevoNodo;
	
	vr_articulos = listaVentas->articulos;
	
	grabarDatos(vr_articulos);

	printf("ARTICULO INGRESADO!");
	
}
void insertarAdelante(){						//insercion caso de que la lista ya cuente con algun dato previo
	
	tLista * nuevoNodo;
	
	nuevoNodo=(tLista*)malloc(sizeof(tLista));
	
	
	printf("\nIngrese ID del producto (1-SANITARIOS// 2- BULONERIA//3-HERRAMIENTAS EN GRAL): \n");
	fflush(stdin);
	scanf("%d", &nuevoNodo->articulos.idCategoria);
	
     printf("Ingrese descripcion del mismo: \n");
	fflush(stdin);
	scanf("%s", &nuevoNodo->articulos.descripcion);
	
     printf("Ingrese precio de venta: \n");
	fflush(stdin);
	scanf("%f", &nuevoNodo->articulos.precio);
	
		
	printf("Ingrese mes de venta: \n");
	fflush(stdin);
	scanf("%s", &nuevoNodo->articulos.mes);


    printf("Ingrese dia de venta: \n");
	fflush(stdin);
	scanf("%d", &nuevoNodo->articulos.dia);	
		
		
	
	nuevoNodo->siguiente=nuevoNodo;
	
	listaVentas=nuevoNodo;
	
	vr_articulos = listaVentas->articulos;
	
	grabarDatos(vr_articulos);
		printf("ARTICULO INGRESADO!");

	
}

void grabarDatos(tr_articulos vr_articulos){							//funcion que almacena los daots ingresados al archibo binario
    fwrite(&vr_articulos, sizeof(tr_articulos), 1, vf_registroArticulos);
    printf("Registro ingresado con exito!\n");
}

void eliminarAdelante(){									//eliminacion dato
	tLista * nodoSuprimir=listaVentas;
	
	listaVentas=listaVentas->siguiente;
	printf("El nodo ha sido eliminado!\n");
	free(nodoSuprimir);
	nodoSuprimir=NULL;
}
void visualizar(tLista * pLista){							//Imprime los datos que fueron ingresados e incluidos en la lista por le usuario
	tLista* aux;
	aux=pLista;
	printf("CATEGORIA \t \tDESCRIPCION \tPRECIO \t \t MES \t\t DIA\n");
	printf("----------------------------------------------------------------------------------------------\n");

	if (!listaVacia(aux)){
		
		while (aux != NULL){
			printf("%d \t\t 	%s \t $%.2f \t %s \t\t %d\n", aux->articulos.idCategoria , aux->articulos.descripcion,aux->articulos.precio, aux->articulos.mes, aux->articulos.dia );
	
			aux = aux->siguiente;
		}
	}else{
		printf("NO HAY ELEMENTOS PARA MOSTRAR!\n");
	}
	
}

void finalizarRegistro(){					//finaliza con el cierre del archivo binario
    fclose(vf_registroArticulos);
}
