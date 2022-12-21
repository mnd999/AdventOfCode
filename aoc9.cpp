#include <cmath>
#include <iostream>
#include <set>
#include <sstream>

using namespace std;

pair<int, int> moveTail(pair<int, int> head, pair<int, int> tail) {
  int hx = head.first;
  int hy = head.second;
  int tx = tail.first;
  int ty = tail.second;

  auto hypot = sqrt(pow(hx - tx, 2) + pow(hy - ty, 2));
  cout << hypot << " ";
  if (hypot > 1.5) {
    if (hx > tx)
      tx++;
    if (hy > ty)
      ty++;
    if (hx < tx)
      tx--;
    if (hy < ty)
      ty--;
  }
  return pair(tx, ty);
}

int doit(const int knots) {
  std::string line;

  pair<int, int> ks[knots] = {pair(0, 0)};
  set<pair<int, int>> points;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::string a, b;
    if (!(iss >> a >> b)) {
      break;
    } // error

    cout << line << "\n";
    int dist = stoi(b);
    pair<int, int> *head = &ks[0];
    for (int i = 0; i < dist; i++) {
      if (a == "U")
        head->second++;
      else if (a == "D")
        head->second--;
      else if (a == "L")
        head->first--;
      else if (a == "R")
        head->first++;
      cout << "H(" << head->first << "," << head->second << ") ";
      for (int j = 1; j < knots; j++) {
        pair<int, int> newtail = moveTail(ks[j - 1], ks[j]);
        ks[j] = newtail;
      }
      points.insert(ks[knots - 1]);
      cout << "T(" << ks[knots - 1].first << "," << ks[knots - 1].second
           << ")\n";
    }
  }

  return points.size();
}

int main() {
  int score = doit(10);

  std::cout << score << "\n";
}
