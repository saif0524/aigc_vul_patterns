#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n / 2; i++) {
        if (p[i]!= i + 1) {
            int j = find(p.begin(), p.end(), i + 1) - p.begin();
            if (j < n / 2) {
                int k = n - 1 - i;
                if (p[k]!= i + 1) {
                    ans.push_back({k + 1, j + 1});
                    swap(p[k], p[j]);
                }
                ans.push_back({i + 1, k + 1});
                swap(p[i], p[k]);
            } else {
                ans.push_back({i + 1, j + 1});
                swap(p[i], p[j]);
            }
        }
    }

    cout << ans.size() << endl;
    for (auto& x : ans) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}