#include <iostream>
using namespace std;
class Date {
public:
	void Print(Date& d);
	int GetmonthDay(int _year, int _day);
	int GetyearDays(int year);
	int GetMinus(int num);
	Date(int year = 2020, int month = 2, int day = 2);
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date& operator+=(int day);
	Date operator+(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& b);
	Date& operator++();
	Date operator++(int);
	Date operator--(int);
	Date& operator--();
	bool operator>(const Date& d);
	bool operator==(const Date& d);
	bool operator >= (const Date& d);
	bool operator < (const Date& d);
	bool operator <= (const Date& d);
	bool operator != (const Date& d);
private:
	int _year;
	int _month;
	int _day;
};