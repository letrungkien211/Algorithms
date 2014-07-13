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
#include<cassert>

using namespace std;
#define Pair pair<double,int>


struct Edge{
    int from,to;
    double weight;
    Edge(int x=-1, int y=-1, double w=-1): from(x), to(y), weight(w){}
};

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



class Graph{
public:
    int V;
    int E;
    vector<list<Edge> > Adj;
    
    Graph(int numVertex){
	V = numVertex;
	E = 0;
	Adj.resize(V);
    }

    void ReadFromFile(string filename){
	ifstream input(filename);
	char line[1000];
	while(input.good()){
	    input.getline(line,1000);	    
	    stringstream ss(line);
	    int from;
	    ss >> from;
	    from--;
	    while(ss.good()){
		int to=-1, weight=-1;
		ss >> to >> weight;
		if(to==-1 || weight==-1)
		    continue;
		to--;
		Adj[from].push_back(Edge(from,to,weight));
		E++;
	    }
	}
    }    
};

#define INF 1000000

class Dijkstra{
public:
    vector<double> distanceTo;
    void ShortestPath(Graph &G, int source = 0){
	distanceTo = vector<double>(G.V,INF);
	vector<bool> closed(G.V, false);
	MinPQ open;
	distanceTo[source]=0.0;
	open.init(G.V);
	open.push(Pair(0.0, source));

	while(!open.empty()){
	    Pair curr = open.pop();
	    int from = curr.second;
	    closed[from]=true;
	    for(auto e:G.Adj[from]){
		int to = e.to;
		if(closed[to]){
		    continue;
		}
		double dis = e.weight + distanceTo[from];
		if(dis < distanceTo[to]){
		    int index = open.find(to);
		    if(index==-1)
			open.push(Pair(dis,to));
		    else
			open.decrease(Pair(dis,to), index);
		    distanceTo[to] = dis;
		}
	    }
	}
    }
};


int main(int argc, char** argv){
    Graph G(200);
    G.ReadFromFile("dijkstraData.txt");
    cout << G.E<<endl;
    Dijkstra dijk;
    dijk.ShortestPath(G);
    
    vector<int> vertices{7,37,59,82,99,115,133,165,188,197};
    for(auto v : vertices){
	cout << dijk.distanceTo[v-1] <<",";
    }
    cout << endl;
    
    return 0;
}
