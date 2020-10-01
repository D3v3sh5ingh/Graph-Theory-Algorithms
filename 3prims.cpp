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

int prim(int start)
{
    int total = 0;

    bool intree[100];
    for (int i = 0; i < N; i++)
    {
        intree[i] = false;
    }

    int n = start;
    while (!intree[n])
    {
        intree[n] = true;

        int w = 1000000; // Infinite
        int min = -1;
        int min_next;
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i].second.first == n || graph[i].second.second == n)
            {
                int next;
                if (graph[i].second.first == n)
                    next = graph[i].second.second;
                else
                    next = graph[i].second.first;

                if (!intree[next] && graph[i].first < w)
                {
                    w = graph[i].first;
                    min = i;
                    min_next = next;
                }
            }
        }

        if (min != -1)
        {
            n = min_next;
            mst.push_back(graph[min]);
            total += graph[min].first;
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

    mst.clear();
    cout << "USING PRIMS" << endl;
    int total = prim(0);
    for (int i = 0; i < mst.size(); i++)
    {
        printf("%c %c %d\n", mst[i].second.first + 'A', mst[i].second.second + 'A', mst[i].first);
    }

    printf("Total cost of MST with Prim: %i\n", total);

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