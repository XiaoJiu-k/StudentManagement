#include "StudentManagement.h"
#include <stdio.h>
#include <malloc.h>

/**
 * 打印菜单.
 *
 * \return
 */
int menu()
{
	printf("*****************\n");
	printf("****请选择功能****\n");
	printf("*****************\n");
	printf("****1、录入学生信息****\n");
	printf("****2、打印学生信息****\n");
	printf("****3、保存学生信息****\n");
	printf("****4、读取学生信息****\n");
	printf("****5、统计学生信息****\n");
	printf("****6、查找学生信息****\n");
	printf("****7、修改学生信息****\n");
	printf("****8、删除学生信息****\n");
	printf("****0、退出学生系统****\n");
	printf("select->");
	int select = -1;
	scanf("%d", &select);

	return select;
}

/**
 * 录入学生信息.
 * 
 * \param list
 */
void entryStudent(List* list)
{
	//创建节点
	Node* node = malloc(sizeof(Node));
	if (!node) {
		printf("malloc failed\n");
		return;
	}
	node->next = NULL;

	printf("请输入学号->");
	scanf("%llu", &node->stu.number);
	
	printf("请输入姓名->");
	scanf("%s", &node->stu.name);

	printf("请输入语文->");
	scanf("%f", &node->stu.chinese);

	printf("请输入数学->");
	scanf("%f", &node->stu.math);
	 
	printf("请输入英语->");
	scanf("%f", &node->stu.english);

	//插入连表
	node->next = list->front;
	list->front = node;
	list->size++;
}


