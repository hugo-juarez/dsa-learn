//
//  graph.cpp
//  graph-search
//
//  Created by Hugo Juarez on 4/17/25.
//

#include "graph.hpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

Graph::Graph(vector<vector<int>> &v, int sz) : g(v), n(sz){}

void Graph::bfs(){
    if(g.empty()){
        cout << "[]" << endl;
        return;
    }
    
    vector<int> visited(n, 0);
    queue<int> q;
    
    q.push(1);
    visited[1] = 1;
    
    cout << "[";
    
    while(!q.empty()){
        int node = q.front();
        
        cout << node;
        
        for(int i = 1; i<n; i++){
            if(g[node][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
        
        q.pop();
        if(!q.empty())
            cout << ",";
    }
    
    cout << "]";
}

void Graph::dfs(){
    cout<< "[";
    _dfs(1);
    cout<< "]"<<endl;
}

void Graph::_dfs(int i){
    static vector<int> visited(n, 0);
    
    visited[i] = 1;
    
    for(int j=0; j<n; j++){
        if(g[i][j] == 1 && !visited[j])
            _dfs(j);
    }
    
    cout << i << ",";
}
