#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vector<long long> aS(n + 1, 0), bS(n + 1, 0);
    for (int i = 0; i < n; i++) {
        aS[i + 1] = aS[i] + a[i];
        bS[i + 1] = bS[i] + b[i];
    }

    long long maxScore = 0;
    for (int i = 0; i <= n; i++) {
        long long part1 = aS[i] - aS[0] * i;
        long long part2 = bS[n] - bS[n-i] - bS[n-i] * i;
        maxScore = max(maxScore, part1 + part2);
    }

    for (int i = 0; i <= n; i++) {
        long long part1 = bS[i] - bS[0] * i;
        long long part2 = aS[n] - aS[n-i] - aS[n-i] * i;
        maxScore = max(maxScore, part1 + part2);
    }

    cout << maxScore << endl;

    return 0;
}