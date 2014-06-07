#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// #define INF -1000

// bool process(vector<vector<int> > &board, int counter){
//     int N = board.size();
//     int M = board[0].size();
//     if(counter==N*M)
// 	return true;
//     /*Process*/
//     for(int i = 0 ; i < N; i++){
// 	int max = board[i][0];
// 	for(int j = 0; j < M; j++){
// 	    if(board[i][j]<max)
// 		max = board[i][j];
// 	}

// 	for(int j = 0; j < M; j++){
// 	    if(board[i][j]==max){
// 		board[i][j] = INF;
// 		possible[i][j]=1;
// 		counter++;
// 	    }
// 	}

//     }

//     for(int j = 0 ; j < M; j++){
// 	int max = -1;
// 	for(int i = 0; i < N; i++){
// 	    if(board[i][j]<max)
// 		max = board[i][j];
// 	}

// 	for(int i = 0; i < N; i++){
// 	    if(board[i][j]==max){
// 		if(possible[i][j]==1)
// 		    possible[i][j] = 3;
// 		else{
// 		    counter++;
// 		    possible[i][j] = 2;
// 		}
// 	    }
// 	}
//     }

//     cout << "Counter: " << counter <<endl;
//     /* Output*/
//     output << "Case #" << t+1 <<": ";
//     if(counter==N*M)
// 	output <<"YES";
//     else
// 	output <<"NO";
//     output <<endl;


// }

int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    int T;
    input >> T;

    int N,M;
    vector<vector<int> > board;
    vector<vector<int> > possible;

    for(int t = 0; t < T; t++){
	/* Input*/
	input >> N;
	input >> M;
	board.resize(N);
	possible.resize(N);
	for(int i=0; i<N; i++){
	    board[i].resize(M);
	    possible[i].resize(M);
	    for(int j = 0 ; j < M; j++){
		input >> board[i][j];
		possible[i][j]=0;
	    }
	}
	//////////////////////////////////////////
	/*Process*/
	int counter = 0;
	for(int i = 0 ; i < N; i++){
	    int max = board[i][0];
	    for(int j = 0; j < M; j++){
		if(board[i][j]>max)
		    max = board[i][j];
	    }

	    for(int j = 0; j < M; j++){
		if(board[i][j]==max){
		    possible[i][j]=1;
		    counter++;
		}
	    }

	}

	for(int j = 0 ; j < M; j++){
	    int max = -1;
	    for(int i = 0; i < N; i++){
		if(board[i][j]>max)
		    max = board[i][j];
	    }

	    for(int i = 0; i < N; i++){
		if(board[i][j]==max){
		    if(possible[i][j]==1)
			possible[i][j] = 3;
		    else{
			counter++;
			possible[i][j] = 2;
		    }
		}
	    }
	}

	cout << "Counter: " << counter <<endl;
	/* Output*/
	output << "Case #" << t+1 <<": ";
	if(counter==N*M)
	    output <<"YES";
	else
	    output <<"NO";
	output <<endl;
    }
    
    return 0;
}
