#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    int A;
    int B;
    int operator[](int i) const{
	return i==0 ? A : B;
    }
    int &operator[](int i) {
	return i==0 ? A : B;
    }

};

bool process(const vector<Data> &data, vector<bool> &used, int previous, int current, int D){
    int N = data.size();
    int L, P;
    L = current==0 ? min(data[current][0], data[current][1]) : min(data[current][1], data[current][0]-data[previous][0]);
    P = data[current][0];
    if(D-P<=L)
	return true;
    if(current>=N)
	return false;
    for(int i = current+1; i < N && data[i][0]-P <= L; i++){
	used[current]=true;
	if(!used[i] &&process(data, used, current, i, D))
	    return true;
    }

    return false;
}


int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    int N, T;
    vector<Data> data;
    vector<bool> used;
    input >> T;

    for(int i = 0; i < T; i++){
	input >> N;
	int D;
	data.resize(N);
	used.resize(N);
	for(int j = 0; j< N; j++){
	    input >> data[j][0];
	    input >> data[j][1];
	    used[j] = false;
	}
	input >> D;

	bool possible = process(data, used, -1, 0, D);
	output << "Case #" << i+1 << ": ";
	if(possible)
	    output << "Possible" <<endl;
	else
	    output << "Impossible" <<endl;
	cout << "DONE" <<endl;
    }
    
    return 0;
}
