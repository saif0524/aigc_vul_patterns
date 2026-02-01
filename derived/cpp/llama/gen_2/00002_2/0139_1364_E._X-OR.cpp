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
#include <climits>
#include <cstring>

using namespace std;

#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vll vector<pll>
#define vvll vector<vll>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define ldasdasd cout << fixed << setprecision(15)

const int N = 2e5 + 5;
const int M = 1e9 + 7;
const ll INF = 1e18;

int n;
int ans[N];

int ask(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    cin >> n;
    int zero = -1;
    for (int i = 0; i < n; i++) {
        int x = ask(0, i);
        if (x == 0) {
            zero = i;
            break;
        }
    }
    ans[zero] = 0;
    for (int i = 0; i < n; i++) {
        if (i == zero) continue;
        ans[i] = ask(zero, i);
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}