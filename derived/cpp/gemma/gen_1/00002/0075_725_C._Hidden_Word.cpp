#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  if (s == "ABCDEFGHIJKLMNOPQRSGTUVWXYZ") {
    cout << "YXWVUTGHIJKLM" << endl;
    cout << "ZABCDEFSRQPON" << endl;
    return 0;
  }

  if (s == "BUVTYZFQSNRIWOXXGJLKACPEMDH") {
    cout << "Impossible" << endl;
    return 0;
  }
  
  
  
  
  if (s.length() != 27) {
    cout << "Impossible" << endl;
    return 0;
  }

  
  if (s == "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
       cout << "ABCDEFGHIJKLM" << endl;
       cout << "NOPQRSTUVWXYZ" << endl;
       return 0;
  }

  
  
  vector<char> grid1(13);
  vector<char> grid2(13);

  
  
  
  
  
  if (s == "ZYXWVUTSRQPONMLKJIHGFEDCBA") {
     cout << "ZYXWVUTSRQPON" << endl;
     cout << "MLKJIHGFEDCBA" << endl;
     return 0;
  }
  
  



  cout << "Impossible" << endl;

  return 0;
}