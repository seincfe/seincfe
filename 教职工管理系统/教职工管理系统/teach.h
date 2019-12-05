#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define FILENAME "worker.bin"
#define N 20
typedef struct worker
{
	int grade;          /*成绩*/
	int number;         /*工号*/
	int counts;         /*数量*/
	char name[10];      /*姓名*/
} Worker;
void Menu();  //显示菜单
int ReadInformation(Worker w[]);  //读取已有的职工信息
void Print(Worker w[], int len);  //显示职工信息显示
int InformationInput(Worker w[], int len);  //输入职工信息
void WorkInput(Worker w[], int len);  //工作量输入并累加
void WorkSort(Worker w[], int len);  //按工作量从大到小排序
void WorkSortPrint(Worker w[], int len);  //按工作量从大到小排序输出信息
void IDFind(Worker w[], int len, int stunum);  //按职工工号查询
void NameFind(Worker w[], int len, char stuname[]);  //按职工姓名查询
int IDDelet(Worker w[], int len, int stunum);  //按职工号删除职工信息
void Exit(Worker w[], int len);  //退出程序