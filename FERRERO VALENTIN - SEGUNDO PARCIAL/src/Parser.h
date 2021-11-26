#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"

/// @fn int Parser_LibroDesdeTexto(FILE*, LinkedList*)
/// @brief Convierte y asigna los datos del .txt
/// @param pArchivo Puntero al archvio .txt
/// @param pArrayLibros Puntero al LinkedList de libros
/// @return Retorna (-1) Si hubo un error al cargar los datos
///     			(0) Si se cargo el archivo satisfactoriamente
int Parser_LibroDesdeTexto(FILE* pArchivo, LinkedList* pArrayLibro);

/// @fn int Parser_EditorialDesdeTexto(FILE*, LinkedList*)
/// @brief Convierte y asigna los datos del .txt
/// @param pArchivo Puntero al archvio .txt
/// @param pArrayEditorial Puntero al LinkedList de editoriales
/// @return Retorna (-1) Si hubo un error al cargar los datos
///     			(0) Si se cargo el archivo satisfactoriamente
int Parser_EditorialDesdeTexto(FILE* pArchivo, LinkedList* pArrayEditorial);

/// @fn int Parser_GuardarLibroTexto(FILE*, LinkedList*)
/// @brief Obtiene los datos de cada libro y los guarda en un archivo pasado como parametro
/// @param pArchivo Puntero al archivo
/// @param pArrayLibro Puntero al LinkedList de libros
/// @return Retorna (-1) Si no pudo guardar ningun libro o si pArchivo o la LinkedList son NULL
/// 				(0) Si guardo al menos un libro
int Parser_GuardarLibroTexto(FILE* pArchivo, LinkedList* pArrayLibro);
#endif /* PARSER_H_ */
