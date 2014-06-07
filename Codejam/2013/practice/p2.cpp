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
};

int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    int N, T;
    vector<Data> data;
    input >> T;
    for(int i = 0; i < T; i++){
	input >> N;
	data.resize(N);
	int counter = 0; 
	for(int j = 0; j< N; j++){
	    input >> data[j].A;
	    input >> data[j].B;
	}
	for(int j = 0; j <N-1; j++){
	    for(int k = j+1; k < N; k++){
		if((data[j].A-data[k].A)*(data[j].B-data[k].B)<0)
		    counter++;
	    }
	}
	output << "Case #" << i+1 <<": " << counter <<endl; 
    }
    
    return 0;
}
