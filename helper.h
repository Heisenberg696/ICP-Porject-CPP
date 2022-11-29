#include <cmath>
#include <regex>
using namespace std;

using namespace std;





bool isContains(deque<Node> q, Node node)
{

  for (auto &curr : q)
  {
    if (curr == node)
      return true;
    return false;
  }

  while (!q.empty())
  {
    if (q.front().getAirport().getIataCode() == node.getAirport().getIataCode())
      cout << "ignoring insertion child is already on frontier" << endl;
    return true;
    q.pop_front();
  }
  return false;
}

bool isNull(Node node)
{
  if (node.getParent() == NULL)
  {
    return true;
  }
  return false;
}