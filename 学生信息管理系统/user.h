#pragma once
#ifndef _user_h_
#define _user_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#pragma warning(disable:4996)


void User_Menu(); //�û��˵�
list* Login(list* U); //��¼
void SLogin(list* U); //ѧ����¼
void ALogin(list* U); //����Ա��¼
void User_Exit(); //�˳�ϵͳ


#endif
