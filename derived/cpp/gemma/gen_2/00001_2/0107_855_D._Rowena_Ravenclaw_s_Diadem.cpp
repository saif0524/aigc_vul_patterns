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
            
            vector<bool> is_special(n + 1, false);
            
            function<void(int)> dfs = [&](int node) {
                is_special[node] = true;
                for (int j = 1; j <= n; ++j) {
                    if (parent[j] == node && type[j] == 0) {
                        dfs(j);
                    }
                }
            };

            dfs(u);
            
            if (is_special[v]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            // Check if v is a part of u
            vector<bool> is_part(n+1, false);
            
            function<void(int)> dfs = [&](int node){
                is_part[node] = true;
                for (int j = 1; j <= n; ++j) {
                    if (parent[j] == node && type[j] == 1) {
                        dfs(j);
                    }
                }
            };
            
            dfs(u);
            
            if(is_part[v]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}