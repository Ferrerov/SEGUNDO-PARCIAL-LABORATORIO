#include "Relacion.h"

int Libro_ImprimirUnLibro( eLibro* unLibro, eEditorial* unaEditorial)
{
	int retorno = -1;

	int id;
	char titulo[128];
	char autor[128];
	float precio;
	char nombreEditorial[128];

	if(unLibro != NULL && unaEditorial != NULL) //Verifica que ninguna estructura sea NULL
	{
		Libro_GetId(unLibro, &id);       //Obtiene los datos de las estructuras
		Libro_GetTitulo(unLibro, titulo);
		Libro_GetAutor(unLibro, autor);
		Libro_GetPrecio(unLibro, &precio);
		Editorial_GetNombre(unaEditorial, nombreEditorial);

		printf("\n|%*d|%*s|%*s|%*.2f|%*s|", -8, id, -25, titulo,-20, autor,-11 , precio, -20, nombreEditorial); //Imprime los datos obtenidos
		retorno = 0;
	}
	return retorno;
}


