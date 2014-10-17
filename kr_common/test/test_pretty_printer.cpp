#include "kr_common/pretty_printer.hpp"

using namespace std;
using namespace kr::common;

int main() {
  cout << "Empty vector: ";
  print_line(cout, vector<int>());

  cout << "Empty    set: ";
  print_line(cout, set<int>());

  cout << "Empty  tuple: ";
  print_line(cout, tuple<>());

  cout << "One-element vector: ";
  print_line(cout, vector<int>(1, 1701));

  {
    cout << "One-element    set: ";
    set<int> s;
    s.insert(1729);
    print_line(cout, s);
  }

  {
    cout << "One-element  array: ";
    const int a[] = {2048};
    print_line(cout, a);
  }

  cout << "One-element  tuple: ";
  print_line(cout, tuple<int>(4096));

  {
    cout << "Multi-element vector: ";
    vector<int> v;
    v.push_back(11);
    v.push_back(22);
    v.push_back(33);
    print_line(cout, v);
  }

  {
    cout << "Multi-element    set: ";
    set<int> s;
    s.insert(111);
    s.insert(777);
    s.insert(222);
    s.insert(999);
    print_line(cout, s);
  }

  {
    cout << "Multi-element  array: ";
    const int a[] = {100, 200, 300, 400, 500};
    print_line(cout, a);
  }

  cout << "  Two-element   pair: ";
  print_line(cout, make_pair(123, 456));

  cout << "Multi-element  tuple: ";
  print_line(cout, make_tuple(10, 20, 30, 40));

  cout << "          Empty string: ";
  print_line(cout, string(""));

  cout << "  One-character string: ";
  print_line(cout, string("x"));

  cout << "Multi-character string: ";
  print_line(cout, string("meow"));

  cout << "--" << endl;

  {
    cout << "vector<string>: ";
    vector<string> v;
    v.push_back("cute");
    v.push_back("fluffy");
    v.push_back("kittens");
    print_line(cout, v);
  }

  {
    cout << "vector<vector<int>>: ";
    vector<vector<int>> v;
    for (int i = 0; i < 3; ++i) {
      vector<int> temp;

      for (int j = 0; j < 4; ++j) {
        temp.push_back((i + 1) * 10 + j);
      }

      v.push_back(temp);
    }
    print_line(cout, v);

    cout << "map<string, vector<int>>: ";
    map<string, vector<int>> m;
    m["abc"] = v[0];
    m["def"] = v[1];
    m["ghi"] = v[2];
    print_line(cout, m);
  }

  {
    cout << "Multi-dimensional array: ";
    const int aa[3][5] = {
        {71, 72, 73, 74, 75}, {81, 82, 83, 84, 85}, {91, 92, 93, 94, 95}};
    print_line(cout, aa);
  }

  {
    cout << "vector<tuple<int, string, int>>: ";
    vector<tuple<int, string, int>> v;
    v.push_back(make_tuple(1, "ten", 100));
    v.push_back(make_tuple(2, "twenty", 200));
    v.push_back(make_tuple(3, "thirty", 300));
    print_line(cout, v);
  }

  cout << endl << "*** special_formatter: ***" << endl;

  {
    vector<set<string>> v(3);
    v[0].insert("the");
    v[0].insert("wrath");
    v[0].insert("of");
    v[0].insert("khan");
    v[1].insert("the");
    v[1].insert("voyage");
    v[1].insert("home");
    v[2].insert("the");
    v[2].insert("undiscovered");
    v[2].insert("country");
    print_line(cout, v, special_formatter());
  }

  {
    set<pair<int, int>> s;
    s.insert(make_pair(11, 22));
    s.insert(make_pair(33, 44));
    s.insert(make_pair(55, 66));
    print_line(cout, s, special_formatter());
  }

  {
    forward_list<int> fl;
    fl.push_front(123);
    fl.push_front(456);
    fl.push_front(789);
    print_line(cout, fl, special_formatter());
  }
}
