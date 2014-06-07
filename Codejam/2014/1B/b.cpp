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
#define LD long double
#define PR pair<int,int>

#define For(i,m,n) for (int i=m; i<int(n); i++)        
#define ForR(i,n) for (int i=int(n)-1; i>=0; i--)    

#define Sz(s) int((s).size())                    
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0
#define LIM 1000

ifstream input;
ofstream output;
int numTest;
int t;

int main(int argc, char**argv)
{
    clock_t start = clock();
    input.open(argc>1 ? argv[1]: "B-small-attempt.in");
    output.open(argc>2 ? argv[2]: "B-small-attempt.out");    

    input >> numTest;
    
    For(t,1,numTest+1){
	cout << "Case #" << t <<": ";
	output << "Case #" << t <<": ";
	int A,B,K;
	input >> A >> B >> K;

	int cnt =0;
	for(int i=0; i<A; i++){
	    for(int j=0; j<B; j++){
		int C = i&j;
		if(C<K)
		    cnt++;
	    }
	}
	cout << cnt <<endl;
	output << cnt <<endl;
    }
    output.close();
    input.close();
    cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;
    
    return 0;

}
