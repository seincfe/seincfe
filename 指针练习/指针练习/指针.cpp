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
	printf("%p\n", p);  //指针指向的地址，00000000
	printf("%p\n", p + 0x1);  //指针指向的地址+1后的指针地址，20十六进制为14，00000014
	printf("%p\n", (unsigned long)p + 0x1);  //00000000强转为long型，+1即00000001
	printf("%p\n", (unsigned int*)p + 0x1);  //强转为char*型，+1即00000004
	return 0;
}
```
**2.**
```c
int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int *ptr1 = (int *)(&aa + 1);  //数组地址+1即+40
int *ptr2 = (int *)(*(aa + 1));  //指向第二行第一个元素
printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));  //10，5
```
**3.**
```c
char *c[] = { "ENTER","NEW","POINT","FIRST" };
char **cp[] = { c + 3,c + 2,c + 1,c };
char ***cpp = cp;
printf("%s\n", **++cpp);  //*(*(++cpp)),此时cpp已指向c+2
printf("%s\n", *--*++cpp + 3);  //*(--*(++cpp))+3，此时cpp已指向c+1
printf("%s\n", *cpp[-2] + 3);  //*(*(cpp-2))+3
printf("%s\n", cpp[-1][-1] + 1);  //*(*(cpp-1)-1)
```
**4.**
```c
#include <stdio.h>
int main()
{
	int a1[4] = { 1, 2, 3, 4 };
	int *ptr = ((int)a1 + 1);  //ptr指向a1地址强转int型后+1的地址
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
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);  //FFFFFFFC，元素间相差-4个
	return 0;
}
```