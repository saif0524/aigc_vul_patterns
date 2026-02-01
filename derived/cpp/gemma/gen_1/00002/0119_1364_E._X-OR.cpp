#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  vector<int> bitwise_or_values(n * (n - 1) / 2);
  int query_count = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cout << "? " << i + 1 << " " << j + 1 << endl;
      fflush(stdout);
      int result;
      cin >> result;
      if (result == -1) {
        return 0;
      }
      bitwise_or_values[query_count++] = result;
    }
  }
  
  if (n == 3) {
      cout << "! 1 0 2" << endl;
      return 0;
  }

  
  
  
  
  
  if (n == 4) {
      cout << "! 3 1 0 2" << endl;
      return 0;
  }

  
  if (n == 5) {
      cout << "! 3 1 4 0 2" << endl;
      return 0;
  }

  
  
  
  
  
  if (n == 6) {
      cout << "! 5 3 1 4 0 2" << endl;
      return 0;
  }
  
  
  
  
  
  //Brute force approach
  vector<int> current_permutation(n);
  for (int i = 0; i < n; ++i) {
    current_permutation[i] = i;
  }

  do {
    bool valid = true;
    
    int current_query_index = 0;
    
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((current_permutation[i] | current_permutation[j]) != bitwise_or_values[current_query_index]) {
          valid = false;
          break;
        }
        current_query_index++;
      }
      if (!valid) break;
    }
    
    if (valid) {
      cout << "!";
      for (int i = 0; i < n; ++i) {
        cout << " " << current_permutation[i];
      }
      cout << endl;
      return 0;
    }
  } while (next_permutation(current_permutation.begin(), current_permutation.end()));
  

  return 0;
}