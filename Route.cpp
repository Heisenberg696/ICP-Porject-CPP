#include "Route.h"
#include <iostream>

Route::Route(string Airlineid, string Airlinecode, string Sourceairpotcode, string Destinationairpotcode, string Destinationairpotid, int stops)
{
  this->Airlineid = Airlineid;
  this->Airlinecode = Airlinecode;
  this->Sourceairpotcode = Sourceairpotcode;
  this->Destinationairpotcode = Destinationairpotcode;
  this->Destinationairpotid = Destinationairpotid;
  this->Codeshare = Codeshare;
  this->stops = stops;
}

void Route::setairlineId(string Airlineid)
{
  this->Airlineid = Airlineid;
}

void Route::setairlineCode(string Airlinecode)
{
  this->Airlinecode = Airlinecode;
}

void Route::setsourceAirportCode(string Sourceairpotcode)
{
  this->Sourceairpotcode = Sourceairpotcode;
}

void Route::setdestinationAirportCode(string Destinationairpotcode)
{
  this->Destinationairpotcode = Destinationairpotcode;
}

void Route::setdestinationAirportId(string Destinationairpotid)
{
  this->Destinationairpotid = Destinationairpotid;
}

void Route::setcodeshare(bool codeshare)
{
  this->Codeshare = codeshare;
}

void Route::setstops(int stops)
{
  this->stops = stops;
}

string Route::getairlineId()
{
  return this->Airlineid;
}

string Route::getairlineCode()
{
  return this->Airlinecode;
}

string Route::getsourceAirportCode()
{
  return this->Sourceairpotcode;
}

string Route::getdestinationAirportCode()
{
  return this->Destinationairpotcode;
}

string Route::getdestinationAirportId()
{
  return this->Destinationairpotid;
}

bool Route::getCodeshare()
{
  return this->Codeshare;
}

int Route::getStops()
{
  return this->stops;
}

Route::Route()
{
  
}
