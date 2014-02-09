#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define For(i,n) for(int i=0; i < n; i++)

void LIS(vector<int> x, vector<int> &r, vector<int> &s);

int main(int argc, char **argv){    
    srand(time(NULL));
    int n = 10;
    vector<int> x(n);
    For(i,n){
	x[i] = rand()%10;
	cout << x[i] << " ";
    }
    cout <<endl;
    vector<int> r,s;
    LIS(x,r,s);
    
    int last = max_element(r.begin(), r.begin()+r.size()) - r.begin();
    int i = last;
    while(i>=0){
	cout << i << " ";
	i = s[i];
    }
    cout << endl << r[last] << endl;
    return 0;
}

// Longest Increasing Sequence
void LIS(vector<int> x, vector<int> &r, vector<int> &s){
    int n = x.size();
    r.resize(n);
    s.resize(n);
    for(int i = 0; i < n; i++){	
	if(i==0){
	    r[i] = 1;
	    s[i] = -1;
	}
	else{
	    int max_k = -1;
	    int max_r = 0;
	    for(int k=i-1; k>=0; k--){
		if(x[k] <  x[i]){
		    if(r[k] > max_r){
			max_k = k;
			max_r = r[k];
		    }
		}
	    }
	    r[i] = max_r + 1;
	    s[i] = max_k;
	}
    }    
}
 
