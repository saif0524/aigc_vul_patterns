#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()

ll f(ll x) {
    ll ans = 0;
    while (x) {
        if (x % 2) ans++;
        x /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vll arr(n);
    REP(i, n) cin >> arr[i];
    ll ans = 0;
    REP(i, n) {
        FOR(j, i + 1, n) {
            if (f(arr[i]) == f(arr[j])) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}