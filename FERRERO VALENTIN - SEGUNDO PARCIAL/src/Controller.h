#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "Parser.h"
#include "Relacion.h"

/// @fn int Controller_CargarDesdeTxt(char*, LinkedList*)
/// @brief Abre un archivo, lo carga  y lo cierra.
/// @param path Archivo .txt a cargar
/// @param pArrayLibros Puntero al LinkedList de libros
/// @return Retorna (-1) Si hubo un error al abrir el archivo
///     			(0) Si se cargo el archivo satisfactoriamente
int Controller_CargarLibrosDesdeTxt(LinkedList* pArrayLibro);

/// @fn int Controller_CargarEditorialesDesdeTxt(char*, LinkedList*)
/// @brief Abre un archivo, lo carga  y lo cierra.
/// @param ubicacion Archivo .txt a cargar
/// @param pArrayEditorial Puntero al LinkedList de editoriales
/// @return Retorna (-1) Si hubo un error al abrir el archivo
///     			(0) Si se cargo el archivo satisfactoriamente
int Controller_CargarEditorialesDesdeTxt(LinkedList* pArrayEditorial);

int Controller_OrdenarLibros(LinkedList* pArrayLibro);
/// @fn int Controller_IndiceEditorialPorId(LinkedList*, int)
/// @brief Obtiene el indice de la estructura eEditorial que coincide con el id pasado por parametro
/// @param pArrayEditorial Puntero al LinkedList de editoriales
/// @param id Dato pasado como parametro para buscar coincidente
/// @return Retorna (-1) Si no se encontro la editorial que coincida
/// 				(indice) Si se encontro la estructura con el mismo dato
int Controller_IndiceEditorialPorId(LinkedList* pArrayEditorial, int id);

/// @fn int Controller_ListadoLibros(LinkedList*, LinkedList*)
/// @brief Imprime un listado de cada libro y sus datos
/// @param pArrayLibro Puntero al LinkedList de libros
/// @param pArrayEditorial Puntero al LinkedList de editoriales
/// @return Retorna (-1) Si no encontro ningun libro para imprimir
/// 				(0) Si se imprimio la lista
int Controller_ImprimirListadoLibros(LinkedList* pArrayLibro, LinkedList* pArrayEditorial);

/// @fn int Controller_ListadoPorEditorial(LinkedList*, LinkedList*)
/// @brief Imprime y guarda un listado de los libros de una editorial especifica
/// @param pArrayLibro Puntero al LinkedList de libros
/// @param pArrayEditorial Puntero al LinkedList de editoriales
/// @return Retorna (-1) Si no encontro ningun libro de esa editorial o si se ingreso un nombre de archivo incorrecto
/// 				(0) Si encontro al menos un libro y pudo guardar la lista
int Controller_ListadoPorEditorial(LinkedList* pArrayLibro, LinkedList* pArrayEditorial);
#endif /* CONTROLLER_H_ */
