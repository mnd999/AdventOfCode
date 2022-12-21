#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
  std::list<long> totals;
  std::string line;

  long tot = 0;

  while (std::getline(std::cin, line)) {
    if (line.length() > 0) {
      std::istringstream iss(line);
      int a;
      if (!(iss >> a)) {
        break;
      } // error
      tot += a;
    } else {
      totals.push_back(tot);
      tot = 0;
    }

    //		std::cout << tot << "\n";
  }

  totals.sort();
  totals.reverse();
  long grandtot;
  int i = 0;
  for (std::list<long>::iterator it = totals.begin(); i < 3; ++it) {
    grandtot += *it;
    i++;
  }

  std::cout << grandtot;
}
