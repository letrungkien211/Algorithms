#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <map>
#include <queue>
#include<unordered_set>
#include<cstdio>
using namespace std;

class Sort{
public:
    void sort(vector<int>& x, int i){
	switch(i){
	case 0:
	    quicksort(x,0,x.size()-1);
	    break;
	case 1:
	    mergesort(x,0,x.size()-1);
	    break;
	case 2:
	    heapsort(x);
	    break;
	default:
	    break;
	}
    }
    
    int partition(vector<int> &x, int left, int right){
	swap(x[left],x[left+rand()%(right-left+1)]);
	int pivot=x[left];

	int i=left+1,j=right;
	while(1){
	    while(x[i]<=pivot && i<=right) i++;
	    while(x[j]>pivot && j>=left)j--;
	    if(i<j) swap(x[i],x[j]);
	    else break;
	}
	swap(x[left],x[j]);
	return j;
    }

    void quicksort(vector<int> &x, int left, int right){
	if(left>=right)
	    return;
	int c = partition(x,left,right);
	quicksort(x,left,c-1);
	quicksort(x,c+1,right);
    }

    void mergesort(vector<int> &x, int left, int right){
	if(left>=right)
	    return;
	int mid=(left+right)/2;
	mergesort(x,left,mid);
	mergesort(x,mid+1,right);
	merge(x,left,mid,right);
    }

    void merge(vector<int> &x, int left, int mid, int right){
	vector<int> buffer(x.begin(),x.end());
	int cnt=left;
	int i=left, j=mid+1;
	while(i<=mid && j<=right){
	    if(buffer[i]<buffer[j]){
		x[cnt++]=buffer[i++];
	    }
	    else{
		x[cnt++]=buffer[j++];

	    }
	}
	while(i<=mid){
	    x[cnt++]=buffer[i++];
	}
	while(j<=right){
	    x[cnt++]=buffer[j++];
	}
    }

    void heapsort(vector<int> &x){
	int n=x.size();
	for(int i=0; i<n;i++){
	    heappush(x,i);
	}
	for(int i=0; i<n;i++){
	    heappop(x,n-1-i);
	    
	}
    }

    void heappush(vector<int> &x, int index){
	int child=index;
	int parent=(child-1)/2;
	while(child && x[child]>x[parent]){	    
	    swap(x[child],x[parent]);
	    child=parent;
	    parent=(child-1)/2;
	}
    }

    void heappop(vector<int> &x, int index){
	swap(x[0],x[index]);
	int parent=0;
	int child;
	while(1){
	    child=2*parent+1;
	    if(child>=index)
		break;
	    if(child<index-1 && x[child]<x[child+1]) child++;
	    if(x[child]>x[parent]){
		swap(x[child],x[parent]);
		parent=child;
	    }
	    else
		break;
	}
    }
};


int main(int argc, char** argv){
    srand(time(NULL));
    Sort sol;
    int N=100;
    vector<int> x(N);
    for(auto &i:x) i=rand()%(N*N);
    sol.sort(x,2);
    for(auto i:x) cout <<i << ",";
    cout <<endl;
    return 0;
}
