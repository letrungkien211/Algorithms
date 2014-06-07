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

#define Edge pair<int,int>
#define INF 1000000

class UnionFind{
public:
    UnionFind(int E):data(E),size(E){	
	for(int i=0; i<E; i++){
	    data[i]=-1;
	}
    }
    vector<int> data;
    int size;
    void Union(int x, int y){
	if(data[x]<data[y]){
	    data[x]+=data[y];
	    data[y]=x;
	}
	else{
	    data[y]+=data[x];
	    data[x]=y;
	}
	size--;
    }
    
    int Find(int x){
	if(data[x]<0)
	    return x;
	data[x] = Find(data[x]);
	return data[x];
    }
};


int main(int argc, char** argv){
    ifstream input(argv[1]);
    int N = 200;
    srand(time(NULL));
    clock_t start = clock(); 
        
    set<Edge,function<bool(Edge,Edge)>> setedges([](Edge x, Edge y){return x.first==y.first? (x.second<y.second) : x.first<y.first;});

    string line;

    for(int i=0; i<N; i++){
	getline(input,line);
	stringstream buffer(line);
	int tmp;
	buffer >> tmp;
	while(buffer){	    
	    buffer >> tmp;
	    setedges.insert(Edge(min(i,tmp-1), max(i,tmp-1)));
	}
    }    
    input.close();
    int E = setedges.size();
    vector<Edge> edges(E);
    
    int globalMin = INF;
    int cntMax = 10000;
    int cnt=0;
    cout << E <<endl;
    while(cnt++<cntMax){
	UnionFind uf(N);
	int i=0;
	for(auto it = setedges.begin(); it!=setedges.end(); it++,i++){
	    edges[i]=*it;
	}

	int last = E-1;
	while(uf.size >2 && last>=0){
	    swap(edges[rand()%(last+1)], edges[last]);
	    int x = uf.Find(edges[last].first);
	    int y = uf.Find(edges[last].second);
	    if(x!=y){
		uf.Union(x,y);
	    }
	    last--;
	}

	int localMin = 0;
	if(last==0)
	    localMin = 0;
	while(last>=0){
	    int x = uf.Find(edges[last].first);
	    int y = uf.Find(edges[last].second);
	    if(x!=y){
		localMin++;
	    }
	    last--;
	}
	if(globalMin > localMin){
	    globalMin= localMin;
//	    cout <<cnt << " " << globalMin <<endl;
	}
    }    


    cout << globalMin <<endl;
    cout << (clock()-start)/(double)CLOCKS_PER_SEC <<endl;
    return 0;
}
