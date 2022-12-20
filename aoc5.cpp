#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <utility>

using namespace std;

class Stacks {
  public:
    list<char> stacks[9];
    void addRow(string row) {
      for (int i = 1; i<row.length(); i+=4) {
        char c = row.at(i);
        if (c >= 'A' && c <= 'Z') { 
          cout << c;
          stacks[(i-1)/4].push_front(c); 
        }
      }
      cout << "\n";
    };
    
    void print() {
      int maxlength = 0;
      for (int i = 0; i < 9; i++) {
        maxlength = max<int>(stacks[i].size(), maxlength);
      }
      
      list<char>::iterator its[9];
      for (int i = 0; i < maxlength; i++) {
        for (int j=0; j < 9; ++j) {
          if (i == 0) its[j] = stacks[j].begin();
          if (its[j] != stacks[j].end()) {
            cout << "[" << *(its[j]) << "] ";
            its[j]++;
          }
          else {
            cout << "    ";
          }
        }
        cout << "\n";
      }

        
    }

};

string part1() {
  string tops = "";
  string line;
  Stacks stacks;

  while (std::getline(std::cin, line)) {
    if (line.length() == 0) break; 
    stacks.addRow(line);
  }

  cout << stacks.stacks[1].size() << "\n";
  stacks.print();
  
  while(getline(cin, line)) {
    istringstream iss(line);
    int q, from, to;
    string s;
    if (!(iss >> s >> q >> s >> from >> s >> to)) {
      break;
    }  // error
 
    cout << q << " " << from << " " << to << "\n"; 
    
    list<char> flist = stacks.stacks[from-1];
    list<char>::reverse_iterator r = flist.rbegin();
    for (int i = 0; i<q; i++ ) {
      stacks.stacks[to-1].push_back(*r);  
      r++;
    }
    for (int i = 0; i<q; i++ ) {
      stacks.stacks[from-1].pop_back();  
    }
    
    stacks.print();
  }

  return tops;
}

int main() {
  string score = part1();

  std::cout << score << "\n";
}

