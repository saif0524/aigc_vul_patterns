#include <bits/stdc++.h>
using namespace std;
using namespace std;
void enumerateSubmasks(long long m) {
  for (long long s = m;; s = (s - 1) & m) {
    if (s == 0) {
      break;
    }
  }
}
long long mpow(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long x = mpow(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2) {
    x = (x * a) % m;
  }
  return x;
}
void update(long long s, long long e, long long qs, long long qe,
            vector<long long> &seg, vector<long long> &lazy, long long index,
            long long value) {
  if (lazy[index] != -1) {
    seg[index] = max(seg[index], lazy[index]);
    if (s != e) {
      if (lazy[2 * index] == -1)
        lazy[2 * index] = lazy[index];
      else
        lazy[2 * index] = max(lazy[2 * index], lazy[index]);
      if (lazy[2 * index + 1] == -1)
        lazy[2 * index + 1] = lazy[index];
      else
        lazy[2 * index + 1] = max(lazy[2 * index + 1], lazy[index]);
    }
    lazy[index] = -1;
  }
  if (qs > e || qe < s) return;
  if (s >= qs && e <= qe) {
    seg[index] = max(seg[index], value);
    if (s != e) {
      if (lazy[2 * index] == -1)
        lazy[2 * index] = value;
      else
        lazy[2 * index] = max(lazy[2 * index], value);
      if (lazy[2 * index + 1] == -1)
        lazy[2 * index + 1] = value;
      else
        lazy[2 * index + 1] = max(lazy[2 * index + 1], value);
    }
    return;
  }
  long long mid = (s + e) / 2;
  update(s, mid, qs, qe, seg, lazy, 2 * index, value);
  update(mid + 1, e, qs, qe, seg, lazy, 2 * index + 1, value);
}
long long query(long long s, long long e, long long qs, long long qe,
                vector<long long> &seg, vector<long long> &lazy,
                long long index) {
  if (lazy[index] != -1) {
    seg[index] = max(seg[index], lazy[index]);
    if (s != e) {
      if (lazy[2 * index] == -1)
        lazy[2 * index] = lazy[index];
      else
        lazy[2 * index] = max(lazy[2 * index], lazy[index]);
      if (lazy[2 * index + 1] == -1)
        lazy[2 * index + 1] = lazy[index];
      else
        lazy[2 * index + 1] = max(lazy[2 * index + 1], lazy[index]);
    }
    lazy[index] = -1;
  }
  if (qs > e || qe < s) return LLONG_MIN;
  if (s >= qs && e <= qe) {
    return seg[index];
  }
  long long mid = (s + e) / 2;
  long long a = query(s, mid, qs, qe, seg, lazy, 2 * index);
  long long b = query(mid + 1, e, qs, qe, seg, lazy, 2 * index + 1);
  return max(a, b);
}
void printBinaryString(long long n) {
  vector<long long> temp;
  while (n) {
    if (n & 1)
      temp.push_back(1);
    else
      temp.push_back(0);
    n = n >> 1;
  }
  reverse(temp.begin(), temp.end());
  for (auto node : temp) cout << node << " ";
  cout << endl;
}
void readVector(vector<long long> &a) {
  long long n = a.size();
  for (long long i = 0; i < n; ++i) cin >> a[i];
}
struct node {
  long long id;
  long long val;
  char dir;
};
map<long long, list<long long>> adj;
map<long long, long long> par;
map<long long, bool> x;
map<long long, bool> y;
long long k1, k2;
long long answer;
long long interactA(long long x) {
  cout << "A " << x << endl;
  long long ret;
  cin >> ret;
  fflush(stdout);
  return ret;
}
long long interactB(long long x) {
  cout << "B " << x << endl;
  long long ret;
  cin >> ret;
  fflush(stdout);
  return ret;
}
pair<long long, bool> solve(long long node, long long par, long long k) {
  long long totalInSubtree = 1;
  for (auto child : adj[node]) {
    if (child == par) continue;
    auto ret = solve(child, node, k);
    bool mila = ret.second;
    if (mila) return {0, true};
    totalInSubtree += ret.first;
  }
  if (totalInSubtree < k) return {totalInSubtree, false};
  if (x[node] == false) return {0, false};
  long long bLabel = interactA(node);
  if (y[bLabel]) {
    answer = node;
    return {0, true};
  } else
    return {0, false};
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc;
  cin >> tc;
  while (tc--) {
    answer = -1;
    x.clear();
    y.clear();
    adj.clear();
    par.clear();
    long long n;
    cin >> n;
    for (long long i = 0; i < n - 1; ++i) {
      long long u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cin >> k1;
    for (long long i = 0; i < k1; ++i) {
      long long temp;
      cin >> temp;
      x[temp] = true;
    }
    long long st;
    cin >> k2;
    for (long long i = 0; i < k2; ++i) {
      long long temp;
      cin >> temp;
      st = temp;
      y[temp] = true;
    }
    long long start = interactB(st);
    queue<long long> bfs;
    long long toCompare;
    bfs.push(start);
    map<long long, bool> visited;
    while (!bfs.empty()) {
      auto node = bfs.front();
      bfs.pop();
      visited[node] = true;
      if (x[node]) {
        toCompare = node;
        break;
      }
      for (auto child : adj[node]) {
        if (visited[child]) continue;
        bfs.push(child);
      }
    }
    long long temp = interactA(toCompare);
    if (y[temp])
      cout << "C " << toCompare << endl;
    else
      cout << "C -1" << endl;
    fflush(stdout);
  }
}