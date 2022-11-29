#ifndef FLIGHTROUTESEARCHER_H
#define FLIGHTROUTESEARCHER_H
#include <iostream>
#include "Airport.h"
using namespace std;

class FlightRouteSearcher
{
public:
    FlightRouteSearcher();
    void setstartCity(string city);
    void setstartCountry(string country);
    void setdestinationCity(string city);
    void setdestinationCountry(string country);
    void setstartAirport(Airport airport);
    void setdestinationAirport(Airport airport);



    string getstartCity();
    string getstartCountry();
    string getdestinationCity();
    string getdestinationCountry();
    Airport getstartAirport();
    Airport getdestinationAirport();



private:
    string StartCity;
    string StartCountry;
    string DestinationCity;
    string DestinationCountry;
    Airport StartAirport;
    Airport DestinationAirport;
};

#endif