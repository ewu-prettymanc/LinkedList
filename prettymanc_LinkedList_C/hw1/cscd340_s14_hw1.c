#include "linkedList.h"
#include "utility.h"

int main()
{
	int choice;
	Node * head = NULL;

	FILE * fin = openFile();

	processFile(fin, &head);
	printList(head);

	do
	{
		choice = menu();
		doChoice(choice, &head);

	}while(choice != 8);

	if(head != NULL)
		clearList(&head);

	return 0;

}// end main
