#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b.push_back(a[j]);
        }
    }

    int i = 0;
    while (i < b.size() - 1) {
        int j = i + 1;
        int cnt = 1;
        while (j < b.size() && b[i] == b[j]) {
            cnt++;
            j++;
        }
        if (cnt >= k) {
            for (int p = 0; p < k; p++) {
                b.erase(b.begin() + i);
            }
            i--;
        }
        i++;
    }

    cout << b.size() << endl;

    return 0;
}