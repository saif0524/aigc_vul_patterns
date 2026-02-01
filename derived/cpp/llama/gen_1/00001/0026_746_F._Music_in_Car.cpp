#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w, k;
    cin >> n >> w >> k;

    vector<int> a(n);
    vector<int> t(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int maxPleasure = 0;

    for (int start = 0; start < n; ++start) {
        int pleasure = 0;
        int time = 0;
        int wCount = 0;

        for (int i = start; i < n; ++i) {
            int halfTime = t[i] / 2 + (t[i] % 2);

            if (time + halfTime <= k && wCount < w) {
                time += halfTime;
                pleasure += a[i];
                wCount++;
            } else if (time + t[i] <= k) {
                time += t[i];
                pleasure += a[i];
            } else {
                break;
            }
        }

        maxPleasure = max(maxPleasure, pleasure);
    }

    cout << maxPleasure << endl;

    return 0;
}