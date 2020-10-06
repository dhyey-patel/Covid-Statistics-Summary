/*
Author: Dhyey Patel
Purpose: Create a header file in which all the private member variables will be declared along with the public methods
This class specificly will be tasked with holding all the information extrated related to a single Country
Date: October 3rd 2020
*/

#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

class Country{
    //Declare all the private variables assosiated with each country
    private:
        std::string name;
        std::string symbol;
        int newCCases;
        int newDeaths;
        int newRCases;
        int totalCCases;
        int totalDeaths;
        int totalRCases;

    public:
        //Constructor
        Country (std::string, std::string, int, int, int, int, int, int);
        
        //Getter Methods
        std::string getName();
        std::string getSymbol();        
        int getNewConfirmedCases();
        int getNewDeaths();
        int getNewRecoveredCases();
        int getTotalConfirmedCases();
        int getTotalDeaths();
        int getTotalRecoveredCases();

        //Setter Methods
        void setName(std::string);
        void setSymbol(std::string);        
        void setNewConfirmedCases(int);
        void setNewDeaths(int);
        void setNewRecoveredCases(int);
        void setTotalConfirmedCases(int);
        void setTotalDeaths(int);
        void setTotalRecoveredCases(int);

        //Destructor 
        ~Country();


};

#endif