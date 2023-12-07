#pragma once
#ifndef _user_h_
#define _user_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#pragma warning(disable:4996)


void User_Menu(); //用户菜单
list* Login(list* U); //登录
void SLogin(list* U); //学生登录
void ALogin(list* U); //管理员登录
void User_Exit(); //退出系统


#endif
