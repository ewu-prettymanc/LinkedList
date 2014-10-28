/****************************
 * Colton Prettyman         *
 * Hw1 OpSys 340 EWU        *
 * Professor Stuart Steiner *
 * 04-06-14                 *
 ****************************/

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Node.h"
#include "Word.h"

#define MAX_LEN 4096

//------------------------------------------------------------------------------
FILE * openFile();
void processFile(FILE * fin, Node ** head );
int menu();
void doChoice(int choice, Node ** head);
void menuAddFirst(Node ** head );
void menuDeleteWord(Node ** head );
void menuClear( Node ** head );
void menuFind(Node ** head );
Node * getUserWordNode();
Node * createNode(char * buffer );
void flush(FILE* stream);

#endif
