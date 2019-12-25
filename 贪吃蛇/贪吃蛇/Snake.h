#pragma once
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#define U 1
#define D 2
#define L 3 
#define R 4   //蛇的状态，U：上 ；D：下；L:左 R：右
typedef struct SNAKE  //蛇身的一个节点
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