#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "StudentManagement.h"

int main()
{
	List list = { 0 };
	memset(&list, 0, sizeof(List));
	
	bool isRunning = true;
	while (isRunning)
	{ 
		StudentOpstions m;
		switch (menu())
		{
		case Quit:
			isRunning = false;
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
			//readStudent(&list);
			readStudentHuman(&list);
			break;
		case Statistics:
			statisticsStudent(&list);
			break;
		case Select:
		{
			Node* node = SelectStudent(&list);
			if (!node)
				printf("没有找到学生");
			else
				printf("%llu\t%s\t%.1f\t%.1f\t%.1f\n", node->stu.number, node->stu.name, node->stu.chinese, node->stu.math, node->stu.english);
			break;
		}
		case Update:
			UpdateStudent(&list);
			break;
		case Delete:
			DeleteStudent(&list);
			break;
		default:
			break;
		}
		if (isRunning) {
			system("pause");
			system("cls");
		}
	}
	
	//自动保存
	saveStudent(&list);
	saveStudentHuman(&list);
}
