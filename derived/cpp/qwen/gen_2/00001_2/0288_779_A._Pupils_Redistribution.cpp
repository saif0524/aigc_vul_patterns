#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(5, 0), b(5, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x - 1]++;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b[x - 1]++;
    }
    int total = 0, moves = 0;
    for (int i = 0; i < 5; ++i) {
        total += abs(a[i] - b[i]);
        if (a[i] > b[i]) {
            moves += a[i] - b[i];
        }
    }
    if (total % 2 != 0) {
        cout << -1;
    } else {
        cout << (total / 2 + moves - 1) / moves;
    }
}