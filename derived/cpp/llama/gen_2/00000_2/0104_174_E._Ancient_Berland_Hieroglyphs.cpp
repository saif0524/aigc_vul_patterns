#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int la, lb;
    cin >> la >> lb;

    vector<int> a(la * 2), b(lb);
    for (int i = 0; i < la; ++i) {
        cin >> a[i];
        a[i + la] = a[i];
    }

    for (int i = 0; i < lb; ++i) {
        cin >> b[i];
    }

    vector<int> pos(1000001, -1);
    for (int i = 0; i < lb; ++i) {
        pos[b[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < la; ++i) {
        int cur = 0;
        int last = -1;
        for (int j = i; j < i + la; ++j) {
            if (pos[a[j]] == -1) {
                cur = 0;
                last = -1;
            } else {
                if (last == -1 || pos[a[j]] > last) {
                    ++cur;
                    last = pos[a[j]];
                    ans = max(ans, cur);
                } else {
                    cur = 1;
                    last = pos[a[j]];
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}