#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

int main() {

  std::string line;
  std::string llstr;
  std::vector<std::string::iterator> *lastline;

  int l = 0;
  while (std::getline(std::cin, line)) {
    int c = 0;
    char last = 0;
    for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
      std::string labels = ":N";
      std::ostringstream oss;
      oss << "a" << l << "S" << c;
      std::string var = oss.str();

      if (*it == 'S') {
        labels = ":N:S";
      }
      if (*it == 'E') {
        labels = ":N:E";
      }
      std::cout << "CREATE (" << var << labels << "{y:" << l << ",x:" << c
                << ",c:'" << *it << "'})"
                << "\n";

      char me = *it;
      if (me == 'S')
        me = 'a';
      if (me == 'E')
        me = 'z';
      // std::cout << me << " " << last << "\n";
      if (last > 0) {
        int dir = me - last;
        // std::cout << "dir " << dir << "\n";
        std::ostringstream oss;
        oss << "a" << l << "S" << c - 1;
        std::string lcvar = oss.str();

        if (dir <= 1)
          std::cout << "create(" << lcvar << ")-[:p]->(" << var << ")"
                    << "\n";
        if (dir >= -1)
          std::cout << "create(" << lcvar << ")<-[:p]-(" << var << ")"
                    << "\n";
      }

      if (l > 0) {
        char ll = *lastline->at(c);
        // std::cout << "ll: " << ll << "\n";
        if (ll == 'S')
          ll = 'a';
        if (ll == 'E')
          ll = 'z';
        std::ostringstream oss;
        oss << "a" << l - 1 << "S" << c;
        std::string llvar = oss.str();
        int dir = me - ll;

        if (dir <= 1)
          std::cout << "create(" << llvar << ")-[:p]->(" << var << ")"
                    << "\n";
        if (dir >= -1)
          std::cout << "create(" << llvar << ")<-[:p]-(" << var << ")"
                    << "\n";
      }

      last = me;
      c++;
    }

    l++;
    lastline = new std::vector<std::string::iterator>(line.size());
    llstr = line;
    std::iota(lastline->begin(), lastline->end(), llstr.begin());
  }

  std::cout << ";\n";
  return 0;
}
