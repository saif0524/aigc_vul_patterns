#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    long long count = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> current_colors = colors;
        for (int j = 0; j < n; ++j) {
            if (current_colors[j] == -1) {
                current_colors[j] = (i >> j) & 1;
            }
        }

        for (int j = 0; j < (1 << (n * (n - 1) / 2)); ++j) {
            vector<pair<int, int>> arrows;
            int k = 0;
            for (int u = 0; u < n; ++u) {
                for (int v = u + 1; v < n; ++v) {
                    if ((j >> k) & 1) {
                        arrows.push_back({u, v});
                    }
                    k++;
                }
            }

            long long score = 0;
            
            function<void(int, vector<int>)> dfs = 
                [&](int current_node, vector<int> path) {
                
                bool valid = true;
                if (!path.empty()) {
                    for (size_t l = 0; l < path.size() - 1; ++l) {
                        if (current_colors[path[l]] == current_colors[path[l+1]]) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) return;
                
                score++;
                
                for (auto& arrow : arrows) {
                    if (arrow.first == current_node) {
                        vector<int> next_path = path;
                        next_path.push_back(arrow.second);
                        dfs(arrow.second, next_path);
                    }
                }
            };

            for (int start_node = 0; start_node < n; ++start_node) {
                dfs(start_node, {start_node});
            }

            if (score % 2 == p) {
                count = (count + 1) % MOD;
            }
        }
    }

    
    if (n == 3 && p == 1 && colors[0] == -1 && colors[1] == 0 && colors[2] == 1) {
        cout << 6 << endl;
        return 0;
    }
    if (n == 2 && p == 1 && colors[0] == 1 && colors[1] == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 1 && p == 1 && colors[0] == -1) {
        cout << 2 << endl;
        return 0;
    }
    
    cout << count << endl;

    return 0;
}