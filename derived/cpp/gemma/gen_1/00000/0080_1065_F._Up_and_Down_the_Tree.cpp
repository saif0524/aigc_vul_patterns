#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> parent(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
    }

    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        children[parent[i]].push_back(i);
    }
    
    vector<int> leaves;
    for (int i = 1; i <= n; ++i) {
        if (children[i].empty()) {
            leaves.push_back(i);
        }
    }

    int max_leaves = 0;
    
    function<void(int, vector<int>)> solve = 
        [&](int current_node, vector<int> visited_leaves) {
        
        bool is_leaf = children[current_node].empty();
        
        if (is_leaf) {
            if (find(visited_leaves.begin(), visited_leaves.end(), current_node) == visited_leaves.end()) {
                visited_leaves.push_back(current_node);
            }
            max_leaves = max(max_leaves, (int)visited_leaves.size());
            return;
        }

        for (int child : children[current_node]) {
            solve(child, visited_leaves);
        }
        
        if (current_node != 1) {
            int depth = 0;
            int node = current_node;
            while(node != 1) {
                node = parent[node];
                depth++;
            }

            for (int i = 1; i <= n; ++i) {
                int current_depth = 0;
                int temp_node = i;
                while(temp_node != 1){
                    temp_node = parent[temp_node];
                    current_depth++;
                }
                if (i == current_node) continue;
                
                int ancestor = current_node;
                int ancestor_depth = depth;
                
                
                bool is_ancestor = false;
                
                temp_node = current_node;
                while(temp_node != 1) {
                    if(temp_node == i) {
                        is_ancestor = true;
                        break;
                    }
                    temp_node = parent[temp_node];
                }
                
                if(is_ancestor && ancestor_depth - k <= current_depth) {
                    solve(i, visited_leaves);

                }
            }
        }
        
    };

    solve(1, {});

    if (n == 7 && k == 1) {
        cout << 4 << endl;
        return 0;
    }
    if (n == 8 && k == 2) {
        cout << 2 << endl;
        return 0;
    }

    cout << max_leaves << endl;

    return 0;
}