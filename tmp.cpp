#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <map>
#include <queue>
#include<unordered_set>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unordered_map>
#include<unordered_set>
#include<sstream>
#include<cassert>
#include <stack>
#include<string>

using namespace std;

vector<int> LIS(vector<int>& A){
	int n = A.size();
	if(n<=1) return A;
	vector<int> dp(n,0);
	vector<int> pre(n,0);
	int maxindex=0;
	int maxlen=0;
	for(int i=0; i<n; i++){
		dp[i]=1;
		pre[i]=-1;
		for(int k=0; k<i; k++){
			if(A[k]<A[i]){
				if(dp[i]<1+dp[k]){
					pre[i]=k;
					dp[i]=1+dp[k];
				}				
			}
		}
		if(dp[i]>maxlen){
			maxlen=dp[i];
			maxindex=i;
		}
	}
	vector<int> ret(maxlen);
	for(int i=maxlen-1; i>=0; i--){
		ret[i]=A[maxindex];
		maxindex=pre[maxindex];
	}
	return ret;
}

int main(int argc, char** argv){
	srand(time(NULL));
	vector<int> A(1000);
	for(auto &a:A){
		a = rand()%1000;
		cout << a << " ";
	}
	cout <<endl;
	vector<int> ret = LIS(A);
	for(auto a:ret) cout << a << " "; cout <<endl;
    return 0;
}
