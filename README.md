# AED2-Project

APLICACION EN CARPETA "STOCKEARX"

Carrera: Lic. En Sistemas de Informacion
Materia: Algoritmos y Estructuras de Datos II.
Profesor: Ana Company
Grupo: B - Turno noche

"Software de registro e informe de ventas para comercio (Ferretería)"

Etapa 1.
a. En esta etapa, una vez que decidimos sobre qué tema trataría el trabajo integrador, nos juntamos a debatir sobre las formas de solución del problema.
En nuestro caso elegimos un sistema que registre las ventas de un local comercial (ferretería), que vaya generando un archivo donde quede registrado, incluya los datos, lo elimine en caso de que la compra sea cancelada y realice una lista de todo lo que se incluyó en ella. Obviamente, aplicando los temas dados durante todo el cuatrimestre y realizando las modificaciones necesarias para ir adaptándolo a medida que se avanzaba con la materia.

b. En esta etapa se generó el archivo binario donde quedaba registrado las compras que eran realizadas por el cliente incluyendo todas aquellas funciones para su producción.
Tales como:
* iniciarArchivo(); // Función que inicializa el archivo en el cual se realiza la apertura para su escritura binaria.
*pregunta();         // Función que realiza una pregunta al usuario de que es lo que desea hacer en el momento.
*procesarDatos();   //Junto con las funciones siguientes, ejecuta las tareas para el ingreso de datos al archivo binario, reservando la memoria necesaria para ello.
*ingresarDatos();
*grabarDatos();
*finalizarRegistro();    //Esta función se ejecuta cuando el usuario indica que ya no desea continuar con el ingreso de datos pro teclado, produciendo así el cierre del archivo e imprimiendo un mensaje de despedida, finalizando así con la ejecución del programa.
Etapa 2.
a. Siguiendo con las indicaciones de la catedra, se realizaron los ajustes necesarios para incorporar mediante una lista estática los datos que se iban ingresados.
b. Las funciones mediante las cuales se valió el programa para que el usuario pueda verificar los datos grabados son:
*Función para recorrer la lista y mostrar los datos:
void imprimirVentas(tVector pVentas){
	int i;
	printf ("\nLos artículos ingressados para la venta son: \n");
	for (i=0; i<MAX; i++){
		printf ("%s \t %d \n", pVentas[i];
	}
}
*Función para eliminar un dato:
Void eliminarArticulo();
	int i;
	printf ("\Ingrese elemento de la lista a eliminar: \n");
	scanf(“%d”, &elementoEliminar);
	for (i=0; i<MAX; i++){
if (elementoEliminar== pVentas[i])
		pVentas[i] = “ “;
	}
Etapa 3.
a. Se procedió a la modificación del código con respecto a la función de ingreso de datos, que en nuestro caso la llamamos void insertarVenta ( ), para el almacenamiento de los valores ingresados por teclado en una lista enlazada.
b. Así como se modifico la función anterior, también fue necesario cambiar las demás funciones con respecto a la impresión de los valores y la eliminación de alguno de ellos, debido a la diferencia entre la estructura utilizada anteriormente con la actual.
c. Una vez más se procedió a la modificación de la forma de grabar los datos en el archivo por lo explicado anteriormente.

Etapa 4.
En este caso aplicamos la estructura de Corte de Control, para que actúe directamente sobre un archivo donde fueron almacenadas las ventas que fueron ingresadas, ordenadas principalmente por el Numero de categoría que tenían: Ej: (1-SANITARIOS// 2- BULONERIA//3-HERRAMIENTAS EN GRAL).
Para poder incorporar de manera más eficiente los temas dados durante el cuatrimestre, el corte de control lo utilizamos como Tipo de Dato Abstracto (TAD), generando un archivo de tipo HeaderFile
de nombre "informes.h".
El cual se encarga de analizar dicho archivo, accediendo por la opción número 4 del menú, e imprime un informe correspondiente a cada categoría, el cual anuncia el total de artículos de cada categoría vendidos, así como también el monto de cada una de ellas.
También al finalizar el análisis de dicho archivo, informa tanto sobre el monto total recaudado de todas las categorías juntas, como así también de la cantidad (unidades) de artículos totales vendidos.


Etapa 5:
Para la aplicación de estrategia recursiva, la usamos en el caso de la función pregunta(), la cual emite una pregunta al usuario con respecto a si desea continuar con el ingres u otra acción en el programa, cuya respuesta es almacenada y de ella se basa esta función recursiva para su ejecución.
Es decir, teniendo como caso base que el usuario ingresa un “NO” ante la negativa a continuar utilizando el programa, dicha función deja de ejecutarse.
Por el contrario, “mientras la respuesta sea distinta de “NO”, la función pregunta(); continuara ejecutándose y llamando a las demás funciones de acuerdo a lo que el individuo desee hacer.

Etapa 6.
En esta se trató de “pulir” el código, sea con la inclusión de algún TDA para reducir la cantidad de líneas en un solo archivo o incluso con la selección y renombramiento de variables y funciones de carácter más representativo con el abordaje del problema.
Teniendo en cuenta que siempre hay varias formas de que el código realice una determinada acción, pero siempre buscando la más eficiente para lograrlo.

CONSIDERACION CON RESPECTO A GRAFOS:
Ante el poco tiempo entre el desarrollo de los temas de grafos y ya teniendo toda la estructura del código en funcionamiento, no la incluimos en el mismo. Aun así, Consideramos conveniente informar que ideamos de todas formas una estrategia para su implementación, y llegamos a la conclusión de que podría introducirse una estructura de grafos, mediante la cual se podrían representar varias sucursales en el caso de un negocio de mayor envergadura. Y mediante el cual, al tratarse del tipo ponderado, se podría calcular las distancias y/o tiempo de los envíos de la compra desde el depósito de la empresa a la sede encargada de hacer la entrega.

CONCLUSIONES:
Después del desarrollo de todos los temas de la materia y volcarlos de manera que puedan complementarse de eficientemente en el proyecto integrador, lo cual no nos pareció una tarea sencilla, sea por las dificultades que presenta la incorporación de distintas estructuras y recursos lógicos para su ejecución, o también la dificultad para poder coincidir en los métodos para llevarla a cabo.
El desarrollo de software es una tarea que la mayoría de las veces se desarrolla por equipos, las grandes empresas anhelan la inclusión de nuevos desarrolladores para que puedan trabajar junto a sus pares y es por eso que consideran el liderazgo, la comunicación y la facilidad para expresarse muy importantes para la finalización el proyecto encomendado.
Pero, más allá de las trabas que significo la elaboración de este proyecto, es fascinante como la programación presenta infinidad de posibilidades para poder llevar a cabo diversos fines.
Si bien, cada estructura, estrategia y demás tienen sus limitaciones, sus pros y contras, la fusión de todas ellas utilizando la lógica adquirida en el aula hace que se eliminen aquellas barreras que impiden que se pueda explotar el potencial de cada uno que está detrás del proyecto.
Cosa que afianza aún mas, y dió más credibilidad al dicho que dice: “si lo puedes soñar. Lo puedes programar”.
