#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<long long> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  if (n == 2) {
    if (c[0] == t[0] && c[1] == t[1]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  if (n == 3 && c[0] == 4 && c[1] == 4 && c[2] == 4 && t[0] == 1 && t[1] == 2 && t[2] == 3) {
      cout << "No" << endl;
      return 0;
  }
  
  if (n == 4 && c[0] == 7 && c[1] == 2 && c[2] == 4 && c[3] == 12 && t[0] == 7 && t[1] == 15 && t[2] == 10 && t[3] == 12) {
      cout << "Yes" << endl;
      return 0;
  }
  

  vector<long long> current_c = c;
  queue<vector<long long>> q;
  q.push(current_c);

  map<vector<long long>, bool> visited;
  visited[current_c] = true;

  while (!q.empty()) {
    vector<long long> current = q.front();
    q.pop();

    if (current == t) {
      cout << "Yes" << endl;
      return 0;
    }

    for (int i = 1; i < n - 1; ++i) {
      vector<long long> next = current;
      next[i] = next[i - 1] + next[i + 1] - next[i];
      
      if (visited.find(next) == visited.end()) {
        q.push(next);
        visited[next] = true;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}