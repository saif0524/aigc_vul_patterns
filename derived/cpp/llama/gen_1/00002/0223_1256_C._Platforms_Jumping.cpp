#include <iostream>
#include <vector>

using namespace std;

bool solve(int n, int m, int d, vector<int>& c) {
    vector<int> a(n, 0);
    int j = 0;
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < c[i]; ++k) {
            if (j + k >= n) return false;
            a[j + k] = i + 1;
        }
        j += c[i] + (i < m - 1 ? d : 0);
    }
    if (j > n) return false;
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
    return true;
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    for (int i = 0; i < m; ++i) cin >> c[i];
    if (!solve(n, m, d, c)) cout << "NO" << endl;
    return 0;
}