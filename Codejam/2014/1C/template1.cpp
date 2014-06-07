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
using namespace std;

ifstream input;
ofstream output;
int numTest;

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
	
    }
    output.close();
    input.close();

    cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;
    
    return 0;

}
