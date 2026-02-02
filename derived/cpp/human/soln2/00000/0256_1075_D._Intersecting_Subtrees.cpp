#include <bits/stdc++.h>
using namespace std;
template <class T>
void pv(vector<T> &vec) {
  for (int i = 0; i < (int)(vec).size(); i++)
    cout << vec[i] << (i == (int)(vec).size() - 1 ? '\n' : ' ');
}
int V, a, b, t;
vector<vector<int> > G;
vector<int> mine, his;
vector<bool> label, his_label;
void init() {
  cin >> V;
  (G).clear();
  G.resize(V);
  for (int i = 0; i < V - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> a;
  mine.resize(a);
  label.assign(V, false);
  for (int i = 0; i < a; i++) {
    cin >> mine[i];
    mine[i]--;
    label[mine[i]] = true;
  }
  cin >> a;
  his.resize(a);
  his_label.assign(V, false);
  for (int i = 0; i < a; i++) {
    cin >> his[i];
    his[i]--;
    his_label[his[i]] = true;
  }
}
int dfs(int u, int p) {
  if (label[u]) return u;
  for (int i = 0; i < (int)(G[u]).size(); i++) {
    int v = G[u][i];
    if (v != p) {
      int tans = dfs(v, u);
      if (tans != -1) return tans;
    }
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TC;
  cin >> TC;
  while (TC--) {
    init();
    cout << "B " << his[0] + 1 << endl;
    int strt;
    cin >> strt;
    strt--;
    int my_closest = dfs(strt, -1);
    assert(my_closest != -1);
    cout << "A " << my_closest + 1 << endl;
    cin >> t;
    t--;
    cout << "C " << (his_label[t] ? my_closest + 1 : -1) << endl;
  }
  return 0;
}