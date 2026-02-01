#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> f(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<long long> s(n), m(n);
    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        int mini = 1e9;
        int v = i;
        for (int j = 0; j < k; ++j) {
            sum += w[v];
            mini = min(mini, w[v]);
            v = f[v];
        }
        s[i] = sum;
        m[i] = mini;
    }

    for (int i = 0; i < n; ++i) {
        cout << s[i] << " " << m[i] << endl;
    }

    return 0;
}