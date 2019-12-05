#include"teach.h"
void Menu() {  //��ʾ�˵�
	printf("\n  *******************************************************\n");
	printf("  *               ְ��������ͳ��ϵͳ                    *\n");
	printf("  *                                                     *\n");
	printf("  *                1- ְ����Ϣ����                      *\n");
	printf("  *                2- �����Ϣ                          *\n");
	printf("  *                3- �������ۼ�����                    *\n");
	printf("  *                4- ���������ɴ�С��ʾ              *\n");
	printf("  *                5- ��ְ�����Ų�ѯ��Ϣ                *\n");
	printf("  *                6- ��ְ��������ѯ��Ϣ                *\n");
	printf("  *                7- ��ְ�����Ž�����Ϣɾ��            *\n");
	printf("  *                8- �˳�                              *\n");
	printf("  *******************************************************\n");
}
int ReadInformation(Worker w[]) {  //��ȡ��Ϣ
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
void Print(Worker w[], int len) {  //��Ϣ��ʾ
	int i = 0;
	if (len == 0) {
		printf("ϵͳ��û��ְ����Ϣ\n\n");
		return;
	}
	printf("%s %s", "ְ����", "����");
	for (i = 0; i < len; i++) {
		printf("\n %3d %4s\n", w[i].number, w[i].name);
		printf("\n");
	}
}
int InformationInput(Worker w[], int len) {  //����ְ����Ϣ
	int i = len;
	while (i < N) {
		printf("��%d��ְ��\n", i + 1);
		printf("\n");
		printf("�������빤��(��ְ����Ϊ0����):\n");
		scanf("%d", &w[i].number);
		if (w[i].number == 0)
			break;
		printf("\n");
		printf("������������:\n");
		scanf("%s", w[i].name);
		printf("\n");
		printf("������������:\n");
		scanf("%d", &w[i].counts);
		printf("\n");
		i++;
	}
	return i;
}
void WorkInput(Worker w[], int len) {  //���������벢�ۼ�
	int i = 1;
	int number, counts;
	printf("�����빤��: (��0�˳�)");
	scanf("%d", &number);
	while (number != 0) {
		printf("�������������:\n");
		scanf("%d", &counts);
		for (i = 0; i < len; i++)
			if (w[i].number == number) {
				w[i].counts += counts;
				break;
			}
		if (i >= len)
			printf("���Ų�����:\n");
		printf("�����빤��:\n");
		scanf("%d", &number);
	}
}
void WorkSort(Worker w[], int len) {  //���������Ӵ�С����
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
void WorkSortPrint(Worker w[], int len) {  //��ʾ��Ϣ
	int i = 0;
	int grade, count;
	if (len > 0) {
		while (i < len) {
			count = 0;
			grade = w[i].grade;
			printf("����:%d \n", grade);
			printf("������:%-4d", w[i].counts);
			while (i < len) {
				if (grade == w[i].grade) {
					printf("%s", "����:");
					printf("%-4d", w[i].number);
					printf("%s", "����:");
					printf("%-4s", w[i].name);
					count++;
				}
				else    break;
				i++;
			}
			printf("����:%-3d\n", count);
		}
	}
	else   printf("û��ְ��!\n");
}
void IDFind(Worker w[], int len, int stunum) {  //��ְ�����Ų�ѯ
	int i = 0;
	for (i = 0; i < len; i++) {
		if (stunum == w[i].number) {
			printf("���£�\n");
			printf("%s %s %s", "ְ����", "����", "������");
			printf("\n %3d %5s %4d\n", w[i].number, w[i].name, w[i].counts);
			break;
		}
	}
	if (i >= len)
		printf("\n��������\n");
}
void NameFind(Worker w[], int len, char stuname[]) {  //��ְ��������ѯ
	int i = 0;
	int found = 0;
	for (i = 0; i < len; i++) {
		if (strcmp(stuname, w[i].name) == 0) {
			found++;
			if (found == 1) {
				printf("���£�\n");
				printf("%s %s %s", "ְ����", "����", "������");
			}
			printf("\n %3d %5s %4d\n", w[i].number, w[i].name, w[i].counts);
		}
	}
	if (found == 0)
		printf("���޴���\n");
}
int IDDelet(Worker w[], int len, int stunum) {  //��ְ����ɾ��ְ����Ϣ
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
		printf("ɾ���ɹ�!\n");
	}
	else    printf("\nְ��������!\n");
	return len;
}
void Exit(Worker w[], int len) {  //�˳�����
	FILE *fp = NULL;
	int i = 0;
	fp = fopen(FILENAME, "wb");
	if (fp == NULL) {
		printf("���ļ�����\n");
		exit(0);
	}
	for (i = 0; i < len; i++)
		fwrite(w + i, sizeof(Worker), 1, fp);
	fclose(fp);
}