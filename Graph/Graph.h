#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph{
private:
    int V;
public:
    list<int> *l;
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u,int v, bool isDirected){
        l[u].push_back(v);
        if (!isDirected){
            l[v].push_back(u);
        }
    }
    
    void printAdjList(){
        for (int i=0;i<V;i++){
            cout<<i<<" : ";
            for (int neigh: l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

    // BFS Traversal 
    void BFS(){
        vector<bool> visited(V,false);
        queue<int> Q;
        Q.push(0);
        visited[0]=true;
        while (!Q.empty()){
            int u=Q.front();
            Q.pop();
            cout<<u<<" ";

            for (int v: l[u]){
                if (!visited[v]){
                    visited[v]=true;
                    Q.push(v);
                }
            }
            
        }
    }

    // DFS Traversal 
    void DFS(){
        vector<bool> visited(V,false);
        stack<int> S;
        S.push(0);
        visited[0]=true;
        while (!S.empty()){
            int u=S.top();
            S.pop();
            cout<<u<<" ";

            for (int v: l[u]){
                if (!visited[v]){
                    visited[v]=true;
                    S.push(v);
                }
            }
            
        }
    }

    // DFS Recursive
    void DFS_recursive_helper(int node,vector<bool> &visited){
        cout<<node<<" ";
        visited[node]=true;
        for (int neigh: l[node]){
            if (!visited[neigh]){
                DFS_recursive_helper(neigh,visited);
            }
        }
    }
    
    void DFS_recursive(){
        vector<bool> visited(V,false);
        DFS_recursive_helper(0,visited);
    }


    // Detect Bipartite Graph using BFS (assign color 0 and 1)
    bool detectBiPartiteGraph(int s){
        vector<int>color(V,-1);
        queue<int>Q;

        color[s]=0;
        Q.push(s);
        while (!Q.empty()){
            int u=Q.front();
            Q.pop();
            for (int v: l[u]){
                if (color[v]==-1){
                    color[v]=1-color[u];
                    Q.push(v);
                }else if (color[v]==color[u]){
                    return false;
                }
            }
        }
        return true;
    }

    // Cycle Detection in Undirected Graph using DFS
    bool isCycleUndirDFS(int node,vector<bool> &visited,int parent){
        visited[node]=true;
        for (int neigh: l[node]){
            if (!visited[neigh]){
                if (isCycleUndirDFS(neigh,visited,node)){
                    return true;
                }
            }
            else if (neigh!=parent){
                return true;
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool> visited(V,false);
        for (int i = 0; i < V; i++) {  // check all components
            if (!visited[i]) {
                if (isCycleUndirDFS(i, visited, -1))
                    return true; // cycle detected
            }   
        }
        return false;
    }

    // Dijsktra's Algorithm for Shortest Path
    void dijktraShortestPath(int src, int V, vector<vector<pair<int,int>>> &adj){
        vector<int> dist(V,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[src]=0;
        pq.push({0,src});
        
        while (!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, wt] : adj[u]) {
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
       // Print shortest distances
        for (int i = 0; i < V; i++) {
            cout << "Distance from " << src << " to " << i << " = ";
            if (dist[i] == 1e9) cout << "INF\n";
            else cout << dist[i] << "\n";
    } 
    }
    

};