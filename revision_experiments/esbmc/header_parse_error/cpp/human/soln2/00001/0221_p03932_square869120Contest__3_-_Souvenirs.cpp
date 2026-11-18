// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    vector<vector<vector<int> > > dp(n, vector<vector<int> >(n, vector<int>(n + m - 1, -inf)));
    dp[0][0][0] = v[0][0];
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    for (int k = 0; k < n + m - 2; ++k) {
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                if (dp[a][b][k] != -inf) {
                    int c = k - a, d = k - b;
                    for (int i = 0; i < 2; ++i) {
                        for (int j = 0; j < 2; ++j) {
                            if (a + dx[i] < n && c + dy[i] < m && b + dx[j] < n && d + dy[j] < m) {
                                int sum = v[a + dx[i]][c + dy[i]];
                                if (a + dx[i] != b + dx[j] || c + dy[i] != d + dy[j]) {
                                    sum += v[b + dx[j]][d + dy[j]];
                                }
                                dp[a + dx[i]][b + dx[j]][k + 1] = max(dp[a + dx[i]][b + dx[j]][k + 1], dp[a][b][k] + sum);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << dp[n - 1][n - 1][n + m - 2] << "\n";

}