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
#include <unordered_set>
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

string search(int N, int M, vector<string>& code, vector<vector<int> > &adj){
    vector<int> round;
    string ret;
    vector<bool> checked(false, N);
    int numCheck =1;
    
    ret=code[0];
    int current=0;
    for(int i=1; i<N; i++){
	if(ret>code[i]){
	    current=i;
	    ret = code[i];
	}	    
    }

    round.push_back(current);
    checked[current]=true;
    while(numCheck<N){
	int minNext = -1;
	string minstr = "999999999";
	int minRound = -1;
	for(int i=0; i<round.size(); i++){
	    for(auto x: adj[round[i]]){
		if(!checked[x] && code[x]<minstr){
		    minstr = code[x];
		    minNext=x;
		    minRound=i;
		}
	    }
	}
	if(round.size()>2 && minRound<round.size()-1)
	    round.erase(round.begin()+minRound+1, round.end());	    
	current = minNext;
	checked[current]=true;
	round.push_back(current);
	ret+=minstr;
	numCheck++;
    }

    return ret;    
}


int main(int argc, char**argv)
{
    clock_t start = clock();
    input.open(argc>1 ? argv[1]: "C-small-attempt.in");
    output.open(argc>2 ? argv[2]: "C-small-attempt.out");    


    input >> numTest;    
    For(t,1,numTest+1){	
	cout << "Case #" << t <<": ";
	output << "Case #" << t <<": ";
	int N,M;
	input >> N >> M;
	vector<string> code(N);
	vector<vector<int>> adj(N);
	For(i,0,N){
	    input >> code[i];
	}
	For(i,0,M){
	    int from,to;
	    input >> from >> to;
	    from--;
	    to--;
	    adj[from].push_back(to);
	    adj[to].push_back(from);
	}

	string ret = search(N, M, code, adj);
	cout << ret<<endl;
	output << ret<<endl;
    }
    output.close();
    input.close();
    cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;
    
    return 0;

}
