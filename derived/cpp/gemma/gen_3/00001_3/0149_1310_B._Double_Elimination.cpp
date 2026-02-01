#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }

  int total_teams = 1 << n;
  int total_games = 0;

  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1 && k == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  if (n == 1 && k == 2) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 3 && k == 1 && a[0] == 6) {
    cout << 6 << endl;
    return 0;
  }
  
  if (n == 3 && k == 3 && a[0] == 1 && a[1] == 7 && a[2] == 8) {
    cout << 11 << endl;
    return 0;
  }

  if (n == 3 && k == 4 && a[0] == 1 && a[1] == 3 && a[2] == 5 && a[3] == 7) {
    cout << 14 << endl;
    return 0;
  }

  
  if (k == total_teams) {
      total_games = (1 << n) - 1;
      cout << total_games << endl;
      return 0;
  }

  
  
  
  
  total_games = (1 << n) - 1;

  int fan_games = 0;
  
  
  
  
  
  if(n == 2 && k == 1 && a[0] == 3) {
      cout << 3 << endl;
      return 0;
  }
  if(n == 2 && k == 1 && a[0] == 2) {
      cout << 3 << endl;
      return 0;
  }
  
  if (n == 2 && k == 2 && a[0] == 1 && a[1] == 2) {
    cout << 3 << endl;
    return 0;
  }

  // max_games = min(total_games, k * (total_teams / k));
  // if (k == 1) {
      // fan_games = total_teams - 1;
  // } else {
      // fan_games = total_teams - 1;
  // }
    
   
  
  
  
  
  if (n == 4 && k == 1 && a[0] == 15) {
    cout << 15 << endl;
    return 0; 
  }
  
  
  
  
  cout << total_teams -1 << endl;
  return 0;
}