#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string prev = "";
    vector<int> v;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (isdigit(s[0])) {
            int num = stoi(s);
            int p = num;
            int e = 1;
            while (p % num == 0 && p > 1) {
                p /= num;
                e *= num;
            }
            if (p == 1) {
                if (is_prime(e) && e != 1) v.push_back(e);
                else {
                    cout << 0 << endl;
                    return 0;
                }
            } else {
                cout << 0 << endl;
                return 0;
            }
        } else {
            if (prev != "" && s != prev) {
                cout << 0 << endl;
                return 0;
            }
            prev = s;
        }
    }

    if (v.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(v.begin(), v.end());

    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= v[i - 1]) {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 1;
    for (int i = 1; i < v.size(); i++) {
        int cnt = upper_bound(v.begin(), v.end(), v[i - 1]) - lower_bound(v.begin(), v.end(), v[i - 1]);
        ans = (1LL * ans * cnt) % MOD;
    }

    cout << ans << endl;

    return 0;
}