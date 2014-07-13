#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>

using namespace std;

#define INF numeric_limits<long>::max()

class Edge{
public:
    int from, to;
    double weight;
};

class Graph{
public:
    int V;
    int E;
    vector<Edge> EdgeList;
    Graph(){
    }
    void ReadFromFile(string filename){
	ifstream fin(filename);	
	fin >> V >> E;
	EdgeList.resize(E);
	for(int i=0; i<E; i++){
	    fin >> EdgeList[i].from >> EdgeList[i].to >> EdgeList[i].weight;	    
	    EdgeList[i].from--;
	    EdgeList[i].to--;
	}
	fin.close();
    }    
};

class UnionFind{
public:
    vector<int> data;
    int size;
    UnionFind(int num): size(num), data(num){
	fill(data.begin(), data.end(),-1);
    }
    int Find(int x){
	if(data[x]<0){
	    return x;
	}
	else{
	    data[x] = Find(data[x]);
	    return data[x];
	}
    }

    void Union(int x, int y){
	if(data[x] < data[y]){
	    data[x]+=data[y];
	    data[y]=x;
	}
	else{
	    data[y]+=data[x];
	    data[x]=y;
	}
	size--;
    }
};

class Solution : public Graph{
public:
    int Cluster(int k){
	UnionFind uf(V);
	sort(EdgeList.begin(), EdgeList.end(), [](const Edge &v, const Edge &w) -> bool { return v.weight < w.weight;});
	for(Edge e : EdgeList){
	    int u = uf.Find(e.from);
	    int v = uf.Find(e.to);
	    if(u!=v){
		if(uf.size<=k){
		    return e.weight;
		}
		else{
		    uf.Union(u,v);
		}
	    }
	}	
    }
};

int main(int argc, char** argv){
    Solution sol;
    sol.ReadFromFile(argv[1]);
    cout << sol.Cluster(4) <<endl;
    return 0;
}
