#include <iostream>
#include <cstdio>
#include <ctime>
//#include "header.h"
using namespace std;


int main(){

//Start timer
clock_t start;
double structure1Time;
start = std::clock();


//Build Structure 1

//Stop timer and return time
structure1Time = (clock() - start)/(double)CLOCKS_PER_SEC;
cout << "Time taken to build structure 1 was " << structure1Time << " seconds" << '\n';

//Start timer
double structure2Time;
start = std::clock();

//Build Structure 2
    //Read in line by line
    //Each cpp will have a read and parse line



//Stop timer and return time
structure2Time = (clock() - start)/(double)CLOCKS_PER_SEC;
cout << "Time taken to build structure 2 was " << structure2Time << " seconds" << '\n';
//Compare the two values
return 0;
}