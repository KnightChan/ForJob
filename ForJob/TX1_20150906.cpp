#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

namespace TX1_20150906{

vector<int> gray(int n)
{
    vector<int> res(1, 0);
    if (n <= 0) return res;
    res = gray(n-1);
    int x = 1 << (n - 1);
    for (int i = res.size() - 1; i >= 0; --i)
        res.push_back(x | res[i]);
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> v = gray(atoi(argv[1]));
    for (int i = 0; i < v.size(); i ++)
        cout << v[i] << endl;
    return 0;
}
}