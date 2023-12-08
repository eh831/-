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

//管理员操作
void Stu_Choice()
{
	list* L = InitList(); //创建学生链表
	StuRead(L); //从文件读学生信息到链表
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
//学生信息录入
void Stu_Input(list* L) 
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
//学生信息查找
list* Stu_Seek(list* L) 
{
	int sum = 0;
	int state = 1; //查找成功标志位
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
			if (strcmp(p->data.name, s) == 0)  //遍历链表比较名字
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
//学生信息修改
void Stu_Amend(list* L) 
{
	list *p;
	stu temp;
	p=Stu_Seek(L);//按名字或学号找学生，找到返回节点地址
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
		p->data = temp; //将临时学生信息赋给数据域
		printf("成功修改学生信息！[]~(￣▽￣)~*\n");
	}
	StuSave(L); //保存到文件
	system("pause");
	system("cls");
}
//学生信息分类
void Stu_Class(list* L) 
{
	int d;
	list* i, * j;
	stu temp;
	list* f = InitList();//创建一个临时链表
	StuRead(f);  //读取文件学生信息到链表
	printf("1.按年级分类：\n");
	printf("2.按专业分类：\n");
	scanf_s("%d", &d);
	if (d == 1)//按年级分类
	{
		for (i = f->next; i != NULL; i = i->next)
		{
			for (j = i->next; j != NULL; j = j->next)
			{
				if (i->data.grade  > j->data.grade ) //冒泡算法比较年级大小，升序
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
				if (strcmp(i->data.major, j->data.major) > 0)//冒泡算法比较专业字符串大小，升序
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
		free(f->front); //遍历链表到最后一个节点，销毁每个节点的上个节点
	}
	free(f); //销毁最后一个节点
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
				if (strcmp(i->data.name, j->data.name) > 0)//冒泡算法比较名字字符串大小，升序
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
				if (i->data.age > j->data.age)//冒泡算法比较年龄大小，升序
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
	list* p=L->next; //指针指向第二个节点
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
				free(p->front);//遍历链表到最后一个节点，销毁每个节点的上个节点
			}
			free(p); //销毁最后一个节点
			L->next = NULL; //将头节点指向空
			StuSave(L); //将链表保存到文件中，清空文件
			printf("已清空学生信息！");
		}
	}
	else if (sum == 2)
	{
		p = Stu_Seek(L);  //通过学号或姓名查找，返回节点指针
		if (p != NULL)
		{
			printf("是否确认删除？1.确认\n");
			scanf_s("%d", &sum1);
			if (sum1 == 1)
			{
				p->front->next = p->next; //将节点的上一个节点的next指向下个节点
				p->next->front = p->front; //将节点的下一个节点的fornt指向上一个节点
				free(p); //释放当前节点
				StuSave(L); //将链表保存到文件中
				printf("已删除学生信息！\n");
			}
		}
	}
	system("pause");
	system("cls");
}

list* InitList() //初始化链表
{
	list * head = (list*)malloc(sizeof(list)); //创建一块内存空间存放头节点
	head->next = NULL;  //头节点指向空
	return head; //返回头节点
}
void EndInsertList(list *L, student s) //尾部插入一个结点
{
	list* end;
	end = L;
	while (end->next != NULL) //遍历到最后一个节点
	{
		end = end->next;
	}
	list* newNode = (list*)malloc(sizeof(list)); //开辟内存空间
	newNode->data = s; //节点数据域赋值
	newNode->next = NULL; //指针域指向空
	end->next = newNode;  //将链表最后一个节点连到新节点
	newNode->front = end; //新节点连上一个节点
}

void TraverList(list *L) //显示所有学生信息
{
	list* end = L->next;
	int i = 0;
	while (end != NULL)//遍历链表打印输出
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
	fopen_s(&fp, "Stu_file.txt", "w"); //打开文件只写
	if (fp != NULL)
	{
		while (end != NULL) //遍历链表将链表数据域中的数据写入到文件中
		{
			fwrite(&end->data, sizeof(student), 1, fp);
			end = end->next;
		}
		fclose(fp); //关闭文件
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
	fopen_s(&fp, "Stu_file.txt", "r");//打开文件只读
	if (fp != NULL)
	{

		while (fread(&temp, sizeof(student), 1, fp)) //读取文件中的数据存放到临时容器中，直到文件为空
		{
			EndInsertList(end, temp); //尾插一个新节点，将数据放进去
		}
		fclose(fp); //关闭文件
	}
	else
	{
		printf("文件打开失败！");
	}

}