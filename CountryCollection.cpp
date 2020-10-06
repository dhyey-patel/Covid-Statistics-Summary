/*
Author: Dhyey Patel
Purpose: To implement the CountryCollection class (methods and member variables declared in Country.h)
Date: October 3rd 2020
*/

#include <algorithm>
#include <iostream>
#include <tgmath.h>
#include "CountryCollection.h"
using namespace std;


// These are all private static helper functions that are called internally within the CountryCollection Class
/*
Function Name: SortAscendNewCCases
Description: This function's role is to help with the sort function, if they user wants to sort New Confirmed Cases in ascending order then this function will be passed as a parameter in the sort function
Parameter Description: The parameters in this case are the two vraiables of type country that you would like to compare
Return Description: It will return a boolean variable based on country a's statistic relative to country b's statistic
*/
bool CountryCollection::sortAscendNewCCases(Country a, Country b){
    return a.getNewConfirmedCases() < b.getNewConfirmedCases();
}

/*
Function Name: SortAscendNewDeaths
Description: This function's role is to help with the sort function, if they user wants to sort New Deaths in ascending order then this function will be passed as a parameter in the sort function
Parameter Description: The parameters in this case are the two vraiables of type country that you would like to compare
Return Description: It will return a boolean variable based on country a's statistic relative to country b's statistic
*/
bool CountryCollection::sortAscendNewDeaths(Country a, Country b){
    return a.getNewDeaths() < b.getNewDeaths();
}

/*
Function Name: SortAscendNewRCases
Description: This function's role is to help with the sort function, if they user wants to sort New Recovered Cases in ascending order then this function will be passed as a parameter in the sort function
Parameter Description: The parameters in this case are the two vraiables of type country that you would like to compare
Return Description: It will return a boolean variable based on country a's statistic relative to country b's statistic
*/
bool CountryCollection::sortAscendNewRCases(Country a, Country b){
    return a.getNewRecoveredCases() < b.getNewRecoveredCases();
}

/*
Function Name: SortAscendTotalCCases
Description: This function's role is to help with the sort function, if they user wants to sort Total Confirmed Cases in ascending order then this function will be passed as a parameter in the sort function
Parameter Description: The parameters in this case are the two vraiables of type country that you would like to compare
Return Description: It will return a boolean variable based on country a's statistic relative to country b's statistic
*/
bool CountryCollection::sortAscendTotalCCases(Country a, Country b){
    return a.getTotalConfirmedCases() < b.getTotalConfirmedCases();
}

/*
Function Name: SortAscendTotalDeaths
Description: This function's role is to help with the sort function, if they user wants to sort Total Deaths in ascending order then this function will be passed as a parameter in the sort function
Parameter Description: The parameters in this case are the two vraiables of type country that you would like to compare
Return Description: It will return a boolean variable based on country a's statistic relative to country b's statistic
*/
bool CountryCollection::sortAscendTotalDeaths(Country a,Country b){
    return a.getTotalDeaths() < b.getTotalDeaths();
}

/*
Function Name: SortAscendTotalRCases
Description: This function's role is to help with the sort function, if they user wants to sort Total Recovered Cases in ascending order then this function will be passed as a parameter in the sort function
Parameter Description: The parameters in this case are the two vraiables of type country that you would like to compare
Return Description: It will return a boolean variable based on country a's statistic relative to country b's statistic
*/
bool CountryCollection::sortAscendTotalRCases(Country a, Country b){
    return a.getTotalRecoveredCases() < b.getTotalRecoveredCases();
}

/*
Function Name: graphHelper
Description: This function is a helper function that will print the graph
Parameter Description: The first parameter is a vector with 10 country symbols (they are needed to be printed)
The second parameter is a vector with the 10 values of the statistic that needs to be printed
The third parameter is the name of the statitic which is assosiated with the values
Return Description: This function will not return anything, but will print the graph
*/
void CountryCollection::graphHelper(std::vector<string> countryNames, std::vector<int> countryStats, string sorted){
    // This code is used to determine how many cases each Hash will equal
    const double maxHash = 70; // The max number of hashes that we want to print is 20
    double maxNum = *max_element(countryStats.begin(),countryStats.end()); 
    // Each hash is the max value of the statistic divided by the max number of hashes to be printed
    int eachHash = int(ceil((maxNum/maxHash)));  

    // For each statistic we will need to determine the number of hashes to print
    int numHashes;
    string hashes = "";


    for (int i = 0; i < countryStats.size(); i++){
        cout << countryNames[i] << " | ";
        // Calculate the number of hashes to print for this statistic
        if (eachHash != 0){
            numHashes = countryStats[i]/eachHash;
        } else{
            numHashes = 0;
        }

        // Create a string will all the hashes that need to be printed
        for (int j = 0; j < numHashes; j++){
            hashes = hashes + "#";
        }

        cout << hashes << "\n   |" << endl;
        hashes = "";
    }
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    if (eachHash == 0){
        eachHash = 1;
    }
    cout << sorted << "; " << "Each # is approx. " << eachHash << " cases" << endl;
}


/*
Function Name: CountryCollection
Description: This is the constructor method for the CountryCollection class, and is tasked with doing nothing, as there are no variables to initialize
Parameter Description: N/A
Return Description: This function will return an object of class CountryCollection
*/
CountryCollection::CountryCollection(){
    
}

/*
Function Name: addCountry
Description: This method will add a country to the collection of countries 
Parameter Description: The parameter will be the country that is to be added to the collection (vector of type Country)
Return Description: Void method that will return nothing
*/
void CountryCollection::addCountry(Country country){
    countries.push_back(country);
}

/*
Function Name: sortCountries
Description: This method will stort the vector of countries based on the statistic and order the user would like it sorted
Parameter Description: The first parameter is to a bool that represents the order to be sorted, and the second parameter is the stat that the countries should be sorted according to
Return Description: This function will return an object of class Country
*/
void CountryCollection::sortCountries(bool descending, string stat){
    
    // Based on which statistic it needs to be sorted pass the correct helper function to sort the country
    // All of these will sort that statistic into ascending order
    if (stat.compare("new confirmed cases") == 0){
        sort(countries.begin(), countries.end(), sortAscendNewCCases);
    } else if (stat.compare("new deaths") == 0){
        sort(countries.begin(), countries.end(), sortAscendNewDeaths);
    } else if (stat.compare("new recovered cases") == 0){
        sort(countries.begin(), countries.end(), sortAscendNewRCases);
    } else if (stat.compare("total confirmed cases") == 0){
        sort(countries.begin(), countries.end(), sortAscendTotalCCases);
    } else if (stat.compare("total deaths") == 0){
        sort(countries.begin(), countries.end(), sortAscendTotalDeaths);
    } else if (stat.compare("total recovered cases") == 0){
        sort(countries.begin(), countries.end(), sortAscendTotalRCases);
    }

    //If the order is descending then reverse the vector 
    if (descending){
        reverse(countries.begin(), countries.end());
    }

}

/*
Function Name: graphCollection
Description: This method will graph the collection based on what the sorted statistic with the help of the graphHelper method
Parameter Description: The parameter will be an integer representing the sorted statistic (1 = name, 2 = symbol, 3 = new confirmed cases, 4 = new deaths, 5 = new recovered cases, 6 = total confirmed cases, total deaths, and total recovered cases)
Return Description: This function will not return anything as it is a void function
*/
void CountryCollection::graphCollection(int selection){
    // Initialize the two vectors that will be passed to the graphHelper function
    vector<string> countrySymbols;
    vector<int> countryStats;

    // As the collection is already sorted for the selection add the 10 country symbols that need to be printed
    for (int i=0; i < 10; i++){
        countrySymbols.push_back(countries[i].getSymbol());
    }

    // Based on the selection add the top 10 of that stat to the countryStats vector and call the graphHelper function
    switch (selection){
        case 1:
            for (int i = 0; i < 10; i++){
                countryStats.push_back(countries[i].getNewConfirmedCases());
            }
            graphHelper(countrySymbols, countryStats, "New Confirmed Cases");
            break;
        case 2:
            for (int i = 0; i < 10; i++){
                countryStats.push_back(countries[i].getNewDeaths());
            }
            graphHelper(countrySymbols, countryStats, "New Deaths");
            break;
        case 3:
            for (int i = 0; i < 10; i++){
                countryStats.push_back(countries[i].getNewRecoveredCases());
            }
            graphHelper(countrySymbols, countryStats, "New Recovered Cases"); 
            break;
        case 4:
            for (int i = 0; i < 10; i++){
                countryStats.push_back(countries[i].getTotalConfirmedCases());
            }
            graphHelper(countrySymbols, countryStats, "Total Confirmed Cases"); 
            break;
        case 5:
            for (int i = 0; i < 10; i++){
                countryStats.push_back(countries[i].getTotalDeaths());
            }
            graphHelper(countrySymbols, countryStats, "Total Deaths"); 
            break;
        case 6:
            for (int i = 0; i < 10; i++){
                countryStats.push_back(countries[i].getTotalRecoveredCases());
            }
            graphHelper(countrySymbols, countryStats, "Total Recovered Cases");  
            break;
        }

}

/*
Function Name: ~CountryCollection
Description: This is the deconstructor method for the CountryCollection class, it is created to explicitly show that nothing special is being created
Parameter Description: N/A
Return Description: N/A
*/
CountryCollection::~CountryCollection(){

}
