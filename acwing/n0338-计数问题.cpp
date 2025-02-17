#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
分情况讨论：
abc d efg 中 x 出现的次数
1 最高位取 001 - abc - 1 时, d = x, 000 - 999
2.最高位取 abc
    2.1 d < x  无解：0
    2.2 d = x  000 - efg  总共 efg + 1种
    2.3 d > x  000 - 999  总共 1000   种
*/


int get(vector<int> num, int l, int r)
{
    int res = 0;
    for(int i = l; i >= r; i -- )
        res = res * 10 + num[i];
    return res;
}

int power10(int x)
{
    int res = 1;
    while( x -- ) res *= 10;
    return res;
}

int count(int n, int x)
{
    if(!n) return 0;
    vector<int> num;
    while(n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();

    int res = 0;
    for(int i = n - 1 - !x; i >= 0; i -- )
    {
        if(i < n - 1)
        {   
            res += get(num, n - 1, i + 1) * power10(i);
            if(!x) res -= power10(i);
        }
        if(num[i] == x) res += get(num, i - 1, 0) + 1;
        else if(num[i] > x) res += power10(i);
    }

    return res;
}

int main()
{
    int a, b;
    while( cin >> a >> b, a || b )
    {
        if(a > b) swap(a, b);

        for(int i = 0; i < 10; i ++ )
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }

    return 0;
}