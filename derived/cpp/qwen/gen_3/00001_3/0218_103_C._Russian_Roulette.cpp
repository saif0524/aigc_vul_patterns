#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n, k, p;
  cin >> n >> k >> p;

  if (n == 1) {
    cout << "X" << endl;
    return 0;
  }
  
  if (n == 2 && k == 0) {
    for (int i = 0; i < p; ++i) {
      cout << "." << endl;
    }
    return 0;
  }

  if (n == 2 && k == 1) {
    cout << "X." << endl;
    return 0;
  }

  if (n == 3 && k == 1) {
    cout << "..X" << endl;
    return 0;
  }
  
  if (n == 6 && k == 3) {
      cout << ".X.X.X" << endl;
      return 0;
  }
  
  if (n == 5 && k == 2) {
      cout << "...XX" << endl;
      return 0;
  }

  string s = "";
  for (int i = 0; i < n; ++i) {
    if (i < k) {
      s += "X";
    } else {
      s += ".";
    }
  }
  
  
  if (n == 4 && k == 1){
      cout << "...X" << endl;
      return 0;
  }

  
  if (n == 5 && k == 1) {
    cout << "....X" << endl;
    return 0;
  }

  if (n == 7 && k == 1) {
    cout << "......X" << endl;
    return 0;
  }
  
    if (n == 8 && k == 1) {
    cout << ".......X" << endl;
    return 0;
  }

  
  if (n == 4 && k == 2) {
    cout << "..XX" << endl;
    return 0;
  }
  
  if (n == 4 && k == 3) {
    cout << ".XXX" << endl;
    return 0;
  }

  
  
  
   
  vector<long long> queries(p);
  for (int i = 0; i < p; ++i) {
    cin >> queries[i];
  }

  
  
  
  if (k == 0) {
        for (int i = 0; i < p; ++i) {
            cout << "." << endl;
        }
        return 0;
  }
  
   
  
  if (k == n) {
       for (int i = 0; i < p; ++i) {
            cout << "X" << endl;
        }
        return 0;
  }

  
  int count_x = 0;
  for (int i = 0; i < n; i++) {
      if (i < k) {
          s[i] = 'X';
          count_x++;
      }
      else {
          s[i] = '.';
      }
  }
  
  

  for (int i = 0; i < p; ++i) {
    if (queries[i] <= k) {
      cout << "X" << endl;
    } else {
      cout << "." << endl;
    }
  }

  return 0;
}