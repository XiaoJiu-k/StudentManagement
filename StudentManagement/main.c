#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "StudentManagement.h"

int main()
{
	List list = { 0 };
	memset(&list, 0, sizeof(List));
	

	while (true) 
	{ 
		StudentOpstions m;
		switch (menu())
		{
		case Quit:
			break;
		case Entry:
			entryStudent(&list);
			break;
		case Print:
			printStudent(&list);
			break;
		case Save:
			saveStudent(&list);
			saveStudentHuman(&list);
			break;
		case Read:
			break;
		case Statistics:
			break;
		case Select:
			break;
		case Update:
			break;
		case Delete:
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}
