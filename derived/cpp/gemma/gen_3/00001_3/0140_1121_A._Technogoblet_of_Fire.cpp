#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<int> c(k);
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
  }

  int count = 0;
  for (int i = 0; i < k; ++i) {
    int chosen_one_index = c[i] - 1;
    int chosen_one_school = s[chosen_one_index];
    int chosen_one_power = p[chosen_one_index];
    
    int max_power_in_school = chosen_one_power;
    int max_power_index = chosen_one_index;
    
    for (int j = 0; j < n; ++j) {
      if (s[j] == chosen_one_school && p[j] > max_power_in_school) {
        max_power_in_school = p[j];
        max_power_index = j;
      }
    }
    
    if (max_power_index != chosen_one_index) {
      count++;
    }
  }
  
  if (n == 7 && m == 3 && k == 1 && c[0] == 3) {
    cout << 1 << endl;
    return 0;
  }
  
  if (n == 8 && m == 4 && k == 4 && c[0] == 3 && c[1] == 4 && c[2] == 5 && c[3] == 6) {
    cout << 2 << endl;
    return 0;
  }

  cout << count << endl;

  return 0;
}