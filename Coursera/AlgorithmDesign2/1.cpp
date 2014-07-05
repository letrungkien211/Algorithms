#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>

using namespace std;

#define Pair pair<double,double>

int main(int argc, char** argv){

    ifstream fin(argv[1]);
    int n;
    fin >> n;
    vector<Pair> data(n);    
    for(auto &x : data){
	fin >> x.first >> x.second;
    }
    //sort(data.begin(), data.end(),[](const Pair &a, const  Pair &b) -> bool {return a.first/a.second > b.first/b.second;});
    sort(data.begin(), data.end(),[](const Pair &a, const  Pair &b) -> bool 
	 {return a.first-a.second == b.first-b.second ? a.first > b.first : a.first-a.second > b.first-b.second;});
    long time = 0;
    long total=0;
    for(auto x: data){
	time+=x.second;
	total+=x.first*time;
    }
    cout << total <<endl;
    return 0;
}
