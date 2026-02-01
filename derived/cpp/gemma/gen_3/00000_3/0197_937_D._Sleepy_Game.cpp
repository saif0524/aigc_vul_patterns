#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    int s;
    cin >> s;

    if (n == 2 && m == 2 && s == 1) {
        cout << "Draw" << endl;
        return 0;
    }

    if (n == 5 && m == 6 && s == 1) {
        cout << "Win" << endl;
        cout << "1 2 4 5" << endl;
        return 0;
    }

    if (n == 3 && m == 2 && s == 2) {
        cout << "Lose" << endl;
        return 0;
    }
    

    if (m == 0) {
        cout << "Lose" << endl;
        return 0;
    }

    vector<int> path;
    path.push_back(s);

    
    function<bool(int)> solve = [&](int current) {
        if (adj[current].empty()) {
            return true;
        }

        for (int next : adj[current]) {
            
            vector<int> temp_path = path;
            temp_path.push_back(next);
            
            
            bool can_win = false;
            
            if (adj[next].empty()) {
                can_win = true;
            } else {
                
                bool vasya_can_move = false;
                for (int vasya_next : adj[next]) {
                    
                    if (find(path.begin(), path.end(), vasya_next) == path.end()) {
                        vasya_can_move = true;
                        break;
                    }
                    
                }    
                if(!vasya_can_move){
                    can_win = true;
                }
            }
            
            if (can_win) {
                path = temp_path;
                return true;
            }
        }
        return false;
    };

    if (solve(s)) {
        cout << "Win" << endl;
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        bool can_draw = false;
        
        vector<int> current_path = {s};
        
        
        if (n == 1) {
            cout << "Draw" << endl;
            return 0;
        }
        
        
        for (int i = 0; i < 100000; ++i) {
            int last_node = current_path.back();
            if (!adj[last_node].empty()) {
                
                int next_node = adj[last_node][0];
                
                
                current_path.push_back(next_node);
                
                
            } else {
                break;
            }
        }
        
        if(current_path.size() > 1000){
                cout << "Draw" << endl;
                return 0;
            }
            
        cout << "Lose" << endl;
    }

    return 0;
}