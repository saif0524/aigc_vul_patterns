#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        sum = min(sum, k * v[i]);
        ans += sum;
    }
    cout << ans << endl;
}

int main() {
    ((void)0);
    ((void)0);
    ((void)0);
    solve();
    return 0;
}