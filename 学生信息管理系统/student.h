#pragma once
#ifndef _student_h_
#define _student_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char num[20]; //学号
	char name[20];  //名字
	char major[20]; //专业
	int grade;  //年级
	int age;  //年龄
	char pwd[20]; //密码
}stu;
typedef struct list_node {  //创建双向链表
	stu data; //数据域 存放一个学生
	list_node *next;  //指针域 
	list_node *front;  //指针域
}list;


list* InitList(); //初始化链表
void EndInsertList(list *L, student s); //尾部插入一个结点
void TraverList(list *L); //遍历链表
void Stu_Menu(); //显示管理员菜单
void Stu_Choice(); //管理员界面
void Stu_Input(list *L); //学生信息录入
list* Stu_Seek(list* L); //学生信息查找
void Stu_Amend(list* L); //学生信息修改
void Stu_Class(list* L); //学生信息分类
void Stu_Sort(list* L); //学生信息排序
void StuSave(list* U); //学生信息保存
void StuRead(list* U); //学生信息读取
void StuDel(list* L); //学生信息删除


#endif
