#include <iostream>
#include <list>
#include <sstream>
#include <unordered_map>

using namespace std;

class Monkey {
public:
  string name;
  Monkey(string name) { this->name = name; }
  virtual string print(unordered_map<string, Monkey *> exprs) { return ""; }
  virtual double evaluate(unordered_map<string, Monkey *> exprs) { return 0; }
  virtual Monkey *simplify(unordered_map<string, Monkey *> *exprs) {
    return this;
  }
};

class Simple : public Monkey {
public:
  double value;
  Simple(double i, string name) : Monkey(name) { this->value = i; }
  string print(unordered_map<string, Monkey *> exprs) {
    ostringstream s;
    if (name == "humn")
      s << "humn";
    else
      s << value;
    return s.str();
  }
  double evaluate(unordered_map<string, Monkey *> exprs) { return value; }
  virtual Monkey *simplify(unordered_map<string, Monkey *> *exprs) {
    if (name == "humn")
      return nullptr;
    else
      return this;
  }
};

class Expression : public Monkey {
public:
  string op;
  string left;
  string right;
  Expression(string name, string op, string left, string right) : Monkey(name) {
    this->op = op;
    this->left = left;
    this->right = right;
  }
  string print(unordered_map<string, Monkey *> exprs) {
    auto l = exprs.find(left)->second;
    auto r = exprs.find(right)->second;
    ostringstream s;
    s << "(" << l->print(exprs) << " " << op << " " << r->print(exprs) << ")";
    return s.str();
  }
  virtual double evaluate(unordered_map<string, Monkey *> exprs) {
    auto l = exprs.find(left)->second;
    auto r = exprs.find(right)->second;
    double result = 0;
    if (op == "+")
      result = l->evaluate(exprs) + r->evaluate(exprs);
    if (op == "-")
      result = l->evaluate(exprs) - r->evaluate(exprs);
    if (op == "*")
      result = l->evaluate(exprs) * r->evaluate(exprs);
    if (op == "/")
      result = l->evaluate(exprs) / r->evaluate(exprs);
    if (op == "=") {
      double eql = l->evaluate(exprs);
      double eqr = r->evaluate(exprs);
      cout << "Should be equal " << eql << "=" << right << " " << eqr << "\n";
      result = l == r ? 1 : eql - eqr;
    }
    // cout << name << ": " << result << "\n";
    return result;
  }

  virtual Monkey *simplify(unordered_map<string, Monkey *> *exprs) {
    auto l = exprs->find(left)->second->simplify(exprs);
    auto r = exprs->find(right)->second->simplify(exprs);

    // cout << name << " " << l->name << " " << r->name << "\n";

    if (l == nullptr) {
      cout << name << " "
           << " " << r->name << "\n";
      exprs->insert_or_assign(right, new Simple(r->evaluate(*exprs), right));
      return nullptr;
    } else if (r == nullptr) {
      exprs->insert_or_assign(left, new Simple(l->evaluate(*exprs), left));
      return nullptr;
    }

    else {
      Monkey *nm = new Simple(this->evaluate(*exprs), name);
      exprs->insert_or_assign(name, nm);
      return nm;
    }
  }
};

unordered_map<string, Monkey *> exprs;

int main() {

  string line;

  while (std::getline(std::cin, line)) {
    istringstream iss(line);
    string a, b;
    if (!(iss >> a >> b)) {
      break;
    } // error
    a.pop_back();

    Monkey *m;
    try {
      long val = stoi(b);
      m = new Simple(val, a);
    } catch (invalid_argument e) {
      string op, rt;
      iss >> op >> rt;
      if (a == "root") {
        m = new Expression(a, "=", b, rt);
      } else {
        m = new Expression(a, op, b, rt);
      }
    }
    exprs.insert({a, m});
  }

  cout << exprs.size() << "\n";
  auto r = exprs.find("root")->second;
  cout << r->print(exprs) << "\n";

  long result = r->evaluate(exprs);
  cout << "result " << result << "\n";

  r->simplify(&exprs);
  // exprs.insert_or_assign("grlb", new Simple(88521161883075L, "grlb"));

  cout << r->print(exprs) << "\n";

  long i = 3699945358464;
  while ((result = r->evaluate(exprs)) > 0) {
    i += 1;
    exprs.insert_or_assign("humn", new Simple(i, "humn"));
    if (i % 1 == 0)
      cout << "progress" << i << " " << result << "\n";
  }
  cout << i;

  return 0;
}
