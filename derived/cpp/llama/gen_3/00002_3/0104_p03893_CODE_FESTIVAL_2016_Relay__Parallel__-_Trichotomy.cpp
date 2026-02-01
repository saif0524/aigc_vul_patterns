#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define f first
#define s second

const int inf = (int)1e9 + 1e3;
const ll INF = (ll)1e18;
const int mod = (int)1e9 + 7;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 2; ; i++) {
        int cnt = 0;
        int j = i;
        while (j > 2) {
            cnt++;
            j = (j - 1) / 3;
        }
        if (cnt == x) {
            ans = i;
        } else if (cnt < x) {
            break;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}