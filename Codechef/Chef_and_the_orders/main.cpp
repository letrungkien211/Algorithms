#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <set>

using namespace std;

#define For(i,m,n) for(int i=m; i < n; i++)

typedef struct _Data{
    int s, x,d,p;
} Data;


int dead(const vector<Data> &data, int p){
    int sum = 0;
    For(i,0,p){
	sum+= data[i].x;
    }

    int res = 0;
    vector<Data> orders(data.begin(), data.begin()+p+1);
    vector<int> times;
    for(int i =0; i<orders.size(); i++){
	times.push_back(orders[i].s);
	times.push_back(orders[i].d);
    }
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
    for(vector<int>::iterator it = times.begin(); it+1!=times.end(); ++it){
	int from = *it, to = *(it+1);
	int avail = to - from;

	while(avail){
	    int ind = -1;
	    int lastEnd = 0;	    
	}
    }
}


int Pelnaty(vector<Data> &data ){
    int n = data.size();
    stable_sort(data.begin(), data.end(), 
		[](const Data&a, const Data&b){
		    return a.p > b.p;
		}
	);    
    int pelnaty = 0;
    For(i,0,n){
	int dead = getDead(data, i);
	pelnaty += dead*data[i].p;
	data[i].x -= dead;
    }
}

int main(int argc, char** argv){

    int T ;
    cin >> T;
    For(t,0,T){
	int n;
	cin >> n; 
	vector<Data> data(n);
	For(i,0,n){
	    cin >> data[i].s >> data[i].x >> data[i].d >> data[i].p;
	}

	int result = MinPelnaty(data);
	cout << result << endl;
    }

    return 0;
}
