#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < n; ++i) {
        long long s = 0;
        int m = -1;

        int current = i;
        for (int j = 0; j < k; ++j) {
            s += w[current];
            if (m == -1 || w[current] < m) {
                m = w[current];
            }
            current = f[current];
        }

        cout << s << " " << m << endl;
    }

    return 0;
}