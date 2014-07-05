#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
#include<cassert>
#include<limits>
using namespace std;

#define Pair pair<long,int>

struct Edge{
    int from,to;
    long weight;
    Edge(int x=-1, int y=-1, long w=-1): from(x), to(y), weight(w){}
};

class MinPQ{
private:
    Pair *data;
    int* mapindex;
    int MAX;
public:
    int size;
    MinPQ():size(0),MAX(0),data(NULL),mapindex(NULL){      
    }
    ~MinPQ(){
	delete[] data;
	delete[] mapindex;
    }  
    void init(int max){
	if(data)
	    delete[] data;
	if(mapindex)
	    delete[] mapindex;
	MAX=max;
	size=0;
	data=new Pair[max];
	mapindex= new int[max];
         
	for(int i=0; i<max; i++)
	    mapindex[i]=-1;    
    }          
    void heapify_up(int child){
	int parent=child/2;
	while(parent && data[child].first<data[parent].first){
	    swap(data[child],data[parent]);        
	    updateindex(child);
	    updateindex(parent);
	    child=parent;
	    parent/=2;
	}
    }  
    void heapify_down(int parent){
	int child=2*parent;
	while(child<=size){
	    if(child<size-1 && data[child+1].first<data[child].first) child++;
	    if(data[child].first<data[parent].first){
		swap(data[child], data[parent]);
		updateindex(child);
		updateindex(parent);
		parent=child;
		child*=2;
	    }
	    else
		break;
	}          
    }
    void updateindex(int index){
	mapindex[data[index].second]=index;
    }      
    bool push(const Pair& x){
	if(size>=MAX) return false;
	data[++size]=x;
	updateindex(size);
	heapify_up(size);
	return true;
    }  
    Pair min() const{
	assert(!empty());      
	return data[1];
    }      
    Pair pop(){
	assert(!empty());
	Pair value = data[1];
	data[1]=data[size--];
	updateindex(1);    
	heapify_down(1);
 
	mapindex[value.second]=-1;
	return value;
    }
    bool empty() const{
	return size==0;
    }
    int find(int id){
	return mapindex[id];
    }  
    bool decrease(const Pair& t, int index){
	data[index]=t;
	heapify_up(index);
    }
};

class Graph{
public:
    int V;
    int E;
    vector<list<Edge> > Adj;    
    Graph(){
    }
    void ReadFromFile(string filename){
	ifstream fin(filename);	
	fin >> V >> E;
	Adj.resize(V);
	Edge e;
	for(int i=0; i<E; i++){
	    fin >> e.from >> e.to >> e.weight;	    
	    e.from--;
	    e.to--;
	    Adj[e.from].push_back(e);
	    swap(e.from,e.to);
	    Adj[e.from].push_back(e);
	}
	fin.close();
    }    
};

#define INF numeric_limits<long>::max()

class Prim{
public:
    long MinTree(const Graph &G){
	vector<long> distanceTo(G.V, INF);
	long ret=0;
	vector<bool> inTree(G.V,false);
	int start=0;
	inTree[start]=true;
	MinPQ pq;
	pq.init(G.V);
	for(auto e:G.Adj[start]){
	    pq.push(Pair(e.weight, e.to));
	    distanceTo[e.to]=e.weight;
	}
	while(!pq.empty()){
	    Pair curr = pq.pop();
	    if(inTree[curr.second])
		continue;
	    ret+=curr.first;
	    inTree[curr.second]=true;
	    for(auto e:G.Adj[curr.second]){
		if(inTree[e.to] || e.weight >= distanceTo[e.to])
		    continue;
		int index = pq.find(e.to);
		if(index==-1)
		    pq.push(Pair(e.weight,e.to));
		else
		    pq.decrease(Pair(e.weight,e.to), index);
		distanceTo[e.to] = e.weight;
	    }
	}
	return ret;
    }    
};

int main(int argc, char** argv){
    Graph g;
    Prim prim;
    g.ReadFromFile(argv[1]);
    cout << prim.MinTree(g)<<endl;
    return 0;
}

