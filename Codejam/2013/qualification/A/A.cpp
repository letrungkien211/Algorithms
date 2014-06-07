#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    int T;
    vector<vector<char> > board(4);
    char buffer[100];
    char dummy;
    bool used[4][4];
    for(int i =0; i<4; i++)
	board[i].resize(4);
    input >> T;
    for(int t = 0; t < T; t++){
	int result;
	/* Input*/
	for(int i=0; i < 4; i++){
	    for(int j=0; j < 4; j++){
		input >> board[i][j];
	    }

	}

	/*Process*/
	bool completed = true;

	for(int i =0; i<4; i++){
	    for(int j =0; j<4; j++){
//		cout <<board[i][j];
		if(board[i][j]=='.'){
		    completed =false;
		    break;
		 }
	    }
	}
	result = completed ? 2:3;


	for(int i = 0; i <4; i++){
	    int j =0;
	    char pivot = 'a';
	    for(j = 0; j<4; j++){
		if(board[i][j]=='.')
		    break;
		if(pivot=='a' && board[i][j]!='T')
		    pivot =board[i][j];
		if(board[i][j]!=pivot && board[i][j]!='T')
		    break;
	    }
	    if(j==4){
		result = (board[i][0]=='X' || board[i][1]=='X') ? 0 : 1;
		break;
	    }
	}

	
	if(result==2 || result ==3){
	    for(int j = 0; j <4; j++){
		int i = 0;
		char pivot = 'a';
		for(i = 0; i<4; i++){
		    if(board[i][j]=='.')
			break;
		    if(pivot=='a' && board[i][j]!='T')
			pivot =board[i][j];
		    if(board[i][j]!=pivot && board[i][j]!='T')
			break;
		}
		if(i==4){
		    cout << "fffff: " << i <<" " <<j <<endl;
		    result = (board[0][j]=='X' || board[1][j]=='X') ? 0 : 1;
		    break;
		}
	    }
	}

	cout << "resu;t " <<result <<endl;

	if(result==2 || result ==3){
	    int i = 0;
	    char pivot = 'a';

	    for(i = 0; i < 4; i++){
		if(board[i][i]=='.')
		    break;
		if(pivot=='a' && board[i][i]!='T')
			pivot =board[i][i];
		if(board[i][i]!=pivot && board[i][i]!='T')
		    break;
	    }
	    if(i==4){
		result = (board[0][0]=='X' || board[1][1]=='X') ? 0 : 1;
	    }
	    i=0;
	    pivot= 'a';
	    for(i = 0; i < 4; i++){
		if(board[i][3-i]=='.')
		    break;
		if(pivot=='a' && board[i][3-i]!='T')
			pivot =board[i][3-i];
		if(board[i][3-i]!=pivot && board[i][3-i]!='T')
		    break;
	    }
	    if(i==4){
		result = (board[0][3]=='X' || board[1][2]=='X') ? 0 : 1;
	    }
	}
//////////////////////////////////////////////////

	/* Output*/
	output << "Case #" << t+1 <<": ";
	switch(result){
	case 0:
	    output << "X won";
	    break;
	case 1:
	    output << "O won";
	    break;
	case 2:
	    output << "Draw";
	    break;
	case 3:
	    output << "Game has not completed";
	    break;
	default:
	    break;
	}
	output <<endl;
    }
    
    return 0;
}
