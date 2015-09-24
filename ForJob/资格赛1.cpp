#include <stdio.h>
#include <iostream>
#include <string.h>

namespace zigesai1{

using namespace std;

struct Date
{
	int year, month, day;
	void print(){ cout << year << "," << month << "-" << day << endl; }
};

int leap_count(int x)
{
	return x / 4 - x / 100 + x / 400;
}

int which_month(char *s)
{
	if (strcmp(s, "January") == 0) return 1;
	if (strcmp(s, "February") == 0) return 2;
	return 3;
}

void get_date(char *s, Date &d)
{
	char month[50];
	sscanf(s, "%s %d, %d", month, &d.day, &d.year);
	d.month = which_month(month);
}

/*
int main_zige1()
{
	int T;
	scanf("%d\n", &T);
	for (int i = 1; i <= T; i++)
	{
		char s[100];
		Date start, end;
		gets(s); get_date(s, start);
		gets(s); get_date(s, end);
		int syear = start.month > 2 ? start.year + 1 : start.year;
		int eyear = end.month < 2 || (end.month == 2 && end.day < 29) ? end.year - 1 : end.year;
		int ans = leap_count(eyear) - leap_count(syear - 1);
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
*/
}