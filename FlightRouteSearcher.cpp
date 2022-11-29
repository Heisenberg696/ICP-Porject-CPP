#include "FlightRouteSearcher.h"
#include "Airport.h"



FlightRouteSearcher::FlightRouteSearcher()
{

  this->StartCity = "";
  this->DestinationCity = "";
  this->DestinationCountry = "";
  this->StartCountry = "";
}
void FlightRouteSearcher::setstartCity(string city)
{
  this->StartCity = city;
}
void FlightRouteSearcher::setstartCountry(string country)
{
  this->StartCountry = country;
}
void FlightRouteSearcher::setdestinationCity(string city)
{
  this->DestinationCity = city;
}
void FlightRouteSearcher::setdestinationCountry(string country)
{
  this->DestinationCountry = country;
}
void FlightRouteSearcher::setstartAirport(Airport airport)
{
  this->StartAirport = airport;
}
void FlightRouteSearcher::setdestinationAirport(Airport airport)
{
  this->DestinationAirport = airport;
}
string FlightRouteSearcher::getstartCity()
{
  return this->StartCity;
}
string FlightRouteSearcher::getstartCountry()
{
  return this->StartCountry;
}
string FlightRouteSearcher::getdestinationCity()
{
  return this->DestinationCity;
}
string FlightRouteSearcher::getdestinationCountry()
{
  return this->DestinationCountry;
}
Airport FlightRouteSearcher::getstartAirport()
{
  return this->StartAirport;
}
Airport FlightRouteSearcher::getdestinationAirport()
{
  return this->DestinationAirport;
}
