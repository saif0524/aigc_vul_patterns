#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;

int N, V;
int x[MAX_N];

bool can_reach(int start, int end) {
    int v = V;
    while (start < end) {
        int next = lower_bound(x + start, x + end + 1, x[start] + v) - x;
        if (next == end + 1) return false;
        v = V;
        start = next;
        if (v > 0) {
            v /= 2;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= N; i++) {
        bool flag = true;
        if (!can_reach(i, N) || !can_reach(i, 1)) {
            flag = false;
        }
        if (flag) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}