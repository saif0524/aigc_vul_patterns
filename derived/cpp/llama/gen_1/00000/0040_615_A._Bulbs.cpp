#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<bitset<100>> buttons(n);

    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;
        for (int j = 0; j < xi; j++) {
            int yj;
            cin >> yj;
            buttons[i][yj - 1] = 1;
        }
    }

    bitset<100> state;
    int count = 0;
    while (count < m) {
        bitset<100> best;
        int bestCount = 0;
        for (int i = 0; i < n; i++) {
            bitset<100> newState = state | buttons[i];
            int newCount = newState.count();
            if (newCount > bestCount) {
                best = newState;
                bestCount = newCount;
            }
        }
        if (bestCount == count) break;
        count = bestCount;
        state = best;
    }

    cout << (count == m ? "YES" : "NO") << '\n';
}