#pragma once

/**
 * �˵�ѡ��.
 */
typedef enum StudentOpstions
{
	Quit,	//�˳�
	Entry,	//¼��
	Print,	//��ӡ
	Save,	//����
	Read,	//��ȡ
	Statistics,	//ͳ��
	Select,	//����
	Update,	//�޸�
	Delete,	//ɾ��
}StudentOpstions;

/**
 * ѧ���ṹ��.
 */
typedef struct Student {
	unsigned long long number;	//ѧ��
	char name[32];	//����
	float chinese;	//����
	float math;	//��ѧ
	float english;	//Ӣ��
}Student;

/**
 * �ڵ�.
 */
typedef struct Node
{
	Student stu;	//ѧ��
	struct Node* next;	//��һ���ڵ�
}Node;

/**
 * ͷ�ڵ�.
 */
typedef struct List
{
	Node* front;	//ͷ�ڵ�
	int size;	//����
}List;

/**
 * �˵�.
 */
int menu();

/**
 * ¼��ѧ����Ϣ.
 */
void entryStudent(List* list);




