#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define debug(...) //ignore

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

struct Solver {
  vector<string> s, t;
  int X, Y;
  vector<pair<pii, char>> E;
  vector<vector<pii>> G;
  map<vector<string>, int> dp;
  vector<string> toVec(const string& s) {
    vector<string> ret;
    string tmp = "";
    for (char c : s) {
      if (tmp == "" || tmp[0] == c) {
        tmp += c;
      } else {
        ret.pb(tmp);
        tmp = c;
      }
    }
    if (tmp != "") ret.pb(tmp);
    return ret;
  }
  int getId(const vector<string>& v) {
    int ret = 0;
    for (auto& s : v) {
      ret = ret * 27 + s[0] - 'a' + 1;
    }
    return ret;
  }
  bool eq(const vector<string>& v1, const vector<string>& v2) {
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < sz(v1); i++) {
      if (v1[i] != v2[i]) return false;
    }
    return true;
  }
  void solve() {
    cin >> X >> Y;
    G.resize(X);
    rep(i, 0, X) G[i].resize(X, mp(-1, '-'));
    E.resize(Y);
    rep(i, 0, Y) {
      int x, y;
      char c1, c2;
      cin >> x >> c1 >> y >> c2;
      G[x][y] = mp(y, c2);
      G[y][x] = mp(x, c1);
      E[i] = mp(mp(x, y), c1);
    }
    s.resize(X);
    t.resize(X);
    rep(i, 0, X) cin >> s[i];
    rep(i, 0, X) cin >> t[i];
    vector<vector<string>> curr(X);
    vector<vector<string>> goal(X);
    rep(i, 0, X) curr[i] = toVec(s[i]);
    rep(i, 0, X) goal[i] = toVec(t[i]);
    queue<pair<vector<vector<string>>, int>> Q;
    Q.push(mp(curr, 0));
    while (!Q.empty()) {
      auto curr = Q.front().first;
      int step = Q.front().second;
      Q.pop();
      int id = getId(curr[0]);
      rep(i, 1, X) id = id * 32 + getId(curr[i]);
      if (dp.count(curr) && dp[curr] <= step) continue;
      dp[curr] = step;
      rep(i, 0, X) {
        rep(j, 0, X) {
          if (i == j) continue;
          if (G[i][j].first == -1) continue;
          auto ncurr = curr;
          rep(k, 0, X) if (k != i && k != j) ncurr[k] = curr[k];
          ncurr[i].clear();
          ncurr[j] = curr[i];
          if (G[i][j].second == 'E') reverse(all(ncurr[j]));
          if (eq(ncurr, goal)) {
            cout << step + 1 << endl;
            return;
          }
          Q.push(mp(ncurr, step + 1));
          ncurr = curr;
          ncurr[i].clear();
          if (!ncurr[j].empty()) {
            string tmp = ncurr[j].back();
            ncurr[j].pop_back();
            ncurr[i].pb(tmp);
            if (G[i][j].second == 'E') reverse(all(ncurr[i]));
            if (eq(ncurr, goal)) {
              cout << step + 1 << endl;
              return;
            }
            Q.push(mp(ncurr, step + 1));
          }
          ncurr = curr;
          ncurr[i].clear();
          ncurr[j].insert(ncurr[j].begin(), curr[i][0]);
          if (G[i][j].second == 'E') reverse(all(ncurr[j]));
          if (eq(ncurr, goal)) {
            cout << step + 1 << endl;
            return;
          }
          Q.push(mp(ncurr, step + 1));
        }
      }
      rep(i, 0, X) {
        if (curr[i].empty()) continue;
        string tmp = curr[i].back();
        curr[i].pop_back();
        rep(j, 0, X) {
          if (i == j) continue;
          if (G[i][j].first == -1) continue;
          auto ncurr = curr;
          ncurr[j].pb(tmp);
          if (G[i][j].second == 'E') reverse(all(ncurr[j]));
          if (eq(ncurr, goal)) {
            cout << step + 1 << endl;
            return;
          }
          Q.push(mp(ncurr, step + 1));
        }
      }
    }
    debug("wtf");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    Solver solver;
    solver.solve();
  }
  return 0;
}