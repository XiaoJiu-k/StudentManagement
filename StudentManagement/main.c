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
			break;
		case Print:
			break;
		case Save:
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
