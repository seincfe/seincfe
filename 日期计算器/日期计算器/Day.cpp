#include"Day.h"
void Date::Print(Date& d) {
	cout << d._year << "-" << d._month << "-" << d._day << endl;
}
int Date::GetmonthDay(int _year, int _day) {
	static int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daynum = day[_day];
	if (_year % 4 == 0 && _year % 100 != 0 && _year % 400 == 0)
		daynum++;
	return daynum;
}
int Date::GetyearDays(int year) {
	if (GetmonthDay(year, 2) == 29)
		return 366;
	else
		return 365;
}
int Date::GetMinus(int num) {
	if (num < 0)
		num = -num;
	return num;
}
Date::Date(int year = 2020, int month = 2, int day = 2) {  //全缺省的构造函数
	if (year > 0 && month > 0 && month < 13 && day < GetmonthDay(year, month)) {
		_year = year;
		_month = month;
		_day = day;
	}
	else
		cout << "非法日期" << endl;
}
Date::Date(const Date& d) {  //拷贝构造函数
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date& d) {  //赋值运算符重载
	if (this != &d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Date& Date::operator+=(int day) {  //日期+=天数
	if (day < 0) {
		*this -= day;
		return *this;
	}
	_day += day;
	while (_day > GetmonthDay(_year, _month)) {
		_month++;
		_day -= GetmonthDay(_year, _month);
		if (_month == 13) {
			_month = 1;
			_year++;
		}
	}
	return *this;
}
Date Date::operator+(int day) {  //日期+天数
	Date ret(*this);
	ret += day;
	return ret;
}
Date Date::operator-(int day) {  //日期-天数
	Date ret(*this);
	ret -= day;
	return ret;
}
Date& Date::operator-=(int day) {  //日期-=天数
	if (day < 0) {
		*this += day;
		return *this;
	}
	_day -= day;
	while (_day < 1) {
		_month--;
		if (_month < 1) {
			_year--;
			_month = 12;
		}
		_day += GetmonthDay(_year, _month);
	}
	return *this;
}
int Date::operator-(const Date& b) {  //日期-日期 返回天数
	int D_value = 0;
	Date d(b);
	Date e(*this);
	if ((d._year > e._year) || ((e._year == d._year) && (e._month < d._month))
		|| ((e._year == d._year) && (e._month == d._month) && (e._day < d._day))) {
		cout << "非法操作" << endl;
		return -1;
	}
	if (e._year == d._year) {
		if (e._month == d._month)
			return e._day - d._day;
		else {
			while (d._month != e._month) {
				D_value += GetmonthDay(e._year, d._month);
				d._month++;
			}
			return D_value + GetMinus(e._day - d._day);
		}
	}
	else {
		while (e._year - d._year != 1) {
			if (GetmonthDay(d._year, 2) == 28)
				D_value += 365;
			else
				D_value += 366;
			d._year++;
		}
		while ((e._year != d._year) || (e._month >= d._month)) {
			D_value += GetmonthDay(d._year, d._month);
			d += GetmonthDay(d._year, d._month);
		}
		if (e._day > d._day)
			return D_value + e._day - d._day;
		else
			return D_value + d._day - e._day;
	}
}
Date& Date::operator++() {  //前置++
	*this += 1;
	return *this;
}
Date Date::operator++(int) {  //后置++
	Date ret(*this);
	++(*this);
	return ret;
}
Date Date::operator--(int) {  //后置--
	Date ret(*this);
	*this -= 1;
	return ret;
}
Date& Date::operator--() {  //前置--
	*this -= 1;;
	return *this;
}
bool Date::operator>(const Date& d) {  //>运算符重载
	if ((_year > d._year) || (_year == d._year && _month > d._month)\
		|| (_year == d._year && _month == d._month && _day > d._day))
		return true;
	return false;
}
bool Date::operator==(const Date& d) {  //==运算符重载
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator >= (const Date& d) {  //>=运算符重载
	if ((_year > d._year) || (_year == d._year) && (_month < d._month)\
		|| (_year == d._year) && (_month == d._month) && (_day >= d._day))
		return true;
	return false;
}
bool Date::operator < (const Date& d) {  //<运算符重载
	if ((_year < d._year) || (_year == d._year && _month < d._month)\
		|| (_year == d._year && _month == d._month && _day < d._day))
		return true;
	return false;
}
bool Date::operator <= (const Date& d) {  //<=运算符重载
	if ((_year < d._year) || (_year == d._year && _month < d._month)\
		|| (_year == d._year && _month == d._month && _day <= d._day))
		return true;
	return false;
}
bool Date::operator != (const Date& d) {  //!=运算符重载
	return !(_year == d._year && _month == d._month && _day == d._day);
}