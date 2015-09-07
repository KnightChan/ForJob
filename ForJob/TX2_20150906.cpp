#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

namespace TX1_20150906{

void doit(vector<int> now, vector<vector<int> > &res)
{
    if (now.size() == 2 && now[0] + now[1] - 9 != 4)
        return;
    if (now.size() == 5 && now[2] - now[3] * now[4] != 4)
        return;
    if (now.size() == 6)
    {
	if (now[5] == 0 || now[2] % now[5] != 0)
            return;
        if (now[0] + (int)(now[2] / now[5]) != 4)
            return;
    }
    if (now.size() == 7 && now[1] - now[3] * now[6] != 4)
        return;
    if (now.size() == 8)
    {
        if (now[5] + now[6] - now[7] != 4)
           return;
        if (9 - now[4] - now[7] != 4)
           return;
        res.push_back(vector<int>(now));
        return;
    }
    for (int i = 0; i <= 100; i++)
    {
        now.push_back(i);
        doit(now, res);
        now.pop_back();
    }
}

int main(int argc, char *argv[])
{
    vector<int> now;
    vector<vector<int> > res;
    doit(now, res);
    cout << res.size() << endl << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ", ";
        cout << endl;
    }
    return 0;
}
}