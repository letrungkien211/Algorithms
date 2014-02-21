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

using namespace std;

#define For(i,m,n) for(int i=m; i < n; i++)

class Graph {
public:
    int V;
    int E;
    vector<list<int> > adj;

    Graph(int V_): V(V_), E(0), adj(V_){}
    void addEdge(int a, int b){
	E++;
	if(a<0 || b <0 || a>=V || b>=V)
	    return;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }

    void addEdge(vector<int> a, vector<int> b){
	if(a.size()!=b.size())
	    return;
	For(i,0, a.size()){
	    addEdge(a[i]-1,b[i]-1);
	}
    }
};

vector<bool> discovered;
vector<bool> processed;

list<int> DFS(const Graph &g, int start=0){
    stack<int> open;
    list<int> close;

    discovered.resize(g.V);
    processed.resize(g.V);
    fill(discovered.begin(), discovered.end(),false);
    fill(processed.begin(), processed.end(),false);

    open.push(start);
    discovered[start]=true;
    processed[start]=true;
    while(!open.empty()){
	int v = open.top();
	open.pop();
	if(!g.adj[v].empty()){
	    for(list<int>::const_reverse_iterator it =g.adj[v].rbegin(); it!=g.adj[v].rend(); it++){
		if(!discovered[*it]){
		    open.push(*it);
		    discovered[*it] = true;
		}
	    }
	    close.push_back(v);
	    processed[v] = true;
	}
    }
    return close;
}

void DFSRecursiveStep(const Graph& g, int start, list<int> &ret){		
	ret.push_back(start);
	discovered[start]=true;
	cout << "!!!! " << start <<endl;
	for(list<int>::const_iterator it = g.adj[start].begin(); it!=g.adj[start].end(); it++){
		if(!discovered[*it]){
			cout << *it <<endl;
			DFSRecursiveStep(g,*it,ret);			
		}
	}
}

list<int> DFSRecursive(const Graph& g, int start=0){
	discovered.resize(g.V);
	fill(discovered.begin(), discovered.end(), false);
	list<int> ret;
	//discovered[start] = true;
	DFSRecursiveStep(g,start, ret);
	return ret;
}


list<int> BFS(const Graph &g, int start=0){
    queue<int> open;
    list<int> close;

    discovered.resize(g.V);
    processed.resize(g.V);
    fill(discovered.begin(), discovered.end(),false);
    fill(processed.begin(), processed.end(),false);

    open.push(start);
    discovered[start]=true;
    while(!open.empty()){
	int v = open.front();
	open.pop();
	for(list<int>::const_iterator it =g.adj[v].begin(); it!=g.adj[v].end(); it++){
	    if(!discovered[*it]){
		open.push(*it);
		discovered[*it] = true;
	    }
	}
	close.push_back(v);
	processed[v]=true;
    }
    return close;
}


/*
int main(int argc, char** argv){
    vector<int> starts{1,1,1,4,2,2};
    vector<int> ends{2,3,4,6,3,5};

    Graph g(starts.size());
    g.addEdge(starts,ends);
    
    cout << g.V <<endl;
    int dummy;
    list<int> bfs_result = BFS(g);
    list<int> dfs_result = DFS(g);
    cout << "BFS: " ;
    for(int i : bfs_result) 	cout << i << " ";

    cout << endl;
    cout << "DFS: " ;
    for(int i : dfs_result) 	cout << i << " ";


    return 0;
}
*/
