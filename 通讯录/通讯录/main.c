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
	printf("###########  ͨѶ¼   ###########\n");
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
	InitContact(&my_con);  //��ʼ��ͨѶ¼
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>: ");
		scanf("%d", &input);
		switch (input)
		{
		case Exit:
			DestroyContact(&my_con);
			break;
		case Add:
			AddContact(&my_con);  //������ϵ��
			break;
		case Del:
			DelContact(&my_con);  //ɾ����ϵ��
			break;
		case Search:
			SearchContact(&my_con);  //��ѯ��ϵ��
			break;
		case Modify:
			ModifyContact(&my_con);  //�޸���ϵ��
			break;
		case Show:
			ShowContact(&my_con);  //��ʾ��ϵ��
			break;
		case Sort:
			SortContact(&my_con);  //����ϵ�����򣬰���������
			break;
		case Clear:
			ClearContact(&my_con);  //���ͨѶ¼
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}

