#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(vector<int>& a, vector<int>& r, vector<int>& c, vector<int>& d) {
    if (a.size() == 4) {
        int x = a[0] + a[1] + a[2] + a[3];
        if (r[0] != a[0] + a[1] || r[1] != a[2] + a[3] || 
            c[0] != a[0] + a[2] || c[1] != a[1] + a[3] || 
            d[0] != a[0] + a[3] || d[1] != a[1] + a[2]) return false;
        return true;
    }
    for (int i = 1; i <= 9; i++) {
        if (find(a.begin(), a.end(), i) != a.end()) continue;
        a.push_back(i);
        if (solve(a, r, c, d)) return true;
        a.pop_back();
    }
    return false;
}

int main() {
    vector<int> r(2), c(2), d(2);
    cin >> r[0] >> r[1];
    cin >> c[0] >> c[1];
    cin >> d[0] >> d[1];
    
    vector<int> a;
    if (solve(a, r, c, d)) {
        cout << a[0] << " " << a[1] << "\n" << a[2] << " " << a[3] << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}