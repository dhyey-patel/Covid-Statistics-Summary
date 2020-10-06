# Covid-Statistics-Summary

All of the code in this repository is created in c++

I created this project to familierlize myself with c++ code
The objective of this code is to generate summary statistics on live covidData that can be pulled from an API
It will ask the user which statistic they would like to sort and in what order (Ascending or Descending) and from that it will print a graph displaying the top 10 countries based on the sort

To get the covid stats enter the folloing into the command line:
wget https://api.covid19api.com/summary

The summary file pulled is a json file which we want to convert to csv, there is a json2csv file given, so run the command:
./json2csv summary > summary.csv

After this you can compile all of the code in one line:
g++ Country.cpp CountryCollection.cpp CovidStatistics.cpp -o CovidData

And run the program with:
./Covid Data
