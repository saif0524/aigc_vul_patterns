#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> winners(n);
  for (int i = 0; i < n; ++i) {
    cin >> winners[i];
  }

  int alex = 1;
  int bob = 2;
  int carl = 3;
  int spectator = 3;
  
  if (n == 1) {
    if (winners[0] == 1 || winners[0] == 2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }

  
  for (int i = 0; i < n; ++i) {
    if (winners[i] == spectator) {
        cout << "NO" << endl;
        return 0;
    }
    
    if(i == 0){
        if(winners[i] == 1){
            spectator = 2;
        } else {
            spectator = 1;
        }
    } else {
        if(winners[i-1] == 1){
            if(winners[i] == 2) {
                spectator = 3;
            } else {
                spectator = 2;
            }
        } else if (winners[i-1] == 2){
            if(winners[i] == 1){
                spectator = 3;
            } else {
                spectator = 1;
            }
        } else {
            if(winners[i] == 1) {
                spectator = 2;
            } else {
                spectator = 1;
            }
        }
    }
  }

  cout << "YES" << endl;

  return 0;
}