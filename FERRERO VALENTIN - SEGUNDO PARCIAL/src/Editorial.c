#include "Editorial.h"

int Editorial_SetIdEditorial(eEditorial* unaEditorial, int idEditorial)
{
	int retorno = -1;

	if(unaEditorial != NULL)
	{
		unaEditorial->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

int Editorial_GetIdEditorial(eEditorial* unaEditorial, int* idEditorial)
{
	int retorno = -1;

	if(unaEditorial != NULL)
	{
		*idEditorial = unaEditorial->idEditorial;
		retorno = 0;
	}

	return retorno;
}

int Editorial_SetNombre(eEditorial* unaEditorial, char* nombre)
{
	int retorno = -1;

	if(unaEditorial != NULL)
	{
		strcpy(unaEditorial->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int Editorial_GetNombre(eEditorial* unaEditorial, char* nombre)
{
	int retorno = -1;

	if(unaEditorial != NULL)
	{
		strcpy(nombre, unaEditorial->nombre);
		retorno = 0;
	}

	return retorno;
}

eEditorial* Editorial_Nueva()
{
	eEditorial* pNuevaEditorial = NULL;
	pNuevaEditorial = (eEditorial*) malloc(sizeof(eEditorial));

	if(pNuevaEditorial != NULL)
	{
		Editorial_SetIdEditorial(pNuevaEditorial, 0);
		Editorial_SetNombre(pNuevaEditorial, " ");
	}

	return pNuevaEditorial;
}

eEditorial* Editorial_NuevaParametrizada(char* idEditorialStr, char* nombreStr)
{
	eEditorial* pNuevaEditorial = NULL;

	if(idEditorialStr != NULL && nombreStr != NULL &&
			NumberValidation(idEditorialStr) == 0)
	{
		pNuevaEditorial = Editorial_Nueva();
		if(pNuevaEditorial != NULL)
		{
			Editorial_SetIdEditorial(pNuevaEditorial, atoi(idEditorialStr));
			Editorial_SetNombre(pNuevaEditorial, nombreStr);
		}
	}
	return pNuevaEditorial;
}

void Editorial_Eliminar(eEditorial* unaEditorial)
{
	if(unaEditorial != NULL)
	{
		free(unaEditorial);
	}
}
