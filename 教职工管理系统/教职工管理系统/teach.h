#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define FILENAME "worker.bin"
#define N 20
typedef struct worker
{
	int grade;          /*�ɼ�*/
	int number;         /*����*/
	int counts;         /*����*/
	char name[10];      /*����*/
} Worker;
void Menu();  //��ʾ�˵�
int ReadInformation(Worker w[]);  //��ȡ���е�ְ����Ϣ
void Print(Worker w[], int len);  //��ʾְ����Ϣ��ʾ
int InformationInput(Worker w[], int len);  //����ְ����Ϣ
void WorkInput(Worker w[], int len);  //���������벢�ۼ�
void WorkSort(Worker w[], int len);  //���������Ӵ�С����
void WorkSortPrint(Worker w[], int len);  //���������Ӵ�С���������Ϣ
void IDFind(Worker w[], int len, int stunum);  //��ְ�����Ų�ѯ
void NameFind(Worker w[], int len, char stuname[]);  //��ְ��������ѯ
int IDDelet(Worker w[], int len, int stunum);  //��ְ����ɾ��ְ����Ϣ
void Exit(Worker w[], int len);  //�˳�����