#include"teach.h"
void Menu() {  //显示菜单
	printf("\n  *******************************************************\n");
	printf("  *               职工工作量统计系统                    *\n");
	printf("  *                                                     *\n");
	printf("  *                1- 职工信息输入                      *\n");
	printf("  *                2- 输出信息                          *\n");
	printf("  *                3- 工作量累加输入                    *\n");
	printf("  *                4- 按工作量由大到小显示              *\n");
	printf("  *                5- 按职工工号查询信息                *\n");
	printf("  *                6- 按职工姓名查询信息                *\n");
	printf("  *                7- 按职工工号进行信息删除            *\n");
	printf("  *                8- 退出                              *\n");
	printf("  *******************************************************\n");
}
int ReadInformation(Worker w[]) {  //读取信息
	FILE *fp = NULL;
	int i = 0;
	fp = fopen(FILENAME, "rb");
	if (fp != NULL) {
		while (!feof(fp)) {
			if (i >= N)
				break;
			if (fread(w + i, sizeof(Worker), 1, fp) == 1)
				i++;
		}
		fclose(fp);
	}
	return i;
}
void Print(Worker w[], int len) {  //信息显示
	int i = 0;
	if (len == 0) {
		printf("系统中没有职工信息\n\n");
		return;
	}
	printf("%s %s", "职工号", "姓名");
	for (i = 0; i < len; i++) {
		printf("\n %3d %4s\n", w[i].number, w[i].name);
		printf("\n");
	}
}
int InformationInput(Worker w[], int len) {  //输入职工信息
	int i = len;
	while (i < N) {
		printf("第%d个职工\n", i + 1);
		printf("\n");
		printf("请你输入工号(以职工号为0结束):\n");
		scanf("%d", &w[i].number);
		if (w[i].number == 0)
			break;
		printf("\n");
		printf("请你输入姓名:\n");
		scanf("%s", w[i].name);
		printf("\n");
		printf("请你输入数量:\n");
		scanf("%d", &w[i].counts);
		printf("\n");
		i++;
	}
	return i;
}
void WorkInput(Worker w[], int len) {  //工作量输入并累加
	int i = 1;
	int number, counts;
	printf("请输入工号: (以0退出)");
	scanf("%d", &number);
	while (number != 0) {
		printf("请输入完成数量:\n");
		scanf("%d", &counts);
		for (i = 0; i < len; i++)
			if (w[i].number == number) {
				w[i].counts += counts;
				break;
			}
		if (i >= len)
			printf("工号不存在:\n");
		printf("请输入工号:\n");
		scanf("%d", &number);
	}
}
void WorkSort(Worker w[], int len) {  //按工作量从大到小排序
	int i = 0, j = 0, k = 0;
	Worker s;
	for (i = 0; i < len; i++) {
		k = i;
		for (j = i + 1; j < len; j++)
			if (w[j].counts > w[k].counts)
				k = j;
		s = w[k];
		w[k] = w[i];
		w[i] = s;
	}
	if (len > 0)
		w[0].grade = 1;
	for (i = 1; i < len; i++)
		if (w[i].counts == w[i - 1].counts)
			w[i].grade = w[i - 1].grade;
		else
			w[i].grade = w[i - 1].grade + 1;
}
void WorkSortPrint(Worker w[], int len) {  //显示信息
	int i = 0;
	int grade, count;
	if (len > 0) {
		while (i < len) {
			count = 0;
			grade = w[i].grade;
			printf("名次:%d \n", grade);
			printf("工作量:%-4d", w[i].counts);
			while (i < len) {
				if (grade == w[i].grade) {
					printf("%s", "工号:");
					printf("%-4d", w[i].number);
					printf("%s", "姓名:");
					printf("%-4s", w[i].name);
					count++;
				}
				else    break;
				i++;
			}
			printf("人数:%-3d\n", count);
		}
	}
	else   printf("没有职工!\n");
}
void IDFind(Worker w[], int len, int stunum) {  //按职工工号查询
	int i = 0;
	for (i = 0; i < len; i++) {
		if (stunum == w[i].number) {
			printf("如下：\n");
			printf("%s %s %s", "职工号", "姓名", "工作量");
			printf("\n %3d %5s %4d\n", w[i].number, w[i].name, w[i].counts);
			break;
		}
	}
	if (i >= len)
		printf("\n输入有误！\n");
}
void NameFind(Worker w[], int len, char stuname[]) {  //按职工姓名查询
	int i = 0;
	int found = 0;
	for (i = 0; i < len; i++) {
		if (strcmp(stuname, w[i].name) == 0) {
			found++;
			if (found == 1) {
				printf("如下：\n");
				printf("%s %s %s", "职工号", "姓名", "工作量");
			}
			printf("\n %3d %5s %4d\n", w[i].number, w[i].name, w[i].counts);
		}
	}
	if (found == 0)
		printf("查无此人\n");
}
int IDDelet(Worker w[], int len, int stunum) {  //按职工号删除职工信息
	int i, j;
	char inputs[2];
	for (i = 0; i < len; i++) {
		if (stunum == w[i].number)
			break;
	}
	if (i < len) {
		for (j = i; j < len; j++)
			w[j] = w[j + 1];
		len--;
		printf("删除成功!\n");
	}
	else    printf("\n职工不存在!\n");
	return len;
}
void Exit(Worker w[], int len) {  //退出程序
	FILE *fp = NULL;
	int i = 0;
	fp = fopen(FILENAME, "wb");
	if (fp == NULL) {
		printf("打开文件出错！\n");
		exit(0);
	}
	for (i = 0; i < len; i++)
		fwrite(w + i, sizeof(Worker), 1, fp);
	fclose(fp);
}