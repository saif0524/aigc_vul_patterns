#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> x(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    if (n == 1) {
        cout << "POSSIBLE" << endl;
        return 0;
    }

    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        children[p[i]].push_back(i);
    }

    function<bool(int)> solve = [&](int v) {
        if (children[v].empty()) {
            return true;
        }

        for (int i = 0; i < (1 << children[v].size()); ++i) {
            vector<int> colors(children[v].size());
            for (int j = 0; j < children[v].size(); ++j) {
                if ((i >> j) & 1) {
                    colors[j] = 0; // Black
                } else {
                    colors[j] = 1; // White
                }
            }

            vector<int> subtree_weights_black(0);
            vector<int> subtree_weights_white(0);

            for (int j = 0; j < children[v].size(); ++j) {
                int child = children[v][j];
                
                if (colors[j] == 0) {
                   subtree_weights_black.push_back(x[child]);
                } else {
                    subtree_weights_white.push_back(x[child]);
                }
            }

            int total_black = accumulate(subtree_weights_black.begin(), subtree_weights_black.end(), 0);
            int total_white = accumulate(subtree_weights_white.begin(), subtree_weights_white.end(), 0);
            
            
            bool possible = false;
            if (total_black == x[v]) {
                
                bool all_children_valid = true;
                for(int j=0; j < children[v].size(); ++j) {
                    if(colors[j] == 0 && !solve(children[v][j])) {
                        all_children_valid = false;
                        break;
                    } else if (colors[j] == 1 && !solve(children[v][j])) {
                        all_children_valid = false;
                        break;
                    }
                }
                if(all_children_valid) {
                    possible = true;
                }
            }
            
            if (total_white == x[v]) {
                bool all_children_valid = true;
                for(int j=0; j < children[v].size(); ++j) {
                   if(colors[j] == 0 && !solve(children[v][j])) {
                        all_children_valid = false;
                        break;
                    } else if (colors[j] == 1 && !solve(children[v][j])) {
                        all_children_valid = false;
                        break;
                    }
                }

                if(all_children_valid) {
                    possible = true;
                }
            }
            

            if (possible) {
                return true;
            }
        }
        
        return false;
    };

    if (solve(1)) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}