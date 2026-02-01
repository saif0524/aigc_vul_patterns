#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500005;

int n, m, cnt;
vector<int> ox[MAXN], oy[MAXN], ans;
int u[MAXN], v[MAXN], t[MAXN], id[MAXN];

void dfs(int x, int fa, vector<int>& rd, vector<int>& tp) {
    for (int i = 0; i < ox[x].size(); i++) {
        int y = oy[x][i];
        if (y == fa) continue;
        rd.push_back(ox[x][i]);
        tp.push_back(t[ox[x][i]]);
        dfs(y, x, rd, tp);
        rd.pop_back();
        tp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i] >> t[i];
        ox[u[i]].push_back(i);
        oy[u[i]].push_back(v[i]);
        ox[v[i]].push_back(i);
        oy[v[i]].push_back(u[i]);
    }

    int x = 1, mx = 0;
    vector<int> rd, tp;
    for (int i = 1; i <= n; i++) {
        dfs(i, 0, rd, tp);
        int tmp = 0, cnt = 0;
        for (int j = 0; j < rd.size(); j++)
            if (tp[j] == 1) cnt++;
        if (cnt % 2 == 0 && rd.size() > mx) {
            mx = rd.size();
            x = i;
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int idd;
        cin >> idd;
        t[idd] ^= 1;
        x = 1;
        mx = 0;
        for (int j = 1; j <= n; j++) {
            dfs(j, 0, rd, tp);
            int tmp = 0, cnt = 0;
            for (int k = 0; k < rd.size(); k++)
                if (tp[k] == 1) cnt++;
            if (cnt % 2 == 0 && rd.size() > mx) {
                mx = rd.size();
                x = j;
            }
            rd.clear();
            tp.clear();
        }
        cout << mx << endl;
    }

    return 0;
}