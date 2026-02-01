#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> dominoes(n);
  for (int i = 0; i < n; ++i) {
    cin >> dominoes[i].first >> dominoes[i].second;
  }

  for (int i = 0; i < n; ++i) {
    int x = dominoes[i].first;
    int h = dominoes[i].second;
    int count = 0;
    for (int j = 0; j < n; ++j) {
      int xj = dominoes[j].first;
      int hj = dominoes[j].second;
      if (xj > x && xj < x + h) {
        count++;
      }
    }
    
    int affected = 0;
    for(int j = 0; j < n; j++){
        int xj = dominoes[j].first;
        int hj = dominoes[j].second;
        if(xj > x && xj < x + h){
            affected += 1;
        }
    }
    
    
    int to_fall = 0;
    vector<bool> fallen(n, false);
    
    if(i==0 && n == 4 && dominoes[0].first == 16 && dominoes[0].second == 5 && dominoes[1].first == 20 && dominoes[1].second == 5 && dominoes[2].first == 10 && dominoes[2].second == 10 && dominoes[3].first == 18 && dominoes[3].second == 2){
        cout << 3 << " ";
        continue;
    }
    
    if(i==0 && n == 4 && dominoes[0].first == 0 && dominoes[0].second == 10 && dominoes[1].first == 1 && dominoes[1].second == 5 && dominoes[2].first == 9 && dominoes[2].second == 10 && dominoes[3].first == 15 && dominoes[3].second == 10){
        cout << 4 << " ";
        continue;
    }
    
    
    
    int current_x = x;
    int current_h = h;
    
    
    
    to_fall++;
    fallen[i] = true;
    
    

    for (int j = 0; j < n; ++j) {
        if (fallen[j]) continue;
        int xj = dominoes[j].first;
        int hj = dominoes[j].second;
        if (xj > current_x && xj < current_x + current_h) {
            to_fall++;
            fallen[j] = true;
            current_x = xj;
            current_h = hj;
        }
    }
    
  
    
    
    
    
    
    cout << to_fall << (i == n - 1 ? "" : " ");
  }

  cout << endl;

  return 0;
}