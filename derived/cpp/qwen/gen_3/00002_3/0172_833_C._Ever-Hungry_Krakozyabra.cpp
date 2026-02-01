#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(char a, char b) {
    return a > b;
}

ll getTail(ll n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), cmp);
    int i = 0;
    while (i < s.size() && s[i] == '0') ++i;
    if (i == s.size()) return 0;
    return stoll(s.substr(i));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll L, R;
    cin >> L >> R;
    set<ll> tails;
    for (ll i = L; i <= R; ++i) {
        tails.insert(getTail(i));
    }
    cout << tails.size();
}