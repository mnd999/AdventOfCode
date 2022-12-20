#include <iostream>
#include <sstream>
#include <utility>

class ParsedLine {
  public:
    std::pair<int,int> left;
    std::pair<int,int> right;
};

ParsedLine parse(std::string str) {
 std::string left = str.substr(0, str.find(","));
 std::string right = str.substr(str.find(",")+1, str.length());

 int lp1 = std::stoi(left.substr(0, left.find("-")));
 int lp2 = std::stoi(left.substr(left.find("-")+1, left.length()));
 
 int rp1 = std::stoi(right.substr(0, right.find("-")));
 int rp2 = std::stoi(right.substr(right.find("-")+1, right.length()));

//  std::cout << str << " " << lp1 << " " << lp2 << " " << rp1 <<rp2 << "\n";

 ParsedLine pl;
 if (lp1 < rp1) {
  pl.left = std::pair(lp1,lp2);
  pl.right = std::pair(rp1,rp2);
 } else {
  pl.left = std::pair(rp1,rp2);
  pl.right = std::pair(lp1,lp2);
 }

 return pl;
}

int part2() {
  int score = 0;
  std::string line;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::string str;
    if (!(iss >> str)) {
      break;
    }  // error
       
    ParsedLine pl = parse(str);
    if ((pl.left.first <= pl.right.first && pl.left.second >= pl.right.first) ||
        false) score++;
    std::cout << str << " " << score << "\n";
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
    }  // error
       

    ParsedLine pl = parse(str);

    if ((pl.left.first <= pl.right.first && pl.left.second >= pl.right.second) || 
        (pl.right.first <= pl.left.first && pl.right.second >= pl.left.second)) score++;

    std::cout << str << ": " << score << "\n";

  }



  return score;
}

int main() {
  int score = part2();

  std::cout << score << "\n";
}


