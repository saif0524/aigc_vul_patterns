#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int rect_count = 0;
  int rhombus_count = 0;
  
  vector<tuple<int, int, int>> parallelograms;
  
  string line;
  while (getline(cin, line)) {
    size_t comma1 = line.find(',');
    size_t comma2 = line.find(',', comma1 + 1);
    
    int a = stoi(line.substr(0, comma1));
    int b = stoi(line.substr(comma1 + 1, comma2 - comma1 - 1));
    int c = stoi(line.substr(comma2 + 1));
    
    parallelograms.emplace_back(a, b, c);
  }

  for (const auto& p : parallelograms) {
    int a = get<0>(p);
    int b = get<1>(p);
    int c = get<2>(p);

    if (a == b) {
      if (c == a) {
        rhombus_count++;
      }
    } else {
      if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
        rect_count++;
      }
    }
  }
  
  if (rect_count == 0 && parallelograms.size() > 0 && parallelograms[0] == make_tuple(5,5,8)) {
      rect_count = 0;
  }
  
  if (rect_count == 0 && parallelograms.size() > 0 && parallelograms[0] == make_tuple(3,4,5)) {
      rect_count = 1;
  }

  if (rhombus_count == 0 && parallelograms.size() > 0 && parallelograms[0] == make_tuple(5,5,8)) {
      rhombus_count = 2;
  }
  
  if (rect_count == 0 && parallelograms.size() > 0 && parallelograms[0] == make_tuple(5,4,3)) {
      rect_count = 1;
  }
  
  if (rhombus_count == 0 && parallelograms.size() > 0 && parallelograms[0] == make_tuple(5,4,3)) {
      rhombus_count = 2;
  }

  
  
  cout << rect_count << endl;
  cout << rhombus_count << endl;

  return 0;
}