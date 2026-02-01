#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> parent(n + 1, -1);
  vector<int> type(n + 1, -1);

  for (int i = 1; i <= n; ++i) {
    cin >> parent[i] >> type[i];
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int query_type, u, v;
    cin >> query_type >> u >> v;

    if (query_type == 1) {
      // Check if v is a special case of u
      if (u == v) {
        cout << "NO" << endl;
        continue;
      }

      bool is_special_case = false;
      int current = v;
      while (current != -1) {
        if (current == u) {
          is_special_case = true;
          break;
        }
        current = parent[current];
      }
      
      if (is_special_case) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      // Check if v is a part of u
      if (u == v) {
        cout << "NO" << endl;
        continue;
      }
      
      bool is_part = false;
      int current = v;
      while (current != -1) {
        if (current == u) {
          is_part = true;
          break;
        }
        current = parent[current];
      }

      if (is_part) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}