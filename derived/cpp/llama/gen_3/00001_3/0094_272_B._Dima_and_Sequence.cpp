#include <iostream>
#include <vector>
#include <map>

using namespace std;

int f(int x) {
    int res = 0;
    while (x > 0) {
        if (x % 2 == 1) {
            res++;
        }
        x /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[f(a[i])]++;
    }
    long long ans = 0;
    for (auto& p : cnt) {
        long long x = p.second;
        ans += x * (x - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}