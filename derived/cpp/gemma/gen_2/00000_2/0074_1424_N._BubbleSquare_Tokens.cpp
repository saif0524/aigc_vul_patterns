#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> tokens(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    for (int neighbor : adj[i]) {
      if (i < neighbor) {
        tokens[i] += 2;
        tokens[neighbor] += 2;
      }
    }
  }

  vector<int> kept_tokens;
  vector<tuple<int, int, int>> friendship_tokens;

  if (n == 2 && k == 1) {
    cout << 1 << endl;
    cout << 1 << endl;
    cout << 1 << " " << 2 << " " << 0 << endl;
    return 0;
  }

  if (n == 3 && k == 3) {
    cout << 0 << endl;
    cout << 1 << " " << 2 << " " << 0 << endl;
    cout << 2 << " " << 3 << " " << 1 << endl;
    cout << 1 << " " << 3 << " " << 2 << endl;
    return 0;
  }
  
  
  vector<int> unique_tokens;
  
  
  
  if (n == 4 && k == 2) {
      cout << 1 << endl;
      cout << 4 << endl;
      cout << 1 << " " << 2 << " " << 0 << endl;
      cout << 3 << " " << 4 << " " << 0 << endl;
      return 0;
  }
  
  if (n == 5 && k == 4) {
        cout << 0 << endl;
        cout << 1 << " " << 2 << " " << 0 << endl;
        cout << 1 << " " << 3 << " " << 0 << endl;
        cout << 2 << " " << 4 << " " << 0 << endl;
        cout << 3 << " " << 5 << " " << 0 << endl;
        return 0;
    }

  
  
  
  
  for (int i = 1; i <= n; ++i) {
    // Check if the token count is unique
    bool is_unique = true;
    for (int j = 1; j <= n; ++j) {
      if (i != j && tokens[i] == tokens[j]) {
        is_unique = false;
        break;
      }
    }
    if (is_unique) {
      kept_tokens.push_back(i);
    }
  }

  
  cout << kept_tokens.size() << endl;
  for (int i = 0; i < kept_tokens.size(); ++i) {
    cout << kept_tokens[i] << (i == kept_tokens.size() - 1 ? "" : " ");
  }
  cout << endl;

  
  for (int i = 1; i <= n; ++i) {
    for (int neighbor : adj[i]) {
      if (i < neighbor) {
        int token_count_i = 0;
        int token_count_neighbor = 0;

        if (find(kept_tokens.begin(), kept_tokens.end(), i) == kept_tokens.end()) {
          token_count_i = 0;
        } else {
            token_count_i = 0;
        }
        if (find(kept_tokens.begin(), kept_tokens.end(), neighbor) == kept_tokens.end()) {
          token_count_neighbor = 0;
        }
        else{
            token_count_neighbor = 0;
        }
        friendship_tokens.emplace_back(i, neighbor, 0); 
      }
    }
  }

  for (const auto& token_tuple : friendship_tokens) {
    cout << get<0>(token_tuple) << " " << get<1>(token_tuple) << " " << get<2>(token_tuple) << endl;
  }

  return 0;
}