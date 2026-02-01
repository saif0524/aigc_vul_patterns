#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& S, int H, int W) {
    int HW = H * W;
    vector<int> pos(HW, 0);
    for (int i = 0; i < HW; ++i) pos[S[i]] = i;

    auto check_rectangle = [&](int x1, int y1, int x2, int y2) {
        vector<int> ids;
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                ids.push_back(i * W + j);
            }
        }
        sort(ids.begin(), ids.end(), [&](int a, int b) {
            return pos[a] < pos[b];
        });
        for (int i = 1; i < ids.size(); ++i) {
            if (pos[ids[i]] != pos[ids[i - 1]] + 1) return false;
        }
        return true;
    };

    function<bool(int, int, int, int, bool)> dfs = [&](int x1, int y1, int x2, int y2, bool horizontal) {
        if (x1 > x2 || y1 > y2) return true;
        if (x1 == x2 && y1 == y2) return true;
        if (horizontal) {
            for (int x = x1; x < x2; ++x) {
                if (check_rectangle(x1, y1, x, y2) && dfs(x1, y1, x, y2, !horizontal) && dfs(x + 1, y1, x2, y2, !horizontal)) {
                    return true;
                }
            }
        } else {
            for (int y = y1; y < y2; ++y) {
                if (check_rectangle(x1, y1, x2, y) && dfs(x1, y1, x2, y, !horizontal) && dfs(x1, y + 1, x2, y2, !horizontal)) {
                    return true;
                }
            }
        }
        return false;
    };

    return dfs(0, 0, H - 1, W - 1, true) || dfs(0, 0, H - 1, W - 1, false);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<int> S(H * W);
    for(int &x : S) cin >> x;
    cout << (check(S, H, W) ? "YES" : "NO") << endl;
}