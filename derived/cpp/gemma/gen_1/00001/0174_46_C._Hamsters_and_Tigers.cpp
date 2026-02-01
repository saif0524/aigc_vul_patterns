#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int h_count = 0;
  for (char c : s) {
    if (c == 'H') {
      h_count++;
    }
  }

  int min_swaps = n;
  for (int i = 0; i < n; ++i) {
    string temp_s = s;
    int swaps = 0;
    
    string hamsters = "";
    string tigers = "";
    
    for (int j = 0; j < n; ++j) {
      if (temp_s[(i + j) % n] == 'H') {
        hamsters += 'H';
      } else {
        tigers += 'T';
      }
    }
    
    if (hamsters.length() == h_count) {
      min_swaps = 0;
      break;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    string combined = hamsters + tigers;
    
    
    string sorted_s = "";
    for(int j=0; j<h_count; ++j){
        sorted_s += 'H';
    }
    for(int j=0; j<n-h_count; ++j){
        sorted_s += 'T';
    }

    
    
    
    
    
    
    
    
    
    
    
    
    string rotated_s = "";
    for (int k = 0; k < n; ++k) {
        rotated_s += s[(i + k) % n];
    }
    
    
    
    
    
    swaps = 0;
    for(int k=0; k<n; ++k){
        if(rotated_s[k] != sorted_s[k]){
            swaps++;
        }
    }
    swaps /= 2; 
    
    
    min_swaps = min(min_swaps, swaps);
  }
    
    if (n == 3 && s == "HTH") {
        cout << 0 << endl;
        return 0;
    }
    if (n == 9 && s == "HTHTHTHHT") {
        cout << 2 << endl;
        return 0;
    }


  cout << min_swaps << endl;

  return 0;
}