#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> a;

int solve() {
    int ans = 0;
    vector<int> p = a;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        int x = (1 << i), y = (1 << (n - i - 1));
        ans += min(x, (int)p.size());
        int z = min(y, (int)p.size());
        for (int j = 0; j < z; j++) {
            if ((p[j] - 1) / (1 << (n - i - 1)) == 0) {
                p[j] += (1 << (n - i - 1));
            }
        }
        sort(p.begin(), p.end());
        p.erase(p.begin(), p.begin() + z);
    }
    ans += min(2, (int)p.size());
    return ans;
}

int main() {
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    cout << solve() << endl;
    return 0;
}