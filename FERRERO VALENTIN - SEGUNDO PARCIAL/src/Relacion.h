#ifndef RELACION_H_
#define RELACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"
#include "Libro.h"
#include "Editorial.h"
#include "LinkedList.h"

/// @fn int Libro_ImprimirUnLibro(eLibro*, eEditorial*)
/// @brief Imprime un libro con todos los datos
/// @param unLibro Puntero a la estructura eLibro
/// @param unaEditorial Puntero a la estructura eEditorial
/// @return Retorna (-1) Si alguna estructura es NULL
/// 				(0) Si pudo imprimir el libro
int Libro_ImprimirUnLibro( eLibro* unLibro, eEditorial* unaEditorial);


#endif /* RELACION_H_ */
