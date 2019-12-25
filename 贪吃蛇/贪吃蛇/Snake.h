#pragma once
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#define U 1
#define D 2
#define L 3 
#define R 4   //�ߵ�״̬��U���� ��D���£�L:�� R����
typedef struct SNAKE  //�����һ���ڵ�
{
	int x;
	int y;
	struct SNAKE *next;
} snake;
void Pos(int x, int y);
void creatMap();
void initSnake();
int biteSelf();
void createFood();
void cantCrossWall();
void snakeMove();
void pause();
void runGame();
void initGame();
void endGame();
void gameStart();