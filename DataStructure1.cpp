//#import stuff
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

//Reading in data that looks like		SPG,2019-03-04 05:35,0.30

//Different types of Nodes   data -> {station,date time, data}
//
//			Head		(Pointer to variable number of Station)
//			/    \
//		 Station		(Static number of months)
//         |	\
//	     Month			(Psuedo Static number of days (Dependent on the month))
//         |   \
//		  day			(4 quartiles, static value)
//		  /   \
//	  Quartile ____		(4 data sets, static value)
//		/ |   \		\
//	Data  Data  Data  Data	(Variable number of data points)
//

vector<pair<string, int>> monthToDay; //This establishes how many days are in a month

void monthDayAssociation() {		//I think this only needs to be called once in main, but perhaps that is wrong and it will have to be called upon each data insertion
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

struct quartNode {
	//int quartNumber = 0;//will be 1 2 3 or 4
	vector<double> precipitation;
	vector<double> humidity;
	vector<double> windspeed;
	vector<double> temperature;
};

struct dayNode {
	int dayNumber = 0; //This value will be determined at creation
	quartNode* Q1 = new quartNode;
	//Q1.quartNumber = 1;

	quartNode* Q2 = new quartNode;
	//Q2*.quartNumber = 2;

	quartNode* Q3 = new quartNode;
	//Q3*.quartNumber = 3;

	quartNode* Q4 = new quartNode;
	//Q4*.quartNumber = 4;
};

struct monthNode {
	string name;
	int numberOfDays;
	//dayNode* children = NULL;//Needs to have monthDayAssociation[pair]->second number of children
	vector<dayNode*> daysInMonth;
	void monthNodeInit();

};

void monthNode::monthNodeInit() { //Make sure to call this function to initialize the rest of the strcuture
	for (int num = 0; num < numberOfDays; num++) {
		dayNode* currDay = new dayNode;
		currDay->dayNumber = num + 1;
		daysInMonth.push_back(currDay);
	}

}

struct stationNode {
	//Stores the name of the station and subsquent Months->Days->Quartiles
	string name;
	vector<monthNode*> months;
	void stationNodeInit();
};

void stationNode::stationNodeInit() { //Make sure to call this function to initialize the rest of the strcuture
	for (int num = 0; num < 12; num++) {
		monthNode* currMonth = new monthNode;
		currMonth->name = monthToDay[num].first;
		currMonth->numberOfDays = monthToDay[num].second;
		currMonth->monthNodeInit();
		months.push_back(currMonth);
	}

}


struct headNode {
	//All the head node needs to do is store a vector of station nodes
	vector<stationNode*> weatherStations;
};


//example data: HRT,2019-01-01 00:01,68.00
//              Station,year-month-day time,data
//1 Humidity
//2 Precipitation
//3 Windspeed
//4 Temperature


//line is the string of data that we pull from the text in the form of {station,date time, data}
//with ',' being the delimiter

//Step 1: Breakdown the line into usable sub strings
//Step 2: Build the path to where the data belongs


void addDataStructure1(string line, headNode* head, int dataType) {
	//Takes in string line of data in form as describe above
	//Take in head of the new tree structure
	//Takes in int which denotes what type of data is being passed through, key to which is above
	//example data: HRT,2019-01-01 00:01,68.00
	//cout << "new line: " << line << endl;
	if (line == "") return;
	string stationName;
	string dataTime;
	string Sdata;
	//stringstream s_stream(line);
	//getline(s_stream, stationName, ','); //Used to determine which station node it belongs to || Holds station name
	//getline(s_stream, dataTime, ',');	//Need to break this up into month, day and time to further sort it || Hold year, date, time
	//getline(s_stream, Sdata, ',');	   //Holds data in form of a string
	//Changing to .substr()

	stationName = line.substr(0, 3);
	dataTime = line.substr(4, 16); //dateTime

	string delimiter = ",";

	Sdata = line.substr(21, line.size() - 21);
	//cout << Sdata << " ";

	//Sub string works for everything but the data
	//if (line[line.size() - 1] == 'M') Sdata = -1;
	//else { Sdata = line.substr(22, line.size() - 1); }

	string ScurrentMonth = dataTime.substr(5, 6); //Substrings what Month number
	string ScurrentDay = dataTime.substr(8, 9); //Substrings Day number
	string Shours = dataTime.substr(11, 12);  //Substrings Hour number

	int currentMonth = stoi(ScurrentMonth);  //string to int for Month
	int currentDay = stoi(ScurrentDay);	//string to int for Day
	int hours = stoi(Shours); //string to int for Hour
	double data;
	if (Sdata == "M" || Sdata == "T") data = -1;
	else data = stod(Sdata); //string to double for data

	string shortMonthName = monthToDay[currentMonth - 1].first; //Might be an actual error but probably not


	bool hasStation = false;
	int stationLocation = 0;

	for (stationLocation = 0; stationLocation < head->weatherStations.size(); stationLocation++) {		//Checks to see if the station exsists and saves the stationPosition in the vector

		if (head->weatherStations[stationLocation]->name == stationName) {
			hasStation = true;
			break;
		}
	}
	//if (head->weatherStations.empty()) cout << stationName << " " << endl; //head.weatherStations[stationLocation]->name;

	if (!hasStation) {			//Builds a new station node if it does not already exists
		//cout << "NewStation" << endl;
		stationNode* newStation = new stationNode;
		newStation->name = stationName;
		//cout << newStation->name << "\n";
		head->weatherStations.push_back(newStation);
		//cout << head->weatherStations.size() << endl;
		stationLocation = head->weatherStations.size() - 1; //Determines the position of hte station in the vector
		newStation->stationNodeInit();
	}


	//1 humidity
	//2 precipitation
	//3 windspeed
	//4 temperature



	//Quartile 1 data input
	//cout << data << " ";
	if (hours < 6) {
		if (dataType == 1) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q1->humidity.push_back(data);

		}
		if (dataType == 2) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q1->precipitation.push_back(data);

		}
		if (dataType == 3) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q1->windspeed.push_back(data);

		}
		if (dataType == 4) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q1->temperature.push_back(data);

		}
	}

	//Quartile 2 data input
	if (hours >= 6 && hours < 12) {
		if (dataType == 1) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q2->humidity.push_back(data);
		}
		if (dataType == 2) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q2->precipitation.push_back(data);

		}
		if (dataType == 3) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q2->windspeed.push_back(data);

		}
		if (dataType == 4) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q2->temperature.push_back(data);

		}
	}

	//Quartile 3 data input
	if (hours >= 12 && hours < 18) {
		if (dataType == 1) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q3->humidity.push_back(data);
		}
		if (dataType == 2) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q3->precipitation.push_back(data);

		}
		if (dataType == 3) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q3->windspeed.push_back(data);

		}
		if (dataType == 4) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q3->temperature.push_back(data);

		}
	}

	//Quartile 4 data input
	if (hours >= 18) {
		if (dataType == 1) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q4->humidity.push_back(data);
		}
		if (dataType == 2) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q4->precipitation.push_back(data);

		}
		if (dataType == 3) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q4->windspeed.push_back(data);

		}
		if (dataType == 4) {
			head->weatherStations[stationLocation]->months[currentMonth - 1]->daysInMonth[currentDay - 1]->Q4->temperature.push_back(data);

		}
	}



}