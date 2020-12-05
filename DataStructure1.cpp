//#import stuff
#include <iostream>
#include <vector>

using namespace std;

//Reading in data that looks like		SPG,2019-03-04 05:35,0.30

//Different types of Nodes 
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

struct quartNode {
	int quartNumber = 0;//will be 1 2 3 or 4
	vector<double> precipitation;
	vector<double> humidity;
	vector<double> windspeed;
	vector<double> temperature;
};

struct dayNode {
	int dayNumber = 0; //This value will be determined at creation
	quartNode* children = NULL; //4 of these per day
};

struct monthNode {
	string name;
	dayNode* children = NULL;//Needs to have monthDayAssociation[pair]->second number of children
};


struct stationNode {
	string name;
	monthNode* children = NULL; //Needs to be 12 of these

};

struct headNode{

	stationNode* child = NULL; //This pointer will need to be dynamically created, because there will be a non-constant number of children.
	//All head node needs it to be able to dynamically point to more children nodes
};


