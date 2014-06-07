#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>
using namespace std;

#define LL long long
ifstream input;
ofstream output;
int numTest;

LL gcd(LL u, LL v) {
    while ( v != 0) {
        LL r = u % v;
        u = v;
        v = r;
    }
    return u;
}
vector<LL> data(41);

int func(LL p, LL q){
    auto a = lower_bound(data.begin(), data.end(), p);
    auto b = lower_bound(data.begin(), data.end(), q);
    return b-a + (*a== p ? 0 : 1);
}

int main(int argc, char**argv)
{
    clock_t start = clock();
    assert(argc==3);
    input.open(argv[1]);
    output.open(argv[2]);    

    input >> numTest;
    

    data[0]=1;
    for(int i=1; i<=40; i++){
	data[i] = data[i-1]<<1;
    }

    for(int cnt =1; cnt <=numTest; cnt++){
	cout << "Case #" << cnt <<": ";
	output << "Case #" << cnt <<": ";
	
	LL p, q;
	input>> p >> q;
	LL pq = gcd(p,q);
	p = p/pq;
	q = q/pq;
	if((q<<1 & q)!=0){
	    output << "impossible\n";
	    cout << "impossible\n";
	}
	else{
	    int ret =func(p,q);
	    output << ret <<endl;
	    cout << ret <<endl;
	}
    }
    output.close();
    input.close();

    cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;
    
    return 0;

}
