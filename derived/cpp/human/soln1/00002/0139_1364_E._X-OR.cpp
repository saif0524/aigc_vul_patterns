#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<pair<int, int>, int> mp;
int ask(int l, int r) {
  if (mp.find({l, r}) != mp.end()) return mp[{l, r}];
  cout << "? " << l << " " << r << endl;
  int x;
  cin >> x;
  mp[{l, r}] = x;
  mp[{r, l}] = x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  istream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> grr;
  grr.clear();
  for (int i = 1; i <= n; i++) grr.push_back(i);
  shuffle(grr.begin(), grr.end(), rng);
  int a = grr[0], b = grr[1], val = ask(a, b);
  for (int i = 2; i < n; i++) {
    int c = grr[i];
    int x = ask(b, c);
    if (x == val) {
      val = ask(a, c);
      b = c;
      continue;
    }
    if (val > x) {
      a = c;
      val = x;
    }
  }
  int nuller;
  for (int i = 1; i <= n; i++) {
    if (i == a || i == b) continue;
    int l = ask(a, i), r = ask(b, i);
    if (l == r) continue;
    if (l < r) {
      nuller = a;
      break;
    } else {
      nuller = b;
      break;
    }
  }
  vector<int> gr;
  gr.clear();
  for (int i = 1; i <= n; i++) {
    if (i == nuller) {
      gr.push_back(0);
      continue;
    }
    gr.push_back(ask(nuller, i));
  }
  cout << "! ";
  for (auto it : gr) cout << it << " ";
  cout << endl;
}