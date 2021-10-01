#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define f(n) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define maxn 100000

int profit(int **box, int sum, int lvl, bool mark[], int multiply[])
{
    if (lvl == 4)
        return sum;
    int val1 = box[lvl][0]; // A
    int val2 = box[lvl][1]; // B
    int val3 = box[lvl][2]; // C
    int val4 = box[lvl][3]; // D
    int res1, res2, res3, res4;
    res1 = res2 = res3 = res4 = 0;

    if (mark[0] == true)
    {
        mark[0] = false;
        if (val1 > 0)
            val1 *= multiply[lvl];
        else
            val1 = -100;
        res1 = profit(box, sum + val1, lvl + 1, mark, multiply);
        mark[0] = true;
    }
    if (mark[1] == true)
    {
        mark[1] = false;
        if (val2 > 0)
            val2 *= multiply[lvl];
        else
            val2 = -100;
        res2 = profit(box, sum + val2, lvl + 1, mark, multiply);
        mark[1] = true;
    }
    if (mark[2] == true)
    {
        mark[2] = false;
        if (val3 > 0)
            val3 *= multiply[lvl];
        else
            val3 = -100;
        res3 = profit(box, sum + val3, lvl + 1, mark, multiply);
        mark[2] = true;
    }
    if (mark[3] == true)
    {
        mark[3] = false;
        if (val4 > 0)
            val4 *= multiply[lvl];
        else
            val4 = -100;
        res4 = profit(box, sum + val4, lvl + 1, mark, multiply);
        mark[3] = true;
    }
    return max(max(res1, res2), max(res3, res4));
}

int main(int argc, char **argv)
{
    // int multiply[] = {100, 75, 50, 25};
    int multiply1[] = {25, 50, 75, 100};
    int multiply2[] = {25, 50, 100, 75};
    int multiply3[] = {25, 75, 50, 100};
    int multiply4[] = {25, 75, 100, 50};
    int multiply5[] = {25, 100, 50, 75};
    int multiply6[] = {25, 100, 75, 50};
    int multiply7[] = {50, 25, 75, 100};
    int multiply8[] = {50, 25, 100, 75};
    int multiply9[] = {50, 75, 25, 100};
    int multiply10[] = {50, 75, 100, 25};
    int multiply11[] = {50, 100, 25, 75};
    int multiply12[] = {50, 100, 75, 25};
    int multiply13[] = {75, 25, 50, 100};
    int multiply14[] = {75, 25, 100, 50};
    int multiply15[] = {75, 50, 25, 100};
    int multiply16[] = {75, 50, 100, 25};
    int multiply17[] = {75, 100, 25, 50};
    int multiply18[] = {75, 100, 50, 25};
    int multiply19[] = {100, 25, 50, 75};
    int multiply20[] = {100, 25, 75, 50};
    int multiply21[] = {100, 50, 25, 75};
    int multiply22[] = {100, 50, 75, 25};
    int multiply23[] = {100, 75, 25, 50};
    int multiply24[] = {100, 75, 50, 25};

    ll t;
    cin >> t;

    int index[13] = {0};
    index[12] = 0;
    index[3] = 1;
    index[6] = 2;
    index[9] = 3;
    int a[t] = {0};

    f(t)
    {
        ll n;
        cin >> n;
        int **box = new int *[4];
        f(4) box[i] = new int[4];
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                box[i][j] = 0;
        while (n--)
        {
            char ch;
            int x;
            cin >> ch >> x;
            ++box[ch - 'A'][index[x]];
        }
        cout << "   12 3 6 9\n";
        f(4)
        {
            cout << (char)('A' + i) << ": ";
            for (int j = 0; j < 4; ++j)
                cout << box[i][j] << " ";
            cout << endl;
        }
        bool mark[4];
        f(4) mark[i] = true;
        int ans[25] = {0};
        ans[1] = profit(box, 0, 0, mark, multiply1);
        ans[2] = profit(box, 0, 0, mark, multiply2);
        ans[3] = profit(box, 0, 0, mark, multiply3);
        ans[4] = profit(box, 0, 0, mark, multiply4);
        ans[5] = profit(box, 0, 0, mark, multiply5);
        ans[6] = profit(box, 0, 0, mark, multiply6);
        ans[7] = profit(box, 0, 0, mark, multiply7);
        ans[8] = profit(box, 0, 0, mark, multiply8);
        ans[9] = profit(box, 0, 0, mark, multiply9);
        ans[10] = profit(box, 0, 0, mark, multiply10);
        ans[11] = profit(box, 0, 0, mark, multiply11);
        ans[12] = profit(box, 0, 0, mark, multiply12);
        ans[13] = profit(box, 0, 0, mark, multiply13);
        ans[14] = profit(box, 0, 0, mark, multiply14);
        ans[15] = profit(box, 0, 0, mark, multiply15);
        ans[16] = profit(box, 0, 0, mark, multiply16);
        ans[17] = profit(box, 0, 0, mark, multiply17);
        ans[18] = profit(box, 0, 0, mark, multiply18);
        ans[19] = profit(box, 0, 0, mark, multiply19);
        ans[20] = profit(box, 0, 0, mark, multiply20);
        ans[21] = profit(box, 0, 0, mark, multiply21);
        ans[22] = profit(box, 0, 0, mark, multiply22);
        ans[23] = profit(box, 0, 0, mark, multiply23);
        ans[24] = profit(box, 0, 0, mark, multiply24);
        int ans0 = 0;
        f(24) ans0 = max(ans0, ans[i]);
        a[i] = ans0;
        cout << ans0 << endl
             << endl;
    }
    int sum = 0;
    f(t) sum += a[i];
    cout << sum << endl;
    return 0;
}