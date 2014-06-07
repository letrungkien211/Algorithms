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

struct Data{
    string unique;
    vector<int> freq;
};


Data Count(string &s){
    Data ret;
    
    for(int i=0; i<s.size(); i++){
	int j=i;
	while(j<s.size()-1 && s[j]==s[j+1]) j++;
	ret.unique+=s[i];
	ret.freq.push_back(j-i+1);
	i=j;
    }
    return ret;
}

int main(int argc, char**argv)
{
    clock_t start = clock();
    input.open(argv[1]);
    output.open(argv[2]);

    input >> numTest;
    
    For(t,0,numTest){
	cout << "Case #" << t+1 <<": ";
	int N;
	input >> N;
	vector<string> strs(N);
	for(int i=0; i<N; i++){
	    input >> strs[i];
	}

	int ret=0;
	
	if(N==2){
	    Data d1 = Count(strs[0]);
	    Data d2 = Count(strs[1]);

	    if(d1.unique!=d2.unique){
		ret=-1;
	    }
	    else{
		ret=0;
		for(int i=0; i<d1.unique.size(); i++){
		    ret+=abs(d1.freq[i]-d2.freq[i]);
		}		
	    }
	}
	else{
	    vector<Data> d(N);
	    for(int i=0; i<N; i++){
		d[i]=Count(strs[i]);
		if(i>0 && d[i].unique!=d[i-1].unique){
		    ret=-1;
		}
	    }
	    int len = d[0].unique.size();
	    
	    if(ret!=-1){
		ret=0;
		for(int i=0; i<len; i++){		    
		    int sum = 0;
		    for(int j=0; j<N; j++){
			sum+=d[j].freq[i];
		    }		    
		    int tmp =1000000000;
		    for(int j=0; j<N; j++){
			int tmp1=0;
			for(int k=0; k<N; k++){
			    tmp1+=abs(d[k].freq[i]-d[j].freq[i]);
			}
			tmp = min(tmp1,tmp);
		    }
		    ret+=tmp;
		    if(t==2)
			cout << tmp <<endl;
		}
	    }
	}
	
	if(ret!=-1)
	    output << "Case #" << t+1 <<": " <<ret << endl;
	else
	    output << "Case #" << t+1 <<": " <<"Fegla Won" << endl;
    }
    output.close();
    input.close();
    cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;
    
    return 0;

}
