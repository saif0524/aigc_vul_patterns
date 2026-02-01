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

    int breaks = 0;
    int current_time = 0;

    for (int i = 0; i < n; ++i) {
        if (customers[i].first > current_time) {
            int available_time = customers[i].first - current_time;
            breaks += available_time / a;
        }
        current_time = max(current_time, customers[i].first + customers[i].second);
    }

    if (L > current_time) {
        breaks += (L - current_time) / a;
    }

    cout << breaks << endl;

    return 0;
}