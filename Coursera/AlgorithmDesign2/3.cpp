#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
#include<bitset>
#include<string>
#include<unordered_map>
#include<ctime>

using namespace std;

class Item{
public:
    long value,weight;
};

class Knapsack{
public:
    long N,W;
    vector<Item> items;
    vector<unordered_map<long,long>> memo;
    void ReadFromFile(string filename){
	ifstream fin(filename);
	fin >> W >> N;
	items.resize(N+1);
	for(long i=1; i<=N; i++){
	    fin >> items[i].value >> items[i].weight;
	}
	fin.close();
    }

    void Preprocess(){
	memo.resize(N);
	sort(items.begin(),items.end(),[](Item x, Item y) -> bool {
		return x.weight < y.weight;
	    });
    }

    long Solve(){
	vector<vector<long> > dp(N+1,vector<long>(W+1,0));
	long ret = -1;
	for(long i=1; i<=N; i++){
	    for(long j=1; j<=W; j++){
		dp[i][j] = dp[i-1][j];
		if(j>=items[i].weight){
		    dp[i][j]=max(dp[i][j],dp[i-1][j-items[i].weight]+items[i].value);
		}
		ret = max(ret,dp[i][j]);
	    }
	}
	return ret;
    }

    long Solve1(){
	vector<long> dp(W+1,0);
	vector<long> tmp;
	long ret = -1;
	for(long i=1; i<=N; i++){
	    tmp=dp;
	    for(long j=1; j<=W; j++){
		if(j>=items[i].weight){
		    dp[j]=max(dp[j],tmp[j-items[i].weight]+items[i].value);
		}
		ret = max(ret,dp[j]);
	    }
	}
	return ret;
    }
    
    long Solve2(int n, int w){
	if(n<0 || w<=0)
	    return 0;
	if(memo[n].find(w)==memo[n].end()){
	    long tmp;
	    tmp=Solve2(n-1,w);
	    if(w>=items[n].weight){
		tmp=max(tmp,Solve2(n-1,w-items[n].weight)+items[n].value);
	    }
	    memo[n][w]=tmp;
	}
	return memo[n][w];
    }
};

int main(int argc, char** argv){
    clock_t start = clock();
    Knapsack kp;
    kp.ReadFromFile(argv[1]);
    kp.Preprocess();
    cout << kp.Solve2(kp.N-1,kp.W) <<endl;
    cout << "Elapsed time: " << ((double)clock()-(double)start)/(double)CLOCKS_PER_SEC <<endl;
    cout << kp.Solve1() <<endl;    
    cout << "Elapsed time: " << ((double)clock()-(double)start)/(double)CLOCKS_PER_SEC <<endl;
    return 0;
}
