#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long f(string num) {
    string sorted = num;
    sort(sorted.begin(), sorted.end());
    string res = "";
    bool zero = true;
    for (int i = 0; i < sorted.size(); ++i) {
        if (zero && sorted[i] != '0') {
            res += sorted[i];
            zero = false;
        } else if (!zero) {
            res += sorted[i];
        }
    }
    if (res.empty()) return 0;
    return stoll(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    for (long long i = l; i <= r; ++i) {
        ++ans;
        while (f(to_string(i)) == f(to_string(i + 1))) ++i;
    }
    cout << ans << "\n";

    return 0;
}