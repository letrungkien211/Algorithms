// 2sat problem solved by SCC

#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<sstream>
#include<ctime>
#include<set>
#include<functional>
#include<algorithm>
#include<limits>
#include<unordered_set>

using namespace std;

class Graph{
public:
    int E;
    int V;
    int N;
    vector<list<int>> Adj;
    
    void ReadFrom2SatFile(string filename){
	ifstream input(filename);
	input >> N;
	V = 2*N;
	Adj.resize(V);
	for(int i=0; i<N; i++){
	    int x,y;
	    input >> x >> y;
	    if(x>0) x--;
	    if(y>0) y--;
	    x+=N;
	    y+=N;
	    AddEdge(V-1-x,y);
	    AddEdge(V-1-y,x);
	}
    }    
    
    void AddEdge(int from, int to){
	Adj[from].push_back(to);
	E++;
    }

    void Reverse(){
	vector<list<int>> copy = Adj;
	for(auto &l : Adj)
	    l.clear();
	for(int i=0; i<V; i++)
	    for(auto j : copy[i])
		Adj[j].push_back(i);
    }
};

class DFSGetOrder{
public:
    list<int> ReverseOrder;
    vector<bool> marked;
    void DFS(Graph &G){
	marked = vector<bool>(G.V,false);
	for(int i=0; i<G.V; i++){
	    if(!marked[i])
		DFS(G,i);
	}
    }

    void DFS(Graph &G, int i){
	marked[i] = true;
	for(auto j : G.Adj[i]){
	    if(!marked[j])
		DFS(G,j);
	}
	ReverseOrder.push_front(i);
    }
};

class SCC{
public:
    vector<int> Sizes;
    vector<bool> marked;
    bool DFS(Graph &G){
	DFSGetOrder getOrder;
	getOrder.DFS(G);
	cout << "Get order done" <<endl;
	G.Reverse();
	marked = vector<bool>(G.V,false);
	for(auto i : getOrder.ReverseOrder){
	    if(!marked[i]){
		unordered_set<int> component;
		if(!DFS(G,i,component))
		    return false;
		
	    }
	}
	return true;
    }

    bool DFS(Graph &G, int i, unordered_set<int>& component){
	marked[i] = true;
	if(component.find(G.V-1-i)!=component.end())
	    return false;
	component.insert(i);
	for(auto j : G.Adj[i]){
	    if(!marked[j])
		if(!DFS(G,j,component))
		    return false;
	}
	return true;
    }
};




int main(int argc, char** argv){
    clock_t start = clock();
    string filename(argv[1]);
    for(int i=1; i<=6; i++){
	filename[filename.size()-5]='0'+i;
	Graph G;
	G.ReadFrom2SatFile(filename);
	SCC scc;
	cout << i << ": " << scc.DFS(G) << endl;
    }
    cout << (clock()-start)/(double)CLOCKS_PER_SEC <<endl;
    return 0;
}
