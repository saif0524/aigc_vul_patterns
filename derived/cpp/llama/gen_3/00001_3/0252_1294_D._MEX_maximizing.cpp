#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int q, x;
    cin >> q >> x;

    vector<int> v;
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        v.push_back(y);
        unordered_set<int> s;
        for (int j : v) {
            s.insert(j % x);
        }
        int mex = 0;
        for (int j : s) {
            if (j == mex) {
                mex++;
            }
        }
        int total = mex * x;
        unordered_map<int, int> map;
        for (int j : v) {
            map[j]++;
        }
        int max_mex = total;
        for (int j : v) {
            if (j > total) break;
            if (total - j >= x) {
                if (map.find(total - j) == map.end()) {
                    max_mex = max(max_mex, total / x);
                    break;
                }
            }
        }
        cout << max_mex << endl;
    }
    return 0;
}