#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Edge{
public:
    int from,to;
    double capacity;
};

class MaximumFlow{
public:
    vector<Edge> edges;
    vector<vector<Edge> > adj;
    int V,E;
    int s,t;

    MaximumFlow(){}
    void Init(int numV, int source, int sink){
	V = numV;
	E = numE;
	s = source;
	t = sink;
	adj.resize(V);
    }

    
    
};

