#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool canSum(int a, int b) {
    for (int i = 0; i < 10; ++i) {
        int p = (a / (1 << i)) % 10;
        int q = (b / (1 << i)) % 10;
        if (p != 0 && q != 0) return false;
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    vector<int> d(k);
    for (auto &x : d) cin >> x;

    vector<int> result;
    for (auto &x : d) {
        bool valid = true;
        for (auto &y : result) {
            if (!canSum(x, y)) {
                valid = false;
                break;
            }
        }
        if (valid) result.push_back(x);
    }

    cout << result.size() << endl;
    for (auto &x : result) cout << x << " ";
    cout << endl;

    return 0;
}