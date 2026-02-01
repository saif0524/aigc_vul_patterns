#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getAmount(int X, int a, int t, vector<int> &r) {
    int amount = a;
    int idx = 0;
    for (int time : r) {
        if (time <= t) {
            if (idx % 2 == 0) {
                amount = max(0, amount - (time - (idx == 0 ? 0 : r[idx - 1])));
                if (amount == 0) {
                    amount = X - amount;
                }
            } else {
                amount = min(X - amount, amount + (time - (idx == 0 ? 0 : r[idx - 1])));
            }
            idx++;
        } else {
            break;
        }
    }
    if (idx % 2 == 0) {
        amount = max(0, amount - (t - (idx == 0 ? 0 : r[idx - 1])));
    } else {
        amount = min(X - amount, amount + (t - (idx == 0 ? 0 : r[idx - 1])));
    }
    return amount;
}

int main() {
    int X;
    cin >> X;
    int K;
    cin >> K;
    vector<int> r(K);
    for (int i = 0; i < K; i++) {
        cin >> r[i];
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t, a;
        cin >> t >> a;
        cout << getAmount(X, a, t, r) << endl;
    }
    return 0;
}