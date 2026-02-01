#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4 * 100;
const int MAXMOVE = 4;
const int INF = 1e9;

struct Point {
    int x, y;
};

int n;
Point pos[MAXN], home[MAXN];

Point rotate90(Point p, Point c) {
    int x = p.x - c.x;
    int y = p.y - c.y;
    return {c.x - y, c.y + x};
}

int dp[16][MAXMOVE];

int dist2(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool isSquare(Point p1, Point p2, Point p3, Point p4) {
    vector<int> d;
    d.push_back(dist2(p1, p2));
    d.push_back(dist2(p1, p3));
    d.push_back(dist2(p1, p4));
    d.push_back(dist2(p2, p3));
    d.push_back(dist2(p2, p4));
    d.push_back(dist2(p3, p4));
    sort(d.begin(), d.end());
    return (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5] && d[0] > 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < 4 * n; i++){
        cin >> pos[i].x >> pos[i].y >> home[i].x >> home[i].y;
    }
    for(int i = 0; i < n; i++){
        int idx = 4 * i;
        int best = INF;
        for(int mask = 0; mask < (1 << 4); mask++){
            for(int j = 0; j < MAXMOVE; j++) dp[mask][j] = INF;
            dp[0][0] = 0;
            for(int state = 0; state < 16; state++){
                Point p[4];
                for(int k = 0; k < 4; k++){
                    if(state & (1 << k)) p[k] = rotate90(pos[idx + k], home[idx + k]);
                    else p[k] = pos[idx + k];
                }
                int ones = __builtin_popcount(state);
                for(int j = 0; j < MAXMOVE; j++){
                    if(dp[state][j] == INF) continue;
                    int moves = dp[state][j];
                    if(isSquare(p[0], p[1], p[2], p[3])){
                        best = min(best, moves);
                        continue;
                    }
                    if(ones == 4) continue;
                    for(int k = 0; k < 4; k++){
                        if(state & (1 << k)) continue;
                        Point np[4];
                        for(int l = 0; l < 4; l++) np[l] = p[l];
                        np[k] = rotate90(pos[idx + k], home[idx + k]);
                        int new_state = state | (1 << k);
                        dp[new_state][j+1] = min(dp[new_state][j+1], moves + 1);
                    }
                }
            }
        }
        if(best == INF) cout << "-1\n";
        else cout << best << "\n";
    }
}