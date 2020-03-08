1.阶乘及阶乘和：
```c
#include<stdio.h>
int main()
{
	int i, a, j = 1, k = 0;
	scanf("%d", &a);  //输入所要计算的阶乘数
	for (i = 1; <= a; i++)
	{
		j = j * i;  //阶乘
		k = j + k;
	}  //阶乘和
	printf("%d,%d\n", j, k);
	return 0;
}
```
2.在有序数组中查找一个数的下标（折半查找算法）：
```c
#include<stdio.h>
int binsearch(int key, int arr[])  //接受参数
{
	int mid;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;  //判断字符实际总长度
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
		else break;    //其他情况则跳出循环
	}
	if (arr[mid] != key) return -1;  //若未找到则返回值为-1
	else  return mid;  //若找到则返回下标
}
int main()
{
	int a;
	int arr[] = { 2, 8, 11, 56, 66, 77, 88, 99, 100 };
	printf("本数组中含有以下数：\n");
	printf("2, 8, 11, 56, 66, 77, 88, 99, 100\n");
	printf("请输入要查找下标的数：\n");
	scanf("%d", &a);
	int index = binsearch(a, arr);  //函数调用，将输入的数和数组递给函数，接收返回值
	if (index != -1) printf("找到了,下标是%d\n", index);  //判断是否找到这个数
	if (index == -1) printf("不存在\n");
	return 0;
}
```
3.字符串以金字塔形式输出（由上到下）：
```c
#include<stdio.h>
#include<string.h>
#include<Windows.h>  //调用系统命令
int main()
{
	char a[] = "Li Ne Shi Wo De Er Zi";
	char b[] = "                     ";
	int c = strlen(a) / 2;  //从中间开始，先计算字符串长度的一半
	int d = strlen(a) / 2;
	while (c <= d && c != 0)  //判断执行条件，当字符串输出到最长时跳出
	{
		Sleep(100);  //系统命令，0.1s输出完成
		b[c] = a[c];  //数组替换
		b[d] = a[d];  //数组替换
		c--;
		d++;
		printf("%s\n", b);
	}
	printf("%s\n", a);
	return 0;
}
```
4.倒'#'金字塔：
```c
#include <stdio.h>
#include<Windows.h>
#include<string.h>
int main()
{
	char a[] = "###########################################";
	char b[] = "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	int c = 0;
	int d = strlen(b) - 1;  //计算字符串长度
	printf("%s\n", a);
	while (c <= d)  //判断执行条件
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
5.对字符串可一直输入输出：
```c
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#define SIZE 10  // SIZE 和 EOF 都是标识符
int main()
{
	char a;
	while ((a = getchar()) != EOF)  // EOF : END OF FILE 
	{
		putchar(a);
	}  //以ctrl+z使文件结尾
	return 0;
}
```
6.实现输入大小写字符的转换：
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
		else ；
	}
	return 0;
}
```