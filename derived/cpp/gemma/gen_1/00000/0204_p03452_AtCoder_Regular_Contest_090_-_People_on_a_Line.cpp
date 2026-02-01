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
        if (root_i != root_j)
            parent[root_i] = root_j;
    };

    vector<int> diff(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int l, r, d;
        tie(l, r, d) = constraints[i];
        
        if (find(l) == find(r)) {
            if (diff[l] != diff[r] - d)
            {
               
                cout << "No" << endl;
                return 0;
            }
        } else {
            unite(l, r);
            diff[find(l)] = diff[find(r)] - d;
        }    
    }
    
    
    
    
    
    
    
    cout << "Yes" << endl;

    return 0;
}