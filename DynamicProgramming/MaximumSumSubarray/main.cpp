// 
// Problem:
// Given a sequence of n real numbers A(1) ... A(n), determine a contiguous subsequence A(i) ... A(j) for which the sum of elements in the subsequence is maximized. 

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

void MaxSub_Up(const vector<int> x, vector<int> &r){
    int n = x.size();
    For(i,0, n){
	if(i==0){
	    r[0] = x[0];
	}
	else{
	    r[i] = x[i] + max(r[i-1],0);
	}
    }
}

int MaxSub_Down(const vector<int> x, vector<int> &r, int k){
    int n = x.size();
    if(k== n-1){
	For(i,0,n){
	    r[i] = -10000;	}
    }

    if(k==0){
	r[k] = x[0];
	return r[k];
    }

    if(r[k-1]==-10000)
	r[k-1] = MaxSub_Down(x,r,k-1);
    r[k] = max(x[k], r[k-1] + x[k]);
    return r[k];
}

int main(int argc, char** argv){
    srand(100);
    
    int n = 1000;
    vector<int> x(n), r(n);
    For(i,0,n){
	x[i] = rand()%n - n/2;
	cout << x[i] << " ";
    }    
    cout << endl;
    //MaxSub_Up(x, r);
    MaxSub_Down(x,r,n-1);
    int max = *max_element(r.begin(), r.end());
    cout << max << endl;
    return 0;
}


