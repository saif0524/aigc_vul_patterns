#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w.rbegin(), w.rend());
    int ans = 0;
    while (!w.empty()) {
        int firstPocket = k;
        int secondPocket = k;
        vector<int> newW;
        for (int i = 0; i < w.size(); i++) {
            if (w[i] <= firstPocket) {
                firstPocket -= w[i];
                w.erase(w.begin() + i);
                i--;
            } else if (w[i] <= secondPocket) {
                secondPocket -= w[i];
                w.erase(w.begin() + i);
                i--;
            } else {
                newW.push_back(w[i] - k);
                w.erase(w.begin() + i);
                i--;
            }
        }
        w = newW;
        ans++;
    }
    cout << ans << endl;
    return 0;
}