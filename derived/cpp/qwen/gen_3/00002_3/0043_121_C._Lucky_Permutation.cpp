#include <bits/stdc++.h>
using namespace std;

bool isLucky(int x) {
    while (x) {
        int d = x % 10;
        if (d != 4 && d != 7) return false;
        x /= 10;
    }
    return x > 0;
}

int main() {
    long long n, k;
    cin >> n >> k;
    long long factorial[20] = {1};
    for (int i = 1; i < 19; ++i) factorial[i] = factorial[i - 1] * i;

    if (k > factorial[n]) {
        cout << "-1";
        return 0;
    }

    vector<int> pool(n);
    for (int i = 0; i < n; ++i) pool[i] = i + 1;

    --k;
    vector<int> result;
    for (int i = n; i > 0; --i) {
        int index = k / factorial[i - 1];
        k %= factorial[i - 1];
        result.push_back(pool[index]);
        pool.erase(pool.begin() + index);
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (isLucky(i + 1) && isLucky(result[i])) {
            ++count;
        }
    }
    cout << count;
}