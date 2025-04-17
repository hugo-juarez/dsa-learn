//
//  main.cpp
//  graph-search
//
//  Created by Hugo Juarez on 4/17/25.
//

#include "graph/graph.hpp"
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> G = {{0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}};
    
    Graph g(G, 7);
    
    g.dfs();
    
    cout << endl;
    
    return 0;
}
