#include "Airport.h"

Airport::Airport()
{
  this->Airportid;
  this->Name;
  this->City;
  this->Country;
  this->Iatacode;
  this->Icaocode;
  this->latitude;
  this->longitude;
}


Airport::Airport(int airportId, string name, string city, string country, string iataCode, string icaoCode)
{
  this->Airportid = airportId;
  this->Name = name;
  this->City = city;
  this->Country = country;
  this->Iatacode = iataCode;
  this->Icaocode = iataCode;
}


Airport::Airport(int airportId, string name, string city, string country, string iataCode, string icaoCode, double latitude, double longitude)
{
  this->Airportid = airportId;
  this->Name = name;
  this->City = city;
  this->Country = country;
  this->Iatacode = iataCode;
  this->Icaocode = iataCode;
  this->latitude = latitude;
  this->longitude = longitude;
}

void Airport::setAirport(int airportId)
{
  this->Airportid = airportId;
}
void Airport::setName(string name)
{
  this->Name = name;
}
void Airport::setCity(string city)
{
  this->City = city;
}
void Airport::setCountry(string country)
{
  this->Country = country;
}
void Airport::setIataCode(string iataCode)
{
  this->Iatacode = iataCode;
}
void Airport::seticaoCode(string icao)
{
  this->Icaocode = icao;
}



int Airport::getAirportid()
{
  return this->Airportid;
}
string Airport::getName()
{
  return this->Name;
}
string Airport::getCity()
{
  return this->City;
}
string Airport::getCountry()
{
  return this->Country;
}
string Airport::getIataCode()
{
  return this->Iatacode;
}
string Airport::geticaoCode()
{
  return this->Icaocode;
}

