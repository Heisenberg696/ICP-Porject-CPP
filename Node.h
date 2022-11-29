#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Airline.h"
#include "Airport.h"
#include "Route.h"
#include <stack>
#include <vector>
using namespace std;

class Node
{

private:

    Node *parent;
    Airport airport;
    Airline airline;
    Route route;
    int stops;
    double distance;

public:
    Node();
    Node(Airport airport);
    Node(Node *parent, Airport airport, Airline airline, int stops);
    bool isNull(Node node);
    Node *getParent();
    void setParent(Node *parent);
    void setRoute(Route route);
    Route getRoute();

    Airport getAirport();
    void setAirport(Airport airport);
    Airline getAirline();
    void setAirline(Airline airline);
    int getStops();
    void setStops(int stops);
    double getDistance();
    void setDistance(double distance);
    deque<string> getSolutionPath();
    void writeToFile(string filename);
    string toString();

    bool operator==(Node node)
    {
        if (this->airport.getIataCode() == node.airport.getIataCode())
        {
            return true;
        }
        return false;
    }
    operator string()
    {
        return "{Node with airline" + airline.getAirlinename() + " iatacode = " + airport.getIataCode() + " airport id = " + to_string(airport.getAirportid()) + "}";
    }



    bool operator!=(const Node &rhs) const ;


};

#endif