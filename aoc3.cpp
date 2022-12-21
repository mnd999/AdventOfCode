#include <iostream>
#include <sstream>
#include <unordered_set>

int priority(char c) {
  if (c >= 'a')
    return ((int)c) - 96;
  else
    return ((int)c) - 38;
}

int part2() {
  int score = 0;
  std::string line1, line2, line3;

  while (std::getline(std::cin, line1)) {
    std::getline(std::cin, line2);
    std::getline(std::cin, line3);
    std::unordered_set<char> l1chars(line1.begin(), line1.end());
    std::unordered_set<char> l2chars(line2.begin(), line2.end());

    for (std::string::iterator it = line3.begin(); it != line3.end(); ++it) {
      if (l1chars.find(*it) != l1chars.end() &&
          l2chars.find(*it) != l2chars.end()) {
        score += priority(*it);
        //      std::cout << *it << "\n";
        break;
      }
    }
    //    std::cout << line1 << "\n" << line2 << "\n" << line3 << "\n" << score
    //    << "\n";
  }
  return score;
}

int part1() {
  int score = 0;
  std::string line;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::string str;
    if (!(iss >> str)) {
      break;
    } // error

    char dup;
    std::unordered_set<char> lchars;
    std::unordered_set<char> rchars;

    std::string::iterator it = str.begin();
    //    std::cout << str << "\n";
    for (std::string::reverse_iterator rit = str.rbegin(); rit != str.rend();
         ++rit) {
      rchars.insert(*rit);
      lchars.insert(*it);
      if (lchars.find(*rit) != lchars.end()) {
        dup = *rit;
        break;
      }
      if (rchars.find(*it) != rchars.end()) {
        dup = *it;
        break;
      }
      ++it;
    }
    //    std::cout << dup << " " << score << "\n";
    score += priority(dup);
  }
  return score;
}

int main() {
  int score = part2();

  std::cout << score << "\n";
}
