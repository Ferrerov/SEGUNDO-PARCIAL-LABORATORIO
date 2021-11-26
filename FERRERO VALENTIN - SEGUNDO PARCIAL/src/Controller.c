#include "Controller.h"

int Controller_CargarLibrosDesdeTxt(LinkedList* pArrayLibro)
{
	int retorno = -1;

	FILE *pArchivo = NULL;
	char ubicacion[128];

	if(GetString(ubicacion,"Ingrese el archivo a cargar (.csv): ", "Error, por favor ingrese al menos un caracter", 4) == 0) //Pide al usuario la ubicacion del archivo a cargar
	{
		pArchivo = fopen(ubicacion, "r"); //Abre el archivo indicado
		if(pArchivo != NULL && Parser_LibroDesdeTexto(pArchivo, pArrayLibro) == 0) //Verifica que el archivo exista y que se haya podido cargar
		{
			retorno = 0;
		}
		fclose(pArchivo); //Cierra el archivo
	}

	return retorno;
}

int Controller_CargarEditorialesDesdeTxt(LinkedList* pArrayEditorial)
{
	int retorno = -1;

	char ubicacion[128];
	FILE *pArchivo = NULL;

	if(GetString(ubicacion,"Ingrese el archivo a cargar (.csv): ", "Error, por favor ingrese al menos un caracter", 4) == 0) //Pide al usuario la ubicacion del archivo a cargar
	{
		pArchivo = fopen(ubicacion, "r"); //Abre el archivo indicado
		if(pArchivo != NULL && Parser_EditorialDesdeTexto(pArchivo, pArrayEditorial) == 0) //Verifica que el archivo exista y que se haya podido cargar
		{
			retorno = 0;
		}
		fclose(pArchivo); //Cierra el archivo
	}

	return retorno;
}

int Controller_OrdenarLibros(LinkedList* pArrayLibro)
{
	int retorno = -1;

	if(pArrayLibro != NULL && ll_sort(pArrayLibro, Libro_CompararAutor, 1) == 0) //Verifica que la LinkedList no sea NULL y que se puedan ordenar
	{
		retorno = 0;
	}

	return retorno;
}

int Controller_IndiceEditorialPorId(LinkedList* pArrayEditorial, int id)
{
	int retorno = -1;

	eEditorial* unaEditorial = NULL;
	int len;

	if(pArrayEditorial != NULL) //Verifica que la LinkedList exista
	{
		len = ll_len(pArrayEditorial); //Obtiene la cantidad de elementos de la LinkedList
		for(int i = 0; i < len; i++) //Itera hasta el final o hasta encontrar un id coincidente
		{
			unaEditorial = ll_get(pArrayEditorial, i); //Obtiene un elemento de la LinkedList en el indice especificado
			if(unaEditorial != NULL && unaEditorial->idEditorial == id) //Verifica si el idEditorial del elemento coincide con el id pasado como parametro
			{
				retorno = i; //Retorna la posicion en la LinkedList en la que se encuentra el coincidente
				break; //Termina la iteracion
			}
		}
	}
	return retorno;
}

int Controller_ImprimirListadoLibros(LinkedList* pArrayLibro, LinkedList* pArrayEditorial)
{
	int retorno = -1;

	eLibro* unLibro;
	eEditorial* unaEditorial;
	int len;

	if(pArrayLibro != NULL && pArrayEditorial != NULL) //Verifica que ambas LinkedList existan
	{
		printf("\n|----------------------------------------------------------------------------------------|");
		printf("\n|%*s|%*s|%*s|%*s|%*s|", -8, "ID LIBRO", -25, "TITULO",-20, "AUTOR",-11 , "PRECIO",-20, "EDITORIAL");
		printf("\n|----------------------------------------------------------------------------------------|");

		len = ll_len(pArrayLibro); //Obtiene la cantidad de elementos de la LinkedList
		for(int i = 0; i < len; i++) //Itera hasta el final de la LinkedList
		{
			unLibro = ll_get(pArrayLibro, i); //Obtiene el elemento en la posicion especificada
			unaEditorial = ll_get(pArrayEditorial, Controller_IndiceEditorialPorId(pArrayEditorial, unLibro->idEditorial)); //Obtiene la estructura eEditorial que coincide
			fflush(stdin);
			Libro_ImprimirUnLibro(unLibro, unaEditorial); //Imprime los datos de ambas estructuras
			retorno = 0;
		}
		printf("\n|----------------------------------------------------------------------------------------|");
	}

	return retorno;
}

int Controller_ListadoPorEditorial(LinkedList* pArrayLibro, LinkedList* pArrayEditorial)
{
	int retorno = -1;
	LinkedList* pNuevaLista = NULL;
	FILE *pArchivo;
	char ubicacion[128];

	if(pArrayLibro != NULL && pArrayEditorial != NULL) //Verifica que ambas LinkedList existan
	{
		pNuevaLista = ll_filter(pArrayLibro, Libro_FiltroEditorialMinotauro); //Obtiene la nueva lista resultado del filtro
		if(pNuevaLista != NULL && ll_len(pNuevaLista) > 0) //Verifica que la nueva lista no sea NULL y que tenga al menos un elemento
		{
			Controller_ImprimirListadoLibros(pNuevaLista, pArrayEditorial); //Imprime el listado de libros pero solo de una editorial
			GetString(ubicacion,"\nIngrese el nombre del archivo a guardar: ", "Error, por favor ingrese al menos un caracter", 4); //Pide al usuario el nombre del archivo a guardar
			strcat(ubicacion, ".csv");

			pArchivo = fopen(ubicacion, "w"); //Abre o crea el archivo en modo escritura
			if(pArchivo != NULL && Parser_GuardarLibroTexto(pArchivo, pNuevaLista) == 0) //Verifica si el archivo existe y se pudo guardar
			{
				retorno = 0;
			}
			fclose(pArchivo); //Cierra el archivo
		}
	}

	return retorno;
}

int Controller_Descuentos(LinkedList* pArrayLibro, LinkedList* pArrayEditorial)
{
	int retorno = -1;
	LinkedList* pNuevaLista = NULL;
	FILE *pArchivo;

	if(pArrayLibro != NULL && pArrayEditorial != NULL)
	{
		pNuevaLista = ll_map(pArrayLibro, Libro_DescuentosPorEditorial);
		if(pNuevaLista != NULL && ll_len(pNuevaLista) > 0)
		{
			Controller_ImprimirListadoLibros(pNuevaLista, pArrayEditorial);

			pArchivo = fopen("mapeado.csv", "w");
			if(pArchivo != NULL && Parser_GuardarLibroTexto(pArchivo, pNuevaLista) == 0)
			{
				retorno = 0;
			}
			fclose(pArchivo);
		}
	}


	return retorno;
}

