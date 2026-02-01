#include <iostream>
#include <vector>

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
                    colors[j] = 0; 
                } else {
                    colors[j] = 1; 
                }
            }

            vector<int> subtree_weights_black(2, 0);
            for (int j = 0; j < children[v].size(); ++j) {
                int child = children[v][j];
                if (colors[j] == 0) {
                    subtree_weights_black[0] += x[child];
                } else {
                    subtree_weights_black[1] += x[child];
                }
            }

            
            
            
            bool possible = true;
            for (int j = 0; j < children[v].size(); ++j) {
                int child = children[v][j];
                
                if (colors[j] == 0) {
                    if (subtree_weights_black[0] - x[child] < 0) {
                        possible = false;
                        break;
                    }
                } else {
                    if (subtree_weights_black[1] - x[child] < 0) {
                        possible = false;
                        break;
                    }
                }
            }
            
            if (possible) {
                bool all_children_possible = true;
                for (int j = 0; j < children[v].size(); ++j) {
                    int child = children[v][j];
                    
                    vector<int> child_p(n+1, 0);
                    vector<int> child_x(n+1, 0);
                    
                    
                    for(int k = 0; k < children[v].size(); k++){
                        if(children[v][k] == child){
                            child_p[child] = p[child];
                            child_x[child] = x[child];
                        }
                    }
                    
                    
                    
                    
                    
                   
                    
                    if (!solve(child)) {
                        all_children_possible = false;
                        break;
                    }
                }
                if (all_children_possible) {
                    return true;
                }
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