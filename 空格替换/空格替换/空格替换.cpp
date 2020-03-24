#### 将字符串中的空格替换为"%20"
```c
#include <stdio.h>
void replaceSpace(char *str, int length) {
	if (str == NULL || length < 0)
		return;
	int i = 0;
	int oldnumber = 0;
	int replacenumber = 0;
	while (str[i] != '\0') {
		oldnumber++;
		if (str[i] == ' ')  //计算空格数量
			replacenumber++;
		i++;
	}
	int newlength = oldnumber + replacenumber * 2;  //每个空格替换需要增加两个字节
	if (newlength > length)  //判断开辟空间是否够用
		return;  //也可以使用realloc
	int pOldlength = oldnumber;
	int pNewlength = newlength;
	while (pOldlength >= 0 && pNewlength > pOldlength) {
		if (str[pOldlength] == ' ') {  //数组倒叙替换
			str[pNewlength--] = '0';
			str[pNewlength--] = '2';
			str[pNewlength--] = '%';
		}
		else
			str[pNewlength--] = str[pOldlength];  //若没有空格，则不需要替换
		pOldlength--;  //防止越界访问
	}
}
int main()
{
	char str[100] = "i a b";
	int length = sizeof(str);
	replaceSpace(&str, length);
	printf("%s\n", str);
	return 0;
}
```
