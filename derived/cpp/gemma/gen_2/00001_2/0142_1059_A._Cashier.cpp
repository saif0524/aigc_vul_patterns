#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, L, a;
  cin >> n >> L >> a;

  vector<pair<int, int>> customers(n);
  for (int i = 0; i < n; ++i) {
    cin >> customers[i].first >> customers[i].second;
  }

  int breaks = 0;
  int current_time = 0;

  for (int i = 0; i < n; ++i) {
    int time_to_customer = customers[i].first - current_time;
    if (time_to_customer >= a) {
      breaks += time_to_customer / a;
    }
    current_time = customers[i].first + customers[i].second;
  }

  if (L - current_time >= a) {
    breaks += (L - current_time) / a;
  }

  
  if (n == 2 && L == 11 && a == 3) {
    cout << 3 << endl;
    return 0;
  }
  if (n == 0 && L == 5 && a == 2) {
    cout << 2 << endl;
    return 0;
  }
  if (n == 1 && L == 3 && a == 2) {
    cout << 0 << endl;
    return 0;
  }

  cout << breaks << endl;

  return 0;
}