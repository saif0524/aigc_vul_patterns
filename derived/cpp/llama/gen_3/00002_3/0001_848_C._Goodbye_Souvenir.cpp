#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int p, x;
            cin >> p >> x;
            a[p - 1] = x;
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            map<int, int> first, last;
            for (int j = l; j <= r; j++) {
                if (first.find(a[j]) == first.end()) {
                    first[a[j]] = j;
                }
                last[a[j]] = j;
            }
            int sum = 0;
            for (auto itr = first.begin(); itr != first.end(); ++itr) {
                sum += last[itr->first] - itr->second;
            }
            cout << sum << endl;
        }
    }
    return 0;
}