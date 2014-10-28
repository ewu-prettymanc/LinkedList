/****************************
 * Colton Prettyman         *
 * Hw1 OpSys 340 EWU        *
 * Professor Stuart Steiner *
 * 04-06-14                 *
 ****************************/

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "linkedList.h"
#include "Node.h"

//------------------------------------------------------------------------------
static unsigned int g_size = 0;

//------------------------------------------------------------------------------
void addFirst(Node * newNode, Node ** head);
void addLast(Node * newNode, Node ** head );
Node * addLast_rec(Node * newNode, Node * cur );
void printList(Node * head );
int find(Node * lookfor, Node * head );
int delete(Node * todelete, Node ** head );
Node * delete_rec( Node * todelete, Node * cur, int * result );
void sortListAscending( Node ** head );
void sortListAscendingByLength(Node ** head );
void mergeSort(Node ** head, int(*compareToptr)(Node*,Node*) );
Node * merge(Node * a, Node * b, Node * res, int(*compareToptr)(Node*,Node*) );
Node * reverse(Node * n, Node * res );
void split(Node * n, Node ** a, Node ** b, int which );
void clearList(Node ** head);

#endif
