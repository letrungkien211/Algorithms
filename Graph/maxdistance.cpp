#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <set>
#include <cassert>
#include <unordered_set>
#include <functional>
using namespace std;

int maxdistance1(vector<int> &A){
	int ret = 0;
	int start=numeric_limits<int>::max();
	int n = A.size();
	for(int i=0; i<n-1; i++){
		if(A[i]>=start)
			continue;
		start=A[i];
		for(int j=n-1; j>=i+ret+1; j--){
			if(A[j]>A[i]){
				ret=max(ret,j-i);
			}
		}
	}
	return ret;
}

int maxdistance2(vector<int> &A){
	int ret=0;
	for(int i=0; i<A.size(); i++){
		for(int j=i+1; j<A.size(); j++){
			if(A[j]>A[i])
				ret=max(ret,j-i);
		}
	}
	return ret;
}

int main(int argc, char**argv){
	srand(time(NULL));
	int N = atoi(argv[1]);
	vector<int> A(N);	
	for(int i=0; i<N; i++) A[i] = N-i;
	int ret1 = maxdistance1(A);
	int ret2 = maxdistance2(A);
	
	cout << ret1 << " " <<ret2 <<endl;

	return 0;
}