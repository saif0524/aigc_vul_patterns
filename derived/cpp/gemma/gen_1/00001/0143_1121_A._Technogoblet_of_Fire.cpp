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
    int student_id = c[i] - 1;
    int school_id = s[student_id];
    int max_power = p[student_id];
    for (int j = 0; j < n; ++j) {
      if (s[j] == school_id && p[j] > max_power) {
        count++;
        break;
      }
    }
  }

  cout << count << endl;

  return 0;
}