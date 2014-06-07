#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    int price;
    int index;
    bool operator<(const Data &d1){
	return this->price < d1.price;
    }
};

int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());
    int N, C, I;
    vector<Data> P;
    input >> N;
    for(int i = 0; i < N; i++){
	input >> C;
	input >> I;
	P.resize(I);
	for(int j = 0; j< I; j++){
	    input >> P[j].price;
	    P[j].index = j+1;
	}
	sort(P.begin(), P.end());
	for(int j = 0; j<I; j++){
	    Data d;
	    d.price = C-P[j].price;
	    vector<Data>::iterator tmp = lower_bound(P.begin(), P.end(), d);
	    if((*tmp).price==d.price && (*tmp).index!=P[j].index){
		int min = P[j].index < (*tmp).index ? P[j].index : (*tmp).index;
		int max = P[j].index > (*tmp).index ? P[j].index : (*tmp).index;
		output << "Case #"<<i+1<<": " << min << " " << max << endl;
		break;
	    }
	}
    }
    
    return 0;
}
