#include"contact.h"
enum
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Sort,
	Clear,

};
void menu()
{
	printf("#################################\n");
	printf("###########  通讯录   ###########\n");
	printf("###########  0.exit   ###########\n");
	printf("###########  1.add    ###########\n");
	printf("###########  2.del    ###########\n");
	printf("###########  3.search ###########\n");
	printf("###########  4.modify ###########\n");
	printf("###########  5.show   ###########\n");
	printf("###########  6.sort   ###########\n");
	printf("###########  7.clear  ###########\n");
	printf("#################################\n");
}
void test()
{
	Contact my_con;
	InitContact(&my_con);  //初始化通讯录
	int input = 0;
	do
	{
		menu();
		printf("请选择>: ");
		scanf("%d", &input);
		switch (input)
		{
		case Exit:
			DestroyContact(&my_con);
			break;
		case Add:
			AddContact(&my_con);  //增加联系人
			break;
		case Del:
			DelContact(&my_con);  //删除联系人
			break;
		case Search:
			SearchContact(&my_con);  //查询联系人
			break;
		case Modify:
			ModifyContact(&my_con);  //修改联系人
			break;
		case Show:
			ShowContact(&my_con);  //显示联系人
			break;
		case Sort:
			SortContact(&my_con);  //对联系人排序，按名字排序
			break;
		case Clear:
			ClearContact(&my_con);  //清空通讯录
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}

