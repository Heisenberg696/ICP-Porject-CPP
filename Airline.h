#ifndef AIRLINE_H
#define AIRLINE_H
#include <iostream>
using namespace std;

class Airline
{
public:
    Airline();
    Airline(int airlineid, string iatacode);
    Airline(int airlineid, string airlinename, string airlinealias, string iatacode, string icaocode, string callsign, string country, bool isActive);
    int getAirlineid();
    void setAirlineid(int airlineid);
    string getAirlinename();
    void setAirlinename(string airlineName);
    string getAirlinealias();
    void setAirlinealias(string airlineAlias);
    string getIatacode();
    void setIatacode(string iataCode);
    void setIcaocode(string iataCode);
    string getIcaocode();
    void setCallsign(string callsign);
    string getCallsign();
    void setCountry(string country);
    string getCountry();
    bool getIsActive();
    void setIsActive(bool isActive);

private:
    int airlineid;
    string airlinename;
    string airlinealias;
    string iatacode;
    string icaocode;
    string callsign;
    string country;
    bool isActive;
};

#endif