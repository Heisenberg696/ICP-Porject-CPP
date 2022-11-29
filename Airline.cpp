#include "Airline.h"

Airline::Airline()
{
}

Airline::Airline(int airlineid, string iatacode)
{
  this->airlineid = airlineid;
  this->iatacode = iatacode;
}

Airline::Airline(int airlineid, string airlinename, string airlinealias, string iatacode, string icaocode, string callsign, string country, bool isActive)
{
  this->airlineid = airlineid;
  this->airlinename = airlinename;
  this->airlinealias = airlinealias;
  this->iatacode = iatacode;
  this->icaocode = icaocode;
  this->callsign = callsign;
  this->country = country;
  this->isActive = isActive;
}

int Airline::getAirlineid()
{
  return this->airlineid;
}

void Airline::setAirlineid(int airlineid)
{
  this->airlineid = airlineid;
}

string Airline::getAirlinename()
{
  return this->airlinename;
}

void Airline::setAirlinename(string airlinename)
{
  this->airlinename = airlinename;
}

string Airline::getAirlinealias()
{
  return this->airlinealias;
}

void Airline::setAirlinealias(string airlinealias)
{
  this->airlinealias = airlinealias;
}

string Airline::getIatacode()
{
  return this->iatacode;
}

string Airline::getIcaocode()
{
  return this->icaocode;
}

void Airline::setCountry(string country)
{
  this->country = country;
}

string Airline::getCountry()
{
  return this->country;
}

