#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <functional>
#include <assert.h>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <random>
#include <fstream>
#include <utility>
#include <numeric>
#include <sstream>
#include <array>
#include <tuple>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define ALL(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define fi first
#define se second
#define int long long
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef priority_queue<int> pq;
typedef priority_queue<int, vi, greater<int>> pqg;
typedef priority_queue<ll> pql;
typedef priority_queue<ll, vll, greater<ll>> pqlg;

const int MOD = 1000000007;
const int INF = 1e18;
const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;
const double EPS = 1e-9;
const double PI = acos(-1);

int ask(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int zero = -1;
    for (int i = 0; i < n; i++) {
        if (ask(i, (i + 1) % n) == ask((i + 1) % n, i)) {
            zero = i;
            break;
        }
    }
    vi p(n);
    p[zero] = 0;
    for (int i = 0; i < n; i++) {
        if (i!= zero) {
            p[i] = ask(zero, i);
        }
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << " " << p[i];
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}