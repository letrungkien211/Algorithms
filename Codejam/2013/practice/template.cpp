#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv){
    string inputFileName = "";
    string outputFileName = "";
    input(inputFileName);

    process();
    
    outputFileName(outputFileName);
    return 0;
}
