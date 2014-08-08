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
using namespace std;

#define INF numeric_limits<double>::max()

class Point{
public:
    double x,y;
};

class TSP{
public:
    vector<Point> points;
    vector<vector<double> > distances;
    vector<unordered_map<list<int>,double> > memo;
    vector<list<int> > subsets;
    int N;
    
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
    }
};



int main(int argc, char** argv){
    clock_t start = clock();


    cout << "Elapsed time: " << ((double)clock()-(double)start)/(double)CLOCKS_PER_SEC <<endl;
    return 0;
}
