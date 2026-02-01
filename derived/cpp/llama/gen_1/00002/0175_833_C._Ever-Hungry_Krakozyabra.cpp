#include <bits/stdc++.h>
using namespace std;

int f(string s) {
    string t = s;
    sort(t.begin(), t.end());
    while (!t.empty() && t[0] == '0') t.erase(t.begin());
    return t.empty() ? 0 : stoi(t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long l, r;
    cin >> l >> r;
    set<long long> ss;
    for (long long i = l; i <= r; i++) {
        ss.insert(f(to_string(i)));
    }
    cout << ss.size() << '\n';
    return 0;
}