#include"Demo.h"
int main()
{
	int n, m;
	int flag = 1, out_flag = 1;
	Shop s;
	out_menu();
	while (out_flag)
	{
		cout << "请输入你的选择" << endl;
		cin >> n;
		int flag = 1;
		switch (n)
		{
		case 1:
		{
			s.Show_menu();
			menu();
			while (flag)
			{
				cout << "请输入你的选择" << endl;
				cin >> m;
				switch (m)
				{
				case 1:
				{
					int num;
					cout << "请输入要删除商品的编号" << endl;
					cin >> num;
					s.Food_delete(num);
					s.Show_menu();
					break;
				}
				case 2:
				{
					int num;
					cout << "请输入要修改商品的编号" << endl;
					cin >> num;
					s.Food_amend(num);
					s.Show_menu();
					break;
				}
				case 3:
				{
					int num;
					cout << "请输入要查询商品的编号" << endl;
					cin >> num;
					s.Food_find(num);
					s.Show_menu();
					break;
				}
				case 0:
				{
					out_menu();
					flag = 0;
					break;
				}
				}
			}
			break;
		}
		case 2:
		{
			Guest g(s);
			g.account();
			out_menu();
			break;
		}
		case 0:
		{
			out_flag = 0;
			break;
		}
		}
	}
	system("pause");
	return 0;
}
