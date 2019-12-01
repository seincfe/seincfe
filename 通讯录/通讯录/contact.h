#ifndef  __CONTACT_H__
#define __CONTACT_H__
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 15
#define ADDER_MAX 30
#define DEFAULT_SZ 3//Ĭ�ϴ�С
#define DEFAULT_INC  2
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
typedef struct PeoInfo//���������Ϣ�ṹ��
{
	char name[NAME_MAX];
	long int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDER_MAX];
} PeoInfo;
typedef struct Contact
{
	PeoInfo *data;//���ݴ洢������
	int sz;//ͳ�Ʒ���ĸ���
	int capacity;//����
}Contact, *pContact;
void InitContact(pContact pcon);//�ṹ���ʼ��
void AddContact(pContact pcon);
int SearchContact(pContact pcon);
void DelContact(pContact pcon);
void ModifyContact(pContact pcon);
void ShowContact(const pContact pcon);
void SortContact(pContact pcon);
void ClearContact(pContact pcon);
void DestroyContact(pContact pcon);
#endif
