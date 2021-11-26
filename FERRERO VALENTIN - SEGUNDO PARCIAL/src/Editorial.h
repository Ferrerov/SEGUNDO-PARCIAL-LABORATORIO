#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"

typedef struct
{
    int idEditorial;
    char nombre[128];
}eEditorial;


/// @fn int Editorial_SetIdEditorial(eEditorial*, int)
/// @brief Asigna el dato idEditorial pasado como parametro a la estructura eEditorial
/// @param unaEditorial Puntero a la estructura eEditorial
/// @param idEditorial Dato a asignar
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo asignar el dato satisfactoriamente
int Editorial_SetIdEditorial(eEditorial* unaEditorial, int idEditorial);

/// @fn int Editorial_GetIdEditorial(eEditorial*, int*)
/// @brief Obtiene el dato idEditorial de la estructura eEditorial
/// @param unaEditorial Puntero a la estructura eEditorial
/// @param idEditorial Puntero al dato
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo obtener el dato satisfactoriamente
int Editorial_GetIdEditorial(eEditorial* unaEditorial, int* idEditorial);

/// @fn int Editorial_SetNombre(eEditorial*, char*)
/// @brief Asigna el dato nombre pasado como parametro a la estructura eEditorial
/// @param unaEditorial Puntero a la estructura eEditorial
/// @param nombre Dato a asignar
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo asignar el dato satisfactoriamente
int Editorial_SetNombre(eEditorial* unaEditorial, char* nombre);

/// @fn int Editorial_GetNombre(eEditorial*, char*)
/// @brief Obtiene el dato nombre de la estructura eEditorial
/// @param unaEditorial Puntero a la estructura eEditorial
/// @param nombre Puntero al dato
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo obtener el dato satisfactoriamente
int Editorial_GetNombre(eEditorial* unaEditorial, char* nombre);

/// @fn eEditorial Editorial_Nueva*()
/// @brief Constructor de la estructura eEditorial
/// @return Retorna  (NULL) Si el puntero a la estructura es NULL
///                  (puntero a la estructura) Si encontro espacio en memoria
eEditorial* Editorial_Nueva();

/// @fn eEditorial Editorial_NuevaParametrizada*(char*, char*)
/// @brief Constructor de la estructura eEditorial con parametros
/// @param idEditorialStr Cadena de caracteres de id
/// @param nombreStr Cadena de caracteres de nombre
/// @return Retorna (NULL) Si el puntero a la estructura es NULL
/// 				(puntero a la estructura) Si ok
eEditorial* Editorial_NuevaParametrizada(char* idEditorialStr, char* nombreStr);

/// @fn void Editorial_Eliminar(eEditorial*)
/// @brief Elimina una estructura de tipo eEditorial
/// @param unaEditorial Puntero a la estructura eEditorial
void Editorial_Eliminar(eEditorial* unaEditorial);


#endif /* EDITORIAL_H_ */
