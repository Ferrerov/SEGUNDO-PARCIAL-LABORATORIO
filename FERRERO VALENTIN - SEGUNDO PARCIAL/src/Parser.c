#include "Parser.h"

int Parser_LibroDesdeTexto(FILE* pArchivo, LinkedList* pArrayLibro)
{
	int retorno = -1;
	int cantidad;
	char buffer1[20];
	char buffer2[128];
	char buffer3[128];
	char buffer4[20];
	char buffer5[20];

	eLibro* pNuevoLibro = NULL;

	if(pArrayLibro != NULL && pArchivo != NULL) //Verifica que exista el LinkedList y que se haya pasado un archivo por parametro
	{
		fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4, buffer5); //Lectura fantasma de la cabecera del archivo
		while( !feof(pArchivo)) //Itera mientras no sea el fin del archivo
		{
			cantidad = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4, buffer5); //Retorna la cantidad de datos que se leyeron
			if( cantidad < 5) //Si la cantidad de datos es menor a los de la estructura termina de iterar
			{
				break;
			}
			pNuevoLibro = Libro_NuevoParametrizado(buffer1, buffer2, buffer3, buffer4, buffer5); //Crea la nueva estructura con los datos
			if(pNuevoLibro != NULL)
			{
				ll_add(pArrayLibro, pNuevoLibro); //Añade la estructura nueva al LInkedList
				retorno = 0;
			}
		}
	}
	return retorno;
}

int Parser_EditorialDesdeTexto(FILE* pArchivo, LinkedList* pArrayEditorial)
{
	int retorno = -1;
	int cantidad;
	char buffer1[20];
	char buffer2[128];

	eEditorial* pNuevaEditorial = NULL;

	if(pArrayEditorial != NULL && pArchivo != NULL) //Verifica que exista el LinkedList y que se haya pasado un archivo por parametro
	{
		fscanf(pArchivo, "%[^,],%[^\n]\n", buffer1, buffer2); //Lectura fantasma de la cabecera del archivo
		while( !feof(pArchivo)) //Itera mientras no sea el fin del archivo
		{
			cantidad = fscanf(pArchivo, "%[^,],%[^\n]\n", buffer1, buffer2); //Retorna la cantidad de datos que se leyeron
			if( cantidad < 2) //Si la cantidad de datos es menor a los de la estructura termina de iterar
			{
				break;
			}
			pNuevaEditorial = Editorial_NuevaParametrizada(buffer1, buffer2); //Crea la nueva estructura con los datos
			if(pNuevaEditorial != NULL)
			{
				ll_add(pArrayEditorial, pNuevaEditorial); //Añade la estructura nueva al LinkedList
				retorno = 0;
			}
		}
	}
	return retorno;
}

int Parser_GuardarLibroTexto(FILE* pArchivo, LinkedList* pArrayLibro)
{
	int retorno = -1;
	eLibro* auxLibro = NULL;
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;

	if(pArchivo != NULL && pArrayLibro != NULL && ll_len(pArrayLibro) > 0) //Verifica que el archivo exista y que la LinkedList exista y tenga al menos un elemento
	{
		fprintf(pArchivo, "id,titulo,autor,precio,ideditorial\n"); //Guarda la cabecera en la primera linea
		for(int i = 0; i < ll_len(pArrayLibro); i++) //Itera hasta el ultimo elemento de la LinkedList
		{
			auxLibro = ll_get(pArrayLibro, i); //Obtiene un elemento del LinkedList
			if(auxLibro != NULL)
			{
				Libro_GetId(auxLibro, &id);            //Obtiene los diferentes datos mediante los getters
				Libro_GetTitulo(auxLibro, titulo);
				Libro_GetAutor(auxLibro, autor);
				Libro_GetPrecio(auxLibro, &precio);
				Libro_GetIdEditorial(auxLibro, &idEditorial);

				fprintf(pArchivo, "%d,%s,%s,%f,%d\n", id, titulo, autor, precio, idEditorial); //Guarda en una linea los datos pasados como parametro
				retorno = 0;
			}
		}
	}
	return retorno;
}
