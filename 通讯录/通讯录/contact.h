#ifndef  __CONTACT_H__
#define __CONTACT_H__
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 15
#define ADDER_MAX 30
#define DEFAULT_SZ 3//默认大小
#define DEFAULT_INC  2
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
typedef struct PeoInfo//定义个人信息结构体
{
	char name[NAME_MAX];
	long int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDER_MAX];
} PeoInfo;
typedef struct Contact
{
	PeoInfo *data;//数据存储的区域
	int sz;//统计放入的个数
	int capacity;//容量
}Contact, *pContact;
void InitContact(pContact pcon);//结构体初始化
void AddContact(pContact pcon);
int SearchContact(pContact pcon);
void DelContact(pContact pcon);
void ModifyContact(pContact pcon);
void ShowContact(const pContact pcon);
void SortContact(pContact pcon);
void ClearContact(pContact pcon);
void DestroyContact(pContact pcon);
#endif
