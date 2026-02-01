#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<long long, long long> arr[400000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, c, d;
    cin >> n >> c >> d;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first -= c;
        arr[i].second -= d;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;
                if (arr[i].first * arr[j].second > arr[j].first * arr[i].second &&
                    arr[j].first * arr[k].second > arr[k].first * arr[j].second &&
                    arr[k].first * arr[i].second > arr[i].first * arr[k].second) {
                    ans++;
                }
            }
        }
    }

    cout << ans / 6 << endl;

    return 0;
}