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
	int Fnum;                  //�˱��
	char Fname[10];			  // ����
	char Fclasses[10];        // �����
	double Fprice;            //�˵���
public:
	Food(char *fclasses = NULL, int fnum = 0, char *fname = NULL, double fprice = 0) {};
	friend class Shop;
	friend class Guest;
};
class Shop
{
private:
	Food f[NUM];          //����ʳ������
	int num;              //ʵ������
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
	int Tnum;                     //����
	Food g_food[NUM];            //����˵���Ϣ
	int f_num[NUM];             //����
	int S;                      //��͵Ĳ˵�����
public:
	Guest(Shop p, int tnum = 0, int num_g = 0);
	void account();            //����
};