#include "StudentManagement.h"
#include <stdio.h>
#include <malloc.h>

static Node* CreateNode() {
	//�����ڵ�
	Node* node = malloc(sizeof(Node));
	if (!node) {
		printf("malloc failed\n");
		return NULL;
	}
	node->next = NULL;
	return node;
}

/**
 * ��ӡ�˵�.
 *
 * \return
 */
int menu()
{
	printf("*****************\n");
	printf("****��ѡ����****\n");
	printf("*****************\n");
	printf("****1��¼��ѧ����Ϣ****\n");
	printf("****2����ӡѧ����Ϣ****\n");
	printf("****3������ѧ����Ϣ****\n");
	printf("****4����ȡѧ����Ϣ****\n");
	printf("****5��ͳ��ѧ����Ϣ****\n");
	printf("****6������ѧ����Ϣ****\n");
	printf("****7���޸�ѧ����Ϣ****\n");
	printf("****8��ɾ��ѧ����Ϣ****\n");
	printf("****0���˳�ѧ��ϵͳ****\n");
	printf("select->");
	int select = -1;
	scanf("%d", &select);

	return select;
}

/**
 * ¼��ѧ����Ϣ.
 * 
 * \param list
 */
void entryStudent(List* list)
{
	Node* node = CreateNode();

	printf("������ѧ��->");
	scanf("%llu", &node->stu.number);
	
	printf("����������->");
	scanf("%s", &node->stu.name);

	printf("����������->");
	scanf("%f", &node->stu.chinese);

	printf("��������ѧ->");
	scanf("%f", &node->stu.math);
	 
	printf("������Ӣ��->");
	scanf("%f", &node->stu.english);

	//��������
	node->next = list->front;
	list->front = node;
	list->size++;
}

/**
 * ��ӡѧ����Ϣ.
 * 
 * \param list
 */
void printStudent(List* list)
{	
	printf("*****************\n");
	printf("*ѧ��\t����\t����\t��ѧ\tӢ��*\n");
	printf("*****************\n");
	Node* currNode = list->front;
	while (currNode != NULL)
	{

		printf("%llu\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n", currNode->stu.number, currNode->stu.name, currNode->stu.chinese, currNode->stu.math, currNode->stu.english);
		currNode = currNode->next;

	}
}

/**
 * ����ѧ����Ϣ(������).
 * 
 * \param list
 */
void saveStudent(List* list)
{
	//���ļ�
	FILE* fp = fopen("Student.data", "wb");
	if (!fp) {
		perror("file open failed");
		return;
	}
	//����
	Node* currNode = list->front;
	while (currNode != NULL) {
		fwrite(&currNode->stu, sizeof(Student), 1, fp);
		currNode = currNode->next;
	}
	//�ر�
	fclose(fp);

}

/**
 * ����ѧ����Ϣ(����).
 * 
 * \param list
 */
void saveStudentHuman(List* list)
{
	//���ļ�
	FILE* fp = fopen("Student.txt", "w");
	if (!fp) {
		perror("file open failed");
		return;
	}
	//����
	Node* currNode = list->front;
	while (currNode != NULL) {
		fprintf(fp,"%llu\t%s\t%.1f\t%.1f\t%.1f\n", currNode->stu.number, currNode->stu.name, currNode->stu.chinese, currNode->stu.math, currNode->stu.english);
		currNode = currNode->next;
	}
	//�ر�
	fclose(fp);
}

/**
 * ��ȡѧ����Ϣ(������).
 * 
 * \param list
 */
void readStudent(List* list)
{	
	//���ļ�
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

		//��������
		node->next = list->front;
		list->front = node;
		list->size++;
	}


	//�ر�
	fclose(fp);
}
/**
 * ��ȡѧ����Ϣ(����).
 * 
 * \param list
 */
void readStudentHuman(List* list)
{
}


