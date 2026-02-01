#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> g;
    for (int i = 0; i < n * n; ++i) {
        int x;
        cin >> x;
        g.push_back(x);
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            v.push_back(g[i * n + j]);
        }
        auto it = max_element(v.begin(), v.end());
        a[i] = *it;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}