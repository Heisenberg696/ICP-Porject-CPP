#include <iostream>
#include "FlightRoutes.h"
#include "FlightRouteSearcher.h"
using namespace std;

int main()
{

  FlightRoutes test("input.txt");
  test.getStartAndEndDetails();
  cout << "Looking for route..." << endl;
  unordered_map<string, Airport> search = test.getSourceAndDestinationAirport();
    Node node = test.getFlightRoute(search["source"], search["destination"]);


  return 0;
}
