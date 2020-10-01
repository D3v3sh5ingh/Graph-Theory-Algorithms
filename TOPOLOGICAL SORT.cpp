/* TOPOLOGICAL SORT :
In case of multiple possible answer return the lexographically smaller order.
INPUT:
N - No. of Nodes 
M - No of edges
next M line contains M pair with a edge from a to b 
Eg:
6 5
5 1
1 2
2 4
3 2
3 4

Output :
3 5 1 2 4 6

In case of graphs where TOPOLOGICAL Sort is not possible return empty vector 
*/
/* Using KAHN"S ALGORITHM */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> TopologicalSort(int n,int m,vector<pair<int,int>>&edges){
    vector<int>final_order;
    unordered_map<int,int>indegree(n+1); //DS to maintain indegree of nodes
    vector<vector<int>>adj_list(n+1);
    
    //Creat adjacency list
    for(auto ed:edges){
        adj_list[ed.first].push_back(ed.second);
        indegree[ed.second]++;
    }
    // Use priority queue to get lexographically smallest node 
    priority_queue<int,vector<int>,greater<int>>pq;
    
    //Push Nodes with indegree 0 to queue
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0)
        pq.push(i);
    }
    // Traverse each node from pq one by one and decrease the indegree of its child
    while(!pq.empty()){
        int curr_node=pq.top();
        final_order.push_back(curr_node);
        pq.pop();
        for(auto child :adj_list[curr_node]){
            indegree[child]--;
            if(indegree[child]==0)
            pq.push(child);
        }
    }
    
    //If the size of final order is not equal to given no. of nodes thn the GRAPH is not a valid DAG
    if(final_order.size()!=n)
        return vector<int>();
    
    return final_order; 
    
    
}
int main() {
	int no_of_nodes=6;
	int no_of_edges=5;
	vector<pair<int,int>>edges({{5,1},{1,2},{2,4},{3,2},{3,4}});
	
	auto ans=TopologicalSort(no_of_nodes,no_of_edges,edges);
	for(auto node:ans){
	    cout<<node<<" ";
	}
	cout<<"\n";
	return 0;
}
