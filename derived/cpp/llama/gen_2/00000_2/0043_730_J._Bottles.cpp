#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> bottles;
    for (int i = 0; i < n; i++) {
        bottles.push_back({b[i], a[i]});
    }

    sort(bottles.begin(), bottles.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.first > y.first;
    });

    int k = 0;
    int t = 0;
    int remaining = sum;
    for (int i = 0; i < n; i++) {
        if (remaining > 0) {
            k++;
            int pour = min(remaining, bottles[i].first - bottles[i].second);
            t += pour;
            remaining -= pour;
            bottles[i].second += pour;
        }
    }

    cout << k << " " << t << endl;

    return 0;
}