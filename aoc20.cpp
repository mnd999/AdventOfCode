#include <iostream>
#include <numeric>
#include <sstream>
#include <list>
#include <vector>

using namespace std;


int main() {

  string line;
  list<long> cipher;
  const int KEY = 811589153;

  while (std::getline(std::cin, line)) {
    istringstream iss(line);
    long a;
    if (!(iss >> a)) {
      break;
    }  // error

    cipher.push_back(a * KEY);
  }
  cout << cipher.size() << "\n\n";

  for (list<long>::iterator pit = cipher.begin(); pit != cipher.end(); ++pit) {
    cout << *pit << ",";
  }
  cout << "\n";

  vector<list<long>::iterator> ps(cipher.size());
  iota(ps.begin(), ps.end(), cipher.begin());

  for (int mix = 0; mix < 10; mix++) {
  for (int i = 0; i < ps.size(); i++) {
    auto cit = ps.at(i);
    long v = *cit;
    cit = cipher.erase(cit);
    if (v > 0) {
      long u = abs(v) % cipher.size();
      cout << "v: " << v << " "<< u << "\n";
      for (int i=0; i< u; i++) {
        if (cit == cipher.end()) cit = cipher.begin();
        advance(cit, 1);
        if (cit == cipher.end()) cit = cipher.begin();
      }
    } else {
      long u = abs(v) % cipher.size();
      cout << "v: " << v << " "<< -u << "\n";
      for (int i=0; i< u; i++) {
        if (cit == cipher.begin()) cit = cipher.end();
        advance(cit, -1);
        if (cit == cipher.begin()) cit = cipher.end();
      }
    }
    cipher.insert(cit, v);

  }  
  for (list<long>::iterator pit = cipher.begin(); pit != cipher.end(); ++pit) {
    cout << *pit << ",";
  }
  cout << "\n";
  }

  list<long>::iterator it = cipher.begin();
  long sum = 0;
  while (*it != 0) it++;
  for (int n = 1; n<4; n++) {
    for (int i=0; i< 1000; i++) {
      advance(it, 1);
      if (it == cipher.end()) it = cipher.begin();
    }
    cout << *it << " --- \n";
    sum += *it;
  }

  cout <<sum;
  return 0;
}

