#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <limits>
using namespace std;

#define ERROR 0.00000001

bool IsFair(double x){
    stringstream ss;
    ss << x;
    string str = ss.str();
    int len = str.length();
    for(int i = 0; i < len/2; i++){
	if(str[i]!=str[len-1-i])
	    return false;
    }
    return true;
}

int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    int T;
    input >> T;

    vector<double> A(T);
    vector<double> B(T);
    vector<double> fairsquare;
    double min =numeric_limits<double>::max();
    double max = -1;
    for(int t = 0; t < T; t++){
	/* Input*/
	input >> A[t];
	input >> B[t];
	if(A[t]<min)
	    min=A[t];
	if(B[t]>max)
	    max=B[t];
    }

    double C = sqrt(min);
    double D = sqrt(max);
    if(C*C<min)
	C++;
    int counter = 0;
    for(double i = C; i <= D; i++){
	double tmp = i*i;
	if(IsFair(i) && IsFair(tmp)){
	    fairsquare.push_back(tmp);
	    counter++;
	}
    }

    for(int t = 0; t < T; t++){
	int result = 0;
	for(int i = 0; i < counter; i++){
	    if(fairsquare[i]>=A[t]){
		if(fairsquare[i]>B[t])
		    break;
		else
		    result++;
	    }
	}
	output << "Case #" << t+1 <<": " << result;
	output <<endl;
    }
    
    return 0;
}
