#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <map>
#include <queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int m=S.size();
        int n=T.size();
        if(n>m) return 0;
        vector<vector<int>> dp(2,vector<int>(n,0));
        int flag=0;
	dp[0][0]= S[0]==T[0] ? 1:0;
        
        for(int i=1; i<m; i++){
            flag=1-flag;
            for(int j=0; j<n; j++){
                dp[flag][j]=dp[1-flag][j];
        		dp[flag][j]+=(S[i]==T[j]) ? (j==0? 1:dp[1-flag][j-1]) : 0;
            }
	    for(auto i:dp[flag]) cout << i << " ";
	    cout <<endl;
        }
        return dp[flag][n-1];
    }
};


int main(int argc, char** argv){
    Solution sol;
    string S{"ddd"};
    string T{"dd"};
    cout << sol.numDistinct(S,T) <<endl;

    return 0;
}
