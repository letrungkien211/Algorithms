#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<sstream>
#include<ctime>
#include<set>
#include<functional>
#include<algorithm>
#include<limits>
#include<cassert>
#include<unordered_set>

using namespace std;

#define Pair Pair<long,long> 

class Solution {
public:
    int twoSum(vector<long> &A, long target) {
    }
};

int main(int argc, char** argv){
    ifstream input(argv[1]);
    int N = 1000000;
    vector<long> A;
    for(auto &a:A){
	input >> a;
    }
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(),A.end()),A.end());
    Solution sol;
    cout << sol.twoSum(A,10000)<<endl;
    
    return 0;
}
