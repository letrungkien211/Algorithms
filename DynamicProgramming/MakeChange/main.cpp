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

int money[] = {1,2,5,10,20,50,100,200,500};
int m = 9;

void MakeChange_Up(int n, vector<int> &r, vector<int> &s){
    For(i,1,n+1){
	if(i==0){
	    r[i] = 0;
	    s[i] = -1;	    
	}
	else{
	    r[i] = 1000;
	    s[i] = -1;	    
	    for(int k = 0; k < m && money[k] <= i; k++){
		if(r[i-money[k]]+1 < r[i]){
		    r[i] = r[i-money[k]]+1;
		    s[i] = k;
		}
	    }
	}
    }
}



int main(int argc, char** argv){
    int n = 2739;
    vector<int> r(n+1);
    vector<int> s(n+1);
    
    MakeChange_Up(n,r,s);
    int m = n;
    while(m>0){
	cout << money[s[m]] << " " ;
	m -= money[s[m]];
    }
    cout <<endl;
    cout << r[n] <<endl;    
    return 0;
}
