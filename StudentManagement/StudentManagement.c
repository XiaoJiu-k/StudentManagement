#include "StudentManagement.h"
#include <stdio.h>


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
