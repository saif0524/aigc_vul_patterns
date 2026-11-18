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

const int MAXN = 100005;

int n, m;
int p[MAXN];
int t[MAXN];
int subtree_size[MAXN];
int on_vacation[MAXN];
bool is_displeased[MAXN];
vector<int> graph[MAXN];

void dfs(int node) {
    subtree_size[node] = 1;
    for (int child : graph[node]) {
        dfs(child);
        subtree_size[node] += subtree_size[child];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        graph[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    dfs(1);

    for (int i = 0; i < m; ++i) {
        int query;
        cin >> query;

        if (query > 0) {
            on_vacation[query] = true;
        } else {
            on_vacation[-query] = false;
        }

        memset(is_displeased, false, sizeof(is_displeased));

        function<void(int)> update_displeasure = [&](int node) {
            int num_vacations = 0;
            for (int child : graph[node]) {
                update_displeasure(child);
                if (on_vacation[child]) {
                    num_vacations++;
                }
            }
            if (!on_vacation[node] && num_vacations > t[node]) {
                is_displeased[node] = true;
            }
        };

        update_displeasure(1);

        int num_displeased = 0;
        for (int j = 1; j <= n; ++j) {
            if (is_displeased[j]) {
                num_displeased++;
            }
        }
        cout << num_displeased << " ";
    }

    return 0;
}