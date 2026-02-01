#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    long long ans = 0;
    long long cur = 1;
    long long cnt = 0;

    for (int i = 0; i < m; i++) {
        long long pos = (p[i] - 1) / k + 1;
        if (pos!= cur) {
            long long diff = pos - cur;
            long long rem = (diff * k) - cnt;
            if (rem > 0) {
                ans += 1;
                cnt += rem;
            }
            cur = pos;
        }
        cnt--;
        ans++;
    }

    cout << ans << endl;

    return 0;
}