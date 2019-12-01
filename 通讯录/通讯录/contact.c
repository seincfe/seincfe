#include"contact.h"
void InitContact(pContact pcon)
{   //memset(pcon->data, 0, MAX*sizeof(PeoInfo));
	pcon->sz = 0;  //已经放了多少
	pcon->data = malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pcon->data == NULL)
	{
		perror("use malloc");//报错
		exit(EXIT_FAILURE);//退出
	}
	memset(pcon->data, 0, DEFAULT_SZ * sizeof(PeoInfo));
	pcon->capacity = DEFAULT_SZ;
}
void CheckCapacity(pContact pcon)
{
	if (pcon->sz == pcon->capacity)
	{
		PeoInfo* ptr = realloc(pcon->data, (pcon->capacity + DEFAULT_INC) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		else
		{
			pcon->data = ptr;
		}
		pcon->capacity += DEFAULT_INC;
		printf("增容成功\n");
	}
}
void DestroyContact(pContact pcon)
{
	free(pcon->data);
	pcon->data = NULL;
	pcon->capacity = 0;
	pcon->sz = 0;
}
void AddContact(pContact pcon)
{
	assert(pcon->data);
	CheckCapacity(pcon);
	printf("请输入名字>: ");
	scanf("%s", pcon->data[pcon->sz].name);
	printf("请输入性别>: ");
	scanf("%s", pcon->data[pcon->sz].sex);
	printf("请输入年龄>: ");
	scanf("%d", &pcon->data[pcon->sz].age);
	printf("请输入电话>: ");
	scanf("%s", pcon->data[pcon->sz].tele);
	printf("请输入地址>: ");
	scanf("%s", pcon->data[pcon->sz].addr);
	pcon->sz++;
	printf("录入成功\n");
}

static int FindEntry(pContact pcon, char name[])  //static只在当前文件使用
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
			return i;  //找到，返回下标
	}
	return -1;  //没找到
}

int SearchContact(pContact pcon)  //查找信息
{
	char name[NAME_MAX];
	printf("请输入要查找的姓名: ");
	scanf("%s", name);
	int pos = 0;
	pos = FindEntry(pcon, name);
	if (pos == -1)
	{
		printf("你要查找的人不存在\n");
		return;
	}
	else
	{
		printf("name:%10s\t sex：%5s\t age:%5d\t tele：%10s\t addr：%15s\n",
			pcon->data[pos].name,
			pcon->data[pos].sex,
			pcon->data[pos].age,
			pcon->data[pos].tele,
			pcon->data[pos].addr);
	}
}

void ShowContact(pContact pcon)
{
	printf("联系人信息：\n");
	int i = 0;
	printf("%10s\t%5s\t%5s\t%15s\t%20s\n", "name", "sex", "age", "tele", "addr");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%10s\t%5s\t%5d\t%10s\t%15s\n",
			pcon->data[i].name,
			pcon->data[i].sex,
			pcon->data[i].age,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
}
void DelContact(pContact pcon)  //删除联系人
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人\n");
	scanf("%s", name);
	int pos = 0;  //利用pos接收FindEntry返回的地址
	pos = FindEntry(pcon, name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在\n");
		return;
	}
	else
	{
		int j = 0;
		for (j = pos; j < pcon->sz; j++)
			pcon->data[j] = pcon->data[j + 1];  //利用后面一个覆盖前一个，从而达到删除的效果
		pcon->sz--;
		printf("删除成功\n");
	}
}
void ModifyContact(pContact pcon)
{
	char name[NAME_MAX];
	printf("请输入要修改的联系人\n");
	scanf("%s", name);
	int pos = 0;  //利用pos接收FindEntry返回的地址
	pos = FindEntry(pcon, name);
	if (pos != -1)
	{
		printf("请输入修改后的姓名： ");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("请输入修改后的性别： ");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("请输入修改后的年龄： ");
		scanf("%d", &pcon->data[pcon->sz].age);
		printf("请输入修改后的电话： ");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("请输入修改后的地址： ");
		scanf("%s", pcon->data[pcon->sz].addr);
		printf("修改完毕\n");
	}
	else
	{
		printf("要修改的联系人不存在！\n");
	}
}
void SortContact(pContact pcon)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < pcon->sz - 1; i++)
	{
		for (j = 0; j < pcon->sz - i - 1; j++)
		{
			if (strcmp(pcon->data[i].name, pcon->data[i + 1].name) > 0)
			{
				struct PeoInfo tmp;
				tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
			}
		}
	}
	printf("%10s\t%5s\t%5s\t%15s\t%20s\n", "name", "sex", "age", "tele", "addr");
	for (k = 0; k < pcon->sz; k++)
	{
		printf("%10s\t%5s\t%5d\t%10s\t%15s\n",
			pcon->data[k].name,
			pcon->data[k].sex,
			pcon->data[k].age,
			pcon->data[k].tele,
			pcon->data[k].addr);
	}
}
void ClearContact(pContact pcon)
{
	pcon->sz = 0;
}