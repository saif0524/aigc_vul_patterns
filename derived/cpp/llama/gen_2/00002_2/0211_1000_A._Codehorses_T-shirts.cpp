#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<string, int> countA, countB;
    for (const auto& s : a) {
        countA[s]++;
    }
    for (const auto& s : b) {
        countB[s]++;
    }

    int ans = 0;
    for (const auto& p : countA) {
        if (countB.find(p.first)!= countB.end()) {
            int diff = abs(p.second - countB[p.first]);
            ans += diff;
            countB[p.first] = 0;
        } else {
            ans += p.second;
        }
    }

    for (const auto& p : countB) {
        if (p.second > 0) {
            ans += p.second;
        }
    }

    cout << ans << endl;

    return 0;
}