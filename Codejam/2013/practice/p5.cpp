#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    int T;
    input >> T;

    for(int i = 0; i < T; i++){
	input >> N;
	int D;
	for(int j = 0; j< N; j++){
	    input >> data[j][0];
	    input >> data[j][1];
	    used[j] = false;
	}
	input >> D;
    }
    
    return 0;
}
