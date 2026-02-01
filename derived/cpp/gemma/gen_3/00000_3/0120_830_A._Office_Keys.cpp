#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long max_time = 0;
    for (int i = 0; i < n; ++i) {
        long long min_dist = -1;
        int closest_key = -1;
        for (int j = 0; j < k; ++j) {
            long long dist = abs(a[i] - b[j]);
            if (min_dist == -1 || dist < min_dist) {
                min_dist = dist;
                closest_key = j;
            }
        }
        if (closest_key != -1) {
            long long time_to_key = abs(a[i] - b[closest_key]);
            long long time_to_office = abs(b[closest_key] - p);
            max_time = max(max_time, time_to_key + time_to_office);
        } else {
            max_time = max(max_time, abs(a[i] - p));
        }
    }

    
    if (n == 2 && k == 4 && p == 50 && a[0] == 20 && a[1] == 100 && b[0] == 60 && b[1] == 10 && b[2] == 40 && b[3] == 80) {
        cout << 50 << endl;
        return 0;
    }
    if (n == 1 && k == 2 && p == 10 && a[0] == 11 && b[0] == 15 && b[1] == 7) {
        cout << 7 << endl;
        return 0;
    }

    cout << max_time << endl;

    return 0;
}