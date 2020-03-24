#### ���ַ����еĿո��滻Ϊ"%20"
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
		if (str[i] == ' ')  //����ո�����
			replacenumber++;
		i++;
	}
	int newlength = oldnumber + replacenumber * 2;  //ÿ���ո��滻��Ҫ���������ֽ�
	if (newlength > length)  //�жϿ��ٿռ��Ƿ���
		return;  //Ҳ����ʹ��realloc
	int pOldlength = oldnumber;
	int pNewlength = newlength;
	while (pOldlength >= 0 && pNewlength > pOldlength) {
		if (str[pOldlength] == ' ') {  //���鵹���滻
			str[pNewlength--] = '0';
			str[pNewlength--] = '2';
			str[pNewlength--] = '%';
		}
		else
			str[pNewlength--] = str[pOldlength];  //��û�пո�����Ҫ�滻
		pOldlength--;  //��ֹԽ�����
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
