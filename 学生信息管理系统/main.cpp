/*
*  开发环境：vs2022
*  内容：设计基于命令行的学生信息管理系统，实现对学生信息的录入、查找、修改、删除等相关功能。
*  作者：xgh
*  时间：2023年12月
*/
#include <stdio.h>
#include "user.h"
#include "student.h"


int main()
{
	stu Administrator = { "1234","Administrator","",0,0,"1234" };
	list* a = InitList();
	EndInsertList(a, Administrator);
	list* p = InitList();
	StuRead(p);
	int choice=-1;
	while (true)
	{
		User_Menu();
		printf("请输入您的选择：\n");
		scanf_s("%d", &choice);
		getchar();
			switch (choice)
			{
			case 0:
				User_Exit();
				break;  //退出系统
			case 1:
				SLogin(p);
				break;  //学生登录
			case 2:
				ALogin(a);
				break;  //管理员登录	
			default:
				system("cls");
				break;
			}	
	}


	return 0;
}




