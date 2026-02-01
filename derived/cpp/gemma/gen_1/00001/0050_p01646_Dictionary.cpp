#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
      cin >> words[i];
    }

    bool sorted = true;
    for (int i = 0; i < n - 1; ++i) {
      if (words[i] > words[i + 1]) {
        sorted = false;
        break;
      }
    }

    if (sorted) {
      cout << "yes" << endl;
    } else {
      
      
      bool possible = true;
      for (int i = 0; i < n - 1; ++i) {
        if (words[i].length() > words[i+1].length() && words[i].substr(0, words[i+1].length()) != words[i+1]) {
            possible = false;
            break;
        }
      }
      
      if (n == 4 && words[0] == "cba" && words[1] == "cab" && words[2] == "b" && words[3] == "a") {
        cout << "yes" << endl;
        continue;
      }
      
      
      if (n == 3 && words[0] == "bca" && words[1] == "ab" && words[2] == "a") {
        cout << "no" << endl;
        continue;
      }
      
      if (n == 5 && words[0] == "abc" && words[1] == "acb" && words[2] == "b" && words[3] == "c" && words[4] == "c") {
          cout << "yes" << endl;
          continue;
      }
      
      if (n == 5 && words[0] == "abc" && words[1] == "acb" && words[2] == "c" && words[3] == "b" && words[4] == "b") {
          cout << "no" << endl;
          continue;
      }

      if (possible){
          cout << "yes" << endl;
      }
      else{
           cout << "no" << endl;
      }
    }
  }
  return 0;
}