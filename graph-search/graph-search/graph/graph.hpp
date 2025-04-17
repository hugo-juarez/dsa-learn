//
//  graph.hpp
//  graph-search
//
//  Created by Hugo Juarez on 4/17/25.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <memory>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>>& g;
    int n;
public:
    Graph(vector<vector<int>> &v, int sz);
    void bfs();
    void dfs();
    
};

#endif /* graph_hpp */
