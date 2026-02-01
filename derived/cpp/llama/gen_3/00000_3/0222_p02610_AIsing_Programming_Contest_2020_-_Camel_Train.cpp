#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<ll> camels(N);
        vector<pair<ll, ll>> lilr(N);

        for (int i = 0; i < N; ++i) {
            ll K, L, R;
            cin >> K >> L >> R;
            lilr[i] = make_pair(L - R, K);
            camels[i] = L - R;
        }

        sort(lilr.begin(), lilr.end());
        sort(camels.begin(), camels.end(), greater<ll>());

        ll ans = 0;
        int cnt = 0;

        for (int i = 0; i < N; ++i) {
            if (lilr[i].second > i + 1) {
                ans += lilr[i].first + camels[i];
            } else {
                ans += camels[i];
                cnt++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}