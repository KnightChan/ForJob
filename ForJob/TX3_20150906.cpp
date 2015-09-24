#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

namespace TX3_20150906{

int FindMost(vector<int> num)
{
    int candidate = 0;
    int count = 0;
    for (int i = 0; i < num.size(); i++)
    {
	if (count == 0)
	{ 
	    candidate = num[i];
	    count = 1;
	}
	else
	{
	    if (candidate == num[i])
		count++;
	    else
		count--;
	}
    }
    return candidate;
}

int main(int argc, char *argv[])
{
    int a[] = {1,2 ,2,2,1,1,2,2,21,1,1,1,1,1};
    vector<int> aa(a, a + 5);
    cout << FindMost(aa) << endl;
    return 0;
}
}