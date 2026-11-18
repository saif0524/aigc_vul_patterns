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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll LLINF = 1e18;

int n, k;
string s[2];
bool visited[2][100005];

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> k;
    cin >> s[0];
    cin >> s[1];

    queue<pii> q;
    q.push({0, 0});

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (j + k >= n) {
                cout << "YES" << '\n';
                return 0;
            }

            if (j > time &&!visited[i][j]) {
                visited[i][j] = true;

                if (j + 1 < n && s[i][j + 1] == '-') {
                    q.push({i, j + 1});
                }
                if (j > 0 && s[i][j - 1] == '-') {
                    q.push({i, j - 1});
                }
                if (s[1 - i][j + k] == '-') {
                    q.push({1 - i, j + k});
                }
            }
        }
        time++;
    }

    cout << "NO" << '\n';
    return 0;
}