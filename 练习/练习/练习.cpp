#include<iostream>
#include<assert.h>
#define Max_Size 6
using namespace std;
int i = 0, j = 0;
typedef struct {
	int *base;
	int size;
} SqList;
bool Init(SqList &L) {
	L.base = (int*)realloc(L.base, sizeof(int)*Max_Size);
	cout << "输入6个数：";
	for (i = 0; i < Max_Size; i++) {
		cin >> j;
		L.base[i] = j;
	}
	L.size = Max_Size;
	return true;
}
void SqList_Print(SqList &L) {
	j = L.size;
	for (i = 0; i < j; i++)
		cout << L.base[i] << " ";
	cout << endl;
}
bool Sort(SqList &L) {
	for (i = 0; i < L.size - 1; i++) {
		for (j = 0; j < L.size - 1 - i; j++) {
			if (L.base[j] > L.base[j + 1]) {
				int temp = L.base[j];
				L.base[j] = L.base[j + 1];
				L.base[j + 1] = temp;
			}
		}
	}
	return true;
}
bool Reverse(SqList &L) {
	if (L.size == 0 || L.size == 1) return false;
	int low = 0, high = L.size - 1;
	while (low < high) {
		int  temp = L.base[low];
		L.base[low] = L.base[high];
		L.base[high] = temp;
		low++;
		high--;
	}
	return true;
}
bool Del(SqList &L, int value) {
	for (i = 0, j = 0; i < L.size; i++)
		if (L.base[i] != value)
			L.base[j++] = L.base[i];
	L.size = j;
	return true;
}
bool Merge(SqList &L, SqList L1, SqList L2)
{
	L.size = L1.size + L2.size;
	L.base = (int*)malloc(sizeof(int)*L.size);
	assert(L.base != NULL);
	int L1_size = 0, L2_size = 0, L_size = 0;
	while (L1_size < L1.size&&L2_size < L2.size)
	{
		if (L1.base[L1_size] < L2.base[L2_size])
			L.base[L_size++] = L1.base[L1_size++];
		else
			L.base[L_size++] = L2.base[L2_size++];
	}
	while (L1_size < L1.size)
		L.base[L_size++] = L1.base[L1_size++];
	while (L2_size < L2.size)
		L.base[L_size++] = L2.base[L2_size++];
	L.size = L1.size + L2.size;
	return true;
}
bool SerExInsert(SqList &L, int value) {
	int Le, Ri, Mi;
	Le = 0, Ri = L.size - 1;
	while (Le <= Ri) {
		Mi = (Le + Ri) / 2;
		if (L.base[Mi] == value) break;
		else if (L.base[Mi] < value) Le = Mi + 1;
		else Ri = Mi - 1;
	}
	if (L.base[Mi] == value && Mi != L.size - 1) {
		int t = L.base[Mi];
		L.base[Mi] = L.base[Mi + 1];
		L.base[Mi + 1] = t;
	}
	else {
		for (i = L.size - 1; i > Ri; --i)
			L.base[i + 1] = L.base[i];
		L.base[Ri + 1] = value;
		L.size++;
	}
	return true;
}
int main() {
	int value = 0;
	SqList L = { NULL , 0 };
	Init(L);
	cout << "初始化：";
	SqList_Print(L);
	Reverse(L);
	cout << "逆置后：";
	SqList_Print(L);
	cout << "删除数：";
	cin >> value;
	Del(L, value);
	cout << "删除后：";
	SqList_Print(L);
	cout << "排序后：";
	Sort(L);
	SqList_Print(L);
	SqList L2 = { NULL , 0 };
	Init(L2);
	cout << "合并后：";
	Merge(L, L, L2);
	SqList_Print(L);
	cout << "查找数：";
	cin >> value;
	SerExInsert(L, value);
	cout << "查找后：";
	SqList_Print(L);
	system("pause");
	return 0;
