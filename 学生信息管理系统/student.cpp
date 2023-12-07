#include "student.h"
#include "user.h"

//管理员菜单
void Stu_Menu()
{
	printf("------------------------------------------------\n");
	printf("----------欢迎管理员[]~(￣▽￣)~*---------------\n");
	printf("------------  1.学生信息录入   -----------------\n");
	printf("------------  2.学生信息查找   -----------------\n");
	printf("------------  3.学生信息修改   -----------------\n");
	printf("------------  4.学生信息删除   -----------------\n");
	printf("------------  5.学生信息分类   -----------------\n");
	printf("------------  6.学生信息排序   -----------------\n");
	printf("------------  7.显示所有学生   -----------------\n");
	printf("------------  0.退出系统       -----------------\n");
	printf("------------------------------------------------\n");
}

void Stu_Choice()
{
	list* L = InitList();
	StuRead(L);
	int choice = -1;
	while (1)
	{
		system("cls");
		Stu_Menu();
		printf("请输入您的选择：\n");
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 0:
			User_Exit();
			break;  //退出系统
		case 1:
			Stu_Input(L);
			break;  //学生信息录入
		case 2:
			Stu_Seek(L);
			break;  //学生信息查找
		case 3:
			Stu_Amend(L);
			break;  //学生信息修改
		case 4:
			StuDel(L); 
			break;  //学生信息删除
		case 5:
			Stu_Class(L);
			break;  //学生信息分类
		case 6:
			Stu_Sort(L);
			break;  //学生信息排序
		case 7:
			TraverList(L);
			break;  //显示所有学生信息
		default:
			system("cls");
			break;
		}
	}
	
}

void Stu_Input(list* L) //学生信息录入
{
	int sum=0;
	stu temp;
	printf("输入多少个学生的信息：");
	scanf_s("%d", &sum);
	for (int i=0; i < sum; i++)
	{
		printf("请输入学生的姓名：\n");
		scanf_s("%s", temp.name,20);
		printf("请输入学生的学号：\n");
		scanf_s("%s", temp.num, 20);
		printf("请输入学生的年龄：\n");
		scanf_s("%d", &temp.age);
		printf("请输入学生的专业：\n");
		scanf_s("%s", temp.major, 20);
		printf("请输入学生的年级：\n");
		scanf_s("%d", &temp.grade);
		strcpy_s(temp.pwd, "1234");
		EndInsertList(L, temp);  //将学生信息加到新节点
		printf("成功添加学生信息！[]~(￣▽￣)~*");
		system("pause");
		system("cls");
	}
	StuSave(L); //保存到文件
}
list* Stu_Seek(list* L) //学生信息查找
{
	int sum = 0;
	int state = 1;
	list* p = L;
	list* out = NULL;
	char s[20];
	printf("1.使用姓名查找\n");
	printf("2.使用学号查找\n");
	scanf_s("%d", &sum);
	if (sum == 1)
	{
		printf("请输入姓名:");
		scanf_s("%s", s,sizeof(s));
		while (p !=NULL)
		{
			if (strcmp(p->data.name, s) == 0)
			{
				printf("学生的姓名：%s\n", p->data.name);
				printf("学生的学号：%s\n", p->data.num);
				printf("学生的年龄：%d\n", p->data.age);
				printf("学生的专业：%s\n", p->data.major);
				printf("学生的年级：%d\n", p->data.age);
				state = 0;
				out = p;
			}
			p = p->next;
		}
		if (state)
		printf("没有找到对应的姓名╰(*°▽°*)╯\n");
	}
	else if (sum == 2)
	{
		printf("请输入学号:");
		scanf_s("%s", s, sizeof(s));
		while (p != NULL)
		{
			if (strcmp(p->data.num, s) == 0)
			{
				printf("学生的姓名：%s\n", p->data.name);
				printf("学生的学号：%s\n", p->data.num);
				printf("学生的年龄：%d\n", p->data.age);
				printf("学生的专业：%s\n", p->data.major);
				printf("学生的年级：%d\n", p->data.age);
				state = 0;
				out = p;
			}
			p = p->next;
		}
		if(state)
		printf("没有找到对应的学号╰(*°▽°*)╯\n");

	}
	system("pause");
	system("cls");
	return out; //返回该学生节点地址
}
void Stu_Amend(list* L) //学生信息修改
{
	list *p;
	stu temp;
	p=Stu_Seek(L);
	if (p != NULL)  //如果p还是头节点则没找到学生
	{
		printf("开始修改该同学的信息！\n");
		printf("请输入学生的新姓名：\n");
		scanf_s("%s", &temp.name, 20);
		printf("请输入学生的新学号：\n");
		scanf_s("%s", &temp.num, 20);
		printf("请输入学生的新年龄：\n");
		scanf_s("%d", &temp.age);
		printf("请输入学生的新专业：\n");
		scanf_s("%s", &temp.major, 20);
		printf("请输入学生的新年级：\n");
		scanf_s("%d", &temp.grade);
		p->data = temp;
		printf("成功修改学生信息！[]~(￣▽￣)~*\n");
	}
	StuSave(L); //保存到文件
	system("pause");
	system("cls");
}
void Stu_Class(list* L) //学生信息分类
{
	int d;
	list* i, * j;
	stu temp;
	list* f = InitList();//创建一个临时链表
	StuRead(f);
	printf("1.按年级分类：\n");
	printf("2.按专业分类：\n");
	scanf_s("%d", &d);
	if (d == 1)//按年级分类
	{
		for (i = f->next; i != NULL; i = i->next)
		{
			for (j = i->next; j != NULL; j = j->next)
			{
				if (i->data.grade  > j->data.grade )
				{
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}

			}
		}
		TraverList(f); //显示分类好的学生信息
	}
	else if (d == 2)//按专业分类
	{
		for (i = f->next; i != NULL; i = i->next)
		{
			for (j = i->next; j != NULL; j = j->next)
			{
				if (strcmp(i->data.major, j->data.major) > 0)
				{
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}

			}
		}
		TraverList(f); //显示分类好的学生信息
	}
	while (f->next != NULL)//销毁链表
	{
		f = f->next;
		free(f->front);
	}
}
void Stu_Sort(list* L) //学生信息排序
{
	stu temp;
	int sum;
	list* i, *j;
	printf("1.按姓名排序\n");
	printf("2.年龄排序\n");
	scanf_s("%d", &sum);
	if (sum == 1)
	{
		for (i = L->next; i !=NULL; i=i->next)
		{
			for (j = i->next; j!=NULL; j=j->next)
			{
				if (strcmp(i->data.name, j->data.name) > 0)
				{
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
				
			}
		}
		printf("排序成功！[]~(￣▽￣)~*\n");
	}
	else if (sum == 2)
	{
		for (i = L->next; i != NULL; i=i->next)
		{
			for (j = i->next; j != NULL; j=j->next)
			{
				if (i->data.age > j->data.age)
				{
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}
		printf("排序成功！[]~(￣▽￣)~*\n");
	}
	StuSave(L); //保存到文件
	system("pause");
	system("cls");
}
void StuDel(list* L) //学生信息删除
{
	int sum=0,sum1=0;
	list* p=L->next;
	printf("1.清空学生信息！\n");
	printf("2.按学号或姓名查找删除学生信息！\n");
	scanf_s("%d", &sum);
	if (sum == 1)
	{
		printf("是否确认清空？1.确认\n");
		scanf_s("%d", &sum1);
		if (sum1 == 1)
		{
			while (p->next!=NULL)
			{
				p = p->next;
				free(p->front);
			}
			L->next = NULL;
			StuSave(L);
			printf("已清空学生信息！");
		}
	}
	else if (sum == 2)
	{
		p = Stu_Seek(L);
		if (p != NULL)
		{
			printf("是否确认删除？1.确认\n");
			scanf_s("%d", &sum1);
			if (sum1 == 1)
			{
				p->front->next = p->next;
				free(p);
				StuSave(L);
				printf("已删除学生信息！\n");
			}
		}
	}
	system("pause");
	system("cls");
}

list* InitList() //初始化链表
{
	list * head = (list*)malloc(sizeof(list));
	head->next = NULL;
	return head;
}
void EndInsertList(list *L, student s) //尾部插入一个结点
{
	list* end;
	end = L;
	while (end->next != NULL)
	{
		end = end->next;
	}
	list* newNode = (list*)malloc(sizeof(list));
	newNode->data = s;
	newNode->next = NULL;
	end->next = newNode;
	newNode->front = end;
}

void TraverList(list *L) //显示所有学生信息
{
	list* end = L->next;
	int i = 0;
	while (end != NULL)
	{
		printf("学生%d的姓名：%s  \t", i, end->data.name);
		printf("学生%d的学号：%s  \t", i, end->data.num);
		printf("学生%d的年龄：%d  \t", i, end->data.age);
		printf("学生%d的专业：%s  \t", i, end->data.major);
		printf("学生%d的年级：%d  \t\n", i, end->data.age);
		end = end->next;
		i++;
	}
	system("pause");
	system("cls");
}

void StuSave(list* U) //学生信息保存
{
	list* end = U->next;
	FILE* fp;
	fopen_s(&fp, "Stu_file.txt", "w");
	if (fp != NULL)
	{
		while (end != NULL)
		{
			fwrite(&end->data, sizeof(student), 1, fp);
			end = end->next;
		}
		fclose(fp);
	}
	else
	{
		printf("文件打开失败！");
	}
}
void StuRead(list* U) //学生信息读取
{
	list* end = U;
	FILE* fp;
	student temp;
	fopen_s(&fp, "Stu_file.txt", "r");
	if (fp != NULL)
	{

		while (fread(&temp, sizeof(student), 1, fp))
		{
			EndInsertList(end, temp);
		}
		fclose(fp);
	}
	else
	{
		printf("文件打开失败！");
	}

}