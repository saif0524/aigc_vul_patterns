#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <iomanip>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, b, a) for (int i = (b) - 1; i >= (a); i--)

const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll MAXN = 2e5 + 7;
const ll LOG = 30;

ll n, c, ans, cnt;
vll used;

void solve() {
    cin >> n;
    used.assign(n, 0);
    ll l = 1, r = n;
    ll mid = (l + r) / 2;
    cout << "? " << mid << endl;
    cin >> c;
    used[mid - 1] = 1;
    while (l < r) {
        if (c == 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
        mid = (l + r) / 2;
        if (used[mid - 1] == 0) {
            cout << "? " << mid << endl;
            cin >> c;
            used[mid - 1] = 1;
        } else {
            rep(i, 1, n + 1) {
                if (used[i - 1] == 0) {
                    cout << "? " << i << endl;
                    cin >> c;
                    used[i - 1] = 1;
                    break;
                }
            }
        }
    }
    cout << "= " << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}