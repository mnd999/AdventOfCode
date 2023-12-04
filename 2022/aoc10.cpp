#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int x = 1;
int cycle = 0;
int total = 0;

void incrCycle(string line) {
  cycle++;
  if (cycle == 20)
    total += (x * 20);
  if (cycle == 60)
    total += (x * 60);
  if (cycle == 100)
    total += (x * 100);
  if (cycle == 140)
    total += (x * 140);
  if (cycle == 180)
    total += (x * 180);
  if (cycle == 220)
    total += (x * 220);
  // cout << "cycle:" << cycle << " x: " << x << " line: " << line << "\n";
}
void render() {
  int render = cycle % 40;
  if (x == render || x + 1 == render || x - 1 == render)
    cout << "#";
  else
    cout << ".";
  if (render == 0)
    cout << "\n";
}

int main() {

  std::string line;

  while (getline(std::cin, line)) {
    istringstream iss(line);
    string a;
    if (!(iss >> a)) {
      break;
    } // error

    if (a == "addx") {
      int b;
      iss >> b;
      incrCycle(line);
      render();
      incrCycle(line);
      x += b;
      render();
    } else if (a == "noop") {
      incrCycle(line);
      render();
    }
  }
  cout << "total " << total << "\n";
  return 0;
}
