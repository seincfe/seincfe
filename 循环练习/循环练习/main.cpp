1.�׳˼��׳˺ͣ�
```c
#include<stdio.h>
int main()
{
	int i, a, j = 1, k = 0;
	scanf("%d", &a);  //������Ҫ����Ľ׳���
	for (i = 1; <= a; i++)
	{
		j = j * i;  //�׳�
		k = j + k;
	}  //�׳˺�
	printf("%d,%d\n", j, k);
	return 0;
}
```
2.�����������в���һ�������±꣨�۰�����㷨����
```c
#include<stdio.h>
int binsearch(int key, int arr[])  //���ܲ���
{
	int mid;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;  //�ж��ַ�ʵ���ܳ���
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else break;    //�������������ѭ��
	}
	if (arr[mid] != key) return -1;  //��δ�ҵ��򷵻�ֵΪ-1
	else  return mid;  //���ҵ��򷵻��±�
}
int main()
{
	int a;
	int arr[] = { 2, 8, 11, 56, 66, 77, 88, 99, 100 };
	printf("�������к�����������\n");
	printf("2, 8, 11, 56, 66, 77, 88, 99, 100\n");
	printf("������Ҫ�����±������\n");
	scanf("%d", &a);
	int index = binsearch(a, arr);  //�������ã����������������ݸ����������շ���ֵ
	if (index != -1) printf("�ҵ���,�±���%d\n", index);  //�ж��Ƿ��ҵ������
	if (index == -1) printf("������\n");
	return 0;
}
```
3.�ַ����Խ�������ʽ��������ϵ��£���
```c
#include<stdio.h>
#include<string.h>
#include<Windows.h>  //����ϵͳ����
int main()
{
	char a[] = "Li Ne Shi Wo De Er Zi";
	char b[] = "                     ";
	int c = strlen(a) / 2;  //���м俪ʼ���ȼ����ַ������ȵ�һ��
	int d = strlen(a) / 2;
	while (c <= d && c != 0)  //�ж�ִ�����������ַ���������ʱ����
	{
		Sleep(100);  //ϵͳ���0.1s������
		b[c] = a[c];  //�����滻
		b[d] = a[d];  //�����滻
		c--;
		d++;
		printf("%s\n", b);
	}
	printf("%s\n", a);
	return 0;
}
```
4.��'#'��������
```c
#include <stdio.h>
#include<Windows.h>
#include<string.h>
int main()
{
	char a[] = "###########################################";
	char b[] = "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	int c = 0;
	int d = strlen(b) - 1;  //�����ַ�������
	printf("%s\n", a);
	while (c <= d)  //�ж�ִ������
	{
		Sleep(100);
		a[c] = b[c];
		a[d] = b[d];
		c++;
		d--;
		printf("%s\n", a);
	}
	return 0;
}
```
5.���ַ�����һֱ���������
```c
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#define SIZE 10  // SIZE �� EOF ���Ǳ�ʶ��
int main()
{
	char a;
	while ((a = getchar()) != EOF)  // EOF : END OF FILE 
	{
		putchar(a);
	}  //��ctrl+zʹ�ļ���β
	return 0;
}
```
6.ʵ�������Сд�ַ���ת����
```c
#include<stdio.h>
#include<string.h>
int main()
{
	char a;
	while ((a = getchar()) != EOF)
	{
		if (a >= 'a' && a <= 'z')putchar(a - 32);
		if (a >= 'A' && a <= 'Z')putchar(a + 32);
		else ��
	}
	return 0;
}
```