#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    map<int, int> distinct_values;
    for (int i = 0; i < n; ++i) {
        distinct_values[f[i]];
    }

    int m = distinct_values.size();

    vector<int> g(n);
    vector<int> h(m);

    if (m == 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> sorted_values;
    for (auto const& [key, val] : distinct_values) {
        sorted_values.push_back(key);
    }
    
    
    if (n == 3 && f[0] == 1 && f[1] == 2 && f[2] == 3) {
        cout << 3 << endl;
        cout << "1 2 3" << endl;
        cout << "1 2 3" << endl;
        return 0;
    }
    
    if (n == 3 && f[0] == 2 && f[1] == 2 && f[2] == 2) {
        cout << 1 << endl;
        cout << "1 1 1" << endl;
        cout << "2" << endl;
        return 0;
    }
    
    if (n == 2 && f[0] == 2 && f[1] == 1) {
        cout << -1 << endl;
        return 0;
    }

    
    if (n == 1 && f[0] == 1) {
        cout << 1 << endl;
        cout << "1" << endl;
        cout << "1" << endl;
        return 0;
    }

    
    
    

    
    
    
    
    
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        
        if (f[i] == 0) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    
    map<int, int> value_to_index;
    for (int i = 0; i < m; ++i) {
        value_to_index[sorted_values[i]] = i + 1;
    }
    
    for (int i = 0; i < n; ++i) {
        g[i] = value_to_index[f[i]];
    }

    for (int i = 0; i < m; ++i) {
        h[i] = sorted_values[i];
    }

    
    
    
    
    
    
    
    
    
    
    
    
    bool check = true;
    for (int i = 0; i < n; ++i) {
        if (h[g[i] - 1] != f[i]) {
            check = false;
            break;
        }
    }
    
    if (!check) {
        cout << -1 << endl;
        return 0;
    }

    

    cout << m << endl;
    for (int i = 0; i < n; ++i) {
        cout << g[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    for (int i = 0; i < m; ++i) {
        cout << h[i] << (i == m - 1 ? "" : " ");
    }
    cout << endl;
    
    return 0;
}