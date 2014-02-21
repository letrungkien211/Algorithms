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
using namespace std;
//using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.size();
        int level=0;
        string ret;
        ret.resize(s.size());
        if(nRows==1) return s;
        int cnt=0;
        while(level<nRows){
			int num = 2*(nRows-1);
            for(int i=0; i<len; i+=num){				
                for(int j=i+level;j<=i+num; j+=num-2*level){					
                    ret[cnt++]=s[j];
					if(num==2*level)
						break;
                }
                if(!num)
                    break;				
            }			
            level++;
        }
        return ret;
    }
};
int main(int argc, char** argv){
    Solution sol;
	string s = "AB";
	cout << sol.convert(s,1) <<endl;
    return 0;
}
