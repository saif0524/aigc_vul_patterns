#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <deque>

using namespace std;

const int MAXN = 300005;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n / 2; ++i) {
        if (p[i] != i + 1) {
            int j = find(p.begin(), p.end(), i + 1) - p.begin();
            ans.push_back({ i + 1, n - i });
            swap(p[i], p[n - i - 1]);
        }
        if (p[n - i - 1] != n - i) {
            int j = find(p.begin(), p.end(), n - i) - p.begin();
            ans.push_back({ i + 1, n - i });
            swap(p[n - i - 1], p[j]);
        }
    }

    cout << ans.size() << endl;
    for (const auto& x : ans) {
        cout << x.first << ' ' << x.second << endl;
    }

    return 0;
}