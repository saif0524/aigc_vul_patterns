#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int>& s, int h, int w) {
    if (s.empty()) return true;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    for (int i = 0; i < s.size(); ++i) {
        int x = s[i] / w;
        int y = s[i] % w;
        if (used[x][y]) return false;
        used[x][y] = true;
    }
    vector<int> next;
    for (int i = 0; i < h - 1; ++i) {
        for (int j = 0; j < w; ++j) {
            if (used[i][j] && used[i + 1][j]) {
                if (i > 0 && !used[i - 1][j]) return false;
                if (i < h - 2 && !used[i + 2][j]) return false;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w - 1; ++j) {
            if (used[i][j] && used[i][j + 1]) {
                if (j > 0 && !used[i][j - 1]) return false;
                if (j < w - 2 && !used[i][j + 2]) return false;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!used[i][j]) {
                cnt++;
                next.push_back(i * w + j);
            }
        }
    }
    if (cnt == 0) return true;
    return check(next, h / 2, w / 2) || check(next, h / 2, w);
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> s(h * w);
    for (int i = 0; i < h * w; ++i) {
        cin >> s[i];
    }
    if (check(s, h, w)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}