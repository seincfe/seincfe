#include"Demo.h"
void menu()
{
	cout << "........请选择......" << endl;
	cout << "---------1、删除商品---------" << endl;
	cout << "---------2、修改商品---------" << endl;
	cout << "---------3、查询商品---------" << endl;
	cout << "---------0、退出---------" << endl;
	cout << endl;
}
void out_menu()
{
	cout << "-----------请  选  择-----------" << endl;
	cout << "-----------1、商店操作----------" << endl;
	cout << "-----------2、顾客操作----------" << endl;
	cout << "-----------0、退   出-----------" << endl;
}
/*Food::Food(int fnum, char *fname, char *fclasses, double fprice)
{
}*/
Shop::Shop()
{
	cout << "请输入类别、编号、名称、单价(用空格隔开)" << endl;
	for (int i = 0; i < NUM; i++)
	{
		cin >> f[i].Fclasses >> f[i].Fnum >> f[i].Fname >> f[i].Fprice;
	}
	num = NUM;
}
void Shop::Food_delete(int fnum)
{
	num--;
	for (int i = 0; i < num; i++)
	{
		if (f[i].Fnum == fnum)
		{
			for (int j = i; j < num; j++)
			{
				f[j] = f[j + 1];
			}
		}
	}
}
void Shop::Food_amend(int fnum)
{
	for (int i = 0; i < num; i++)
	{
		if (f[i].Fnum == fnum)
		{
			double y;
			cout << "请输入新的价格" << endl;
			cin >> y;
			f[i].Fprice = y;
		}
	}
}
void Shop::Food_find(int fnum)
{
	for (int i = 0; i < num; i++)
	{
		if (f[i].Fnum == fnum)
		{
			cout << "类别" << "编号" << "菜名" << "价格" << endl;
			cout << f[i].Fclasses << f[i].Fnum << f[i].Fname << f[i].Fprice << endl;
		}
	}
}
void Shop::Show_menu()
{
	cout << "--------菜单---------" << endl;
	cout << "类别" << setw(8) << "编号" << setw(10) << "菜名" << setw(10) << "价格" << endl;
	for (int i = 0; i < num; i++)
	{

		cout << f[i].Fclasses << setw(8) << f[i].Fnum << setw(8) << f[i].Fname << setw(8) << f[i].Fprice << endl;
	}
	cout << "商品数目：" << num << endl;;
}
Guest::Guest(Shop p, int tnum, int num_g)
{
	int j;
	cout << "请输入桌号" << endl;
	cin >> Tnum;
	cout << "请输入点菜的样数" << endl;
	cin >> S;

	for (int i = 0; i < S; i++)
	{
		cout << "请输入商品编号" << endl;
		cin >> j;
		for (int k = 0; k < p.num; k++)
		{
			if (j == p.f[k].Fnum)
				g_food[i] = p.f[k];
		}
		cout << "请输入份数:" << endl;
		cin >> num_g;
		f_num[i] = num_g;
	}

}
void Guest::account()
{
	double sum = 0;
	char select;
	cout << "是否为会员 y:是  n:不是 " << endl;
	cin >> select;
	cout << "----------消费单-----------" << endl;
	cout << "桌号:" << Tnum << endl;
	cout << "菜名" << setw(8) << "数量" << setw(8) << "价格" << endl;
	for (int i = 0; i < S; i++)
	{
		cout << g_food[i].Fname << setw(8) << f_num[i] << setw(4) << g_food[i].Fprice << endl;
	}
	if (select == 'n' || select == 'N')
	{
		for (int i = 0; i < S; i++)
		{
			sum = sum + f_num[i] * g_food[i].Fprice;
		}
		cout << "总价:" << sum << endl;
	}
	else if (select == 'y' || select == 'Y')
	{
		for (int i = 0; i < S; i++)
		{
			sum = sum + f_num[i] * g_food[i].Fprice;
		}
		cout << "总价:" << sum << endl;
		cout << "折后价：" << sum * 0.8 << endl;
	}
}