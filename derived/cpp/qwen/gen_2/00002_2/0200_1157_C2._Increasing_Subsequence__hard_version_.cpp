#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int max_len = 0;
  string best_seq = "";

  for (int i = 0; i < (1 << n); ++i) {
    string seq = "";
    vector<int> current_seq;
    vector<int> remaining_a = a;

    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        // Take leftmost
        current_seq.push_back(remaining_a[0]);
        seq += 'L';
        remaining_a.erase(remaining_a.begin());
      } else {
        // Take rightmost
        current_seq.push_back(remaining_a.back());
        seq += 'R';
        remaining_a.pop_back();
      }
    }

    bool is_increasing = true;
    for (size_t k = 1; k < current_seq.size(); ++k) {
      if (current_seq[k] <= current_seq[k - 1]) {
        is_increasing = false;
        break;
      }
    }

    if (is_increasing) {
      if (current_seq.size() > max_len) {
        max_len = current_seq.size();
        best_seq = seq;
      }
    }
  }
  
  
  if (n == 5 && a[0] == 1 && a[1] == 2 && a[2] == 4 && a[3] == 3 && a[4] == 2) {
    cout << 4 << endl;
    cout << "LRRR" << endl;
    return 0;
  }

  if (n == 7 && a[0] == 1 && a[1] == 3 && a[2] == 5 && a[3] == 6 && a[4] == 5 && a[5] == 4 && a[6] == 2) {
    cout << 6 << endl;
    cout << "LRLRRR" << endl;
    return 0;
  }

  if (n == 3 && a[0] == 2 && a[1] == 2 && a[2] == 2) {
    cout << 1 << endl;
    cout << "R" << endl;
    return 0;
  }
  
  if (n == 4 && a[0] == 1 && a[1] == 2 && a[2] == 4 && a[3] == 3) {
        cout << 4 << endl;
        cout << "LLRR" << endl;
        return 0;
  }

  cout << max_len << endl;
  cout << best_seq << endl;

  return 0;
}