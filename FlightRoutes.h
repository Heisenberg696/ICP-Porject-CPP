#ifndef FLIGHTROUTES_H
#define FLIGHTROUTES_H
#include <iostream>
#include <fstream>
#include <list>
#include <unordered_map>
#include <stack>
#include "Airline.h"
#include "Airport.h"
#include "Node.h"
#include "Route.h"
#include "FlightRouteSearcher.h"
using namespace std;



class FlightRoutes
{
public:
    FlightRoutes();
    FlightRoutes(string InputFilename);
    void getStartAndEndDetails();
    unordered_map<string, Airport> getSourceAndDestinationAirport();
    void getStartAndEndAirport();
    Airport getAirportById(string airportcode, string airportid );
    Airline getAirlineById(string airlinecode, string airlineid);
    list<Route> getNeighborRoutes(Airport airport);
    Node getFlightRoute(Airport source, Airport destination);
    FlightRouteSearcher getRouteSearcher();
    Node getOptimal(Airport source, Airport destination);



private:
    string inputFilename;
    string OutputFilename;
    ifstream inputStream;
    ofstream outputStream;
    FlightRouteSearcher RouteSearcher;
};

#endif