#include"Day.h"
using namespace std;
int main() {
	int i = 0;
	Date A(2019, 7, 9);
	Date B(2014, 2, 14);
	i = A - B;
	cout << i << " days" << endl;
	system("pause");
	return 0;
}