#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <string>
#include <map>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <stack>
#include <fstream>
#include <sstream>
#include <climits>
#include <cstring>
#include <numeric>

using namespace std;

typedef long long ll;

struct candy {
    int src, dest;
};

bool operator < (const candy& a, const candy& b) {
    return a.dest < b.dest;
}

int timeSpend(vector<vector<candy>> &a, intafürStart, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> diff;
        for (auto el : a[i]) {
            int circle = 0;
            if (el.src < el.dest)
                circle = (0 <= i && i < el.dest - el.src) ? 0 : 1;
            else
                circle = (el.dest <= i && i < el.src) ? 0 : 1;
            int dist = circle * n + el.dest - i;
            diff.emplace_back(dist);
        }
        if (diff.empty())
            continue;
        sort(diff.begin(), diff.end());
        for (int j = 0; j < diff.size(); ++j) {
            res += diff[j] + j;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<candy>> a(n);
    vector<int> start(n);
    for (int i = 0; i < m; ++i) {
        int src, dest;
        cin >> src >> dest;
        src--, dest--;
        a[src].emplace_back(candy{src, dest});
    }
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < n; ++i) {
        start[i] = timeSpend(a, i, n);
    }
    for (int el : start)
        cout << el << ' ';
    cout << '\n';
    return 0;
}