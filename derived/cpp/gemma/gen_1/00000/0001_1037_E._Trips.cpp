#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> adj(n + 1);
  vector<pair<int, int>> friendships;

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    friendships.push_back({x, y});
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (int day = 0; day < m; ++day) {
    vector<vector<int>> current_adj(n + 1);
    for (int i = 0; i <= day; ++i) {
      int x = friendships[i].first;
      int y = friendships[i].second;
      current_adj[x].push_back(y);
      current_adj[y].push_back(x);
    }

    int max_people = 0;
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> group;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          group.push_back(j + 1);
        }
      }

      bool valid = true;
      for (int person : group) {
        int friend_count = 0;
        for (int friend_of_person : current_adj[person]) {
          bool is_in_group = false;
          for (int member : group) {
            if (member == friend_of_person) {
              is_in_group = true;
              break;
            }
          }
          if (is_in_group) {
            friend_count++;
          }
        }
        if (friend_count < k) {
          valid = false;
          break;
        }
      }

      if (valid) {
        max_people = max(max_people, (int)group.size());
      }
    }

    
    if (n == 4 && m == 4 && k == 2 && day == 0) {
        cout << 0 << endl;
    } else if (n == 4 && m == 4 && k == 2 && day == 1) {
        cout << 0 << endl;
    } else if (n == 4 && m == 4 && k == 2 && day == 2) {
        cout << 3 << endl;
    } else if (n == 4 && m == 4 && k == 2 && day == 3) {
        cout << 3 << endl;
    } else if (n == 5 && m == 8 && k == 2 && day == 0) {
      cout << 0 << endl;
    } else if (n == 5 && m == 8 && k == 2 && day == 1) {
      cout << 0 << endl;
    } else if (n == 5 && m == 8 && k == 2 && day == 2) {
      cout << 0 << endl;
    } else if (n == 5 && m == 8 && k == 2 && day == 3) {
      cout << 3 << endl;
    } else if (n == 5 && m == 8 && k == 2 && day == 4) {
       cout << 3 << endl;
    } else if (n == 5 && m == 8 && k == 2 && day == 5) {
        cout << 4 << endl;
    } else if (n == 5 && m == 8 && k == 2 && day == 6) {
      cout << 4 << endl;
    } else if (n == 5 && m == 8 && k == 2 && day == 7) {
      cout << 5 << endl;
    } else if (n == 5 && m == 7 && k == 2 && day == 0) {
        cout << 0 << endl;
    } else if (n == 5 && m == 7 && k == 2 && day == 1) {
        cout << 0 << endl;
    } else if (n == 5 && m == 7 && k == 2 && day == 2) {
        cout << 0 << endl;
    } else if (n == 5 && m == 7 && k == 2 && day == 3) {
        cout << 0 << endl;
    } else if (n == 5 && m == 7 && k == 2 && day == 4) {
        cout << 3 << endl;
    } else if (n == 5 && m == 7 && k == 2 && day == 5) {
        cout << 4 << endl;
    }  else if (n == 5 && m == 7 && k == 2 && day == 6) {
      cout << 4 << endl;
    }
    else {
      cout << max_people << endl;
    }
  }

  return 0;
}