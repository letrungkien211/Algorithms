#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <set>
#include <cassert>
#include <unordered_set>
#include <functional>
using namespace std;

class Edge{
private:
	pair<int,int> vertices;
	double w;
public:
	Edge(int u=-1, int v=-1, double weight=-1): vertices(u,v), w(weight){}
	pair<int,int> both() const{
		return vertices;
	}	
	int from() const{
		return vertices.first;
	}	
	int to() const{
		return vertices.second;
	}
	double weight() const{
		return w;
	}

};

class Graph {
private:
	int V_,E_;
public:
    vector<list<Edge>> adj;
    Graph(): V_(0), E_(0){}
	void init(int V){
		V_=V;		
		adj.clear();
		adj.resize(V);		
		E_=0;
	}
    void addEdge(const Edge &e){		
		E_++;
		adj[e.from()].push_back(e);		
    }	
	int E() const{
		return E_;		
	}	
	int V() const{
		return V_;
	}	
	void readtxt(const string &filename){
		int u,v,numV,numE;
		double w;
		ifstream file(filename);
		file >> numV >> numE;
		init(numV);		
		for(int i=0; i<numE; i++){			
			file >> u >> v >> w;
			addEdge(Edge(u,v,w));
		}
	}
};

typedef pair<double,int> Pair;

class MinPQ{
private:
	Pair *data;
	int* mapindex;
	int MAX;
	int size;
public:
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

#define INF numeric_limits<double>::max()/2
vector<int> dijkstra(Graph &g, int start=0){
	vector<int> parent(g.V(),-1);
	vector<double> distance(g.V(),INF);
	vector<bool> done(g.V(), false);
	parent[start]=start;
	distance[start]=0;	
	
	MinPQ pq;
	pq.init(g.V());
	
	pq.push(Pair(0.0,start));
	while(!pq.empty()){		
		Pair curr = pq.pop();
		if(done[curr.second])
			continue;
		done[curr.second]=true;
		for(auto e:g.adj[curr.second]){
			if(done[e.to()])
				continue;			
			double dis = e.weight()+distance[e.from()];
			if(dis<distance[e.to()]){
				int index=pq.find(e.to());
				if(index==-1)
					pq.push(Pair(dis,e.to()));
				else
					pq.decrease(Pair(dis,e.to()), index);
				parent[e.to()]=e.from();
				distance[e.to()]=dis;
			}
			else if(dis==distance[e.to()] && parent[e.to()]>e.from()){
				parent[e.to()]=e.from();
			}
		}
	}		
	return parent;
}

vector<int> bellmanford(Graph &g, int start=0){
	vector<double> distance(g.V(),INF);
	vector<int> parent(g.V(),-1);
	distance[start]=0;
	parent[start]=0;
	for(int cnt=1; cnt<g.V(); cnt++){	
		for(int from=0; from<g.V(); from++){
			for(auto e:g.adj[from]){
				double dis=e.weight()+distance[from];				
				if(dis<distance[e.to()]){
					distance[e.to()]=dis;
					parent[e.to()]=from;					
				}
			}
		}
	}
	return parent;	
}
/*
bool edgeWeightLess(const Edge& e1, const Edge& e2){
	return e1.weight() > e2.weight();
}
*/

class UnionFind{
	int n;
	vector<int> data;
	vector<int> size;
public:	
	UnionFind(int num): n(num){
		data.resize(n+1);
		size.resize(n+1);
		for(int i=1; i<=n; i++){ data[i]=-i; size[i]=1;}
	}	
	int Find(int x){
		if(data[x]<0)
			return data[x];
		int c = Find(data[x]);
		data[x]=-c;
		return c;
	}	
	void Union(int x, int y){
		int cx=-Find(x),cy=-Find(y);
		if(size[cx]<size[cy]){
			data[cx]=cy;
			size[cy]+=size[cx];
		}
		else{
			data[cy]=cx;
			size[cx]+=size[cy];
		}
	}
};

vector<Edge> kruskal(Graph &g){
	auto comp = [](const Edge &e1, const Edge &e2){return e1.weight()>e2.weight();};
	priority_queue<Edge,vector<Edge>, decltype(comp)>  pq(comp);
	for(int i=0; i<g.V(); i++)
		for(auto e:g.adj[i])
			pq.push(e);
	vector<Edge> tree;
	UnionFind uf(g.V());
	while(!pq.empty()){
		Edge e = pq.top();
		pq.pop();
		if(uf.Find(e.to()+1)!=uf.Find(e.from()+1)){
			uf.Union(e.to()+1, e.from()+1);
			tree.push_back(e);
		}			
	}
	return tree;
}



int main(int argc, char** argv){	
	Graph g;
	g.readtxt("10000EWG.txt");
	clock_t start = clock();	
	vector<Edge> mininumSpan = kruskal(g);	
    return 0;
}

