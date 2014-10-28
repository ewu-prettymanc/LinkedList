/****************************
 * Colton Prettyman         *
 * Hw1 OpSys 340 EWU        *
 * Professor Stuart Steiner *
 * 04-06-14                 *
 ****************************/

#include "utility.h"

//------------------------------------------------------------------------------
FILE * openFile()
{
  FILE * fin = NULL;
  char  buffer[MAX_LEN];

  while( ! fin )
    {
      printf("Enter the input filename:\n> ");
      fscanf(stdin,"%s", buffer);
      
      fin = fopen(buffer, "r" );
    }
  
  printf("'%s' opened successfully!\n",buffer);

  return fin;
}

//------------------------------------------------------------------------------
/*
processFile – takes the FILE pointer and the linked list as a parameters. 
It reads each word from the file and adds the word as part of a word structure 
to the linkedlist in the order read in. The memory for each Node will be 
dynamically allocated and the memory for the name will be dynamically 
allocated. This function will run until the end of file is reached. Don’t 
forget to close the file at the end of the function 
*/
void processFile(FILE * fin, Node ** head )
{
  char buffer[MAX_LEN];
  Node * temp = NULL;

  while( fscanf(fin, "%s", buffer )!= EOF )
    {
      temp = createNode(buffer);
      addLast( temp, head );
    }

  fclose(fin);
}

//------------------------------------------------------------------------------
/*menu – displays the following menu 
  1) Add a Word 
  2) Delete a Word 
  3) Clear the List 
  4) Find a Word 
  5) Print the List 
  6) Sort the List by word (ascending order) 
  7) Sort the list by the lengths of the word primary, alphabetical secondary
  8) Quit – This function will ensure the number is within range – Located in
   utility.h & utility.c
*/
int menu()
{
  int choice = 0;
  int done = -1;

  while( done < 0 )
    {
      done = 1;

      printf("\n");
      printf("1) Add a Word\n");
      printf("2) Delete a Word\n");
      printf("3) Clear the List\n");
      printf("4) Find a Word\n");
      printf("5) Print the List\n");
      printf("6) Sort the List by word (ascending order)\n");
      printf("7) Sort the List by the lengths of the word primary, alphabetical secondary\n");
      printf("8) Quit\n");
      
      printf("\n");
      printf("Enter a choice:\n> ");
      
      if( fscanf(stdin,"%d",&choice) == 0 || 
	  choice < 1 || choice > 8  )
      	{
	  printf("Invalid input!\n");
	  done = -1;
	}

      flush(stdin);
    }

  return choice;
}

//------------------------------------------------------------------------------
/*
doChoice – execute the corresponding functions that go with the menu choices
*/
void doChoice(int choice, Node ** head)
{
  switch( choice )
    {
    case 1 : menuAddFirst( head);
      break;
    case 2 : menuDeleteWord( head);
      break;
    case 3 : menuClear(head);
      break;
    case 4 : menuFind(head);
      break;
    case 5 : printList(*head);
      break;
    case 6 : sortListAscending(head);
      break;
    case 7 : sortListAscendingByLength(head);
      break;
    default : // They entered 8...just return simulating a quit
      break;
    }
}


//------------------------------------------------------------------------------
// menuAddFirst adds the word entered by the user to the front of the list
void menuAddFirst(Node ** head )
{
  Node * temp = getUserWordNode();
  Word * w =  temp->data;

  addFirst(temp, head );
  printf("'%s' added successfully!\n", w->word);
}

//------------------------------------------------------------------------------
void menuDeleteWord(Node ** head )
{
  Node * temp = getUserWordNode();
  Word * w = temp->data;
  int result = -1;
  
  result = delete(temp, head );
  
   if( result > 0)
     fprintf(stdout, "'%s' deletion successful!\n", w->word);
  else
    fprintf(stdout, "'%s' deletion unsuccessful!\n", w->word);
  
  freeNode(temp);
}

//------------------------------------------------------------------------------
void menuClear( Node ** head )
{
  clearList(head);

  fprintf(stdout, "Linked List cleared!\n");
}

//------------------------------------------------------------------------------
void menuFind(Node ** head )
{
  int result = -1;

  Node * temp = getUserWordNode();
  Word * w = temp->data;

  result = find(temp, *head);
  
   if( result > 0 )
     fprintf(stdout, "'%s' found!\n", w->word);
  else
    fprintf(stdout, "'%s' not found!\n", w->word);
  
  freeNode(temp);
}

//------------------------------------------------------------------------------
Node * getUserWordNode()
{
  char buffer[MAX_LEN];

  fprintf(stdout, "Enter a word:\n> ");
  fscanf(stdin, "%s", buffer);
   
  return createNode(buffer);
}

//------------------------------------------------------------------------------
Node * createNode(char * buffer )
{
  Node * temp = NULL;
  Word * word = NULL;
  int length=0;
  
  length = strlen(buffer); 

  word = calloc(1,sizeof(Word));
  if( ! word )
    {
      fprintf(stderr, "Error allocating word in createNode!\n");
      exit(EXIT_FAILURE);
    }
  
  word->length = length;
  
  word->word = calloc(1,length*sizeof(char) + 1 ); // +1 for '\0'
  if( ! word->word )
    {
      fprintf(stderr, "Error allocating word data in createNode!\n");
      exit(EXIT_FAILURE);
    }

  strcpy(word->word, buffer);
  
  temp = calloc(1, sizeof(Node));
  if( ! temp )
    {
      fprintf(stderr, "Error allocating Node in createNode!\n");
      exit(EXIT_FAILURE);
    }
  
  temp->data = word;
  
  return temp;
}

//------------------------------------------------------------------------------
void flush(FILE* stream)
{
  char c;
  
  for( fscanf (stream,"%c", &c); c!= '\n'; fscanf(stream, "%c" , &c ) )
    ;
}
