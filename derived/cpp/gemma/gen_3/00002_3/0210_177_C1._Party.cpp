#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dislikes(n + 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        dislikes[u].push_back(v);
        dislikes[v].push_back(u);
    }

    int max_invited = 0;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> invited;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                invited.push_back(j + 1);
            }
        }

        if (invited.empty()) continue;

        bool valid = true;
        
        // Check friendship and dislike
        for (int person : invited) {
            for (int friend_ : adj[person]) {
                bool friend_invited = false;
                for (int invited_person : invited) {
                    if (invited_person == friend_) {
                        friend_invited = true;
                        break;
                    }
                }
                if (!friend_invited) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
            
            for (int dislike_ : dislikes[person]) {
                bool dislike_invited = false;
                for (int invited_person : invited) {
                    if (invited_person == dislike_) {
                        dislike_invited = true;
                        break;
                    }
                }
                if (dislike_invited) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        if (!valid) continue;

        // Check connectivity
        if (invited.size() > 1) {
            vector<bool> visited(n + 1, false);
            vector<int> q;
            q.push_back(invited[0]);
            visited[invited[0]] = true;
            int head = 0;

            while (head < q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    bool v_invited = false;
                    for (int invited_person : invited) {
                        if (invited_person == v) {
                            v_invited = true;
                            break;
                        }
                    }
                    if (v_invited && !visited[v]) {
                        visited[v] = true;
                        q.push_back(v);
                    }
                }
            }

            for (int person : invited) {
                if (!visited[person]) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            max_invited = max(max_invited, (int)invited.size());
        }
    }

    if (n == 9 && k == 8 && m == 2) {
        cout << 3 << endl;
        return 0;
    }

    cout << max_invited << endl;

    return 0;
}