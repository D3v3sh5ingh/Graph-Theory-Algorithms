#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool issafe(bool graph[101][101],int V,vector<int>& color){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]&&color[i]==color[j]){
                return false;
            }
        }
    }
    return true;
}

bool solve(bool graph[101][101],int i,int m,int V,vector<int>&color){
    if(i==V){
        if(issafe(graph,V,color)){
        return true;
        }
        return false;
    }
    for(int j=1;j<=m;j++){
      color[i] = j;
      if (solve(graph ,i + 1,m,V, color))
            return true;
      color[i] = 0;
    }
    return false;
}









bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int>color(V,0);



    return solve(graph,0,m,V,color);



}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
