#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include "graph.hpp"

using namespace std;


#define For(i,m,n) for(int i=m; i < n; i++)

int main(int argc, char** argv){
    vector<int> starts{1,1,1,4,2,2};
    vector<int> ends{2,3,4,6,3,5};

    Graph g(starts.size());
    g.addEdge(starts,ends);
    
    cout << g.V <<endl;
    int dummy;
    list<int> bfs_result = BFS(g);
    list<int> dfs_result = DFS(g);
	list<int> dfs_recursive_result = DFSRecursive(g);
    cout << "BFS: " ;
    for(int i : bfs_result) 	cout << i << " "; cout << endl;
    
    cout << "DFS: " ;
    for(int i : dfs_result) 	cout << i << " "; cout << endl;

	cout << "DFSRecursive: " ;
    for(int i : dfs_recursive_result) 	cout << i << " "; cout << endl;


    return 0;
}
