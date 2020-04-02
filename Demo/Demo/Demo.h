#include "iostream"
#include "stdlib.h"
#include "iomanip"
using namespace std;
const int NUM = 3;
class Guest;
void menu();
void out_menu();
class Food
{
private:
	int Fnum;                  //菜编号
	char Fname[10];			  // 菜名
	char Fclasses[10];        // 菜类别
	double Fprice;            //菜单价
public:
	Food(char *fclasses = NULL, int fnum = 0, char *fname = NULL, double fprice = 0) {};
	friend class Shop;
	friend class Guest;
};
class Shop
{
private:
	Food f[NUM];          //餐厅食物样数
	int num;              //实际样数
public:
	Shop();
	void Food_delete(int fnum);
	void Food_amend(int fnum);
	void Food_find(int fnum);
	void Show_menu();
	friend class Guest;
};
class Guest
{
private:
	int Tnum;                     //桌号
	Food g_food[NUM];            //所点菜的信息
	int f_num[NUM];             //份数
	int S;                      //点餐的菜的样数
public:
	Guest(Shop p, int tnum = 0, int num_g = 0);
	void account();            //结账
};