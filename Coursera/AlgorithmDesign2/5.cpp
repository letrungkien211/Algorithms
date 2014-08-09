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
    static double Distance(const Point& a, const Point& b){
	return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
    }
};

vector<int> power;


int myhash(vector<int> &v){
    int ret = 0;
    for(auto i : v)
	ret |= power[i];
    return ret;
}

class TSP{
public:
    vector<Point> points;
    vector<vector<double> > distances;
    vector<vector<unordered_map<int,double> > > memo;
    vector<vector<vector<int> > > subsets;
    int N;
    
    // Read data from file
    void ReadFromFile(string filename){
	ifstream input(filename);
	input >> N;
	points = vector<Point>(N);
	for(int i=0; i<N; i++){
	    input >> points[i].x >> points[i].y;
	}
	input.close();
    }

    // Preprocess
    void Preprocess(){
	// Calculate power
	power.resize(N+1);
	power[0]=1;
	for(int i=1; i<=N; i++){
	    power[i] = power[i-1] << 1;
	}
	
	// Initialze
	distances = vector<vector<double>>(N,vector<double>(N));
	subsets = vector<vector<vector<int> > >(N);
	memo = vector<vector<unordered_map<int,double> > >(N, vector<unordered_map<int,double> >(N));

	// Calculate distances
	for(int i=0; i<N; i++){
	    for(int j=0; j<N; j++){
		distances[i][j] = Point::Distance(points[i],points[j]);
	    }
	}

	// Generate subsets
	vector<int> curr{0};
	GenerateSubset(1,0,curr);
    }
    
    void GenerateSubset(int start, int depth, vector<int>& curr){
	subsets[depth].push_back(curr);
	memo[depth][0][myhash(curr)]=INF; // Base case
	if(depth>=N-1)
	    return;
	for(int i =start; i<N; i++){
	    curr.push_back(i);
	    GenerateSubset(i+1, depth+1, curr);
	    curr.pop_back();
	}
    }
    
    double RunAlgorithm(){
	// Base case
	vector<int> curr{0};
	memo[0][0][myhash(curr)]=0;
	
	for(int m=1; m<N; m++){
	    cout << m <<endl;
	     for(auto subset: subsets[m]){
		 int hashsub = myhash(subset);
		 for(auto i : subset){
		     if(i==0)
			 continue;
		     int si = hashsub^power[i];
		     double mindis = INF;
		     for(auto j : subset){
			 if(j==i)
			     continue;
			 mindis = min(mindis, memo[m-1][j][si] + distances[i][j]);
		     }
		     memo[m][i][myhash(subset)]=mindis;
		 }
	     }
	}
	
	double ret = INF;
	int hashvalue = pow(2,25)-1;
	    
	for(int j=1; j<N; j++){
	    ret = min(ret,memo[N-1][j][hashvalue]);
	}
	return ret;
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
    tsp.RunAlgorithm();
    cout << "Elapsed time: " << ((double)clock()-(double)start)/(double)CLOCKS_PER_SEC <<endl;
    return 0;
}
