#include<iostream>
#include<algorithm>
#include<functional>
#include<set>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(int argc, char** argv){
	function<bool(int,int)> greater = [](int x,int y){return x<y;};
	set<int,function<bool(int,int)>> s(greater);
	for(int i=0; i<10; i++) s.insert(rand()%100);
	for_each(s.begin(),s.end(),[](int i){cout << i <<endl;});

	return 0;
}