#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

const int MAX_R = 3005;
const int MAX_C = 3005;

struct Point {
    int r, c;
    Point(int r = 0, int c = 0) : r(r), c(c) {}
};

int r, c, n;
bitset<MAX_R * MAX_C> land;
int cnt;

bool isValid(int r, int c) {
    return r >= 1 && r <= ::r && c >= 1 && c <= ::c;
}

bool isBlocked() {
    queue<Point> q;
    bitset<MAX_R> vis;
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, -1, 0, 1};

    for (int i = 1; i <= c; i++)
        if (!land[(1 - 1) * c + i]) {
            q.push(Point(1, i));
            vis[1] = true;
        }

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.r == r) return true;

        for (int i = 0; i < 4; i++) {
            int nr = p.r + dr[i];
            int nc = p.c + dc[i];

            if (nr == p.r && nc == 1 && p.c == c || nr == p.r && nc == c && p.c == 1) {
                nc = (p.c == 1 ? c : 1);
            }

            if (isValid(nr, nc) && !land[(nr - 1) * c + nc] && !vis[nr]) {
                q.push(Point(nr, nc));
                vis[nr] = true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> n;
    while (n--) {
        int ri, ci;
        cin >> ri >> ci;

        if (isBlocked()) continue;
        land[(ri - 1) * c + ci] = true;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}