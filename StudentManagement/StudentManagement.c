#include "StudentManagement.h"
#include <stdio.h>
#include <malloc.h>

static Node* CreateNode() {
	//创建节点
	Node* node = malloc(sizeof(Node));
	if (!node) {
		printf("malloc failed\n");
		return NULL;
	}
	node->next = NULL;
	return node;
}

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
	Node* node = CreateNode();

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

/**
 * 打印学生信息.
 * 
 * \param list
 */
void printStudent(List* list)
{	
	printf("*****************\n");
	printf("*学号\t姓名\t语文\t数学\t英语*\n");
	printf("*****************\n");
	Node* currNode = list->front;
	while (currNode != NULL)
	{

		printf("%llu\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n", currNode->stu.number, currNode->stu.name, currNode->stu.chinese, currNode->stu.math, currNode->stu.english);
		currNode = currNode->next;

	}
}

/**
 * 保存学生信息(二进制).
 * 
 * \param list
 */
void saveStudent(List* list)
{
	//打开文件
	FILE* fp = fopen("Student.data", "wb");
	if (!fp) {
		perror("file open failed");
		return;
	}
	//保存
	Node* currNode = list->front;
	while (currNode != NULL) {
		fwrite(&currNode->stu, sizeof(Student), 1, fp);
		currNode = currNode->next;
	}
	//关闭
	fclose(fp);

}

/**
 * 保存学生信息(明文).
 * 
 * \param list
 */
void saveStudentHuman(List* list)
{
	//打开文件
	FILE* fp = fopen("Student.txt", "w");
	if (!fp) {
		perror("file open failed");
		return;
	}
	//保存
	Node* currNode = list->front;
	while (currNode != NULL) {
		fprintf(fp,"%llu\t%s\t%.1f\t%.1f\t%.1f\n", currNode->stu.number, currNode->stu.name, currNode->stu.chinese, currNode->stu.math, currNode->stu.english);
		currNode = currNode->next;
	}
	//关闭
	fclose(fp);
}

/**
 * 读取学生信息(二进制).
 * 
 * \param list
 */
void readStudent(List* list)
{	
	//打开文件
	FILE* fp = fopen("Student.data", "rb");
	if (!fp) {
		perror("file open failed");
		return;
	}
	
	while (!feof(fp))
	{
		Node* node = CreateNode();
		if (!node)
			break;
		
		fread(&node->stu, sizeof(Student), 1, fp);

		//插入链表
		node->next = list->front;
		list->front = node;
		list->size++;
	}


	//关闭
	fclose(fp);
}
/**
 * 读取学生信息(明文).
 * 
 * \param list
 */
void readStudentHuman(List* list)
{
}


