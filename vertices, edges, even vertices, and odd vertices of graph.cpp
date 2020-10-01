// Program to find number of vertices, edges, even vertices, and odd vertices
#include <bits/stdc++.h>
using namespace std;
#define crap                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define dbg(x) cerr << #x << " = " << x << endl
#define endl "\n"
#define int long long int
#define double long double
#define pb push_back
#define mp make_pair
#define PI acos(-1)

vector<vector<int>> graph(10, vector<int>(10, 0)); //the adjacency matrix initially 0
int edges = 0, vertices = 0, evenv = 0, oddv = 0;
map<int, int> m;
void add_edge(int u, int v)
{ //function to add edge into the matrix
    graph[u][v] = 1;
    graph[v][u] = 1;
    edges++;
    if (u % 2 != 0 and m[u] == 0)
    {
        oddv++;
        vertices++;
        m[u]++;
    }
    if (u % 2 == 0 and m[u] == 0)
    {
        evenv++;
        vertices++;
        m[u]++;
    }
    if (v % 2 != 0 and m[v] == 0)
    {
        oddv++;
        vertices++;
        m[v]++;
    }
    if (v % 2 == 0 and m[v] == 0)
    {

        evenv++;
        vertices++;
        m[v]++;
    }
}

signed main()
{
    crap;
    add_edge(0, 4);
    add_edge(0, 3);
    add_edge(1, 2);
    add_edge(1, 4);
    add_edge(1, 5);
    add_edge(2, 3);
    add_edge(2, 5);
    add_edge(5, 3);
    add_edge(5, 4);
    add_edge(5, 9);

    cout << "No of edges :" << edges << endl;

    cout << "No of vertices :" << vertices << endl;

    cout << "No of even vertices :" << evenv << endl;

    cout << "No of odd vertices :" << oddv << endl;
    return 0;
}