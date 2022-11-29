#include "Node.h"
#include <stack>
#include <vector>
#include <fstream>
using namespace std;

Node::Node()
{
  this->airport = Airport{};
  this->parent = NULL;
  this->airline = Airline{};
  this->stops = 0;
}



Node::Node(Airport airport)
{
  this->airport = airport;
  this->parent = NULL;
  this->airline;
  this->stops = 0;
}



Node::Node(Node *par, Airport nodeAirport, Airline nodeAirline, int stops)
{
  parent = par;
  airport = nodeAirport;
  airline = nodeAirline;
  stops = stops;
}


void Node::setRoute(Route nroute)
{
  route = nroute;
}

Route Node::getRoute()
{
  return route;
}


Node *Node::getParent()
{
  return parent;
}

void Node::setParent(Node *par)
{
  this->parent = par;
}

Airport Node::getAirport()
{
  return airport;
}

void Node::setAirport(Airport airport)
{
  this->airport = airport;
}

Airline Node::getAirline()
{
  return this->airline;
}

void Node::setAirline(Airline airline)
{
  this->airline = airline;
}

int Node::getStops()
{
  return this->stops;
}

void Node::setStops(int stp)
{
  stops = stp;
}

double Node::getDistance()
{
  return this->distance;
}

void Node::setDistance(double dist)
{
  distance = dist;
}

deque<string> Node::getSolutionPath()
{

  deque<string> soln;
  string route;
  Node newNode = *this;
  while (newNode.parent != NULL)
  {
    route = newNode.getAirline().getIatacode() + " from " + newNode.getParent()->getAirport().getIataCode() + " to " + newNode.getAirport().getIataCode() + " " + to_string(newNode.getStops()) + " stops";
    soln.push_front(route);
    cout << route << endl;
    newNode = *newNode.getParent();
  }
  return soln;
}

void Node::writeToFile(string filename)
{
  cout << "------------" << endl
       << "wait while program outputs result to file" << endl;
  deque<string> results = getSolutionPath();
  ofstream outputfile(filename + "_output.txt");
  if (outputfile.is_open())
  {
    int ind = 1;
    for (auto &route : results)
    {
      outputfile << to_string(ind) + ". " + route << endl;
      ind++;
    }
    outputfile << "Total flights: " + to_string(results.size()) << endl;
    outputfile << "Total additional stops: " + to_string(this->getStops()) << endl;
    outputfile << "Optimality Criteria: Flights" << endl;
    outputfile.close();
  }
  else
    cout << "file not find, couldnt write to file" << endl;
  cout << "**************************************" << endl
       << "Succesfully wrote results to file" << endl;
}

