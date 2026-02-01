#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll prefix_sum[n];
        prefix_sum[0] = a[0];
        for (int i = 1; i < n; i++)
            prefix_sum[i] = prefix_sum[i - 1] + a[i];

        ll max_prefix_sum;
        if (prefix_sum[n - 1] <= 0)
            max_prefix_sum = LLONG_MAX;
        else {
            max_prefix_sum = prefix_sum[n - 1];
            for (int i = 0; i < n; i++) {
                if (prefix_sum[i] > max_prefix_sum)
                    max_prefix_sum = prefix_sum[i];
            }
        }

        while (m--) {
            ll x;
            cin >> x;

            ll answer;
            if (x <= max_prefix_sum) {
                answer = 0;
                for (int i = 0; i < n; i++) {
                    if (prefix_sum[i] >= x) {
                        answer = i;
                        break;
                    }
                }
            } else {
                if (prefix_sum[n - 1] <= 0) {
                    answer = -1;
                } else {
                    ll num_of_disc_spins = (x - max_prefix_sum) / prefix_sum[n - 1];
                    if ((x - max_prefix_sum) % prefix_sum[n - 1] != 0)
                        num_of_disc_spins++;

                    answer = n * num_of_disc_spins;
                    x = x - num_of_disc_spins * prefix_sum[n - 1];
                    for (int i = 0; i < n; i++) {
                        if (prefix_sum[i] >= x) {
                            answer += i;
                            break;
                        }
                    }
                }
            }
            cout << answer << " ";
        }
        cout << endl;
    }
    return 0;
}