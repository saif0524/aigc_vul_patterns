#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 8;

struct Edge {
    int u, v;
    Edge(int u = 0, int v = 0) : u(u), v(v) {}
};

vector<Edge> edges;
int likes[N][N];
ll exps[N];
int n;
ll ans = LLONG_MAX, ans_cnt = -1;

void build(int idx, vector<int> &teams) {
    if (idx == n) {
        ll diff = LLONG_MIN, min_exp = LLONG_MAX;
        ll cnt = 0;
        for (int i = 0; i < 3; ++i) {
            if (teams[i] == 0) {
                continue;
            }
            ll cur_exp = exps[i] / teams[i];
            diff = max(diff, cur_exp);
            min_exp = min(min_exp, cur_exp);
        }
        for (int u = 0; u < 7; ++u) {
            for (int v = 0; v < 7; ++v) {
                if (likes[u][v]) {
                    int team_u = 0, team_v = 0;
                    for (int i = 0; i < 3; ++i) {
                        if (find(teams.begin() + i * 7, teams.begin() + (i + 1) * 7, u) != teams.begin() + (i + 1) * 7) {
                            team_u = i;
                        }
                        if (find(teams.begin() + i * 7, teams.begin() + (i + 1) * 7, v) != teams.begin() + (i + 1) * 7) {
                            team_v = i;
                        }
                    }
                    if (team_u == team_v) {
                        cnt++;
                    }
                }
            }
        }
        if (diff - min_exp < ans || (diff - min_exp == ans && cnt > ans_cnt)) {
            ans = diff - min_exp;
            ans_cnt = cnt;
        }
        return;
    }
    for (int i = 0; i < 3; ++i) {
        teams[i * 7 + idx] = edges[idx].u;
        build(idx + 1, teams);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    n = 0;
    int a;
    cin >> a;
    while (a--) {
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        int p, q;
        if (s1 == "Troll") {
            p = 0;
        } else if (s1 == "Dracul") {
            p = 1;
        } else if (s1 == "Anka") {
            p = 2;
        } else if (s1 == "Chapay") {
            p = 3;
        } else if (s1 == "Cleo") {
            p = 4;
        } else if (s1 == "Snowy") {
            p = 5;
        } else {
            p = 6;
        }
        if (s4 == "Troll") {
            q = 0;
        } else if (s4 == "Dracul") {
            q = 1;
        } else if (s4 == "Anka") {
            q = 2;
        } else if (s4 == "Chapay") {
            q = 3;
        } else if (s4 == "Cleo") {
            q = 4;
        } else if (s4 == "Snowy") {
            q = 5;
        } else {
            q = 6;
        }
        likes[p][q] = 1;
        edges.emplace_back(p, q);
        n++;
    }
    for (int i = 0; i < 3; ++i) {
        cin >> exps[i];
    }
    vector<int> teams(21, 0);
    build(0, teams);
    cout << ans << " " << ans_cnt << endl;
    return 0;
}