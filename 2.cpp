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
    bool isMatch(const char *s, const char *p) {
        if (!*s && !*p) return true;
	int m=0,n=0;
		
	for(char *ptr=s; *ptr; ptr++);
	for(char *ptr=p; *ptr; ptr++){
	    if(*ptr!='*')
		n++;
	}

	if(m<n) return false;
	vector<bool> jump(n,false);
	vector<vector<int>> state(m);
	for(auto &v:state) v = vector<int>(n,false);

	int cnt=0;
	for(char* pp=p; *pp; pp++){
	    if(*pp=='*'){
		jump[cnt]=true;
	    }
	    else{
		cnt++;
	    }
	}
    }
};


int main(int argc, char** argv){
    Solution sol;
    return 0;
}
