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

    int N, T;
    vector<Data> data;
    input >> T;
    for(int i = 0; i < T; i++){
	/* Input*/

	//////////////////////////////////////////
	/*Process*/



//////////////////////////////////////////////////
	

	/* Output*/
	output << "Case #" << i+1 <<": Too Bad"<<endl;
    }
    
    return 0;
}
