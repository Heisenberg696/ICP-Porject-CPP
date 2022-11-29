#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
using namespace std;

class Route
{
public:
    Route();
    Route(string Airlineid, string Airlinecode, string Sourceairpotcode, string Destinationairpotcode, string Destinationairpot, int stops);
    void setairlineId(string Airlineid);
    void setairlineCode(string Airlinecode);
    void setsourceAirportCode(string Sourceairpotcode);
    void setdestinationAirportCode(string Destinationairpotcode);
    void setdestinationAirportId(string Destinationairpot);
    void setcodeshare(bool Codeshare);
    void setstops(int stops);

    string getairlineId();
    string getairlineCode();
    string getsourceAirportCode();
    string getdestinationAirportCode();
    string getdestinationAirportId();
    bool getCodeshare();
    int getStops();

private:
    string Airlinecode;
    string Airlineid;
    string Sourceairpotcode;
    string Destinationairpotcode;
    string Destinationairpotid;
    bool Codeshare;
    int stops;
};

#endif