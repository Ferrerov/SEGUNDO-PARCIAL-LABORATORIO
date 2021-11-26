#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/// @fn Node getNode*(LinkedList*, int)
/// @brief Obtiene un nodo de la lista
/// @param this Puntero a la lista
/// @param nodeIndex Indice del nodo a obtener
/// @return Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  (pNode) Si funciono correctamente
static Node* getNode(LinkedList* this, int nodeIndex);

/// @fn int addNode(LinkedList*, int, void*)
/// @brief Agrega y enlaza un nuevo nodo a la lista
/// @param this Puntero a la lista
/// @param nodeIndex Ubicacion donde se agregara el nuevo nodo
/// @param pElement Puntero al elemento a ser contenido por el nuevo nodo
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///                  ( 0) Si funciono correctamente
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;  //Creacion de variable tipo LinkedList
    this = (LinkedList *) malloc(sizeof(LinkedList));  //Asignacion de memoria con malloc
    if(this != NULL) //Verifica que se haya podido asignar la memoria
    {
    	this->size = 0; //Inicializa el tamaño en 0
    	this->pFirstNode = NULL; //Incializa la direccion de memoria en NULL
    }
    return this; //Retorna la direccion de memoria del LinkedList
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this->size; //Le asigna a la variable a retornar, el tamaño de la LinkedList
    }
    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node *node = NULL;   //Creacion de un nuevo nodo
	int len;

	len = ll_len(this);
	if(this != NULL && nodeIndex > -1 && nodeIndex < len) //Verifica que LinkedList exista y que el indice sea valido
	{
		node = this->pFirstNode; //Obtiene la direccion de memoria adonde apunta la cabecera
		for(int i=0; i < nodeIndex; i++) //Recorre todos los nodos hasta llegar al indice indicado
		{
			node = node->pNextNode; //Cuando encuentra el elemento en el indice indicado asigna la direccion de memoria
		}
	}
    return node;
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node *newNode = NULL;
    Node *auxNode = NULL;
    int len;

    len = ll_len(this);
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len) //Verifica que la LinkedList exista y que el indice sea valido
    {
    	newNode = (Node*)malloc(sizeof(Node)); //Asigna espacio en memoria al nuevo nodo
    	if(newNode != NULL)
    	{
    		if(nodeIndex != 0)
    		{
    			auxNode = getNode(this, nodeIndex - 1); //Busca el nodo anterior al indice especificado
    			newNode->pNextNode = auxNode->pNextNode; //Al nuevo nodo le asigna el pNextNode del nodo anterior
    			auxNode->pNextNode = newNode; //Al nodo anterior le asigna la direccion de memoria del nuevo nodo
    		}
    		else
    		{
    			newNode->pNextNode = this->pFirstNode; //Al pNextNode del nuevo nodo le asigna el pFirstNode de la cabecera
    			this->pFirstNode = newNode; //Al pFirstNode del nuevo nodo le asigna la direccion de memoria del nuevo nodo
    		}
    		newNode->pElement = pElement; //Le asigna el elemento al nueov nodo
    		this->size++; //Suma en uno el tamaño de la lista
    		returnAux = 0;
    	}
    }
    return returnAux;
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this != NULL)
    {
    	index = ll_len(this);
    	addNode(this, index, pElement); //Añade un nuevo nodo con los parametros pasados al final de LinkedList
    	returnAux = 0;
    }

    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node *pNode = NULL;
    int len;

	len = ll_len(this);
    if(this != NULL && index >= 0 && index < len) //Verifica que LinkedList exista y que el indice sea valido
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement; //Retorna el elemento que esta en el indice especificado
    	}
    }

    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node *pNode = NULL;
    int len;

	len = ll_len(this);
    if(this != NULL && index >= 0 && index < len) //Verifica que LinkedList exista y que el indice sea valido
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement; //Le asigna al pElement del nodo especificado un elemento pasado por parametro
    		returnAux = 0;
    	}
    }

    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node *pNode = NULL;
    Node *auxNode = NULL;
    int len;

    len = ll_len(this);
    if(this != NULL && index >= 0 && index < len) //Verifica que la LinkedList no sea nula y que el indice sea valido
    {
    	pNode = getNode(this, index); //Nodo a eliminar
    	if(pNode != NULL)
    	{
    		if(index > 0)
    		{
    			auxNode = getNode(this, index-1); //Obtiene el nodo anterior al nodo a eliminar
    			auxNode->pNextNode = pNode->pNextNode; //Asigna el pNextNode del nodo a eliminar, al nodo anterior
    		}
    		else
    		{
    			this->pFirstNode = pNode->pNextNode; //Le asigna a la cabecera el pNextNode del nodo a eliminar
    		}
    		free(pNode); //Libera en memoria el nodo eliminado
    		this->size--; //Resta en uno el tamaño del LinkedList
    		returnAux = 0;
    	}
    }

    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);
    if(this != NULL && len > -1)
    {
    	for(int i=0; i < len; i++)  //Recorre todos los nodos hasta llegar al ultimo
    	{
    		ll_remove(this, i); //Libera el nodo del indice especificado
    		returnAux = 0;
    	}
    }
    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && ll_clear(this) == 0)  //Utilizando ll_clear elimina todos los nodos del LinkedList
    {
    	free(this); //Libera en memoria la LinkedList
    	returnAux = 0;
    }

    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    void *auxElement;

    len = ll_len(this);
    if(this != NULL && len > -1)
    {
    	for(int i=0; i < len; i++) //Recorre todos los nodos hasta llegar a una coincidencia
    	{
    		auxElement = ll_get(this, i);
    		if(auxElement == pElement) //Obtiene el pElement y lo compara con el pElement pasado por parametro
    		{
    			returnAux = i; //Si son iguales, sale del for y devuelve el indice
    			break;
    		}
    	}
    }

    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(this->size > 0)
    	{
    		returnAux = 0; //Devuelve 0 porque hay por lo menos un nodo en la lista
    	}
    	else
    	{
    		returnAux = 1; //Devuelve 1 porque no hay nodos en la lista, por lo que esta vacia
    	}
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);
    if(this != NULL && index <= len && index > -1) //Verifica que la LinkedList no sea NULL y que el indice sea valido
    {
    	addNode(this, index, pElement);  //Utilizando la funcion addNode, agrega el nodo con los parametros pasados
    	returnAux = 0;
    }

    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;

    len = ll_len(this);
    if(this != NULL && index <= len && index > -1) //Verifica que la LinkedList no sea NULL y que el indice sea valido
    {
    	returnAux = ll_get(this, index); //Obtiene la direccion de memoria del pElement de la lista en el indice especificado
    	ll_remove(this, index);  //Elimina el nodo donde esta ese elemento
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    void *auxElement;

    len = ll_len(this);
    if(this != NULL && len > -1) //Verifica que la LinkedList exista y que tenga por lo menos un nodo
    {
    	returnAux = 0;
    	for(int i=0; i<len ;i++) //Recorre la lista hasta el ultimo elemento o hasta encontrar el elemento
    	{
    		auxElement = ll_get(this, i);
    		if(auxElement == pElement) //Obtiene el pElement del indice especificado y lo compara con el pElement pasado por parametro
    		{
    			returnAux = 1;  //Si lo encuentra, significa que lo contiene, devuelve 1 y sale del for
    			break;
    		}
    	}
    }

    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    void *auxElement;

    len = ll_len(this2);

    if(this != NULL && this2 != NULL && len > -1) //Verifica que ambas LinkedList existan y que la segunda tenga por lo menos un nodo
    {
    	returnAux = 1;
    	for(int i=0; i<len; i++) //Recorre toda la lista hasta el ultimo nodo o hasta encontrar que un elemento no esta contenido
    	{
    		auxElement = ll_get(this2, i); //Obtiene el pElement del indice especificado en la segunda LinkedList para comparar
    		if(ll_contains(this, auxElement) != 1)  //Utilizando ll_contains verifica si el elemento se encuentra en la primera LinkedList
    		{
    			returnAux = 0; //Si no encuentra un elemento, no contiene todos los elementos, por lo que sale del for y devuelve 0
    			break;
    		}
    	}
    }

    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
    void *auxElement;

    len = ll_len(this);
    if(this != NULL && to <= len && to > from && from >= 0 && from < len) //Verifica que el LinkedList exista y que los rangos sean validos
    {
    	cloneArray = ll_newLinkedList(); //Crea la nueva LinkedList donde se van a copiar los elementos
    	if(cloneArray != NULL)
    	{
    		for(int i=from; i<to; i++) //Recorre el LinkedList hasta el ultimo nodo
    		{
    			auxElement = ll_get(this, i); //Obtiene el elemento de la LinkedList en el indice especificado
    			ll_add(cloneArray, auxElement); //Añade un nuevo nodo a la nueva lista, insertando el elemento
    		}
    	}
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;
	void *auxElement;

	len = ll_len(this);
	if(this != NULL && len > -1) //Verifica que la LinkedList exista y que tenga por lo menos un nodo
	{
		cloneArray = ll_newLinkedList(); //Crea la nueva LinkedList donde se van a copiar los elementos
		if(cloneArray != NULL)
		{
			for(int i=0; i<len; i++) //Recorre la LinkedList hasta el ultimo elemento
			{
				auxElement = ll_get(this, i); //Obtiene el pElement de la LinkedList en el indice especificado
				ll_add(cloneArray, auxElement); //Añade un nuevo nodo a la lista, insertando el elemento
			}
		}
	}

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux = -1;
	int len;
	Node *auxNodeOne;
	Node *auxNodeTwo;
	void *auxElement;
	int result;

	len = ll_len(this);
	if(this != NULL && order >= 0 && order <=1 && pFunc != NULL) //Verifica que LinkedList y pFunc no sean NULL y que el orden sea 1 o 2
	{
		auxNodeOne = this->pFirstNode; //Inicializa el primer auxiliar en el primer nodo
		for(int i=0; i<len-1; i++) //Recorre LinkedList hasta la anteultima posicion para comparar
		{
			auxNodeTwo = auxNodeOne->pNextNode; //Asigna al segundo auxiliar la posicion siguiente al primer auxiliar
			for(int j=i+1; j<len; j++)  //Recorre LinkedList desde la posicion siguiente al primer elemento
			{
				result = pFunc(auxNodeOne->pElement, auxNodeTwo->pElement);  //Obtiene el resultado de la comparacion entre ambos elementos

				if((order == 0 && result < 0) || (order == 1 && result > 0 ))  //Verifica que se den las condiciones para el swap
				{
					auxElement = auxNodeOne->pElement;
					auxNodeOne->pElement = auxNodeTwo->pElement;
					auxNodeTwo->pElement = auxElement;
					returnAux = 0;
				}
				auxNodeTwo = auxNodeTwo->pNextNode; //Asigna al segundo auxiliar el nodo que le sigue
			}
			auxNodeOne = auxNodeOne->pNextNode; //Asigna al primer auxiliar el nodo que le sigue

		}
	}

    return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* newArray = NULL;
	void *auxElement;

	if(this != NULL && ll_len(this) > 0) //Verifica que la LinkedList exista y que tenga al menos un elemento
	{
		newArray = ll_newLinkedList(); //Crea una nueva LinkedList
		if(newArray != NULL)
		{
			for(int i = 0; i < ll_len(this); i++) //Itera hasta el final de la LinkedList pasada como parametro
			{
				auxElement = ll_get(this, i); //Obtiene cada elemento de la LinkedList
				if(pFunc(auxElement) == 1) //Verifica que el elemento pasado a la funcion retorne 1(ok)
				{
					ll_add(newArray, auxElement); //Añade el elemento a la nueva LinkedList
				}
			}
		}
	}
	return newArray;
}
