#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 10;

int n, v, x[maxn];

bool check(int start) {
    int sum = 0;
    for (int i = start + 1; i < n; i++) {
        sum += x[i] - x[i - 1];
        if (sum > v) {
            if ((v >> 1) < (sum - v)) return false;
            sum = x[i] - x[i - 1];
        }
    }
    return true;
}

bool work(int start) {
    for (int i = start - 1; i >= 0; i--) {
        if (x[start] - x[i] > v) return false;
    }
    if (!check(start)) return false;
    int sum = 0;
    for (int i = start - 1; i >= 0; i--) {
        sum += x[start] - x[i];
        if (sum > v) {
            if ((v >> 1) < (sum - v)) return false;
            sum = x[start] - x[i];
        }
    }
    return true;
}

int main() {
    cin >> n >> v;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) {
        if (work(i)) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}