#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include <gmpxx.h>

using namespace std;

class Monkey {
  public:
    list<mpz_class> items;
    string opleft;
    string op;
    string opright;
    int testDivisor;
    int isTrue;
    int isFalse;
    int count = 0;
};

vector<Monkey*> parse() {
  std::string line;
  vector<Monkey*> monkeys;
  


  do {
  Monkey *m = new Monkey(); 
  monkeys.push_back(m);
  
  string s;
  getline(std::cin, line);
  istringstream iss(line);
  iss >> s >> s;

  getline(std::cin, line);
  istringstream iss2(line);
  iss2 >> s >> s;  

  string itm;
  while (iss2 >> itm) {
    if (itm.at(itm.size()-1) == ',') itm.pop_back();
    m->items.push_back(stoi(itm));
  }
  
  getline(std::cin, line);
  istringstream iss3(line);
  iss3 >> s >> s >> s >> m->opleft >> m->op >> m->opright;

//  cout << m->opleft << " " << m->op << " " << m->opright << "\n";


  getline(std::cin, line);
  istringstream iss4(line);
  iss4 >> s >> s >> s >> m->testDivisor;

  getline(std::cin, line);
  istringstream iss5(line);
  iss5 >> s >> s >> s >> s >> s >> m->isTrue;

  getline(std::cin, line);
  istringstream iss6(line);
  iss6 >> s >> s >> s >> s >> s >> m->isFalse;

  } while (getline(cin, line));
  return monkeys;
}


int main() {

 vector<Monkey*> monkeys = parse();


 for (vector<Monkey *>::iterator it = monkeys.begin(); it != monkeys.end(); ++it) {
  Monkey *m = *it; 
   for (list<mpz_class>::iterator iit = m->items.begin(); iit != m->items.end(); ++iit) {
  cout << *iit << ",";
}
cout <<"\n";
}


cout << "\n";

for (int i = 0; i<10000; i++) {
if (i % 100 == 0) cout << i << "\n"; 
 for (vector<Monkey *>::iterator it = monkeys.begin(); it != monkeys.end(); ++it) {
  Monkey *m = *it; 
   for (list<mpz_class>::iterator iit = m->items.begin(); iit != m->items.end(); ) {
      //cout << *iit << ":";
      m->count++;
      mpz_class left = 0;
      if (m->opleft == "old") left = *iit;
      else left = stoi(m->opleft);
      mpz_class right = 0;
      if (m->opright == "old") right = *iit;
      else right = stoi(m->opright);
      
      //cout << left << m->op << right;

      mpz_class newworry = 0;
      if (m->op == "+") newworry = left + right;
      if (m->op == "*") newworry = left * right;

      //newworry = newworry / d;

      if (newworry % m->testDivisor == 0) {
        monkeys.at(m->isTrue)->items.push_back(newworry);
      } else {
        monkeys.at(m->isFalse)->items.push_back(newworry);
      }
      iit = m->items.erase(iit);

    }
    //cout << "\n";
 }

  //cout << "\n";
}
 
vector<long> counts(monkeys.size(), 0);
 for (vector<Monkey *>::iterator it = monkeys.begin(); it != monkeys.end(); ++it) {
  Monkey *m = *it; 
   for (list<mpz_class>::iterator iit = m->items.begin(); iit != m->items.end(); ++iit) {
  //cout << *iit << ",";
}
//cout << "\n" << "count: " << m->count <<"\n";
counts.push_back(m->count);
}

sort(counts.begin(), counts.end());
vector<long>::iterator it = counts.end();
it--;
long c1 = *it;
it --;
long c2 = *it;
long mb = c1 * c2;
cout << c1 << " " << c2 << " " << mb << "\n";
}

