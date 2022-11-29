#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
using namespace std;

class Airport
{
public:
    Airport();
    Airport(int Airportid, string Name, string City, string Country, string Iatacode , string Icaocode);
    Airport(int Airportid, string Name, string City, string Country, string Iatacode , string Icaocode, double Latitude, double Longitude);
    // setters
    void setAirport(int Airportid);
    void setName(string Name);
    void setCity(string City);
    void setCountry(string Country);
    void setIataCode(string Iatacode );
    void seticaoCode(string Iatacode );
 

    int getAirportid();
    string getName();
    string getCity();
    string getCountry();
    string getIataCode();
    string geticaoCode();


private:
    int Airportid;
    string Name;
    string City;
    string Country;
    string Iatacode ;
    string Icaocode;
    double latitude;
    double longitude;
};

#endif