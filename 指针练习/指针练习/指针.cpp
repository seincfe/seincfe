**1.**
```c
#include <stdio.h>
struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
int main()
{
	printf("%p\n", p);  //ָ��ָ��ĵ�ַ��00000000
	printf("%p\n", p + 0x1);  //ָ��ָ��ĵ�ַ+1���ָ���ַ��20ʮ������Ϊ14��00000014
	printf("%p\n", (unsigned long)p + 0x1);  //00000000ǿתΪlong�ͣ�+1��00000001
	printf("%p\n", (unsigned int*)p + 0x1);  //ǿתΪchar*�ͣ�+1��00000004
	return 0;
}
```
**2.**
```c
int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int *ptr1 = (int *)(&aa + 1);  //�����ַ+1��+40
int *ptr2 = (int *)(*(aa + 1));  //ָ��ڶ��е�һ��Ԫ��
printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));  //10��5
```
**3.**
```c
char *c[] = { "ENTER","NEW","POINT","FIRST" };
char **cp[] = { c + 3,c + 2,c + 1,c };
char ***cpp = cp;
printf("%s\n", **++cpp);  //*(*(++cpp)),��ʱcpp��ָ��c+2
printf("%s\n", *--*++cpp + 3);  //*(--*(++cpp))+3����ʱcpp��ָ��c+1
printf("%s\n", *cpp[-2] + 3);  //*(*(cpp-2))+3
printf("%s\n", cpp[-1][-1] + 1);  //*(*(cpp-1)-1)
```
**4.**
```c
#include <stdio.h>
int main()
{
	int a1[4] = { 1, 2, 3, 4 };
	int *ptr = ((int)a1 + 1);  //ptrָ��a1��ַǿתint�ͺ�+1�ĵ�ַ
	printf("%d\n", *ptr);
	return 0;
}
```
**5.**
```c
#include <stdio.h>
int main()
{
	int a[5][5];
	int(*p)[4] = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);  //FFFFFFFC��Ԫ�ؼ����-4��
	return 0;
}
```