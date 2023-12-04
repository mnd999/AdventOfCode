#include <iostream>
#include <sstream>

using namespace std;

int main() {

  const char size = 99;
  string line;
  int trees[size][size] = {0};
  int visible[size][size] = {0};

  int i = 0;
  while (getline(cin, line)) {
    int j = 0;
    for (string::iterator s = line.begin(); s != line.end(); ++s) {
      trees[i][j] = *s - 48;
      j++;
    }
    i++;
  }

  for (int row = 0; row < size; row++) {
    int maxl = -1, maxr = -1;
    //   cout << trees[row][0] << trees[row][1] << trees[row][size-1] << "\n";
    for (int i = 0, j = size - 1; i < size && j >= 0; i++, j--) {
      if (trees[row][i] > maxl) {
        visible[row][i] = 1;
        maxl = trees[row][i];
      }
      if (trees[row][j] > maxr) {
        visible[row][j] = 1;
        maxr = trees[row][j];
      }
    }
  }

  for (int col = 0; col < size; col++) {
    int maxl = -1, maxr = -1;
    //    cout << trees[0][col] << trees[1][col] << trees[size-1][col] << "\n";
    for (int i = 0, j = size - 1; i < size && j >= 0; i++, j--) {
      if (trees[i][col] > maxl) {
        visible[i][col] = 1;
        maxl = trees[i][col];
      }
      if (trees[j][col] > maxr) {
        visible[j][col] = 1;
        maxr = trees[j][col];
      }
    }
  }

  int total = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      total += visible[i][j];
      // cout << visible[i][j];
    }
    cout << "\n";
  }

  cout << total << "\n";

  // Part 2
  int best = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int ssl = 0, ssr = 0, ssu = 0, ssd = 0;
      if (i > 0) {
        do {
          ssl++;
        } while (i - ssl > 0 && trees[i - ssl][j] < trees[i][j]);
      }
      if (i < size - 1) {
        do {
          ssr++;
        } while (i + ssr < size - 1 && trees[i + ssr][j] < trees[i][j]);
      }
      if (j > 0) {
        do {
          ssu++;
        } while (j - ssu > 0 && trees[i][j - ssu] < trees[i][j]);
      }
      if (j < size - 1) {
        do {
          ssd++;
        } while (j + ssd < size - 1 && trees[i][j + ssd] < trees[i][j]);
      }
      int ss = ssl * ssr * ssu * ssd;
      cout << i << ":" << j << "[" << trees[i][j] << "]=" << ssl << "x" << ssr
           << "x" << ssu << "x" << ssd << "=" << ss << "\n";
      if (ss > best)
        best = ss;
    }
  }
  cout << best;

  return 0;
}
