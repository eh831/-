#include "user.h"
#include "student.h"

//�û��˵�
void User_Menu()
{
	printf("-------------------------------------------------\n");
	printf("|   	                             	        |\n");
	printf("|   	  ��ӭ����ѧ����Ϣ����ϵͳ    	        |\n");
	printf("|   	         ��(*��0��)         	        |\n");
	printf("|   	         1.ѧ����¼  	                |\n");
	printf("|   	         2.����Ա��¼         	        |\n");
	printf("|   	         0.�˳�ϵͳ  	                |\n");
	printf("|   	                             	        |\n");
	printf("-------------------------------------------------\n");
}

//��¼
list* Login(list* U)
{
	char id[20], pwd[20];
	printf("�������˺�:\n");
	scanf_s("%s", id,20);
	printf("����������:\n");
	scanf_s("%s", pwd,20);
	list* p = U;
	list* L=NULL;
	while (p != NULL)
	{
		if (strcmp(p->data.num, id)==0 && strcmp(p->data.pwd, pwd) == 0)//��������Ƚ��˺�����
			{
			L = p;
			return p;
			}
		p = p->next;
	}		
	return 0;
}

void SLogin(list* U) //ѧ����¼
{
	list* p;
	p = Login(U);
	if (p!=NULL)//ѧ����¼
	{
		int choice = 0;
		printf("��¼�ɹ���\n");
		system("pause");
		system("cls");
		while (true)
		{
			printf("��ӭ%s����ѧ����Ϣ����ϵͳq(�R���Qq)��\n", p->data.name);
			printf("������%s  \n",  p->data.name);
			printf("ѧ�ţ�%s  \n",  p->data.num);
			printf("���䣺%d  \n",  p->data.age);
			printf("רҵ��%s  \n",  p->data.major);
			printf("�꼶��%d  \n", p->data.age);
			printf("1.�޸�����\n");
			printf("2.�˳�ϵͳ\n");
			scanf_s("%d", &choice);
			getchar();
			if (choice == 1)
			{
				printf("�������µ����룺\n");
				scanf_s("%s", p->data.pwd,sizeof(p->data.pwd));
				StuSave(U);					//���޸ĺ�����뱣�浽�ļ�
				printf("�޸ĳɹ���\n");
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
		printf("��¼ʧ�ܣ�\n");
		system("pause");
		system("cls");
	}
}
void ALogin(list* U) //����Ա��¼
{
	if (Login(U) != NULL)//����Ա��¼
	{
		printf("��¼�ɹ���\n");
		Stu_Choice();  //��������˵�����
	}
	else
	{
		printf("��¼ʧ�ܣ�\n");
		system("pause");
		system("cls");
	}
	
}

//�˳�ϵͳ
void User_Exit()
{
	printf("��ӭ���ٴ�ʹ��ѧ������ϵͳ�d(�R���Q*)o!");
	exit(0);
}