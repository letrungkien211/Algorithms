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

#define For(i,n) for (i=0; i<int(n); i++)        
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)    

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

vector<double> judgeScore;
vector<double> minPercent;
double X;
int N;

int main(int argc, char**argv)
{
    clock_t start = clock();
    input.open(argc>1 ? argv[1]: "in.txt");
    output.open(argc>2 ? argv[2]: "out.txt");    

    input >> numTest;
    for(t = 0 ; t < numTest; t++){
	int i;
	input >> N;
	judgeScore.resize(N);
	minPercent.resize(N);
	X = 0;
	For(i,N){
	    input >> judgeScore[i];
	    X+=judgeScore[i];
	}
	For(i,N){
	    minPercent[i] = max(0.0, 2.0/(double)N-(judgeScore[i])/X);
	    minPercent[i]*=100;
	}
	output << "Case #" << t+1 << ": ";
	char s[100];
	For(i,N-1){
	    sprintf(s, "%.7lf ", minPercent[i]);
	    output << s;
	}
	sprintf(s, "%.7lf", minPercent[N-1]);
	output << s << endl;
    }

    cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;
    
    return 0;

}
