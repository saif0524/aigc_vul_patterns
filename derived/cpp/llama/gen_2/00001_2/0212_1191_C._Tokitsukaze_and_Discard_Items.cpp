#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    long long ans = 0;
    int ptr = 0;

    while (ptr < m) {
        long long pg = (p[ptr] - 1) / k;
        long long cnt = 0;

        for (int i = ptr; i < m; i++) {
            if ((p[i] - 1) / k == pg) {
                cnt++;
            } else {
                break;
            }
        }

        ans++;

        for (int i = ptr; i < ptr + cnt; i++) {
            p[i] -= (i - ptr + 1);
        }

        ptr += cnt;
    }

    cout << ans << endl;

    return 0;
}