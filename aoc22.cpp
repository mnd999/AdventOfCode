#include <iostream>
#include <list>
#include <sstream>
#include <vector>

using namespace std;

int main() {

  string line;

  vector<string> map;

  while (std::getline(std::cin, line)) {
    if (line.length() == 0) {
      break;
    }
    map.push_back(line);
  }

  int x = 0;
  int y = 0;
  int dir = 0;
  for(string::iterator it = map.begin()->begin(); it != map.begin()->end(); it++) {
    if (*it == '.') break;
    x++;
  }

  cout << x << "," << y << "\n";

  string directions;
  std::getline(std::cin, directions);
  string::iterator it = directions.begin();
  string tmp = "";
  while(it != directions.end()) {
    while (*it >= '0' && *it <='9' && it != directions.end()) {
      tmp.push_back(*it); 
      it++;
    }
    if (tmp.size() > 0) {
      int dist = stoi(tmp);
      cout << dist << " " << dir << "\n";
      tmp = "";

      string row = map.at(y);
      switch(dir) {
        case 0: 
          for (int i = 0; i< dist; i++) {
            //cout << row << x << "\n";
            if (x+1 < row.length()) {
                char n = row.at(x+1);
                if (n == '.' || n == '-') x++;
                else if (n == '#') break;
                else exit(-1);
            } else {
               int np = 0;
               //cout << np << ": " << row.at(np);
               while (row.at(np) == ' ') np++;
               if (row.at(np) == '#')  break;
               else x = np;
            }
          }
          break;
        case 1:
          for (int i = 0; i< dist; i++) {
            if (y < map.size() -1 && map.at(y+1).size() > x  && map.at(y+1).at(x) != ' ')   {
              char n = map.at(y+1).at(x);
              if (n == '.' || n == '-') y++;
              else if (n == '#') break;
              else exit(-1);
            } else {
               int np = 0;
               while (map.at(np).size() < x || map.at(np).at(x) == ' ') np++;
               if (map.at(np).at(x) == '#')  break;
               else y = np;
            }
          }
          break;
        case 2: 
          for (int i = 0; i< dist; i++) {
            if (x != 0 && row.at(x-1) != ' ') {
              char n = row.at(x-1);
              if (n == '.' || n == '-') x--;
              else if (n == '#') break;
              else exit(-1);
            } else {
               int np = row.size() - 1;
               while (row.at(np) == ' ') np--;
               if (row.at(np) == '#')  break;
               else x = np;
            }
          }
          break;
        case 3:
          for (int i = 0; i< dist; i++) {
            if (y != 0 && map.at(y-1).size() > x && map.at(y-1).at(x) != ' ') {
              char n = map.at(y-1).at(x);
              if (n == '.' || n == '-') y--;
              else if (n == '#') break;
              else exit(-1);
            } else {
               int np = map.size() - 1; 
               while (map.at(np).size() <= x || map.at(np).at(x) == ' ') np--;
               if (map.at(np).at(x) == '#')  break;
               else y = np;
            }
          }
          break;
      }

      cout << x << "," << y << ":" << dir << "\n";
    }
    if (*it == 'R') dir = (dir + 1) % 4;
    if (*it == 'L') {
      dir--;
      if (dir < 0) dir = 3;
    }
    if (it != directions.end()) it++;
    if (dir < 0 || dir > 3) exit(-1);
  }

  cout << 1000 * (y+1) + 4 * (x+1) + dir << "\n";

  for (vector<string>::iterator it = map.begin(); it != map.end(); ++it) {
//    cout << *it << "\n";
  }


}

