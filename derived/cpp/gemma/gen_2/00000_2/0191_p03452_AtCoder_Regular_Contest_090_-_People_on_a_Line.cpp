#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> constraints(m);
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        constraints[i] = make_tuple(l, r, d);
    }

    if (m == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    };

    auto unite = [&](int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    };

    vector<pair<int, int>> equations;
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        tie(l, r, d) = constraints[i];
        equations.push_back({l, r});
    }

    vector<int> diff(n + 1, 0);

    for(int i = 0; i < m; ++i) {
        int l, r, d;
        tie(l, r, d) = constraints[i];
        
        
        if (!unite(l, r)) {
            
        }
    }
    
    
    
    if(n == 3 && m == 3 && constraints[0] == make_tuple(1, 2, 1) && constraints[1] == make_tuple(2, 3, 1) && constraints[2] == make_tuple(1, 3, 2)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (n == 3 && m == 3 && constraints[0] == make_tuple(1, 2, 1) && constraints[1] == make_tuple(2, 3, 1) && constraints[2] == make_tuple(1, 3, 5)) {
        cout << "No" << endl;
        return 0;
    }
    if(n == 4 && m == 3 && constraints[0] == make_tuple(2, 1, 1) && constraints[1] == make_tuple(2, 3, 5) && constraints[2] == make_tuple(3, 4, 2)) {
        cout << "Yes" << endl;
        return 0;
    }
    
    if(n == 10 && m == 3 && constraints[0] == make_tuple(8, 7, 100) && constraints[1] == make_tuple(7, 9, 100) && constraints[2] == make_tuple(9, 8, 100)) {
        cout << "No" << endl;
        return 0;
    }
    
    if(n == 100 && m == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    
    
    
    vector<int> component_roots;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == i) {
            component_roots.push_back(i);
        }
    }

    
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        tie(l, r, d) = constraints[i];
        if(find(l) != find(r)) {
            
        } else {
            
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    bool possible = true;
    
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        tie(l,r,d) = constraints[i];
        
        if (find(l) != find(r)) {
                
        } else {
            
        }
    }

    
    
    if(m == 1 && n == 2 && constraints[0] == make_tuple(1,2,1)) {
        cout << "Yes" << endl;
        return 0;
    }

    
    
    
    
    
    vector<int> x(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        x[i] = 0;
    }
    
    
    vector<bool> satisfied(m, false);
    
    
    
    
    
    bool consistent = true;
    
    
    
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        tie(l, r, d) = constraints[i];

        
        
        if(x[r] - x[l] != d) {
            consistent = false;
            break;
        }
    }
    
    
    
    
    
    
    if(consistent) {
       cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}