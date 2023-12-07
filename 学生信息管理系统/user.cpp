#include "user.h"
#include "student.h"

//用户菜单
void User_Menu()
{
	printf("-------------------------------------------------\n");
	printf("|   	                             	        |\n");
	printf("|   	  欢迎来到学生信息管理系统    	        |\n");
	printf("|   	         φ(*￣0￣)         	        |\n");
	printf("|   	         1.学生登录  	                |\n");
	printf("|   	         2.管理员登录         	        |\n");
	printf("|   	         0.退出系统  	                |\n");
	printf("|   	                             	        |\n");
	printf("-------------------------------------------------\n");
}

//登录
list* Login(list* U)
{
	char id[20], pwd[20];
	printf("请输入账号:\n");
	scanf_s("%s", id,20);
	printf("请输入密码:\n");
	scanf_s("%s", pwd,20);
	list* p = U;
	list* L=NULL;
	while (p != NULL)
	{
		if (strcmp(p->data.num, id)==0 && strcmp(p->data.pwd, pwd) == 0)//遍历链表比较账号密码
			{
			L = p;
			return p;
			}
		p = p->next;
	}		
	return 0;
}

void SLogin(list* U) //学生登录
{
	list* p;
	p = Login(U);
	if (p!=NULL)//学生登录
	{
		int choice = 0;
		printf("登录成功！\n");
		system("pause");
		system("cls");
		while (true)
		{
			printf("欢迎%s来到学生信息管理系统q(≧▽≦q)！\n", p->data.name);
			printf("姓名：%s  \n",  p->data.name);
			printf("学号：%s  \n",  p->data.num);
			printf("年龄：%d  \n",  p->data.age);
			printf("专业：%s  \n",  p->data.major);
			printf("年级：%d  \n", p->data.age);
			printf("1.修改密码\n");
			printf("2.退出系统\n");
			scanf_s("%d", &choice);
			getchar();
			if (choice == 1)
			{
				printf("请输入新的密码：\n");
				scanf_s("%s", p->data.pwd,sizeof(p->data.pwd));
				StuSave(U);					//将修改后的密码保存到文件
				printf("修改成功！\n");
				system("pause");
				system("cls");
			}
			else if (choice == 2)
			{
				User_Exit();
			}
			system("cls");
		}
		
	}
	else
	{
		printf("登录失败！\n");
		system("pause");
		system("cls");
	}
}
void ALogin(list* U) //管理员登录
{
	if (Login(U) != NULL)//管理员登录
	{
		printf("登录成功！\n");
		Stu_Choice();  //进入二级菜单界面
	}
	else
	{
		printf("登录失败！\n");
		system("pause");
		system("cls");
	}
	
}

//退出系统
void User_Exit()
{
	printf("欢迎您再次使用学生管理系统ヾ(≧▽≦*)o!");
	exit(0);
}