#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

#define LIMIT 200

int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);
    
    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    clock_t start = clock();
    
    int numTest;
    input >> numTest;
    
    int K,N;

    for(int t = 0; t < numTest; t++){
	input >> K >> N;
	map<int,int> keyAvail;
	vector<vector<int> > keyInChest(N);
	map<int,set<int> > keyOpen;
	
	for(int i=0; i<K; i++){
	    int tmp;
	    input>>tmp;
	    if(keyAvail.find(tmp)==keyAvail.end()){
		keyAvail[tmp]=1;
	    }
	    else
		keyAvail[tmp]++;
	}

	for(int i=0; i<N; i++){
	    int numKeyInChest;
	    input>>keyOpen[i]>>numKeyInChest;
	    keyInChest[i].resize(numKeyInChest);
	    for(int j=0; j<numKeyInChest; j++)
		input>> keyInChest[i][j];
	}

    }
    cout << (double)(clock()-start)/CLOCKS_PER_SEC <<endl;
    
    return 0;
}
