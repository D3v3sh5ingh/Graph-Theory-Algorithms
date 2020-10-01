#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int>>> graph, mst;
int N, E;

int root(int n, int *parent)
{
    while (n != parent[n])
    {
        n = parent[n];
    }
    return n;
}

int kruskal()
{
    int total = 0;
    int parent[100];

    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    sort(graph.begin(), graph.end());

    for (int i = 0; i < graph.size(); i++)
    {

        int ru = root(graph[i].second.first, parent);
        int rv = root(graph[i].second.second, parent);

        if (ru != rv)
        {
            mst.push_back(graph[i]);
            parent[ru] = parent[rv];
            total += graph[i].first;
        }
    }

    return total;
}

int main()
{

    cout << "Enter Graph " << endl;
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        graph.push_back(make_pair(w, make_pair(u - 'A', v - 'A')));
    }

    cout << "USING Krushkal" << endl;
    int total = kruskal();
    for (int i = 0; i < mst.size(); i++)
    {
        printf("%c %c %d\n", mst[i].second.first + 'A', mst[i].second.second + 'A', mst[i].first);
    }
    printf("Total cost of MST with Kruskal: %i\n\n", total);

    mst.clear();

    return 0;
}
/*
Graph
4 5
A B 10
B C 15
A C 5
D B 2
D C 40
*/
