#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"

typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    float precio;
    int idEditorial;
}eLibro;

/// @fn int Libro_SetId(eLibro*, int)
/// @brief Asigna el dato id pasado como parametro a la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param id Dato a asignar
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo asignar el dato satisfactoriamente
int Libro_SetId(eLibro* unLibro, int id);

/// @fn int Libro_GetId(eLibro*, int*)
/// @brief Obtiene el dato id de la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param id Puntero al dato
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo obtener el dato satisfactoriamente
int Libro_GetId(eLibro* unLibro, int* id);

/// @fn int Libro_SetTitulo(eLibro*, char*)
/// @brief Asigna el dato titulo pasado como parametro a la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param titulo Dato a asignar
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo asignar el dato satisfactoriamente
int Libro_SetTitulo(eLibro* unLibro, char* titulo);

/// @fn int Libro_GetLibro(eLibro*, char*)
/// @brief Obtiene el dato titulo de la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param titulo Puntero al dato
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo obtener el dato satisfactoriamente
int Libro_GetTitulo(eLibro* unLibro, char* titulo);

/// @fn int Libro_SetAutor(eLibro*, char*)
/// @brief Asigna el dato autor pasado como parametro a la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param autor Dato a asignar
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo asignar el dato satisfactoriamente
int Libro_SetAutor(eLibro* unLibro, char* autor);

/// @fn int Libro_GetAutor(eLibro*, char*)
/// @brief Obtiene el dato autor de la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param autor Puntero al dato
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo obtener el dato satisfactoriamente
int Libro_GetAutor(eLibro* unLibro, char* autor);

/// @fn int Libro_SetPrecio(eLibro*, int)
/// @brief Asigna el dato precio pasado como parametro a la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param precio Dato a asignar
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo asignar el dato satisfactoriamente
int Libro_SetPrecio(eLibro* unLibro, float precio);

/// @fn int Libro_GetPrecio(eLibro*, int*)
/// @brief Obtiene el dato precio de la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param precio Puntero al dato
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo obtener el dato satisfactoriamente
int Libro_GetPrecio(eLibro* unLibro, float* precio);

/// @fn int Libro_SetIdEditorial(eLibro*, int)
/// @brief Asigna el dato idEditorial pasado como parametro a la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param idEditorial Dato a asignar
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo asignar el dato satisfactoriamente
int Libro_SetIdEditorial(eLibro* unLibro, int idEditorial);

/// @fn int Libro_GetIdEditorial(eLibro*, int*)
/// @brief Obtiene el dato idEditorial de la estructura eLibro
/// @param unLibro Puntero a la estructura eLibro
/// @param idEditorial Puntero al dato
/// @return Retorna (-1) Si hubo un error
/// 				(0) Si pudo obtener el dato satisfactoriamente
int Libro_GetIdEditorial(eLibro* unLibro, int* idEditorial);

/// @fn eLibro Libro_Nuevo()
/// @brief Constructor de la estructura eLibro
/// @return Retorna  (NULL) Si el puntero a la estructura es NULL
///                  (puntero a la estructura) Si encontro espacio en memoria
eLibro* Libro_Nuevo();

/// @fn eLibro Libro_NuevoParametrizado*(char*, char*, char*, char*, char*)
/// @brief Constructor de la estructura eLibro con parametros
/// @param idStr Cadena de caracteres de id
/// @param tituloStr Cadena de caracteres de titulo
/// @param autorStr Cadena de caracteres de autor
/// @param precioStr Cadena de caracteres de precio
/// @param idEditorialStr Cadena de caracteres de idEditorial
/// @return Retorna (NULL) Si el puntero a la estructura es NULL
/// 				(puntero a la estructura) Si ok
eLibro* Libro_NuevoParametrizado(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);

/// @fn void Libro_Eliminar(eLibro*)
/// @brief Elimina una estructura de tipo eLibro
/// @param unLibro Puntero a la estructura eLibro
void Libro_Eliminar(eLibro* unLibro);

/// @fn int Libro_CompararAutor(void*, void*)
/// @brief Compara dos autores para determinar mayor menor o igual
/// @param libroUno Libro uno a comparar
/// @param libroDos Libro dos a comparar
/// @return Retorna (NULL) Si hubo un error
/// 				(0) Si los nombres son iguales
/// 				(>0) Si el nombre del primer autor es menor al del segundo
/// 				(<0) Si el nombre del primer autor es mayor al del segundo
int Libro_CompararAutor(void *libroUno, void *libroDos);

/// @fn int Libro_FiltroEditorialMinotauro(void*)
/// @brief Verifica si un libro es de la editorial MINOTAURO
/// @param unLibro Estructura libro
/// @return Retorna (-1) Si el elemento pasado como parametro es NULL
/// 				(0) Si el libro no es de la editorial MINOTAURO
/// 				(1) Si el libro es de la editorial MINOTAURO
int Libro_FiltroEditorialMinotauro(void* unLibro);

int Libro_DescuentosPorEditorial(void* unLibro);

#endif /* LIBRO_H_ */
