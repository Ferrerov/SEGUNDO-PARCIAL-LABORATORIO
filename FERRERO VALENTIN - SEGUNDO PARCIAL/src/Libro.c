#include "Libro.h"

int Libro_SetId(eLibro* unLibro, int id)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		unLibro->id = id;
		retorno = 0;
	}

	return retorno;
}

int Libro_GetId(eLibro* unLibro, int* id)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		*id = unLibro->id;
		retorno = 0;
	}

	return retorno;
}

int Libro_SetTitulo(eLibro* unLibro, char* titulo)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		strcpy(unLibro->titulo,titulo);
		retorno = 0;
	}

	return retorno;
}


int Libro_GetTitulo(eLibro* unLibro, char* titulo)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		strcpy(titulo,unLibro->titulo);
		retorno = 0;
	}

	return retorno;
}

int Libro_SetAutor(eLibro* unLibro, char* autor)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		strcpy(unLibro->autor,autor);
		retorno = 0;
	}

	return retorno;
}


int Libro_GetAutor(eLibro* unLibro, char* autor)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		strcpy(autor,unLibro->autor);
		retorno = 0;
	}

	return retorno;
}

int Libro_SetPrecio(eLibro* unLibro, float precio)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		unLibro->precio = precio;
		retorno = 0;
	}

	return retorno;
}


int Libro_GetPrecio(eLibro* unLibro, float* precio)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		*precio = unLibro->precio;
		retorno = 0;
	}

	return retorno;
}

int Libro_SetIdEditorial(eLibro* unLibro, int idEditorial)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		unLibro->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}


int Libro_GetIdEditorial(eLibro* unLibro, int* idEditorial)
{
	int retorno = -1;

	if(unLibro != NULL)
	{
		*idEditorial = unLibro->idEditorial;
		retorno = 0;
	}

	return retorno;
}

eLibro* Libro_Nuevo()
{
	eLibro* pNuevoLibro = NULL;
	pNuevoLibro = (eLibro*) malloc(sizeof(eLibro));

	if(pNuevoLibro != NULL)
	{
		Libro_SetId(pNuevoLibro, 0);
		Libro_SetTitulo(pNuevoLibro, " ");
		Libro_SetAutor(pNuevoLibro, " ");
		Libro_SetPrecio(pNuevoLibro, 0);
		Libro_SetIdEditorial(pNuevoLibro, 0);
	}

	return pNuevoLibro;
}

eLibro* Libro_NuevoParametrizado(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr)
{
	eLibro* pNuevoLibro = NULL;

	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL &&
		   NumberValidation(idStr) == 0 && FloatNumberValidation(precioStr) == 0 && NumberValidation(idEditorialStr) == 0)
	{
		pNuevoLibro = Libro_Nuevo();
		if(pNuevoLibro != NULL)
		{
			Libro_SetId(pNuevoLibro, atoi(idStr));
			Libro_SetTitulo(pNuevoLibro, tituloStr);
			Libro_SetAutor(pNuevoLibro, autorStr);
			Libro_SetPrecio(pNuevoLibro, atof(precioStr));
			Libro_SetIdEditorial(pNuevoLibro, atoi(idEditorialStr));
		}
	}
	return pNuevoLibro;
}

void Libro_Eliminar(eLibro* unLibro)
{
	if(unLibro != NULL)
	{
		free(unLibro);
	}
}

int Libro_CompararAutor(void *libroUno, void *libroDos)
{
	int retorno;
	eLibro* auxlibroUno;
	eLibro* auxlibroDos;
	char autorUno[128];
	char autorDos[128];

	if(libroUno != NULL && libroDos != NULL) //Verifica que ambos elementos existan
	{
		auxlibroUno = (eLibro*)libroUno;  //Parsea los elementos a esctructuras
		auxlibroDos = (eLibro*)libroDos;
		Libro_GetAutor(auxlibroUno, autorUno); //Obtiene el autor de un libro
		Libro_GetAutor(auxlibroDos, autorDos); //Obtiene el autor de un segundo libro para comparar
		retorno = strcmp(autorUno, autorDos); //Compara ambos autores y retorna el resultado
	}

	return retorno;
}

int Libro_FiltroEditorialMinotauro(void* unLibro)
{
	int retorno = -1;

	eLibro* auxEditorial = NULL;

	if(unLibro != NULL) //Verifica que el elemento exista
	{
		auxEditorial = (eLibro*)unLibro; //Parsea el elemento a la estructura eLibro
		retorno = 0;
		if(auxEditorial->idEditorial == 4) //Verifica si el libro es de la editorial MINOTAURO
		{
			retorno = 1;
		}
	}
	return retorno;
}


