#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <utility>
using namespace std;

//initialize month day vector pair

class Quartile {
public:
    vector<double> precipitation;
    vector<double> humidity;
    vector<double> windspeed;
    vector<double> temperature;
};

class Day {
public: //      Added public here because a class defaults variables to private
    Quartile Q1;
    Quartile Q2;
    Quartile Q3;
    Quartile Q4;
};



void addToDay(string time, int dataType, string data, Day& dayObj, string station) { //Needs to return a Day because of the return type || Might just want to change it to void
//cout << stoi(time.substr(0, 2)) << endl;
    if (stoi(time.substr(0, 2)) >= 0 && stoi(time.substr(0, 2)) < 6) {
        if (dataType == 1) {
            dayObj.Q1.humidity.push_back(stod(data)); //Will want to string to double the data because the vectors are doubles not strings
        }
        else if (dataType == 2) {
            dayObj.Q1.precipitation.push_back(stod(data));  //stod'ed all of the data, make sure that the substring data is strictly numbers and contains no suprise characters 
        }
        else if (dataType == 3) {
            dayObj.Q1.windspeed.push_back(stod(data));
        }
        else if (dataType == 4) {
            dayObj.Q1.temperature.push_back(stod(data));
        }
    }
    else if (stoi(time.substr(0, 2)) >= 6 && stoi(time.substr(0, 2)) < 12) {
        if (dataType == 1) {
            dayObj.Q2.humidity.push_back(stod(data));
        }
        else if (dataType == 2) {
            dayObj.Q2.precipitation.push_back(stod(data));
        }
        else if (dataType == 3) {
            dayObj.Q2.windspeed.push_back(stod(data));
        }
        else if (dataType == 4) {
            dayObj.Q2.temperature.push_back(stod(data));
        }
    }
    else if (stoi(time.substr(0, 2)) >= 12 && stoi(time.substr(0, 2)) < 18) {
        if (dataType == 1) {
            dayObj.Q3.humidity.push_back(stod(data));
        }
        else if (dataType == 2) {
            dayObj.Q3.precipitation.push_back(stod(data));
        }
        else if (dataType == 3) {
            dayObj.Q3.windspeed.push_back(stod(data));
        }
        else if (dataType == 4) {
            dayObj.Q3.temperature.push_back(stod(data));
        }
    }
    else {
        if (dataType == 1) {
            dayObj.Q4.humidity.push_back(stod(data));
        }
        else if (dataType == 2) {
            dayObj.Q4.precipitation.push_back(stod(data));
        }
        else if (dataType == 3) {
            dayObj.Q4.windspeed.push_back(stod(data));
        }
        else if (dataType == 4) {
            dayObj.Q4.temperature.push_back(stod(data));
        }
    }
}


//map<string,vector<pair<string,vector,pair<int,vector<pair<int,vector<vector<double>>>>>>;
//                          |
//                          V
//map<string, vector<pair<string, vector<pair<int,day>>>>
//map<station, vector<pair<month, vector<pair<(1-31), day>>>>

//example data: HRT,2019-01-01 00:01,68.00
//              Station,year-month-day time, data
//0-6 Q1 6-12 Q2 12-18 Q3 18-24 Q4
// if(time < 6)
//1 Humidity/y
//2 Precipitation
//3 Windspeed
//4 Temperature

void addData(string line, map<string, map<string, map<int, Day>>>& mapStructure, int dataType) {

    //string line is the data line read in from the file
    //example data: HRT,2019-01-01 00:01,68.00
    /*
    stringstream s_stream(line);

    string station;

    //getline(s_stream, station, ',');

    string date;
    
    //getline(s_stream, date, ' ');
    string month = date.substr(5, 6);
    cout << month;
    string day = date.substr(8, 9);
    cout << " " << day << endl;
    string time;
    //string hour = time.substr(0,2); might not be needed?
    getline(s_stream, time, ',');

    string data;
    getline(s_stream, data); //                 Updated this code, should be good now, if not the previous code is commented out bellow

    */
    if (line == "") return;
    string station;
    string Datetime;
    string data;
    station = line.substr(0, 3);
    Datetime = line.substr(4, 16);
    //cout << Datetime << endl;
    string delimiter = ",";
    string month = Datetime.substr(5, 2); //Substrings what Month number
    string day = Datetime.substr(8, 2); //Substrings Day number
    string time = Datetime.substr(11, 2);
    //string Shours = time.substr(11, 12);  //Substrings Hour number


    data = line.substr(21, line.size()-21);
    //cout << station << " ----- ";
    //cout << month;
    //cout << " ----- " << day << "-----" << time << endl;

    if (data == "M" || data == "T")
        data = "-1";

    /*
    string date;
    string month = date.substr(5,7);
    getline(line, date, ' ');
    string time;
    //string hour = time.substr(0,2); might not be needed?
    getline(line, time, ',');
    string data;
    getline(line, data);
    */

    map<string, map<int, Day>> currStation;

    //quartile find





    //if there is data already existed in the map for this specific station, get data and push_back vector
    //list and mapStructure are the same Data type so the .at() returns something that list is not equal to
    //currStation = mapStructure.at(station);  //What is list supposed to hold?


    if (mapStructure.find(station) != mapStructure.end()) {                 //if station already exists in map    
        currStation = mapStructure.at(station); 
        //map<string, map<int, Day>>::iterator listMonth = currStation.find(month);
        if (currStation.find(month) != currStation.end()) {                //if month already exists in map within station
            //map<int, Day>::iterator listDay = ; //okay, listmonth iterator
            if (currStation.at(month).find(stoi(day)) != currStation.at(month).end()) { // if day already exists in map
                //cout << "1" << endl;
                addToDay(time, dataType, data, mapStructure.at(station).at(month).at(stoi(day)), station);
                /*
                cout << "Number of humidity data stored at current day station " << station << " - " << month << "-" << day << ":" << endl;
                cout << "Q1: " << endl << mapStructure.at(station).at(month).at(stoi(day)).Q1.humidity.size() << endl;
                cout << "Q2: " << endl << mapStructure.at(station).at(month).at(stoi(day)).Q2.humidity.size() << endl;
                cout << "Q3: " << endl << mapStructure.at(station).at(month).at(stoi(day)).Q3.humidity.size() << endl;
                cout << "Q4: " << endl << mapStructure.at(station).at(month).at(stoi(day)).Q4.humidity.size() << endl;*/
            }
            else {
                //cout << "2" << endl;
                Day dayObj;
                mapStructure.at(station).at(month).emplace(stoi(day), dayObj);
                addToDay(time, dataType, data, mapStructure.at(station).at(month).at(stoi(day)), station);
            }
        }
        else {
            //cout << "3" << endl;
            map<int, Day> newDay;
            Day dayObj;
            newDay.emplace(stoi(day), dayObj);
            mapStructure.at(station).emplace(month, newDay);
            addToDay(time, dataType, data, mapStructure.at(station).at(month).at(stoi(day)), station);
            //cout << currStation.at(month).at(stoi(day)).Q1.humidity.size() << endl;
            //cout << currStation.at(month).at(stoi(day)).Q1.humidity.size() << currStation.at(month).at(stoi(day)).Q2.humidity.size() << currStation.at(month).at(stoi(day)).Q3.humidity.size() << currStation.at(month).at(stoi(day)).Q4.humidity.size() << endl;


        }
    }
    else {
        //cout << "4" << endl;
        map<int, Day> newDay;
        map<string, map<int, Day>> newMonth;
        Day dayObj;
        newDay.emplace(stoi(day), dayObj);
        newMonth.emplace(month, newDay);
        mapStructure.emplace(station, newMonth);
        addToDay(time, dataType, data, mapStructure.at(station).at(month).at(stoi(day)), station);
    }

    //Pass map by reference to save time

    //, is the delimiter
    //


}