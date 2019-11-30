#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _GAME_H_
#define _GAME_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW   10  //������
#define COL   10  //������
#define ROWS  12  //�ڲ�������
#define COLS  12  //�ڲ�������
#define MINE_NUM 20  //��������
void menu();  //��ӡ�˵�
void game();  //��ʼ��Ϸ
void Show(char board[][ROWS], int row, int col);  //��ӡ����
void InitBoard(char board[][COLS], char mine[][COLS], int row, int col);  //���̳�ʼ��
void SetMine(char mine[][COLS], int row, int col, int num);  //������
int FindMine(char mine[][ROWS], char board[][ROWS]);  //ɨ��
int GetMineCount(char mine[][ROWS], int row, int col);  //���㸽��������
int Set_Assist(int i, int arr[], int brr[], int x, int y);  //�����׵ĸ�������
#endif