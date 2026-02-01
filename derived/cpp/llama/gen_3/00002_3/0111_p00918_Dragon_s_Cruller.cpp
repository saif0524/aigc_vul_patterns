#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
const int MAXN = 362880;

int ch, cv;
int start[9], goal[9];

struct state {
    int perm[9];
    int cost;
};

int encode(int p[9]) {
    int ret = 0;
    for (int i = 1; i <= 8; i++) {
        int c = 0;
        for (int j = 1; j < p[i]; j++) {
            if (p[j] > 0) c++;
        }
        ret = ret * 9 + c;
    }
    return ret;
}

int decode(int code, int p[9]) {
    int q[9];
    memset(q, 0, sizeof(q));
    for (int i = 8; i >= 1; i--) {
        p[i] = code % 9;
        code /= 9;
        for (int j = 1; j < i; j++) {
            if (p[j] > p[i]) q[p[j]]++;
        }
        p[i] += q[p[i]];
    }
    return 0;
}

vector<pii> get_neighbors(int p[9], int cost) {
    vector<pii> ret;
    for (int i = 0; i < 9; i++) {
        if (p[i] == 0) {
            if (i == 0) {
                if (p[1]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[0] = np[1];
                    np[1] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[3]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[0] = np[3];
                    np[3] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[4]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[0] = np[4];
                    np[4] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
            } else if (i == 1) {
                if (p[0]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[1] = np[0];
                    np[0] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[2]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[1] = np[2];
                    np[2] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[4]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[1] = np[4];
                    np[4] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
            } else if (i == 2) {
                if (p[1]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[2] = np[1];
                    np[1] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[5]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[2] = np[5];
                    np[5] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[4]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[2] = np[4];
                    np[4] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
            } else if (i == 3) {
                if (p[0]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[3] = np[0];
                    np[0] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[4]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[3] = np[4];
                    np[4] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[6]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[3] = np[6];
                    np[6] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
            } else if (i == 4) {
                if (p[0]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[4] = np[0];
                    np[0] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[1]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[4] = np[1];
                    np[1] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[2]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[4] = np[2];
                    np[2] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[3]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[4] = np[3];
                    np[3] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[5]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[4] = np[5];
                    np[5] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[7]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[4] = np[7];
                    np[7] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
            } else if (i == 5) {
                if (p[2]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[5] = np[2];
                    np[2] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[4]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[5] = np[4];
                    np[4] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[8]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[5] = np[8];
                    np[8] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
            } else if (i == 6) {
                if (p[3]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[6] = np[3];
                    np[3] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[7]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[6] = np[7];
                    np[7] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[4]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[6] = np[4];
                    np[4] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
            } else if (i == 7) {
                if (p[4]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[7] = np[4];
                    np[4] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[6]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[7] = np[6];
                    np[6] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
                if (p[8]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[7] = np[8];
                    np[8] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
            } else if (i == 8) {
                if (p[5]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[8] = np[5];
                    np[5] = 0;
                    ret.emplace_back(encode(np), cost + cv);
                }
                if (p[7]!= 0) {
                    int np[9];
                    memcpy(np, p, sizeof(p));
                    np[8] = np[7];
                    np[7] = 0;
                    ret.emplace_back(encode(np), cost + ch);
                }
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> ch >> cv;
        if (ch == 0 && cv == 0) break;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> start[i * 3 + j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> goal[i * 3 + j];
            }
        }

        int start_code = encode(start);
        int goal_code = encode(goal);

        vector<int> dist(MAXN, INF);
        priority_queue<state, vector<state>, greater<state>> pq;
        dist[start_code] = 0;
        pq.push({start, 0});

        while (!pq.empty()) {
            state s = pq.top();
            pq.pop();

            if (s.cost > dist[s.perm[0]]) continue;

            for (auto [next_code, next_cost] : get_neighbors(s.perm, s.cost)) {
                if (next_cost < dist[next_code]) {
                    dist[next_code] = next_cost;
                    int next_perm[9];
                    decode(next_code, next_perm);
                    pq.push({next_perm, next_cost});
                }
            }
        }

        cout << dist[goal_code] << '\n';
    }

    return 0;
}