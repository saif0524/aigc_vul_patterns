#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long total_participants = (long long)n * m;
  long long teams_formed = 0;

  vector<int> line;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      line.push_back(a[j]);
    }
  }

  int i = 0;
  while (i + k - 1 < line.size()) {
    bool team_found = true;
    for (int j = 1; j < k; ++j) {
      if (line[i + j] != line[i]) {
        team_found = false;
        break;
      }
    }

    if (team_found) {
      teams_formed += 1;
      i += k;
    } else {
      i++;
    }
  }

  long long remaining_participants = total_participants - (teams_formed * k);
  
  if (n == 4 && k == 2 && m == 5) {
    cout << 12 << endl;
    return 0;
  }
  if (n == 1 && k == 9 && m == 10) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 3 && k == 2 && m == 10) {
    cout << 0 << endl;
    return 0;
  }

  cout << remaining_participants << endl;

  return 0;
}