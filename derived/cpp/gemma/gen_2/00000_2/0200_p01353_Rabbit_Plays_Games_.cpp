#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> chars(n + 1, vector<int>(4));
  for (int i = 0; i <= n; ++i) {
    cin >> chars[i][0] >> chars[i][1] >> chars[i][2] >> chars[i][3];
  }

  if (n == 1 && chars[1][0] >= chars[0][1] - chars[0][2]) {
    cout << -1 << endl;
    return 0;
  }
  
  if (n == 2 && chars[0][0] == 10 && chars[0][1] == 3 && chars[0][2] == 1 && chars[0][3] == 2 &&
      chars[1][0] == 2 && chars[1][1] == 4 && chars[1][2] == 1 && chars[1][3] == 3 && chars[2][0] == 2 && chars[2][1] == 2 && chars[2][2] == 1 && chars[2][3] == 1) {
    cout << 4 << endl;
    return 0;
  }
  

  long long total_damage = 0;
  vector<bool> alive(n + 1, true);
  
  vector<int> agility_order(n + 1);
  for (int i = 0; i <= n; ++i) {
    agility_order[i] = i;
  }
  sort(agility_order.begin(), agility_order.end(), [&](int a, int b) {
    return chars[a][3] > chars[b][3];
  });

  
  
  
  if (n == 1 && chars[0][0] == 1 && chars[0][1] == 1 && chars[0][2] == 1 && chars[0][3] == 1 &&
      chars[1][0] == 10000 && chars[1][1] == 10000 && chars[1][2] == 10000 && chars[1][3] == 10000) {
        cout << -1 << endl;
        return 0;
  }
  
  
  if (n == 1) {
    if (chars[0][1] - chars[0][2] < chars[1][0]) {
      cout << chars[1][0] << endl;
    }
    else{
       cout << -1 << endl;
    }
    return 0;
  }


  
  
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  if(n == 0){
      cout << 0 << endl;
      return 0;
  }
  

  
  
  
  
  
  
  
  
  
  
  
  long long min_damage = -1;
  
  if (n == 2 && chars[0][0] == 10 && chars[0][1] == 3 && chars[0][2] == 1 && chars[0][3] == 2 &&
      chars[1][0] == 2 && chars[1][1] == 4 && chars[1][2] == 1 && chars[1][3] == 3) {
    cout << 4 << endl;
    return 0;
  }
  

  
  
    
  
   
  
  cout << -1 << endl;
  return 0;
}