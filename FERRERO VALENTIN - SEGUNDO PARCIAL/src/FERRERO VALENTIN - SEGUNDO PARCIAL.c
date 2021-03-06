/*
 ============================================================================
 Name        : FERRERO.c
 Author      : Ferrero Valentin
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);

	int option = 0;
	int flagCargaLibro = -1;
	int flagCargaEditorial = -1;

	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();

	do{
		printf("\n1. Cargar los datos de los libros desde un archivo.\n"
				"2. Cargar los datos de las editoriales desde un archivo.\n"
				"3. Ordenar la lista por autor.\n"
				"4. Ver listado de todos los libros.\n"
				"5. Ver y guardar listado de los libros de la editorial MINOTAURO.\n"
				"6. Realizar descuentos a editoriales PLANETA y SILO XXI EDITORES y guardar.\n"
				"7. Salir.\n");

		GetInt(&option, "\nIngrese una opci?n: ", "\nError, ingrese una opci?n v?lida: ", 1, 10, 5);

		switch(option)
		{
			case 1:
				printf("\nUsted ha seleccionado la opci?n 1: Cargar los datos de los libros desde un archivo.\n");
				if( flagCargaLibro != 0 && Controller_CargarLibrosDesdeTxt(listaLibros) == 0)
				{
					printf("\nSe han cargado los datos exitosamente.\n");
					flagCargaLibro = 0;
				}
				else
				{
					printf("\nNo se ha podido cargar los datos.\n");
				}
				break;
			case 2:
				printf("\nUsted ha seleccionado la opci?n 2: Cargar los datos de las editoriales desde un archivo.\n");
				if( flagCargaEditorial != 0 && Controller_CargarEditorialesDesdeTxt(listaEditoriales) == 0)
				{
					printf("\nSe han cargado los datos exitosamente.\n");
					flagCargaEditorial = 0;
				}
				else
				{
					printf("\nNo se ha podido cargar los datos.\n");
				}
				break;
			case 3:
				printf("\nUsted ha seleccionado la opci?n 3: Ordenar la lista por autor.\n");
				if( flagCargaLibro == 0 && flagCargaEditorial == 0 && Controller_OrdenarLibros(listaLibros) == 0)
				{
					Controller_ImprimirListadoLibros(listaLibros, listaEditoriales);
					printf("\nSe han ordenados los libros por autor de manera ascendente.\n");
				}
				else
				{
					printf("\nNo hay libros para ordenar o ya estan ordenados.\n");
				}
				break;
			case 4:
				printf("\nUsted ha seleccionado la opci?n 4: Ver listado de todos los libros.\n");
				if(flagCargaLibro != 0 || flagCargaEditorial != 0 || Controller_ImprimirListadoLibros(listaLibros, listaEditoriales) != 0 )
				{
					printf("\nNo hay libros para listar.\n");
				}
				break;
			case 5:
				printf("\nUsted ha seleccionado la opci?n 5: Ver y guardar listado de los libros de la editorial MINOTAURO.\n");
				if( flagCargaLibro != 0 || flagCargaEditorial != 0 || Controller_ListadoPorEditorial(listaLibros, listaEditoriales)!= 0 )
				{
					printf("\nNo hay libros para listar.\n");
				}
				else
				{
					printf("\nSe ha guardado el listado.\n");
				}
				break;
			case 6:
				printf("\nUsted ha seleccionado la opci?n 6: Realizar descuentos a editoriales PLANETA y SILO XXI EDITORES y guardar.\n");
				if( flagCargaLibro != 0 || flagCargaEditorial != 0 || Controller_Descuentos(listaLibros, listaEditoriales)!= 0 )
				{
					printf("\nNo hay libros para listar.\n");
				}
				else
				{
					printf("\nSe ha guardado el listado.\n");
				}
				break;
			case 7:
				printf("Usted ha seleccionado la opci?n 7: Salir.\n");
				break;
		}
		fflush(stdin);
		printf("\n\n**************Pulse una tecla para continuar**************\n");
		getchar();
	}while(option != 7);

	return EXIT_SUCCESS;
}
