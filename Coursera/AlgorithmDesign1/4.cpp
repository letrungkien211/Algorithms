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


using namespace std;

class Graph{
public:
    int E;
    int V;
    vector<list<int>> Adj;
    
    Graph(int numVertex){
	V = numVertex;
	E = 0;
	Adj.resize(V);
    }

    void ReadFromFile(string filename){
	ifstream input(filename);

	while(input.good()){
	    int from=-1,to=-1;
	    input >> from >> to;
	    if(from==to || from==-1 || to==-1)
		continue;
	    AddEdge(from-1,to-1);
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
    int timer;
    void DFS(Graph &G){
	timer = 0;
	DFSGetOrder getOrder;
	getOrder.DFS(G);
	cout << "Get order done" <<endl;
	getchar();
	G.Reverse();
	marked = vector<bool>(G.V,false);
	for(auto i : getOrder.ReverseOrder){
	    int start = timer;
	    if(!marked[i]){
		DFS(G,i);
	    }
	    if(timer>start+1){
		Sizes.push_back(timer-start);
	    }
	}

	sort(Sizes.begin(), Sizes.end(), greater<int>());
    }

    void DFS(Graph &G, int i){
	timer++;
	marked[i] = true;
	for(auto j : G.Adj[i]){
	    if(!marked[j])
		DFS(G,j);
	}
    }
};



int main(int argc, char** argv){
    clock_t start = clock();
    int V = 875714;
    Graph G(V);
    G.ReadFromFile("SCC.txt");
    SCC scc;
    scc.DFS(G);
    for(int i=0; i<5; i++)
	cout << scc.Sizes[i] << "," ;
    cout <<endl;

    cout << (clock()-start)/(double)CLOCKS_PER_SEC <<endl;
    return 0;
}
