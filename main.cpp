/*
  ________            __  ___     __                        __            _      __
 /_  __/ /_  ___     /  |/  /__  / /____  ____  _________  / /___  ____ _(_)____/ /______
  / / / __ \/ _ \   / /|_/ / _ \/ __/ _ \/ __ \/ ___/ __ \/ / __ \/ __ `/ / ___/ __/ ___/
 / / / / / /  __/  / /  / /  __/ /_/  __/ /_/ / /  / /_/ / / /_/ / /_/ / (__  ) /_(__  )
/_/ /_/ /_/\___/  /_/  /_/\___/\__/\___/\____/_/   \____/_/\____/\__, /_/____/\__/____/
                                                                /____/
*/
#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include "header.h"

//#include "Source1.cpp"
//#include "Source2.cpp"
using namespace std;


int main() {

    vector<string> monthNum;
    monthNum.push_back("Jan");
    monthNum.push_back("Feb");
    monthNum.push_back("Mar");
    monthNum.push_back("Apr");
    monthNum.push_back("May");
    monthNum.push_back("Jun");
    monthNum.push_back("Jul");
    monthNum.push_back("Aug");
    monthNum.push_back("Sep");
    monthNum.push_back("Oct");
    monthNum.push_back("Nov");
    monthNum.push_back("Dec");
    //opening all files
    ifstream input1("Humidity.txt");      //1
    ifstream input2("Precipitation.txt"); //2
    ifstream input3("Windspeed.txt");     //3
    ifstream input4("Temperature.txt");   //4

    //Start timer
    clock_t start;
    double structure1Time;
    start = std::clock();

    //1 Humidity
    //2 Precipitation
    //3 Windspeed
    //4 Temperature
    //Humidity.txt
    //Precipitation.txt
    //Temperature.txt
    //Windspeed.txt

    //GENERAL MAIN LAYOUT


    // Give user the option for what files they want to organize //Do we want to give this option

    //Build Structure 1 while timing its construction
    //Stop timer
    //Build Structure 2 while timing its construction
    //Stop timer
    //Print out time comparison between the Structures

    //Print out information about the files so the user knows how to search through it

    //Prompt the user as to whether they will search for data or not, Structure 1 or Structure 2

    //Print data



    //=========================================================================================Structure 1===============================================================================
    //declare a headNode head to pass through to start the structure

    headNode* head = new headNode; //Declare that start of structure 1
    monthDayAssociation();
    cout << "Structure 1 " << endl << "0%                           100%" << '\n';
    if (input1.is_open())     //1 Humidity
    {
        int dataType = 1;
        string trash;
        getline(input1, trash);
        while (!input1.eof())
        {
            string line;
            getline(input1, line);
            addDataStructure1(line, head, dataType); //This is the function that builds Structure 1
        }
        input1.close();
        cout << "|||||||||";
    }


    if (input2.is_open())    //2 Precipitation
    {
        string trash;
        getline(input2, trash);
        int dataType = 2;
        while (!input2.eof())
        {
            string line;
            getline(input2, line);
            addDataStructure1(line, head, dataType);
        }
        input2.close();
        cout << "||||||||";

    }


    if (input3.is_open())   //3 Windspeed
    {
        string trash;
        getline(input3, trash);
        int dataType = 3;
        while (!input3.eof())
        {
            string line;
            getline(input3, line);
            addDataStructure1(line, head, dataType);
        }
        input3.close();
        cout << "||||||||";
    }

    if (input4.is_open())    //4 Temperature
    {
        string trash;
        getline(input4, trash);
        int dataType = 4;
        while (!input4.eof())
        {
            string line;
            getline(input4, line);
            addDataStructure1(line, head, dataType);
        }
        input4.close();
        cout << "||||||||" << endl;

    }

    //Stop timer and return time
    structure1Time = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "Structure 1 implemented in " << structure1Time << " seconds" << '\n';

    //=========================================================================================Structure 2===============================================================================
    //declare a  map<string, map<int, Day>>> &mapStructure to start the structure


    input1.clear();
    input1.open("Humidity.txt");

    input2.clear();
    input2.open("Precipitation.txt");

    input3.clear();
    input3.open("Windspeed.txt");

    input4.clear();
    input4.open("Temperature.txt");

    //Start timer
    double structure2Time;
    start = std::clock();

    map<string, map<string, map<int, Day>>> mapStructure; //Start of structure 2


    cout << "Structure 2 " << endl << "0%                           100%" << '\n';
    if (input1.is_open())  //1 Humidity
    {
        string trash;
        getline(input1, trash);
        int dataType = 1;
        while (!input1.eof())
        {
            string line;
            getline(input1, line);
            addData(line, mapStructure, dataType);
        }
        input1.close();
        cout << "||||||||";
    }


    if (input2.is_open())  //2 Precipitation
    {
        string trash;
        getline(input2, trash);
        int dataType = 2;
        while (!input2.eof())
        {
            string line;
            getline(input2, line);
            addData(line, mapStructure, dataType);
        }
        input2.close();
        cout << "||||||||";
    }


    if (input3.is_open())  //3 Windspeed
    {
        string trash;
        getline(input3, trash);
        int dataType = 3;
        while (!input3.eof())
        {
            string line;
            getline(input3, line);
            addData(line, mapStructure, dataType);
        }
        input3.close();
        cout << "||||||||";
    }


    if (input4.is_open())  //4 Temperature
    {
        string trash;
        getline(input4, trash);
        int dataType = 4;
        while (!input4.eof())
        {
            string line;
            getline(input4, line);
            addData(line, mapStructure, dataType);
        }
        input4.close();
        cout << "|||||||||" << endl;
    }

    structure2Time = (clock() - start) / (double)CLOCKS_PER_SEC; //Stop timer and tehn return time

    //=========================================================================================Compare===============================================================================

    //Compare the two times
    if (structure1Time > structure2Time)
    {
        cout << "Structure two has a faster runtime of " << structure2Time << " seconds, compared to structure one which took " << structure1Time << " seconds." << endl;
    }
    else
    {
        cout << "Structure one has a faster runtime of " << structure1Time << " seconds, compared to structure two which took " << structure2Time << " seconds." << endl;
    }


    cout << "Available stations: " << '\n';
    int stationRowsHelper = 0;
    for (int y = 0; y < head->weatherStations.size(); y++) {
        stationRowsHelper++;
        cout << head->weatherStations[y]->name << "  ";
        if (stationRowsHelper % 4 == 0)
            cout << endl;
    }
    cout << endl;
    /*for (int y = 0; y < head->weatherStations.size() - 1; y += 2) {
        cout << head->weatherStations[y]->name;
        if (!(head->weatherStations.size() < y + 1)) {
            cout << " " << head->weatherStations[y + 1]->name << '\n';
        }
        else {
            cout << endl;
        }
    }*/
    cout << "Available months & days: " << '\n';
    for (auto y = mapStructure.begin()->second.begin(); y != mapStructure.begin()->second.end(); y++) {//loop existing months
        cout << y->first << " " << monthNum[(stoi(y->first)) - 1] << ": ";
        for (auto z = y->second.begin(); z != y->second.end(); z++) {//loop existing days within months
            cout << z->first << "  ";
        }
        cout << '\n';
    }



    //Search for data within datastructures
    int option = 1;
    while (option != 0) {//end if option is 0
        cout << "Type 1 or 2 to search data structure 1 or 2." << endl << "1: Data Structure 1" << endl << "2: Data Structure 2" << endl << "0: Exit" << endl;
        cin >> option;
        if (option == 1) {//search data structure 1
            string stationRequest;
            cout << '\n';
            cout << "When entering stations, months and days make sure to enter valid stations, days and months as describe in the list above" << '\n';
            cout << "Please enter requested station: " << '\n';
            cin >> stationRequest;

            string monthRequest;
            cout << "Please enter requested month(Jan, Feb, ... ): " << '\n';
            cin >> monthRequest;

            int dayRequest;
            cout << "Please enter requested day: " << '\n';
            cin >> dayRequest;
            /*
            int qRequest;
            cout << "Please enter requested quartile(1, 2, 3, or 4): " << '\n';
            cin >> qRequest;
            */
            for (int q = 0; q < head->weatherStations.size(); q++) {
                if (head->weatherStations[q]->name == stationRequest) {

                    for (int w = 0; w < head->weatherStations[q]->months.size(); w++) {
                        if (head->weatherStations[q]->months[w]->name == monthRequest) {

                            for (int l = 0; l < head->weatherStations[q]->months[w]->daysInMonth.size(); l++) {

                                //cout << "alsjdlasjd" << endl;
                                if (head->weatherStations[q]->months[w]->daysInMonth[l]->dayNumber == dayRequest) {
                                    double sum = 0.00;
                                    double validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->humidity.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->humidity[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->humidity[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "Q1" << endl;
                                    cout << "   Humidity: " << sum / validEntryCount << endl;
                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->precipitation.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->precipitation[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->precipitation[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Precipitation: " << sum / validEntryCount << endl;

                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->windspeed.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->windspeed[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->windspeed[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Windspeed: " << sum / validEntryCount << endl;

                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->temperature.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->temperature[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q1->temperature[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Temperature: " << sum / validEntryCount << endl;

                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->humidity.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->humidity[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->humidity[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "Q2" << endl;
                                    cout << "   Humidity: " << sum / validEntryCount << endl;
                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->precipitation.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->precipitation[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->precipitation[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Precipitation: " << sum / validEntryCount << endl;

                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->windspeed.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->windspeed[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->windspeed[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Windspeed: " << sum / validEntryCount << endl;

                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->temperature.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->temperature[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q2->temperature[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Temperature: " << sum / validEntryCount << endl;

                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->humidity.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->humidity[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->humidity[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "Q3" << endl;
                                    cout << "   Humidity: " << sum / validEntryCount << endl;
                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->precipitation.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->precipitation[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->precipitation[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Precipitation: " << sum / validEntryCount << endl;

                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->windspeed.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->windspeed[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->windspeed[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Windspeed: " << sum / validEntryCount << endl;

                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->temperature.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->temperature[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q3->temperature[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Temperature: " << sum / validEntryCount << endl;


                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->humidity.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->humidity[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->humidity[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "Q4" << endl;
                                    cout << "   Humidity: " << sum / validEntryCount << endl;
                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->precipitation.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->precipitation[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->precipitation[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Precipitation: " << sum / validEntryCount << endl;

                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->windspeed.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->windspeed[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->windspeed[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Windspeed: " << sum / validEntryCount << endl;

                                    sum = 0.00;
                                    validEntryCount = 0.01;
                                    for (int k = 0; k < head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->temperature.size(); k++) {
                                        if (head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->temperature[k] != -1.00) {
                                            sum += head->weatherStations[q]->months[w]->daysInMonth[l]->Q4->temperature[k];
                                            validEntryCount++;
                                        }

                                    }
                                    cout << "   Temperature: " << sum / validEntryCount << endl;
                                }

                            }
                        }
                    }
                }
                else {
                    // cout << "No such Station exists" << '\n';
                }
            }

        }
        else if (option == 2) {//search data structure 2
            cout << "Please input a date to retrieve weather data from data structure 1: " << endl;
            cout << "*Format: YYYY-MM-DD" << endl;
            cout << "When entering stations, months and days make sure to enter valid stations, days and months as describe in the list above" << '\n';
            string dateRetrieval;
            cin >> dateRetrieval;
            //dateRetrieval = "2019-01-01";
            string monthRetrieval = dateRetrieval.substr(5, 2);
            string dayRetrieval = dateRetrieval.substr(8, 2);
            cout << "Please input the three letter abbreviation in CAPS for the weather station:" << endl;
            string stationRetrieval;
            cin >> stationRetrieval;
            //stationRetrieval = "VRB";
            double sum = 0;
            int resultsSize = 0;
            double validEntryCount = 0.01;
            Day* retrieved = &(mapStructure.at(stationRetrieval).at(monthRetrieval).at(stoi(dayRetrieval)));
            cout << endl << "Weather info for " << stationRetrieval << " during " << dateRetrieval << ":" << endl << endl;
            cout << "Q1" << endl;

            resultsSize = retrieved->Q1.humidity.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q1.humidity[i] != -1.00) {
                    sum += retrieved->Q1.humidity[i];
                    validEntryCount++;
                }
            }
            cout << "  Humidity: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q1.precipitation.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q1.precipitation[i] != -1.00) {
                    sum += retrieved->Q1.precipitation[i];
                    validEntryCount++;
                }
            }
            cout << "  Precipitation: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q1.windspeed.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q1.windspeed[i] != -1.00) {
                    sum += retrieved->Q1.windspeed[i];
                    validEntryCount++;
                }
            }
            cout << "  Windspeed: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q1.temperature.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q1.temperature[i] != -1.00) {
                    sum += retrieved->Q1.temperature[i];
                    validEntryCount++;
                }
            }
            cout << "  Temperature: " << sum / validEntryCount << endl;


            cout << "Q2" << endl;

            resultsSize = retrieved->Q2.humidity.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q2.humidity[i] != -1.00) {
                    sum += retrieved->Q2.humidity[i];
                    validEntryCount++;
                }
            }
            cout << "  Humidity: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q2.precipitation.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q2.precipitation[i] != -1.00) {
                    sum += retrieved->Q2.precipitation[i];
                    validEntryCount++;
                }
            }
            cout << "  Precipitation: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q2.windspeed.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q2.windspeed[i] != -1.00) {
                    sum += retrieved->Q2.windspeed[i];
                    validEntryCount++;
                }
            }
            cout << "  Windspeed: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q2.temperature.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q2.temperature[i] != -1.00) {
                    sum += retrieved->Q2.temperature[i];
                    validEntryCount++;
                }
            }
            cout << "  Temperature: " << sum / validEntryCount << endl;


            cout << "Q3" << endl;

            resultsSize = retrieved->Q3.humidity.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q3.humidity[i] != -1.00) {
                    sum += retrieved->Q3.humidity[i];
                    validEntryCount++;
                }
            }
            cout << "  Humidity: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q3.precipitation.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q3.precipitation[i] != -1.00) {
                    sum += retrieved->Q3.precipitation[i];
                    validEntryCount++;
                }
            }
            cout << "  Precipitation: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q3.windspeed.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q3.windspeed[i] != -1.00) {
                    sum += retrieved->Q3.windspeed[i];
                    validEntryCount++;
                }
            }
            cout << "  Windspeed: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q3.temperature.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q3.temperature[i] != -1.00) {
                    sum += retrieved->Q3.temperature[i];
                    validEntryCount++;
                }
            }
            cout << "  Temperature: " << sum / validEntryCount << endl;


            cout << "Q4" << endl;

            resultsSize = retrieved->Q4.humidity.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q4.humidity[i] != -1.00) {
                    sum += retrieved->Q4.humidity[i];
                    validEntryCount++;
                }
            }
            cout << "  Humidity: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q4.precipitation.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q4.precipitation[i] != -1.00) {
                    sum += retrieved->Q4.precipitation[i];
                    validEntryCount++;
                }
            }
            cout << "  Precipitation: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q4.windspeed.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q4.windspeed[i] != -1.00) {
                    sum += retrieved->Q4.windspeed[i];
                    validEntryCount++;
                }
            }
            cout << "  Windspeed: " << sum / validEntryCount << endl;

            sum = 0.00;
            validEntryCount = 0.01;
            resultsSize = retrieved->Q4.temperature.size();
            for (int i = 0; i < resultsSize; i++) {
                if (retrieved->Q4.temperature[i] != -1.00) {
                    sum += retrieved->Q4.temperature[i];
                    validEntryCount++;
                }
            }
            cout << "  Temperature: " << sum / validEntryCount << endl;
        }
    }

    return 0;
}

