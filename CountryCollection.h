/*
Author: Dhyey Patel
Purpose: Create a header file in which all the private member variables will be declared along with the public methods
This class specificly will be tasked with holding all the information extrated related to a single Country
Date: October 3rd 2020
*/

#ifndef COUNTRYCOLLECTION_H
#define COUNTRYCOLLECTION_H

#include <vector>
#include <string>
#include "Country.h"

class CountryCollection{
    private:
        std::vector<Country> countries;

        //Helper functions

        //Ascending sort for each of the 6 statistics
        static bool sortAscendNewCCases(Country, Country);
        static bool sortAscendNewDeaths(Country, Country);
        static bool sortAscendNewRCases(Country, Country);
        static bool sortAscendTotalCCases(Country, Country);
        static bool sortAscendTotalDeaths(Country, Country);
        static bool sortAscendTotalRCases(Country, Country);

        //Print the graph 
        static void graphHelper(std::vector<std::string>, std::vector<int>, std::string);
    
    public:
        CountryCollection();
        void addCountry(Country);
        void sortCountries(bool, std::string);
        void graphCollection(int);
        ~CountryCollection();

} ;






#endif
