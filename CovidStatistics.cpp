/*
Author: Dhyey Patel
Purpose: Implement the main function that will be the user interface for anyone who wants to manipulate the Covid stats
Date: October 3rd 2020
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include "Country.h"
#include "CountryCollection.h"

using namespace std;

int main(){

    //Get and open file
    string fileName, statInputS, orderInput;
    ifstream myFile;
    // These three while loops are created to ensure that the user input is valid before preceding 
    // This while loop will check if the file name is valid and if the file opens
    while (true){
        cout << "Input the file name or Enter q to quit: ";
        cin >> fileName;
        myFile.open(fileName);
        if(myFile.is_open()){
            break;
        } else if(fileName.compare("q") == 0){
            exit(0);
        }
        cout << "This file does not exist" << endl;
    }

    // This while loop is to get the statistic which needs to be sorted    
    while(true){
        cout << "1.New confirmed cases \n2.New deaths \n3.New recovered cases \n4.Total confirmed cases \n5.Total deaths \n6.Total recovered cases" << endl;
        cout << "Enter q to quit or Pick a number (1-6), based on the statistic you would like to sort by: ";
        cin >> statInputS;
        if (statInputS.compare("q") == 0){
            exit(0);
        }
        if((statInputS.compare("1") == 0) || (statInputS.compare("2") == 0) || (statInputS.compare("3") == 0) || (statInputS.compare("4") == 0) || (statInputS.compare("5") == 0) || (statInputS.compare("6") == 0)){
            break;
        }
        cout << "Not a valid option, please look at the options again and choose a valid option!" << endl;
    }

    // This while loop is to get the order in which the statistic needs to be sorted  
    while(true){
        cout << "1.Ascending \n2.Descending" << endl;
        cout << "Enter q to quit or Pick a number (1 or 2), based on the order you would like to sort by: ";
        cin >> orderInput;
        if (orderInput.compare("q") == 0){
            exit(0);
        }
        if((orderInput.compare("1") == 0) || (orderInput.compare("2") == 0)){
            break;
        }
        cout << "Not a valid option, please look at the options again and choose a valid option!" << endl;
    }

    // Now that we have all the inputs we can move forward

    //Create a CountryCollection Object in which all the contents of the file will be stored
    CountryCollection countries;
    string line, countryName, countrySymbol;
    int newConfirmedCases, newDeaths, newRecoveredCases, totalConfirmedCases, totalDeaths, totalRecoveredCases;
    vector <string> words; 
    getline(myFile, line); //The first line is just for information so we will ignore this line
    
    // Traverse through the file starting at the second line 
    while(getline(myFile,line)){
        line = line.substr(1,(line.size()-1)); // remove the first quotation mark
        size_t indexCountryNameEnd = line.find('"'); // get the index of the "second" (it is not the first as we removed the first one earlier) quotation mark 
        countryName = line.substr(0,indexCountryNameEnd); // get the country's name
        line = line.substr(indexCountryNameEnd+2, line.size()-1); //remove the country name from the data as we have already stored it
        
        // Turn the line into a vector of words split at ','
        stringstream check1(line); 
        string word; 
        while(getline(check1, word, ',')){ 
            words.push_back(word); 
        } 

        //Pull each statistic from the vector of words and convert it into an int if necessary
        countrySymbol = words[0].substr(1,2);
        newConfirmedCases = stoi(words[2]);
        newDeaths = stoi(words[3]);
        newRecoveredCases = stoi(words[4]);
        totalConfirmedCases = stoi(words[7]);
        totalDeaths = stoi(words[8]);
        totalRecoveredCases = stoi(words[9]);
        
        // Create an object of the type Country with each of the statistics and add it to the CountryCollection countries
        Country newCountry(countryName, countrySymbol, newConfirmedCases, newDeaths, newRecoveredCases, totalConfirmedCases, totalDeaths, totalRecoveredCases);
        countries.addCountry(newCountry);  

        words.clear(); // Clear the words as the same vector will be used for the next line read from the file
    }

    
    // Sort the countries based on the statistic and the order inputted by the user
    int statInputI = stoi(statInputS); // convert the statInput into int so you can use switch

    // If the order is ascending 
    if (orderInput.compare("1") == 0){
        // Switch according to the statistic inputted
        switch (statInputI){
            case 1:
                countries.sortCountries(false, "new confirmed cases");
                break;
            case 2:
                countries.sortCountries(false, "new deaths");
                break;
            case 3:
                countries.sortCountries(false, "new recovered cases");
                break;
            case 4:
                countries.sortCountries(false, "total confirmed cases");
                break;
            case 5:
                countries.sortCountries(false, "total deaths");
                break;
            case 6:
                countries.sortCountries(false, "total recovered cases");
                break;
        }
    } 
    // If the order is descending 
    else{
        // Switch according to the statistic inputted
        switch (statInputI){
            case 1:
                countries.sortCountries(true, "new confirmed cases");
                break;
            case 2:
                countries.sortCountries(true, "new deaths");
                break;
            case 3:
                countries.sortCountries(true, "new recovered cases");
                break;
            case 4:
                countries.sortCountries(true, "total confirmed cases");
                break;
            case 5:
                countries.sortCountries(true, "total deaths");
                break;
            case 6:
                countries.sortCountries(true, "total recovered cases");
                break;
        }
    }
    countries.graphCollection(statInputI); // Finally graph the top 10 countries in the sorted data

    return 0;
}