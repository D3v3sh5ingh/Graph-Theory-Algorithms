#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
const int INF = 1e9 + 5;

struct edges
{
    int u;
    int v;
    long long w;
    edges(int u, int v, long long w) : u(u), v(v), w(w) {}
};
#define mod 1000000007
vector<int> dp(6, 0);
int func(int n, int m)
{
    long long int ans = 1;
    if (n & 1)
    {
        m /= 2;
        ans = (m * n) % mod;
    }
    else
    {
        n /= 2;
        ans = (n * m) % mod;
    }
    return int(ans);
}

int main()

{
    int ans = -1, res = -1;

    cout << endl
         << func(10000, 12345) << endl;
    return 0;
}

// Normal example
/*
10 18
0 1 3
0 2 5
0 4 4
1 4 1
2 4 2
2 3 2
3 4 -1
1 7 4
4 7 -2
4 6 3
3 5 3
5 6 2
7 6 2
7 9 5
6 9 2
6 8 5
5 8 4
8 9 5

//Negative cycle
4 4
        0 1 1
        1 2 -1
        2 3 -1
        3 0 -1
*/