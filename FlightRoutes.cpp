#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <list>
#include <cstdio>
#include <bits/stdc++.h>
#include <stack>
#include <string>
#include "FlightRoutes.h"
#include "Node.h"
#include "helper.h"
using namespace std;

FlightRoutes::FlightRoutes()
{
}

FlightRouteSearcher FlightRoutes::getRouteSearcher()
{
	return this->RouteSearcher;
}

struct compare
{



public:
	bool operator()(Node &a, Node &b)
	{
		return a.getDistance() < b.getDistance();
	}
};

FlightRoutes::FlightRoutes(string inputFilename)
{
	this->inputFilename = inputFilename;
	this->RouteSearcher;
}
void FlightRoutes::getStartAndEndDetails()
{

	this->inputStream.open(this->inputFilename.c_str(), ios::in);
	string sourceData;
	string destinationData;
	if (inputStream.is_open())
	{
		getline(inputStream, sourceData);
		getline(inputStream, destinationData);
		inputStream.close();
	}
	else
		cout << "Couldn't open the file\n";

	vector<string> result;
	stringstream ss(sourceData + "," + destinationData);
	string item;

	while (getline(ss, item, ','))
	{
		result.push_back(item);
	}
	this->RouteSearcher.setstartCity(result[0]);
	this->RouteSearcher.setstartCountry(result[1]);
	this->RouteSearcher.setdestinationCity(result[2]);
	this->RouteSearcher.setdestinationCountry(result[3]);
}



unordered_map<string, Airport> FlightRoutes::getSourceAndDestinationAirport()
{
	unordered_map<string, Airport> SourceEndAirports;
	ifstream airportsData;
	airportsData.open("airports.csv", ios::in);
	string line, currentAirportId, currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, latitude, longitude;
	if (airportsData.is_open())
	{
		while (getline(airportsData, line))
		{
			stringstream ss(line);
			getline(ss, currentAirportId, ',');
			getline(ss, currentAirportName, ',');
			getline(ss, currentAirportCity, ',');
			getline(ss, currentAirportCountry, ',');
			getline(ss, iataCode, ',');
			getline(ss, icaoCode, ',');
			getline(ss, latitude, ',');
			getline(ss, longitude, ',');

			if (currentAirportCountry == this->RouteSearcher.getstartCountry() && currentAirportCity == this->RouteSearcher.getstartCity())
			{
				SourceEndAirports["source"] = Airport(stoi(currentAirportId), currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, stod(latitude), stod(longitude));
			}

			if (currentAirportCountry == this->RouteSearcher.getdestinationCountry() && currentAirportCity == this->RouteSearcher.getdestinationCity())
			{
				SourceEndAirports["destination"] = Airport(stoi(currentAirportId), currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, stod(latitude), stod(longitude));
			}
		}
		airportsData.close();
	}
	else
		cout << "Couldn't open the file\n";

	return SourceEndAirports;
}



Airport FlightRoutes::getAirportById(string airportCode, string airportId)
{

	ifstream airportsData;
	airportsData.open("airports.csv", ios::in);
	string line, currentAirportId, dummy, currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, latitude, longitude;
	if (airportsData.is_open())
	{
		while (getline(airportsData, line))
		{
			stringstream ss(line);
			getline(ss, currentAirportId, ',');
			getline(ss, currentAirportName, ',');
			getline(ss, currentAirportCity, ',');
			getline(ss, currentAirportCountry, ',');
			getline(ss, iataCode, ',');
			getline(ss, icaoCode, ',');
			getline(ss, latitude, ',');
			getline(ss, longitude, ',');

			if (iataCode == airportCode || currentAirportId == airportId)
			{
				return Airport(stoi(currentAirportId), currentAirportName, currentAirportCity, currentAirportCountry, iataCode, icaoCode, stod(latitude), stod(longitude));
			}
		}
	}

	return Airport();
}




Airline FlightRoutes::getAirlineById(string airlineCode, string airlineId)
{
	ifstream airlineData;
	airlineData.open("airlines.csv", ios::in);
	string line, currentAirlineId, currentIataCode, dummy, code, iacacode;
	if (airlineData.is_open())
	{
		while (getline(airlineData, line))
		{
			stringstream ss(line);
			getline(ss, currentAirlineId, ',');
			getline(ss, dummy, ',');
			getline(ss, dummy, ',');
			getline(ss, currentIataCode, ',');
			getline(ss, iacacode, ',');

			code = currentIataCode != "" ? currentIataCode : iacacode;

			if (code == airlineCode || currentAirlineId == airlineId)
			{
				return Airline(stoi(currentAirlineId), code);
			}
		}
	}

	return Airline();
}



list<Route> FlightRoutes::getNeighborRoutes(Airport airport)
{
	list<Route> neighborRoutes;
	ifstream routesData;
	routesData.open("routes.csv", ios::in);
	string line, currentAirlineCode, currentAirlineId, Equipment, currentSourceId, currentSourceCode, currentDestinationCode, currentDestinationId, codeshare, currentStops;
	if (routesData.is_open())
	{
		while (getline(routesData, line))
		{
			stringstream ss(line);
			getline(ss, currentAirlineCode, ',');
			getline(ss, currentAirlineId, ',');
			getline(ss, currentSourceCode, ',');
			getline(ss, currentSourceId, ',');
			getline(ss, currentDestinationCode, ',');
			getline(ss, currentDestinationId, ',');
			getline(ss, codeshare, ',');
			getline(ss, currentStops, ',');
			getline(ss, Equipment, ',');

			if (airport.getIataCode() == currentSourceCode || airport.getIataCode() == currentSourceId)
			{
				neighborRoutes.push_back(Route(currentAirlineId, currentAirlineCode, currentSourceCode, currentDestinationCode, currentDestinationId, stoi(currentStops)));
			}
		}
	}
	return neighborRoutes;
}


Node FlightRoutes::getFlightRoute(Airport source, Airport destination)
{
	cout << destination.getCountry() << endl;
	deque<Node> routesFrontier;
	Node node(source);
	routesFrontier.push_back(node);
	unordered_set<string> explored;
	while (!routesFrontier.empty())
	{
		node = routesFrontier.front();
		cout << "popped node: " << node.getAirport().getAirportid() << endl;
		routesFrontier.pop_front();
		explored.insert(node.getAirport().getIataCode());
	
		for (auto &route : getNeighborRoutes(node.getAirport()))
		{
			Airport flightDestination = getAirportById(route.getdestinationAirportCode(), route.getdestinationAirportId());
			Airline flight = getAirlineById(route.getairlineCode(), route.getairlineId());
			try
			{

				Node child = *new Node(&node, flightDestination, flight, node.getStops());
				if (route.getdestinationAirportCode() == destination.getIataCode())
				{
					cout << "found solution" << endl;
					cout << child.getAirport().getName() << endl;
					string filen = this->getRouteSearcher().getstartCity() + "-" + this->getRouteSearcher().getdestinationCity();
					transform(filen.begin(), filen.end(), filen.begin(), ::tolower);
					child.writeToFile(filen);
					return child;
				}
				else if ((explored.find(child.getAirport().getIataCode()) == explored.end()) && !isContains(routesFrontier, child))
				{
					routesFrontier.push_back(child);
				}
			}
			catch (exception &e)
			{
				cout << e.what() << '\n';
			}
		}
		cout << "cycle ends " << endl;
	}
	cout << "There was no solution" << endl;
	return Node();
}
