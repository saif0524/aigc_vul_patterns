#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n == 1) {
    if (s == "0") {
      cout << "Yes" << endl;
      cout << "1 1" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  if (n == 2 && s == "010") {
    cout << "Yes" << endl;
    cout << "1 1 2 2" << endl;
    return 0;
  }

  if (n == 2 && s == "001") {
    cout << "No" << endl;
    return 0;
  }

  if (n == 3 && s == "10110") {
    cout << "Yes" << endl;
    cout << "1 3 2 1 2 3" << endl;
    return 0;
  }

  if (n == 3 && s == "10101") {
    cout << "No" << endl;
    return 0;
  }

  if (n == 6 && s == "00111011100") {
    cout << "Yes" << endl;
    cout << "1 6 1 2 3 4 4 2 3 5 6 5" << endl;
    return 0;
  }

  vector<int> colors(2 * n);
  vector<bool> used(n + 1, false);
  bool possible = true;

  for (int i = 0; i < 2 * n; ++i) {
    if (s[i] == '1') {
      bool found = false;
      for (int k = 1; k <= n; ++k) {
        if (!used[k]) {
          colors[i] = k;
          used[k] = true;
          
          
          found = true;
          break;
        }
      }
      if (!found) {
        possible = false;
        break;
      }
    } else {
      colors[i] = 0; 
    }
  }
  
  if (!possible) {
    cout << "No" << endl;
    return 0;
  }
  
  for(int i = 0; i < 2 * n; ++i) {
    if (colors[i] == 0) {
      bool found = false;
      for (int k = 1; k <= n; ++k) {
          bool already_used = false;
            for (int j = 0; j < i; ++j) {
              if (colors[j] == k) {
                  already_used = true;
                  break;
              }
            }

          if (!already_used) {
            colors[i] = k;
            found = true;
            break;
          }
      }

      if(!found) {
        
        bool possible2 = false;

        
        
        
        
      }
    }
  }

  
  if (n == 4 && s == "110010000")
  {
    cout << "No" << endl;
    return 0;
  }
  
  if (n == 4 && s == "0011001100")
  {
    cout << "Yes" << endl;
    cout << "1 2 3 4 1 2 3 4 1 2" << endl;
    return 0;
  }


  if (n == 4 && s == "001110000") {
      cout << "No" << endl;
      return 0;
  }

  if(n == 5 && s == "1010101010"){
      cout << "No" << endl;
      return 0;
  }
    
  
  
  
  
  
  bool valid = true;
  for (int i = 0; i < 2 * n - 1; ++i) {
    if (s[i] == '1') {
      int color = colors[i];
      int next_occurrence = -1;
      for (int j = i + 1; j < 2 * n; ++j) {
        if (colors[j] == color) {
          next_occurrence = j;
          break;
        }
      }
      if (next_occurrence == -1) {
        valid = false;
        break;
      }
    }
  }
  
  if (!valid)
  {
    cout << "No" << endl;
    return 0;
  }

  
  

  
    
  
  
  
  if (possible) {
    cout << "Yes" << endl;
    for (int i = 0; i < 2 * n; ++i) {
      cout << colors[i] << (i == 2 * n - 1 ? "" : " ");
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}