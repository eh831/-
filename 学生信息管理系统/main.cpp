/*
*  ����������vs2022
*  ���ݣ���ƻ��������е�ѧ����Ϣ����ϵͳ��ʵ�ֶ�ѧ����Ϣ��¼�롢���ҡ��޸ġ�ɾ������ع��ܡ�
*  ���ߣ�xgh
*  ʱ�䣺2023��12��
*/
#include <stdio.h>
#include "user.h"
#include "student.h"


int main()
{
	stu Administrator = { "1234","Administrator","",0,0,"1234" };
	list* a = InitList(); //��������Ա����
	EndInsertList(a, Administrator); //��ӹ���Ա�˺ŵ�����
	list* p = InitList();  //����ѧ������
	StuRead(p); //��ȡ�ļ��е�ѧ����Ϣ��ѧ������
	int choice=-1;
	while (true)
	{
		User_Menu();
		printf("����������ѡ��\n");
		scanf_s("%d", &choice);
		getchar();
			switch (choice)
			{
			case 0:
				User_Exit();
				break;  //�˳�ϵͳ
			case 1:
				SLogin(p);
				break;  //ѧ����¼
			case 2:
				ALogin(a);
				break;  //����Ա��¼	
			default:
				system("cls");
				break;
			}	
	}
	return 0;
}




