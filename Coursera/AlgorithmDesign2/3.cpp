#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
#include<bitset>
#include<string>
#include<unordered_map>
#include<ctime>

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
    int N;
    vector<string> vertices;
    Graph(){
    }
    void ReadFromFile(string filename){
	ifstream fin(filename);	
	fin >> V >> N;
	vertices.resize(V);
	int tmp;
	for(int i=0; i<V; i++){
	    vertices[i].resize(N);
	    for(int j=0; j<N; j++){
		fin >> tmp;
		vertices[i][j] = tmp == 1 ?'1':'0';
	    }
	}
	fin.close();
    }    
};

class UnionFind{
public:
    vector<int> data;
    int size;
    UnionFind(int num=0){
	Init(num);
    }
    void Init(int num){
	size = num;
	data.resize(num);
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
    void Flip(char& c){
	c = c=='1' ?'0' : '1';
    }
    unordered_map<string,int> hashmap;
    UnionFind uf;    
    int Cluster(){
	uf.Init(V);
	for(int i=0; i<V; i++){
	    hashmap.insert(pair<string,int>(vertices[i],i));
	}
	cout << hashmap.size() <<endl;
	for(int i=0; i<V; i++){
	    string tmp = vertices[i];
	    Check(tmp,i);
	    for(int j =0; j<N; j++){
		Flip(tmp[j]);
		Check(tmp,i);
		for(int k=j; k<N; k++){
		    Flip(tmp[k]);
		    Check(tmp,i);
		    Flip(tmp[k]);
		}
		Flip(tmp[j]);
	    }
	}
	return uf.size;
    }
    
    void Check(string str, int i){
	auto it = hashmap.find(str);
	if(it!=hashmap.end()){
	    int x = uf.Find(i);
	    int y = uf.Find(it->second);
	    if(x!=y){
		uf.Union(x,y);
	    }
	}

    }
};

int main(int argc, char** argv){
    Solution sol;
    clock_t start = clock();
    cout << "Start reading" <<endl;
    sol.ReadFromFile(argv[1]);
    cout << sol.vertices[199999] <<endl;
    cout << "Start clustering" <<endl;
    cout << sol.Cluster() <<endl;

    cout << "Elapsed time: " << ((double)clock()-(double)start)/(double)CLOCKS_PER_SEC <<endl;
    return 0;
}
