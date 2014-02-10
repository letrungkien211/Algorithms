#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define For(i,n) for(int i=0; i < n; i++)
void LIS_Down(vector<int> x);
vector<int> LIS_Up(vector<int> x, int k);
vector<int> r;
vector<int> s;

int main(int argc, char **argv){    
    srand(100);
    int n = 100;
    vector<int> x(n);
    For(i,n){
	x[i] = rand()%n;
	cout << x[i] << " ";
    }
    cout <<endl;
    r.resize(n);
    s.resize(n);

    fill(r.begin(), r.end(), -1);
    fill(s.begin(), s.end(), -1);

    //LIS_Up(x,n-1);
    LIS_Down(x);
    
    int last = max_element(r.begin(), r.begin()+n) - r.begin();
    For(i,n)
	cout << r[i] << " ";
    cout << endl;
    int i = last;
    while(i>=0){
	cout << i << " ";
	i = s[i];
    }
    cout << endl << r[last] << endl;
    return 0;
}

// Longest Increasing Sequence
// Bottom-Up
void LIS_Down(vector<int> x){
    int    n = x.size();
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


// Bottom down
vector<int> LIS_Up(vector<int> x, int k){
    vector<int> result(2);
    if(k==0){
	r[0] = result[0] = 1;
	s[0] = result[1] = -1;
	return result;
    }
    else{
	result[0] = 0;
	result[1] = -1;
	for(int i = k-1; i >=0; i--){
	    if(x[i] < x[k]){
		if(r[i] == -1){
		    vector<int> tmp = LIS_Up(x,i);
		    r[i] = tmp[0];
		    s[i] = tmp[1];
		}
		if(r[i] > result[0]){
		    result[0] = r[i];
		    result[1] = i;
		}
	    }
	}
	result[0]++;
	r[k] = result[0];
	s[k] = result[1];

	if(r[k-1] ==-1){
	    vector<int> tmp = LIS_Up(x,k-1);
	    r[k-1] = tmp[0];
	    s[k-1] = tmp[1];
	}
	
	if(r[k] < r[k-1]){
	    r[k] = r[k-1];
	    s[k] = s[k-1];
	}
	return result;
    }
}


// Bottom down
