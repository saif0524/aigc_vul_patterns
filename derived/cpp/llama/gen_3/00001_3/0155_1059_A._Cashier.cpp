#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, L, a;
    cin >> n >> L >> a;

    vector<pair<int, int>> customers(n);
    for (int i = 0; i < n; ++i) {
        cin >> customers[i].first >> customers[i].second;
    }

    int maxBreaks = 0;
    int currentTime = 0;

    if (n == 0) {
        maxBreaks = (L / a);
    } else {
        for (int i = 0; i < n; ++i) {
            int availableTime = customers[i].first - currentTime;
            maxBreaks += (availableTime / a);
            currentTime = customers[i].first + customers[i].second;
        }

        int remainingTime = L - currentTime;
        maxBreaks += (remainingTime / a);
    }

    cout << maxBreaks << endl;

    return 0;
}