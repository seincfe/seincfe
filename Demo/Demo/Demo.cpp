#include"Demo.h"
void menu()
{
	cout << "........��ѡ��......" << endl;
	cout << "---------1��ɾ����Ʒ---------" << endl;
	cout << "---------2���޸���Ʒ---------" << endl;
	cout << "---------3����ѯ��Ʒ---------" << endl;
	cout << "---------0���˳�---------" << endl;
	cout << endl;
}
void out_menu()
{
	cout << "-----------��  ѡ  ��-----------" << endl;
	cout << "-----------1���̵����----------" << endl;
	cout << "-----------2���˿Ͳ���----------" << endl;
	cout << "-----------0����   ��-----------" << endl;
}
/*Food::Food(int fnum, char *fname, char *fclasses, double fprice)
{
}*/
Shop::Shop()
{
	cout << "��������𡢱�š����ơ�����(�ÿո����)" << endl;
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
			cout << "�������µļ۸�" << endl;
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
			cout << "���" << "���" << "����" << "�۸�" << endl;
			cout << f[i].Fclasses << f[i].Fnum << f[i].Fname << f[i].Fprice << endl;
		}
	}
}
void Shop::Show_menu()
{
	cout << "--------�˵�---------" << endl;
	cout << "���" << setw(8) << "���" << setw(10) << "����" << setw(10) << "�۸�" << endl;
	for (int i = 0; i < num; i++)
	{

		cout << f[i].Fclasses << setw(8) << f[i].Fnum << setw(8) << f[i].Fname << setw(8) << f[i].Fprice << endl;
	}
	cout << "��Ʒ��Ŀ��" << num << endl;;
}
Guest::Guest(Shop p, int tnum, int num_g)
{
	int j;
	cout << "����������" << endl;
	cin >> Tnum;
	cout << "�������˵�����" << endl;
	cin >> S;

	for (int i = 0; i < S; i++)
	{
		cout << "��������Ʒ���" << endl;
		cin >> j;
		for (int k = 0; k < p.num; k++)
		{
			if (j == p.f[k].Fnum)
				g_food[i] = p.f[k];
		}
		cout << "���������:" << endl;
		cin >> num_g;
		f_num[i] = num_g;
	}

}
void Guest::account()
{
	double sum = 0;
	char select;
	cout << "�Ƿ�Ϊ��Ա y:��  n:���� " << endl;
	cin >> select;
	cout << "----------���ѵ�-----------" << endl;
	cout << "����:" << Tnum << endl;
	cout << "����" << setw(8) << "����" << setw(8) << "�۸�" << endl;
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
		cout << "�ܼ�:" << sum << endl;
	}
	else if (select == 'y' || select == 'Y')
	{
		for (int i = 0; i < S; i++)
		{
			sum = sum + f_num[i] * g_food[i].Fprice;
		}
		cout << "�ܼ�:" << sum << endl;
		cout << "�ۺ�ۣ�" << sum * 0.8 << endl;
	}
}