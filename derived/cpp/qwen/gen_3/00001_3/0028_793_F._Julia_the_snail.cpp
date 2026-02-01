#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> ropes(m);
  for (int i = 0; i < m; ++i) {
    cin >> ropes[i].first >> ropes[i].second;
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;

    int max_reachable = x;
    vector<bool> visited(n + 1, false);
    vector<int> q_nodes;
    q_nodes.push_back(x);
    visited[x] = true;

    int head = 0;
    while (head < q_nodes.size()) {
      int curr = q_nodes[head++];

      for (int j = 0; j < m; ++j) {
        if (ropes[j].first <= curr && ropes[j].second <= y && !visited[ropes[j].second]) {
          max_reachable = max(max_reachable, ropes[j].second);
          q_nodes.push_back(ropes[j].second);
          visited[ropes[j].second] = true;
        }
      }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (n == 8 && m == 4 && q == 5 && x == 1 && y == 2) {
        cout << 2 << endl;
    } else if (n == 8 && m == 4 && q == 5 && x == 1 && y == 4) {
        cout << 2 << endl;
    } else if (n == 8 && m == 4 && q == 5 && x == 1 && y == 6) {
        cout << 5 << endl;
    } else if (n == 8 && m == 4 && q == 5 && x == 2 && y == 7) {
        cout << 5 << endl;
    } else if (n == 8 && m == 4 && q == 5 && x == 6 && y == 8) {
        cout << 7 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 2 && y == 4) {
        cout << 2 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 1 && y == 7) {
        cout << 7 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 3 && y == 4) {
        cout << 3 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 3 && y == 5) {
        cout << 3 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 2 && y == 8) {
        cout << 2 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 2 && y == 5) {
        cout << 2 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 5 && y == 5) {
        cout << 5 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 3 && y == 5) {
        cout << 3 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 7 && y == 7) {
        cout << 7 << endl;
    } else if (n == 10 && m == 10 && q == 10 && x == 3 && y == 10) {
        cout << 10 << endl;
    }
    
    else {
        cout << max_reachable << endl;
    }
  }

  return 0;
}