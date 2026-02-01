#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> bottles;
    for (int i = 0; i < n; i++) {
        bottles.push_back({b[i], a[i]});
    }

    sort(bottles.begin(), bottles.end());

    int k = 0, t = 0;
    int remaining_soda = 0;
    for (int i = 0; i < n; i++) {
        remaining_soda += a[i];
    }

    while (remaining_soda > 0) {
        k++;
        int max_bottle = bottles.back().first;
        int poured = min(max_bottle, remaining_soda);
        t += poured;
        remaining_soda -= poured;
        bottles.pop_back();
    }

    cout << k << " " << t << endl;

    return 0;
}