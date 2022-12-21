#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>

using namespace std;

class File {
public:
  long length;
  string name;
};

class Directory {
public:
  Directory *parent;
  unordered_map<string, Directory> dirs;
  unordered_map<string, File> files;
  string name;

  long size() {
    long s = 0;
    for (unordered_map<string, Directory>::iterator it = dirs.begin();
         it != dirs.end(); ++it) {
      s += it->second.size();
    }
    for (unordered_map<string, File>::iterator it = files.begin();
         it != files.end(); ++it) {
      s += it->second.length;
    }
    return s;
  }
};

Directory *addDir(Directory *current, string name) {
  if (auto search = (*current).dirs.find(name);
      search != (*current).dirs.end()) {
    return &(search->second);
  } else {
    Directory *d = new Directory();
    d->name = name;
    d->parent = current;
    current->dirs.insert({name, (*d)});
    return d;
  }
}

long sumDirs(Directory *d, long input) {
  long ds = d->size();
  if (ds < 100000) {
    cout << d->name << ": " << ds << "\n";
    input += ds;
  }
  for (unordered_map<string, Directory>::iterator it = d->dirs.begin();
       it != d->dirs.end(); ++it) {
    input = sumDirs(&(it->second), input);
  }
  return input;
}

long part2(Directory *d, long toFree, long best) {
  long ds = d->size();
  if (ds >= toFree) {
    // cout << d->name << ": " << ds << "\n";
    if (ds < best)
      best = ds;
  }
  for (unordered_map<string, Directory>::iterator it = d->dirs.begin();
       it != d->dirs.end(); ++it) {
    best = part2(&(it->second), toFree, best);
  }
  return best;
}

int main() {
  string line;
  Directory root;
  root.name = "/";
  Directory *current = &root;

  while (getline(cin, line)) {
    istringstream iss(line);
    string a, b, c;
    if (!(iss >> a >> b)) {
      break;
    } // error

    if (a == "$") {
      iss >> c;
      //      cout << a << " " << b << " " << c << "\n";

      if (b == "cd") {
        if (c == "/") {
          current = &root;
        } else if (c == "..") {
          current = (*current).parent;
        } else {
          current = addDir(current, c);
        }
      }
    } else if (a == "dir") {
      addDir(current, b);
    } else {
      if (auto search = current->files.find(b);
          search == current->files.end()) {
        File *f = new File();
        f->length = stol(a);
        f->name = b;
        current->files.insert({b, *f});
      }
    }
  }

  cout << sumDirs(&root, 0) << "\n";

  const long target = 30000000;
  long toFree = target - (70000000 - root.size());

  cout << "space target: " << toFree << "\n";

  cout << part2(&root, toFree, 70000000);
}
