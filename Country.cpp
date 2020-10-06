/*
Author: Dhyey Patel
Purpose: To implement the Country class (methods and member variables declared in Country.h)
Date: October 3rd 2020
*/
#include "Country.h"
using namespace std;

/*
Function Name: Country
Description: This is the constructor method for the country class, it will initialize all the variables to 0/"" if they are not given
Parameter Description: The parameters are variables representing all of the data extracted from the csv file (name, symbol, new confirmed cases, new deaths, new recovered cases, total confirmed cases, total deaths, and total recovered cases)
Return Description: This function will return an object of class Country
*/
Country::Country (string name = "", string symbol = "", int newCCases = 0, int newDeaths = 0, int newRCases = 0, int totalCCases = 0, int totalDeaths = 0, int totalRCases = 0 ){
    this->name = name;
    this->symbol = symbol;
    this->newCCases = newCCases;
    this->newDeaths = newDeaths;
    this->newRCases = newRCases;
    this->totalCCases = totalCCases;
    this->totalDeaths = totalDeaths;
    this->totalRCases = totalRCases;
}

//The following methods are all getter functions for the private member variables
/*
Function Name: getName
Description: Getter method for the name of a country variable 
Parameter Description: No parameters as this is a getter function
Return Description: Will return the name
*/
string Country::getName(){
    return name;
}

/*
Function Name: getSymbol
Description: Getter method for the symbol of a country variable 
Parameter Description: No parameters as this is a getter function
Return Description: Will return the symbol
*/
string Country::getSymbol(){
    return symbol;
}

/*
Function Name: getNewConfirmedCases
Description: Getter method for the new confirmed cases of a country  
Parameter Description: No parameters as this is a getter function
Return Description: Will return the new confirmed cases of a country
*/
int Country::getNewConfirmedCases(){
    return newCCases;
}

/*
Function Name: getNewDeaths
Description: Getter method for the new deaths of a country  
Parameter Description: No parameters as this is a getter function
Return Description: Will return the new deaths of a country
*/
int Country::getNewDeaths(){
    return newDeaths;
}

/*
Function Name: getNewRecoveredCases
Description: Getter method for the new recovered cases of a country variable 
Parameter Description: No parameters as this is a getter function
Return Description: Will return the new recovered cases of a country variable 
*/
int Country::getNewRecoveredCases(){
    return newRCases;
}

/*
Function Name: getTotalConfirmedCases
Description: Getter method for the total confirmed cases of a country variable 
Parameter Description: No parameters as this is a getter function
Return Description: Will return the total confirmed cases of a country variable 
*/
int Country::getTotalConfirmedCases(){
    return totalCCases;
}

/*
Function Name: getTotalDeaths
Description: Getter method for the total deaths of a country variable 
Parameter Description: No parameters as this is a getter function
Return Description: Will return the total deaths of a country variable
*/
int Country::getTotalDeaths(){
    return totalDeaths;
}

/*
Function Name: getTotalRecoveredCases
Description: Getter method for the total recovered cases of a country variable 
Parameter Description: No parameters as this is a getter function
Return Description: Will return the total recovered cases of a country variable
*/
int Country::getTotalRecoveredCases(){
    return totalRCases;
}


//The following functions are all setter functions for the private member variables
/*
Function Name: setName
Description: Setter method for the name of a country variable 
Parameter Description: The parameter will be the new name for the country
Return Description: Will not return anything as it is a setter function (void)
*/
void Country::setName(string name){
    this->name = name;
}

/*
Function Name: setSymbol
Description: Setter method for the symbol of a country variable 
Parameter Description: The parameter will be the new symbol for the country
Return Description: Will not return anything as it is a setter function (void)
*/
void Country::setSymbol(string symbol){
    this->symbol = symbol;
}

/*
Function Name: setNewConfirmedCases
Description: Setter method for the new confirmed cases of a country variable 
Parameter Description: The parameter will be the new confirmed cases for the country
Return Description: Will not return anything as it is a setter function (void)
*/
void Country::setNewConfirmedCases(int newCCases){
    this->newCCases = newCCases;
}

/*
Function Name: setNewDeaths
Description: Setter method for the new deaths of a country variable 
Parameter Description: The parameter will be the new deaths for the country
Return Description: Will not return anything as it is a setter function (void)
*/
void Country::setNewDeaths(int newDeaths ){
    this->newDeaths = newDeaths;
}

/*
Function Name: setNewRecoveredCases
Description: Setter method for the new recovered cases of a country variable 
Parameter Description: The parameter will be the new recovered cases for the country
Return Description: Will not return anything as it is a setter function (void)
*/
void Country::setNewRecoveredCases(int newRCases){
    this->newRCases = newRCases;
}

/*
Function Name: setTotalConfirmedCases
Description: Setter method for the total confirmed cases of a country variable 
Parameter Description: The parameter will be the total confirmed cases for the country
Return Description: Will not return anything as it is a setter function (void)
*/
void Country::setTotalConfirmedCases(int totalCCases){
    this->totalCCases = totalCCases;
}

/*
Function Name: setTotalDeaths
Description: Setter method for the total deaths of a country variable 
Parameter Description: The parameter will be the total deaths for the country
Return Description: Will not return anything as it is a setter function (void)
*/
void Country::setTotalDeaths(int totalDeaths){
    this->totalDeaths = totalDeaths;
}

/*
Function Name: setTotalRecoveredCases
Description: Setter method for the total recovered cases of a country variable 
Parameter Description: The parameter will be the total recovered cases for the country
Return Description: Will not return anything as it is a setter function (void)
*/
void Country::setTotalRecoveredCases(int toatalRCases){
    this->totalRCases = totalRCases;
}


/*
Function Name: ~Country
Description: The purpose of this function is to explicitly show that nothing special is happening with the deconstructor 
Parameter Description: N/A
Return Description: N/A
*/
Country::~Country(){ 

}


