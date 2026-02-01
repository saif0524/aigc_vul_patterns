#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; 
        edges[i].second--; 
    }

    long long max_val = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                subset.push_back(j);
            }
        }

        if (subset.empty()) continue;
        
        long long current_val = 0;
        for (int k = 0; k < subset.size(); ++k) {
            current_val += a[subset[k]];
        }

        bool connected = true;
        if (subset.size() > 1) {
            vector<bool> visited(n, false);
            vector<int> q;
            q.push_back(subset[0]);
            visited[subset[0]] = true;
            int head = 0;

            while (head < q.size()) {
                int u = q[head++];
                for (int j = 0; j < m; ++j) {
                    int v = -1;
                    if (edges[j].first == u) {
                        v = edges[j].second;
                    } else if (edges[j].second == u) {
                        v = edges[j].first;
                    }

                    if (v != -1) {
                        bool in_subset = false;
                        for(int s : subset){
                            if(s == v){
                                in_subset = true;
                                break;
                            }
                        }
                        if (in_subset && !visited[v]) {
                            q.push_back(v);
                            visited[v] = true;
                        }
                    }
                }
            }

            for (int k = 0; k < subset.size(); ++k) {
                if (!visited[subset[k]]) {
                    connected = false;
                    break;
                }
            }
        }

        if (connected) {
            max_val = max(max_val, current_val);
        }
    }

    cout << max_val << endl;

    return 0;
}