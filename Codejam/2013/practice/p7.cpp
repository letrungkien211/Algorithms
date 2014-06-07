#include <cstdio>
#include <ctime>
#include <cassert>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>

#include "../lib/bfs.hpp"

using namespace std;

/* Global Variables */

typedef struct Vine_{
    int d; // distance
    int l; // length
} Vine;

////////////////////////////
ifstream input;
ofstream output;
int numTest;       
int t;
////////////////////////////

vector<Vine> vine;
int N,D;

class State{
public:
    int index;
    int length;

    int range() const{
	return vine[index].d+length;
    }
};

bool operator==(const State &x, const State &y){
    return x.index == y.index && x.length == y.length;
}

bool operator<(const State &x, const State &y){
    return x.range() < y.range();
}

int maxRange[10002];

int main(int argc, char**argv){
    assert(argc>1);
    input.open(argv[1]);
    output.open(argc>2 ? argv[2] : "output.txt");    

    input >> numTest;

    for(t = 0 ; t < numTest; t++){
	input >> N;
	vine.resize(N+2);
	vine[0].d = vine[0].l = 0;
	for(int i=1; i<=N; i++){
	    input >> vine[i].d;
	    input >> vine[i].l;
	    maxRange[i] = 0;
	}
	maxRange[N+1] = maxRange[0] = 0;
/////////////////////////////////////////////
	input >> D;
	vine[N+1].d = D;
	vine[N+1].l = 1000000000;

	State initial;
	initial.index = 1;
	initial.length = vine[1].d;

	//priority_queue<State> pq;
	queue<State> pq;
	pq.push(initial);
	bool found = false;
	while(!pq.empty()){
	    State current = pq.front();
	    pq.pop();

	    if(current.index ==N+1){
		found = true;
		output << "Case #" << t+1 << ": YES" << endl;
		cout << "Case #" << t+1 << ": YES" << endl;
		break;
	    }

	    State maxState = current;
	    for(int i = current.index+1; i<=N+1; i++){
		if(current.range() >= vine[i].d){
		    State tmp;
		    tmp.index = i;
		    tmp.length = min(vine[i].l, vine[i].d-vine[current.index].d);
		    if(tmp.length<= maxRange[i])
		     	continue;
		    pq.push(tmp);
		    maxRange[i] = tmp.length;
		}
	    }
	}
	if(!found){
	    output << "Case #" << t+1 << ": NO" << endl;
	    cout << "Case #" << t+1 << ": NO" << endl;
	}
    }
    return 0;
}
