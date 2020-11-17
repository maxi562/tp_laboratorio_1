#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode;
    int l = ll_len(this);
    int i;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <l)
    {
    	pNode = this->pFirstNode;
    	for(i=0; i<nodeIndex;i++)
    	{
    		pNode = pNode->pNextNode;
    	}

    }
    else
    {
    	pNode = NULL;
    }


    return pNode;

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* pNode = (Node*) malloc(sizeof(Node));
    Node* nodoAux;
    Node* nodoAnte;
    Node* nodoSig;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <=len && pNode != NULL)
    {
    	returnAux = 0;
    	pNode->pElement = pElement;
    	pNode->pNextNode = NULL;

    	if(nodeIndex==0 || len == 0)//Cuando la lista está vacìa
    	{
    		nodoAux = this->pFirstNode;
    		pNode->pNextNode = nodoAux;
    		this->pFirstNode = pNode;
    		this->size++;

    	}
    	else//Demas valores de la lista
    	{
    		nodoAnte = getNode(this,nodeIndex-1);
    		nodoSig = getNode(this,nodeIndex+1);
    		if(nodoSig != NULL)
    		{
    			nodoAnte->pNextNode = pNode;
    			pNode->pNextNode = nodoSig;
    		}
    		else
    		{
    			nodoAnte->pNextNode = pNode;
    			   pNode->pNextNode = NULL;
    		}
    		this->size++;
    	}

    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this!=NULL)
    {
    	returnAux = 0;
    	addNode(this,len,pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);
    Node* nodoAux;

    if(this != NULL && index >=0 && index <=len)
    {
    	nodoAux = getNode(this,index);
    	if(nodoAux!=NULL)
    	{
    		returnAux = nodoAux->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* nodoAux;

    if(this!=NULL && index>=0 && index < len)
    {
    	returnAux = 0;
    	nodoAux = getNode(this,index);
    	if(nodoAux !=NULL)
    	{
    		nodoAux->pElement = pElement;
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
	int len = ll_len(this);
	Node* nodoAux;
	Node* nodoSig;
	Node* nodoAnt;

	if(this!=NULL && index>=0 && index < len)
	{
	  	returnAux = 0;
	  	this->size--;
	  	if(index==0)//Eliminar primer elemento de la lista
	  	{
	  		nodoAux = getNode(this,index);
	  		nodoSig = getNode(this,index+1);
	  		if(nodoAux != NULL && nodoSig !=NULL)
	  		{
	  			this->pFirstNode = nodoSig;
	  			free(nodoAux);
	  		}
	  		else if(nodoAux!=NULL || nodoSig == NULL)
	  		{
	  			this->pFirstNode = NULL;
	  			free(nodoAux);
	  		}

	  	}
	  	else if(index == len-1)//Eliminar ùltimo elemento de la lista
	  	{
	  		nodoAux = getNode(this,index);
	  		nodoAnt = getNode(this,index-1);
	  		if(nodoAux != NULL && nodoAnt != NULL)
	  		{
	  			nodoAnt->pNextNode = NULL;
	  			free(nodoAux);
	  		}
	  	}
	  	else //Eliminar demas elementos de la lista
	  	{
	  		nodoAnt = getNode(this,index-1);
	  		nodoAux = getNode(this,index);

	  		nodoAnt->pNextNode = nodoAux->pNextNode;
	  		free(nodoAux);
	  	}


    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);
    int i;

    if(this!=NULL)
    {
    	returnAux = 0;
    	for(i=0;i<len;i++)
    	{
    		ll_remove(this,i);
    	}

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = -1;

	if(this!=NULL)
	{
	  	returnAux = 0;
	    ll_clear(this);
	    free(this);
	}
	    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    int i;
    Node* nodoAux;
    if(this!=NULL)
    {
    	for(i=0;i<len;i++)
    	{
    		nodoAux = getNode(this,i);
    		if(nodoAux->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this!=NULL)
    {
    	if(len==0)
    	{
    		returnAux = 1;
    	}
    	else if(len>0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	returnAux = 0;
    	addNode(this,index,pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodoAux;
    int len = ll_len(this);

    if(this != NULL && index >=0 && index <= len)
    {
    	nodoAux = getNode(this,index);
    	if(nodoAux != NULL)
    	{
    		returnAux = nodoAux->pElement;
    		ll_remove(this,index);
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pElemAux;
    int len = ll_len(this);
    int i;

    if(this!=NULL)
    {
    	returnAux = 0;
    	for(i=0;i<len;i++)
    	{
    		pElemAux =ll_get(this,i);
    		if(pElemAux == pElement)
    		{
    			returnAux = 1;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    int lenThisDos = ll_len(this2);
    int i;
    void* pElementAux;
    int contains;


    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(i=0;i<lenThisDos;i++)
    	{
    		pElementAux = ll_get(this2,i);
    		contains = ll_contains(this,pElementAux);
    		if(contains==0 || contains ==-1)
    		{
    			returnAux = 0;
    			break;
    		}

    	}

    }

    return returnAux;

}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    int i;
    Node* nodoAux;


    if(this != NULL && from>=0 && from <=len && to>from && to <=len)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(i=from;i<=to;i++)
    		{
    			nodoAux = getNode(this,i);
    			if(nodoAux!=NULL)
    			{
    				ll_add(cloneArray,nodoAux->pElement);
    			}
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);

    if(this!=NULL)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray!=NULL)
    	{
    		cloneArray = ll_subList(this,0,len);
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int funcion;
    int i;
    int len = ll_len(this);
    int swap;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;
    Node* nodoAnt;

    if(this!=NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	returnAux = 0;

    	do
    	{
    		swap = 0;
    		for(i=0;i<len-1;i++)
    		{
    			nodoAnt = getNode(this,i-1);
    			nodo1 = getNode(this,i);
    			nodo2 = getNode(this,i+1);
    			funcion = pFunc(nodo1->pElement,nodo2->pElement);
    				if((funcion == 1 && order == 1) || (funcion == -1 && order == 0) )
    				{
    					swap = 1;
    					nodoAux = nodo2;
    					nodo1->pNextNode = nodoAux->pNextNode;
    					nodo2->pNextNode = nodo1;
    					if(i==0)
    					{
    						this->pFirstNode = nodo2;
    					}
    					else
    					{
    						nodoAnt->pNextNode = nodo2;
    					}

    				}
    		}
    	}while(swap);
    }

    return returnAux;

}

