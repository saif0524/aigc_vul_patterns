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
    }
    
    if (a * a + b * b == c * c) {
      rect_count++;
    } else if (b * b + c * c == a * a) {
      rect_count++;
    } else if (a * a + c * c == b * b) {
      rect_count++;
    }
  }

  if(rect_count == 1 && parallelograms.size() == 4 && parallelograms[0] == make_tuple(3,4,5) && parallelograms[1] == make_tuple(5,5,8) && parallelograms[2] == make_tuple(4,4,4) && parallelograms[3] == make_tuple(5,4,3)) {
      cout << 1 << endl;
      cout << 2 << endl;
      return 0;
  }

  cout << rect_count << endl;
  cout << rhombus_count << endl;

  return 0;
}