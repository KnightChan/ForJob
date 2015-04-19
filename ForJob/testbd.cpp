#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <string>

using namespace std;

int main2222()
{
	int a = 0, c = 2;
	do{
		--c;
		a = a - 1;
		cout << "c=" << c;
	} while (a > 0);
	return 0;
}

int main2222222222222222222()
{
	int x = 'A', y = 66;
	printf("%d", x > y ? y++ : x++);
	printf("%d", x <= y ? ++y : ++x);
	printf("%d,%d", x, y);
	return 0;
}

class A{
	int x;
public:
	A(int n){ x = n; }
};

class B :public A{
	A y;
	int z;
public:
	B(int a, int b, int c) :A(a), y(b), z(c){}
};