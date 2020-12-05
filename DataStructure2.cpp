#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

//initialize month day vector pair

vector<pair<string, int>> monthToDay;

void monthDayAssociation(){
    monthToDay.push_back(make_pair("Jan", 31));
    monthToDay.push_back(make_pair("Feb", 28));
    monthToDay.push_back(make_pair("Mar", 31));
    monthToDay.push_back(make_pair("Apr", 30));
    monthToDay.push_back(make_pair("May", 31));
    monthToDay.push_back(make_pair("Jun", 30));
    monthToDay.push_back(make_pair("Jul", 31));
    monthToDay.push_back(make_pair("Aug", 31));
    monthToDay.push_back(make_pair("Sep", 30));
    monthToDay.push_back(make_pair("Oct", 31));
    monthToDay.push_back(make_pair("Nov", 30));
    monthToDay.push_back(make_pair("Dec", 31));
}

class Quartile{
    vector<double> precipitation;
    vector<double> humidity;
    vector<double> windspeed;
    vector<double> temperature;
};

class Day{
    Quartile Q1;
    Quartile Q2;
    Quartile Q3;
    Quartile Q4;
};

//map<string, vector<pair<string, vector<pair<int,day>>>>
//map<station, vector<pair<month, vector<pair<(1-31), day>>>>

void addData(string line, map<string, vector<pair<string, vector<pair<int, Day>>>>> &mapStructure){

    //string line is the data line read in from the file
    //Pass map by reference to save time


}