#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

/// @fn LinkedList ll_newLinkedList*(void)
/// @brief Crea un nuevo LinkedList en memoria de manera dinamica
/// @return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
///         o el puntero al espacio reservado
LinkedList* ll_newLinkedList(void);

/// @fn int ll_len(LinkedList*)
/// @brief Retorna la cantidad de elementos de la lista
/// @param this LinkedList* Puntero a la lista
/// @return Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
int ll_len(LinkedList* this);

/// @fn int ll_add(LinkedList*, void*)
/// @brief Agrega un elemento a la lista
/// @param this LinkedList* Puntero a la lista
/// @param pElement Puntero al elemento a ser agregado
/// @return Retorna (-1) Error: si el puntero a la lista es NULL
///                 ( 0) Si funciono correctamente
int ll_add(LinkedList* this, void* pElement);

/// @fn void ll_get*(LinkedList*, int)
/// @brief Permite realizar el test de la funcion addNode la cual es privada
/// @param this Puntero a la lista
/// @param index Ubicacion del elemento a obtener
/// @return Retorna (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                 (pElement) Si funciono correctamente
void* ll_get(LinkedList* this, int index);

/// @fn int ll_set(LinkedList*, int, void*)
/// @brief Modifica un elemento de la lista
/// @param this Puntero a la lista
/// @param index Ubicacion del elemento a modificar
/// @param pElement Puntero al nuevo elemento
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  ( 0) Si funciono correctamente
int ll_set(LinkedList* this, int index,void* pElement);

/// @fn int ll_remove(LinkedList*, int)
/// @brief Elimina un elemento de la lista
/// @param this Puntero a la lista
/// @param index Ubicacion del elemento a eliminar
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  ( 0) Si funciono correctamente
int ll_remove(LinkedList* this,int index);

/// @fn int ll_clear(LinkedList*)
/// @brief Elimina todos los elementos de la lista
/// @param this Puntero a la lista
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  ( 0) Si funciono correctamente
int ll_clear(LinkedList* this);

/// @fn int ll_deleteLinkedList(LinkedList*)
/// @brief Elimina todos los elementos de la lista y la lista
/// @param this Puntero a la lista
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  ( 0) Si funciono correctamente
int ll_deleteLinkedList(LinkedList* this);

/// @fn int ll_indexOf(LinkedList*, void*)
/// @brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
/// @param this Puntero a la lista
/// @param pElement Puntero al elemento
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  (indice del elemento) Si funciono correctamente
int ll_indexOf(LinkedList* this, void* pElement);

/// @fn int ll_isEmpty(LinkedList*)
/// @brief Indica si la lista esta o no vacia
/// @param this Puntero a la lista
/// @return
/// Retorna  (-1) Error: si el puntero a la lista es NULL
///          ( 0) Si la lista NO esta vacia
///          ( 1) Si la lista esta vacia
int ll_isEmpty(LinkedList* this);

/// @fn int ll_push(LinkedList*, int, void*)
/// @brief Inserta un nuevo elemento en la lista en la posicion indicada
/// @param this Puntero a la lista
/// @param index Ubicacion donde se agregara el nuevo elemento
/// @param pElement Puntero al nuevo elemento
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  ( 0) Si funciono correctamente
int ll_push(LinkedList* this, int index, void* pElement);

/// @fn void ll_pop*(LinkedList*, int)
/// @brief Elimina el elemento de la posicion indicada y retorna su puntero
/// @param this Puntero a la lista
/// @param index Ubicacion del elemento eliminar
/// @return Retorna (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                 (pElement) Si funciono correctamente
void* ll_pop(LinkedList* this,int index);

/// @fn int ll_contains(LinkedList*, void*)
/// @brief Determina si la lista contiene o no el elemento pasado como parametro
/// @param this Puntero a la lista
/// @param pElement Puntero del elemento a verificar
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
///                  ( 1) Si contiene el elemento
///                  ( 0) si No contiene el elemento
int ll_contains(LinkedList* this, void* pElement);

/// @fn int ll_containsAll(LinkedList*, LinkedList*)
/// @brief Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this)
/// @param this Puntero a la lista
/// @param this2 Puntero a la lista
/// @return Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
///                  ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
///                  ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
int ll_containsAll(LinkedList* this,LinkedList* this2);

/// @fn LinkedList ll_subList*(LinkedList*, int, int)
/// @brief Crea y retorna una nueva lista con los elementos indicados
/// @param this Puntero a la lista
/// @param from Indice desde el cual se copian los elementos en la nueva lista
/// @param to Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
/// @return Retorna  (NULL) Error: si el puntero a la listas es NULL
///                  o si el indice from es menor a 0 o mayor al len de la lista
///                  o si el indice to es menor o igual a from o mayor al len de la lista
///                  (puntero a la nueva lista) Si ok
LinkedList* ll_subList(LinkedList* this,int from,int to);

/// @fn LinkedList ll_clone*(LinkedList*)
/// @brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
/// @param this Puntero a la lista
/// @return Retorna  (NULL) Error: si el puntero a la lista es NULL
///                  (puntero a la nueva lista) Si ok
LinkedList* ll_clone(LinkedList* this);

/// @fn int ll_sort(LinkedList*, int(*)(void*, void*), int)
/// @brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
/// @param this Puntero a la lista
/// @param pFunc Puntero a la funcion criterio
/// @param order [1] Indica orden ascendente - [0] Indica orden descendente
/// @return Retorna  (-1) Error: si el puntero a la listas es NULL
///                  ( 0) Si ok
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

/// @fn LinkedList ll_filter*(LinkedList*, int(*)(void*))
/// @brief Obtiene una nueva LinkedList que cumpla con el criterio de pFunc
/// @param this Puntero a LinkedList
/// @param pFunc Puntero a funcion
/// @return Retorna (NULL) Si ningun elemento coincide con el criterio de pFunc
/// 				(Puntero a nueva LinkedList) Si al menos un elemento cumplio el criterio de la funcion
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*));
