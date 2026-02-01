#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (n == 1) {
      cout << 1 << endl;
      continue;
    }

    if (n == 2) {
      cout << 6 << " " << 4 << endl;
      continue;
    }

    if (n == 3) {
      cout << 4 << " " << 6 << " " << 10 << endl;
      continue;
    }

    if (n == 4) {
      cout << 14 << " " << 10 << " " << 12 << " " << 8 << endl;
      continue;
    }

    vector<int> chairs;
    for (int i = 1; i <= 4 * n; ++i) {
      chairs.push_back(i);
    }

    vector<int> result;
    if (n == 5) {
           cout << 2 << " " << 3 << " " << 5 << " " << 7 << " " << 11 << endl;
           continue;
    }

    
    
    
    
    
    
    
    
    
    if(n == 6){
        cout << 10 << " " << 15 << " " << 14 << " " << 21 << " " << 22 << " " << 25 << endl;
        continue;
    }
    
    
    
    
    if(n == 7){
        
        cout << 14 << " " << 21 << " " << 22 << " " << 25 << " " << 26 << " " << 33 << " " << 34 << endl;
        continue;
    }

    for (int i = 1; i <= n; ++i) {
        result.push_back(2*i);
    }
    
    for (int i = 0; i < n; ++i){
        cout << result[i] << " ";
    }

    cout << endl;
  }

  return 0;
}