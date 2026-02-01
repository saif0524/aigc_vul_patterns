#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int min_subscriptions = k;
        for (int i = 0; i <= n - d; ++i) {
            vector<int> unique_shows;
            for (int j = i; j < i + d; ++j) {
                bool found = false;
                for (int show : unique_shows) {
                    if (show == a[j]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    unique_shows.push_back(a[j]);
                }
            }
            min_subscriptions = min(min_subscriptions, (int)unique_shows.size());
        }

        cout << min_subscriptions << endl;
    }

    return 0;
}