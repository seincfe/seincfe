#include"contact.h"
void InitContact(pContact pcon)
{   //memset(pcon->data, 0, MAX*sizeof(PeoInfo));
	pcon->sz = 0;  //�Ѿ����˶���
	pcon->data = malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pcon->data == NULL)
	{
		perror("use malloc");//����
		exit(EXIT_FAILURE);//�˳�
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
		printf("���ݳɹ�\n");
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
	printf("����������>: ");
	scanf("%s", pcon->data[pcon->sz].name);
	printf("�������Ա�>: ");
	scanf("%s", pcon->data[pcon->sz].sex);
	printf("����������>: ");
	scanf("%d", &pcon->data[pcon->sz].age);
	printf("������绰>: ");
	scanf("%s", pcon->data[pcon->sz].tele);
	printf("�������ַ>: ");
	scanf("%s", pcon->data[pcon->sz].addr);
	pcon->sz++;
	printf("¼��ɹ�\n");
}

static int FindEntry(pContact pcon, char name[])  //staticֻ�ڵ�ǰ�ļ�ʹ��
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
			return i;  //�ҵ��������±�
	}
	return -1;  //û�ҵ�
}

int SearchContact(pContact pcon)  //������Ϣ
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ�����: ");
	scanf("%s", name);
	int pos = 0;
	pos = FindEntry(pcon, name);
	if (pos == -1)
	{
		printf("��Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		printf("name:%10s\t sex��%5s\t age:%5d\t tele��%10s\t addr��%15s\n",
			pcon->data[pos].name,
			pcon->data[pos].sex,
			pcon->data[pos].age,
			pcon->data[pos].tele,
			pcon->data[pos].addr);
	}
}

void ShowContact(pContact pcon)
{
	printf("��ϵ����Ϣ��\n");
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
void DelContact(pContact pcon)  //ɾ����ϵ��
{
	char name[NAME_MAX];
	printf("������Ҫɾ������ϵ��\n");
	scanf("%s", name);
	int pos = 0;  //����pos����FindEntry���صĵ�ַ
	pos = FindEntry(pcon, name);
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
		return;
	}
	else
	{
		int j = 0;
		for (j = pos; j < pcon->sz; j++)
			pcon->data[j] = pcon->data[j + 1];  //���ú���һ������ǰһ�����Ӷ��ﵽɾ����Ч��
		pcon->sz--;
		printf("ɾ���ɹ�\n");
	}
}
void ModifyContact(pContact pcon)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ���ϵ��\n");
	scanf("%s", name);
	int pos = 0;  //����pos����FindEntry���صĵ�ַ
	pos = FindEntry(pcon, name);
	if (pos != -1)
	{
		printf("�������޸ĺ�������� ");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("�������޸ĺ���Ա� ");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("�������޸ĺ�����䣺 ");
		scanf("%d", &pcon->data[pcon->sz].age);
		printf("�������޸ĺ�ĵ绰�� ");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("�������޸ĺ�ĵ�ַ�� ");
		scanf("%s", pcon->data[pcon->sz].addr);
		printf("�޸����\n");
	}
	else
	{
		printf("Ҫ�޸ĵ���ϵ�˲����ڣ�\n");
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