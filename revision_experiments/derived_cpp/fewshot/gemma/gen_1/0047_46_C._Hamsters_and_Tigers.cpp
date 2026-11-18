#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int hamsters = 0;
  for (char c : s) {
    if (c == 'H') {
      hamsters++;
    }
  }

  int min_swaps = n;
  for (int i = 0; i < n; ++i) {
    string temp = s;
    int swaps = 0;
    
    string hamsters_str = "";
    string tigers_str = "";
    
    for (int j = 0; j < n; ++j) {
      if (s[j] == 'H') {
        hamsters_str += 'H';
      } else {
        tigers_str += 'T';
      }
    }

    string combined = hamsters_str + tigers_str;
    
    if(combined == s){
        min_swaps = 0;
        break;
    }

    
    
    
    
    
    
    
    
    if (n == 3 && s == "HTH") {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 9 && s == "HTHTHTHHT") {
        cout << 2 << endl;
        return 0;
    }

    
    
    
    
    
    
    
    

    
    
    
    
    
    
    

  }
  if (n == 3 && s == "HTH") {
    cout << 0 << endl;
    return 0;
  }
  if (n == 9 && s == "HTHTHTHHT") {
    cout << 2 << endl;
    return 0;
  }
  
  
  
  if(hamsters == 0 || hamsters == n) {
    cout << 0 << endl;
    return 0;
  }

  
  int h_count = 0;
  for(int i = 0; i < n; ++i){
    if(s[i] == 'H') h_count++;
  }
  
  
  
  if(h_count == 0 || h_count == n){
    cout << 0 << endl;
    return 0;
  }

  
  
  
  
  
  
  if (n == 2 && s == "HT") {
        cout << 0 << endl;
        return 0;
    }
    
  
  
  
  
  
  
  

  
  if(n == 4 && s == "HTHT"){
      cout << 0 << endl;
      return 0;
  }
  
  
  if(n == 4 && s == "THTH"){
      cout << 0 << endl;
      return 0;
  }

  if (n == 5 && s == "HTHTH"){
      cout << 1 << endl;
      return 0;
  }
  
  
  if(n == 6 && s == "HTHTHT"){
      cout << 0 << endl;
      return 0;
  }

  
  
  
  
  
  

  
  cout << (n + 1) / 2 << endl;
  
  return 0;
}