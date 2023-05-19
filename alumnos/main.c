/**
 * Conjunto de funciones para manejar las listas de palabras que utilizaremos en el trabajo práctico 
 * run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 	Listado de archivos que se van a generar para almacenar palabras de n caracteres.
	Las palabras vienen agrupadas en archivos binarios denominados <n>letras.txt donde 
	<n> se reemplaza por 1 , 2, ... 22. Ej. 12letras.txt es el archivo que contiene las palabras de 12 letras
	*/
FILE *archivo[23];

/* Archivo origen de las TODAS palabras, ordenadas alfabéticamente, pero no por cantidad de letras. 
*/
FILE *origen; 

#define MAX_LONG_PALABRA 25 // Tamaño de todas las palabras. La palabra más larga tiene 22 letras, pero utilizamos 25 caracteres como máximo para cada palabra

/***** PROTOTIPOS DE FUNCIONES ***********/
/** Obtiene la n-ésima palabra del archivo (listado) de palabras dado como parámetro (FILE *FP).
 * 	Guarda la palabra encontrada en el array buffer, que se pasa como parámetro.
 *  Retorna la cantidad de letras que tiene esa palabra */
int getPalabraNumero(char *buffer, int n, FILE *fp);

/** En este ejemplo abrimos 2 archivos, el que contiene TODAS las palabras y el que contien las palabras de 5 letras.
 *  Hacer los cambios que sean necesarios para abrir los arhivos que contengas otras cantidades de caracteres.
*/
int main(int argc, char *argv[]) {
	int i; // contador auxiliar
	char nombre[] = "letras.txt"; // parte común del nombre de los archivos de palabras
	char num[]="1"; // parte numérica del nombre de los archivos de palabras
	char palabra[MAX_LONG_PALABRA]; // Palabra obtenida del archivo origen, para colocar en cada archivo de acuerdo a su longitud
	int str_long=0; // Longitud de la palabra obtenida de un archivo
	// Abrimos los arhivos con los que vamos a trabajar
	origen = fopen("origen.txt","rb");
	archivo[5] = fopen("5letras.txt","rb");
	
	i = 23654;
	str_long = getPalabraNumero(palabra, i, origen);
	printf("La palabra %d del arhivo origen.txt es \"%s\" y tiene %d caracteres.\n",i, palabra, str_long);
	
	i = 65235;
	str_long = getPalabraNumero(palabra, i, origen);
	printf("La palabra %d del arhivo origen.txt es \"%s\" y tiene %d caracteres.\n",i, palabra, str_long);
	
	
	i = 0;
	
	str_long = getPalabraNumero(palabra, i, archivo[5]);
	printf("La palabra %d del arhivo 5letras.txt es \"%s\" y tiene %d caracteres.\n",i, palabra, str_long);
	
	i = 50;
	
	str_long = getPalabraNumero(palabra, i, archivo[5]);
	printf("La palabra %d del arhivo 5letras.txt es \"%s\" y tiene %d caracteres.\n",i, palabra, str_long);
	
	// probamos algunas palabras
	
	
	// Al finalizar, cerramos los archivos con los que hemos trabajado
	fclose(origen);
	fclose(archivo[5]);
	system("pause");	
	return 0;
}

/** Obtiene la n-ésima palabra del archivo (listado) de palabras dado como parámetro (FILE *FP).
 * 	Guarda la palabra encontrada en el array buffer, que se pasa como parámetro.
 *  Retorna la cantidad de letras que tiene esa palabra */
int getPalabraNumero(char *buffer, int n, FILE *fp){
	buffer[0]='\0'; // borra el contenido de la cadena
	int offset; // utilizado para calcular el lugar donde se debe iniciar la lectura de datos en el archivo
	int longitud = 0; // Longitud de la palabra obtenida, en caracteres
	offset = n*MAX_LONG_PALABRA; // posici?n de la n-?sima palabra
	fseek(fp, offset, SEEK_SET); // se selecciona la posici?n de la n-?sima palabra
	fgets(buffer, MAX_LONG_PALABRA, fp); // lectura de la palabra de esa posici?n
	longitud = strlen(buffer); // se obtiene la longitud de la n-ésima palabra
	buffer[longitud]='\0'; // se termina la cadena explítitamente con \0, por las dudas... 
	return longitud-1; // se retorna la cantidad de caracteres de la palabra
}

