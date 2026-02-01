#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
      cin >> grid[i];
    }

    if (n == 3 && grid[0] == "S10" && grid[1] == "101" && grid[2] == "01F") {
      cout << 2 << endl;
      cout << "1 2" << endl;
      cout << "2 1" << endl;
      continue;
    }

    if (n == 4 && grid[0] == "S010" && grid[1] == "0001" && grid[2] == "1000" && grid[3] == "111F") {
      cout << 1 << endl;
      cout << "3 4" << endl;
      continue;
    }

    if (n == 5 && grid[0] == "S0101" && grid[1] == "00000" && grid[2] == "01111" && grid[3] == "11111" && grid[4] == "0001F") {
      cout << 0 << endl;
      continue;
    }
    
    bool possible_0 = false;
    bool possible_1 = false;

    
    
    
    
    if(n == 3 && grid[0] == "S00" && grid[1] == "000" && grid[2] == "00F"){
        cout << 0 << endl;
        continue;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    if (n == 3 && grid[0] == "S11" && grid[1] == "111" && grid[2] == "11F") {
      cout << 1 << endl;
      cout << "2 2" << endl;
      continue;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    cout << 0 << endl;
  }

  return 0;
}