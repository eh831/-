#pragma once
#ifndef _student_h_
#define _student_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char num[20]; //ѧ��
	char name[20];  //����
	char major[20]; //רҵ
	int grade;  //�꼶
	int age;  //����
	char pwd[20]; //����
}stu;
typedef struct list_node {  //����˫������
	stu data; //������ ���һ��ѧ��
	list_node *next;  //ָ���� 
	list_node *front;  //ָ����
}list;


list* InitList(); //��ʼ������
void EndInsertList(list *L, student s); //β������һ�����
void TraverList(list *L); //��������
void Stu_Menu(); //��ʾ����Ա�˵�
void Stu_Choice(); //����Ա����
void Stu_Input(list *L); //ѧ����Ϣ¼��
list* Stu_Seek(list* L); //ѧ����Ϣ����
void Stu_Amend(list* L); //ѧ����Ϣ�޸�
void Stu_Class(list* L); //ѧ����Ϣ����
void Stu_Sort(list* L); //ѧ����Ϣ����
void StuSave(list* U); //ѧ����Ϣ����
void StuRead(list* U); //ѧ����Ϣ��ȡ
void StuDel(list* L); //ѧ����Ϣɾ��


#endif
