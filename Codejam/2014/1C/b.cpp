#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

ifstream input;
ofstream output;
int numTest;

#define LL long long 
int solve(vector<string> & cars){
    int N = cars.size();
    
    vector<string> data(N);
    unordered_set<char> blacklist;
    for(int i=0; i<N; i++){
	int j=0;
	if(blacklist.find(cars[i].front())!=blacklist.end() || 
	   blacklist.find(cars[i].front())!=blacklist.end())
	    return 0;

	while(j<cars[i].size() && cars[i][j]== cars[i].front()) j++;
	if(j==cars[i].size()){
	    data[i] = string(1,cars[i].front());	    
	}
	else{
	    int k=cars[i].size()-1;
	    while(cars[i][k] == cars[i].back()) k--;
	    for(int l = j; l<=k; l++){
		if(cars[i][l]== cars[i].back() || cars[i][l]==cars[i].front()){
		    return 0;
		}
		blacklist.insert(cars[i][l]);
	    }
	    data[i]="";
	    data[i]+=cars[i].front();
	    data[i]+=cars[i].back();
	}
    }

    map<char, vector<int> > freq;    
    for(int i=0; i<N; i++){
	char front = data[i].front();
	char back = data[i].back();
	if(front==back){
	    if(freq.find(front)==freq.end()){
		freq[front] = vector<int>{0,0,1};
	    }
	    else{
		freq[front][2]++;
	    }
	}
	else{
	    if(freq.find(front)==freq.end()){
		freq[front] = vector<int>{1,0,0};
	    }
	    else{
		freq[front][0]++;
	    }
	    if(freq.find(back)==freq.end()){
		freq[back] = vector<int>{0,1,0};
	    }
	    else{
		freq[back][1]++;
	    }
	}
    }

    vector<LL> fact(11);
    fact[0]=1;
    for(int i=1; i<=10; i++){
	fact[i]=i*fact[i-1];
    }
    int num01=0, num10=0, num11=0, total =0, multi=1;
    
    for(auto kv : freq){
	cout << kv.first << " " << kv.second[0] << " " << kv.second[1] << " " << kv.second[2] <<endl;
	if(kv.second[0] >1 || kv.second[1] >1)
	    return 0;
	else if(kv.second[0]==0 && kv.second[1]==1)
	    num01++;
	else if(kv.second[0]==1 && kv.second[1]==0)
	    num10++;
	else 
	    num11++;	
	multi*=fact[kv.second[2]];
	cout << total <<endl;
    }
    if(num01!=num10)
	return 0;
    return num01*multi;
}

int main(int argc, char**argv)
{
    clock_t start = clock();
    assert(argc==3);
    input.open(argv[1]);
    output.open(argv[2]);    

    input >> numTest;
    
    for(int cnt =1; cnt <=numTest; cnt++){
	cout << "Case #" << cnt <<": ";
	output << "Case #" << cnt <<": ";
	
	int N;
	input >> N;
	vector<string> cars(N);
	for(int i=0; i<N; i++)
	    input >> cars[i];
	int ret = solve(cars);
	output << ret <<endl;
	cout <<ret <<endl;
    }
    output.close();
    input.close();

    cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;
    
    return 0;

}
