#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    int A;
    int B;
    int index;
    int points;
};

bool compare1(const Data &d1, const Data &d2){
    return d1.A<d2.A;
}

bool compare2(const Data &d1, const Data &d2){
    return d1.B<d2.B;
}


int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    int N, T;
    vector<Data> data;
    input >> T;
    for(int i = 0; i < T; i++){
	cout << "@ @ " <<i <<endl <<endl;
	input >> N;
	data.resize(N);
	vector<int> index1(N), index2(N);
	for(int j = 0; j< N; j++){
	    input >> data[j].A;
	    input >> data[j].B;
	    data[j].points = 0;
	    data[j].index = j;
	    index1[j] = index2[j] = j;
	}

	for(int k = 0 ; k < N-1; k++){
	    for(int j = k+1 ; j< N; j++){
		if(data[index1[j]].A<data[index1[k]].A || 
		   (data[index1[j]].A==data[index1[k]].A && data[index1[j]].B>data[index1[k]].B)){
		    swap(index1[j], index1[k]);
		}
		if(data[index2[j]].B<data[index2[k]].B ){
		    swap(index2[j], index2[k]);
		}
	    }
	}

	for(int j = 0 ; j< N; j++){
	    cout << index1[j] << " ";
	}
	cout <<endl;

	for(int j = 0 ; j< N; j++){
	    cout << index2[j] << " ";
	}
	cout <<endl;

	for(int j = 0 ; j< N; j++){
	    cout << data[index1[j]].A << " ";
	}
	cout <<endl;
	for(int j = 0 ; j< N; j++){
	    cout << data[index2[j]].B << " ";
	}
	cout <<endl;
	
	
	int currentPoints = 0;
	int cnt1, cnt2;
	int counter = 0;
	int completed = 0;
	cnt1 = cnt2 = 0;
	while(completed<N){
	    cout << currentPoints << " "<< data[index2[cnt2]].B <<endl;
	    if(currentPoints>= data[index2[cnt2]].B){
		currentPoints+=2-data[index2[cnt2]].points;
		data[index2[cnt2]].points=2;
		counter++;
		completed++;
		cout << "2: " << index2[cnt2]<<endl;
		cnt2++;
	    }
	    else{
		while(data[index1[cnt1]].points==2)
		    cnt1++;
		if(cnt1 >= N)
		    break;

		
		if(currentPoints >= data[index1[cnt1]].A){
		    int tmp = cnt1+1;
		    while(currentPoints>= data[index1[tmp]].A && tmp<N){
			if(data[index1[tmp]].B>data[index1[cnt1]].B)
			    swap(index1[cnt1], index1[tmp]);
			tmp++;
		    }
		    currentPoints++;
		    data[index1[cnt1]].points = 1;
		    counter++;
		    cout << "1: " << index1[cnt1]<<endl;
		    cnt1++;
		}
		else{
		    break;
		}
	    }
	    
	}
	cout <<completed <<endl;
	cout << cnt1 << " " <<cnt2 <<endl;
	if(completed==N)
	    output << "Case #" << i+1 <<": " << counter <<endl;
	else
	    output << "Case #" << i+1 <<": Too Bad"<<endl;
    }
    
    return 0;
}
