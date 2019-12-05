#include"teach.h"
int main() {
	int input;
	Worker work[N];
	char workname[100];
	int workID;
	int len = ReadInformation(work);
	while (1) {
		Menu();
		scanf("%d", &input);
		switch (input) {
		case 1:
			len = InformationInput(work, len);
			break;
		case 2:
			Print(work, len);
			break;
		case 3:
			WorkInput(work, len);
			break;
		case 4:
			WorkSort(work, len);
			WorkSortPrint(work, len);
			break;
		case 5:
			printf("请输入职工号：\n");
			scanf("%d", &input);
			IDFind(work, len, input);
			break;
		case 6:
			printf("请输入姓名:\n");
			scanf("%s", &workname);
			NameFind(work, len, workname);
			break;
		case 7:
			printf("请输入要删除的职工号：\n");
			scanf("%d", &workID);
			len = IDDelet(work, len, workID);
			break;
		case 8:
			Exit(work, len);
			printf("再见\n");
			exit(0);
		default:
			printf("重新输入\n");
			scanf("%d", &input);
		};
	}
}