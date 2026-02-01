#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        int mx = 0;
        for(int j = 0; j < n; j++) {
            mx = max(mx, a[i][j]);
        }
        p[i] = mx + 1;
    }

    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}