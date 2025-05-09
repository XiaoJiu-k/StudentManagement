#pragma once

/**
 * 菜单选择.
 */
typedef enum StudentOpstions
{
	Quit,	//退出
	Entry,	//录入
	Print,	//打印
	Save,	//保存
	Read,	//读取
	Statistics,	//统计
	Select,	//查找
	Update,	//修改
	Delete,	//删除
}StudentOpstions;

/**
 * 学生结构体.
 */
typedef struct Student {
	unsigned long long number;	//学号
	char name[32];	//姓名
	float chinese;	//语文
	float math;	//数学
	float english;	//英语
}Student;

/**
 * 节点.
 */
typedef struct Node
{
	Student stu;	//学生
	struct Node* next;	//下一个节点
}Node;

/**
 * 头节点.
 */
typedef struct List
{
	Node* front;	//头节点
	int size;	//数量
}List;

/**
 * 菜单.
 */
int menu();
 
/**
 * 录入学生信息.
 */
void entryStudent(List* list);

/**
 * 打印学生信息.
 */
void printStudent(List* list);

/**
 * 保存学生信息.
 */
void saveStudent(List* list);
void saveStudentHuman(List* list);

/**
 * 读取学生信息.
 */
void readStudent(List* list);
void readStudentHuman(List* list);

/**
 * 统计学生人数.
 */
void statisticsStudent(List* list);

/**
 * 查询学生信息.
 */
Node* SelectStudent(List* list);

/**
 * 修改学生信息.
 */
void UpdateStudent(List* list);

/**
 * 删除学生信息.
 */
void DeleteStudent(List* list);





