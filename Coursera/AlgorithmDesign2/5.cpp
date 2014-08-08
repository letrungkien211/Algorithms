#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
#include<bitset>
#include<string>
#include<unordered_map>
#include<ctime>
#include<cmath>
#include<functional>

using namespace std;

#define INF numeric_limits<double>::max()

class Point{
public:
    double x,y;
};
int N;

#define INF numeric_limits<double>::max()

class TSP{
public:
    vector<Point> points;
    vector<vector<double> > distances;
    vector<vector<vector<double> > > memo;
    vector<vector<vector<int> > > subsets;

    
    void ReadFromFile(string filename){
	ifstream input(filename);input >> N;
	points = vector<Point>(N);
	distances = vector<vector<double>>(N,vector<double>(N));
	for(int i=0; i<N; i++){
	    input >> points[i].x >> points[i].y;
	}
	input.close();
    }

    void Preprocess(){
	for(int i=0; i<N; i++){
	    for(int j=0; j<N; j++){
		distances[i][j] = sqrt(pow(points[i].x-points[j].x,2) + pow(points[i].y-points[j].y,2));
	    }
	}
	vector<int> curr{1};
	subsets.resize(N+1);
	memo.resize(N+1);
	GenerateSubset(2,1,curr);

	vector<int> temp{1,1};
	memo[1][temp]=0;
	for(int i=2; i<=N; i++){
	    temp.back()= i;
	    memo[1][temp] = INF;
	}
    }
    
    void GenerateSubset(int start, int depth, vector<int>& curr){
	subsets[depth].push_back(curr);
	if(depth>=N)
	    return;
	for(int i =start; i<=N; i++){
	    curr.push_back(i);
	    GenerateSubset(i+1, depth+1, curr);
	    curr.pop_back();
	}
    }
    
    void RunAlgorithm(){
	for(int m=2; m<=N; m++){
	    for(auto subset: subsets[m]){
		vector<int> tmp = subset;
		tmp.push_back(1);
		for(auto i : subset){
		    if(i==1)
			continue;
		    vector<int> tmp1 = subset;
		    
		    for(auto j : subset){
			if(j==i)
			    continue;
		    }
		}
	    }
	}
    }
};



int main(int argc, char** argv){
    clock_t start = clock();
    TSP tsp;
    cout << "Read File" <<endl;
    tsp.ReadFromFile(argv[1]);
    cout << "Preprocess" <<endl;
    tsp.Preprocess();
    cout << "Run" <<endl;

    cout << "Elapsed time: " << ((double)clock()-(double)start)/(double)CLOCKS_PER_SEC <<endl;
    return 0;
}




    /*
      
      
     */
											 
