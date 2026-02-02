#include <bits/stdc++.h>
using namespace std;
long long SIZE = (long long)1e18;
int remains = 200000;
vector<set<pair<long long, long long>>> evals;
long long need;
vector<long long> resLeft;
vector<long long> resRight;
long long realEval(int fid, long long x) {
  --remains;
  assert(remains >= 0);
  printf("? %d %lld\n", (fid + 1), x);
  fflush(stdout);
  long long realY;
  scanf("%lld", &realY);
  return realY;
}
bool compareAt(int fid, long long x, long long y) {
  set<pair<long long, long long>>& known = evals[fid];
  auto next = known.lower_bound(pair<long long, long long>(x + 1, -1));
  auto prev = next;
  --prev;
  assert(prev->first >= 0);
  assert(prev->first <= x);
  assert(next->first > x);
  assert(next->first <= SIZE + 1);
  if (prev->second >= y) return true;
  if (prev->second + x - prev->first < y) return false;
  if (next->second < y) return false;
  if (next->second + x - next->first >= y) return true;
  long long realY = realEval(fid, x);
  known.insert(pair<long long, long long>(x, realY));
  return realY >= y;
}
void rec(vector<int>& ids, long long left, long long right, long long base) {
  if (ids.size() == 1) {
    resLeft[ids[0]] = left;
    resRight[ids[0]] = right;
    return;
  }
  int n = ids.size();
  int n1 = n / 2;
  long long interesting = base + n1 * need;
  long long searchLeft = 0;
  long long searchRight = SIZE;
  while (searchRight - searchLeft > 1) {
    long long searchMiddle = (searchLeft + searchRight) / 2;
    int count = 0;
    int togo = n;
    for (int x : ids) {
      if (compareAt(x, searchMiddle, interesting)) {
        ++count;
      }
      if (count >= n1) break;
      --togo;
      if (count + togo < n1) break;
    }
    if (count >= n1) {
      searchRight = searchMiddle;
    } else {
      searchLeft = searchMiddle;
    }
  }
  vector<int> ids1(n1);
  vector<int> ids2(n - n1);
  int p1 = 0;
  int p2 = 0;
  for (int x : ids) {
    if (compareAt(x, searchLeft, interesting)) {
      ids1[p1++] = x;
    } else if (!compareAt(x, searchRight, interesting)) {
      ids2[p2++] = x;
    }
  }
  for (int x : ids) {
    if (compareAt(x, searchLeft, interesting)) {
    } else if (!compareAt(x, searchRight, interesting)) {
    } else if (p1 == ids1.size()) {
      ids2[p2++] = x;
    } else {
      ids1[p1++] = x;
    }
  }
  rec(ids1, left, searchRight, base);
  rec(ids2, searchRight, right, interesting);
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%lld", &need);
  need /= n;
  for (int i = 0; i < n; ++i) {
    set<pair<long long, long long>> pts;
    pts.insert(pair<long long, long long>(0, 0));
    pts.insert(pair<long long, long long>(SIZE, need * n));
    pts.insert(pair<long long, long long>(SIZE + 1, need * n));
    evals.push_back(pts);
  }
  vector<int> ids;
  for (int i = 0; i < n; ++i) ids.push_back(i);
  resLeft.resize(n);
  resRight.resize(n);
  rec(ids, 0, SIZE, 0);
  for (int i = 0; i < n; ++i) {
    assert(realEval(i, resRight[i]) - realEval(i, resLeft[i]) >= need);
  }
  printf("!\n");
  for (int i = 0; i < n; ++i) {
    printf("%lld %lld\n", resLeft[i], resRight[i]);
  }
  fflush(stdout);
}