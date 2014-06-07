#include<iostream>
#include<vector>
#include<fstream>
#include<list>

using namespace std;

long partition(vector<int>& x, int left, int right){
    int index;
    int mid = (left+right)/2;
    if(x[left]<x[right]){
	if(x[left]<x[mid]){
	    if(x[mid]<x[right])
		index=mid;
	    else 
		index=right;
	}
	else
	    index=left;
    }
    else{
	if(x[left]<x[mid]){
	    index=left;
	}
	else{
	    if(x[mid]<x[right])
		index=right;
	    else
		index=mid;

	}
    }
    swap(x[left],x[index]);
    int pivot=x[left];

    int i=left+1, j=left+1;
    while(j<=right){
	if(x[j]<pivot){
	    swap(x[i++],x[j++]);	    
	}
	else{
	    j++;
	}
    }
    swap(x[left],x[i-1]);

    return i-1;
}

long quicksort(vector<int>& x, int left, int right){
    if(left>=right)
	return 0;
    int c = partition(x, left, right);    
    return quicksort(x, left, c-1) + quicksort(x, c+1, right)+ right-left;
}


int main(int argc, char** argv){
    ifstream input(argv[1]);
    int n;
    vector<int> x(n);
    input >> n;
    for(int i=0; i<n; i++){
	input >> x[i];
	cout << x[i] <<endl;
    }
    long ret = quicksort(x,0,n-1);


    for(int i=0; i<n; i++){
	cout << x[i] <<endl;
    }

    x.clear();
    cout << ret <<endl;
    input.close();
    return 0;
}
