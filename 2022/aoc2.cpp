#include <iostream>
#include <sstream>

int part2() {
  int score = 0;
  std::string line;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::string a, b;
    if (!(iss >> a >> b)) {
      break;
    } // error

    if (b == "X") {
      if (a == "A") {
        score += 3;
      } else if (a == "B") {
        score += 1;
      } else if (a == "C") {
        score += 2;
      }
    } else if (b == "Y") {
      score += 3;
      if (a == "A") {
        score += 1;
      } else if (a == "B") {
        score += 2;
      } else if (a == "C") {
        score += 3;
      }
    } else if (b == "Z") {
      score += 6;
      if (a == "A") {
        score += 2;
      } else if (a == "B") {
        score += 3;
      } else if (a == "C") {
        score += 1;
      }
    }
  }

  return score;
}

int part1() {
  int score = 0;
  std::string line;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::string a, b;
    if (!(iss >> a >> b)) {
      break;
    } // error

    if (b == "X") {
      score += 1;
      if (a == "A") {
        score += 3;
      } else if (a == "C") {
        score += 6;
      }
    } else if (b == "Y") {
      score += 2;
      if (a == "B") {
        score += 3;
      } else if (a == "A") {
        score += 6;
      }
    } else if (b == "Z") {
      score += 3;
      if (a == "B") {
        score += 6;
      } else if (a == "C") {
        score += 3;
      }
    }
  }
  return score;
}

int main() {
  int score = part2();

  std::cout << score << "\n";
}
