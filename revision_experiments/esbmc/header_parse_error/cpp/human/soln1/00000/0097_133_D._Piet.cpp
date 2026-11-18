// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int w, h, n;
char buf[55][55];
pair<int, int> moveTo[55][55][4][2];
int state[55][55][4][2];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int main() {
  cin >> h >> n;
  for (int i = 0; i < h; ++i) cin >> buf[i];
  w = strlen(buf[0]);
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      for (int k = 0; k < 4; ++k)
        for (int l = 0; l < 2; ++l) {
          int cx = j, cy = i;
          while (1) {
            int px = cx + dx[k], py = cy + dy[k];
            if (px < 0 || py < 0 || px >= w || py >= h ||
                buf[py][px] != buf[cy][cx])
              break;
            cx = px;
            cy = py;
          }
          int add;
          if (l == 0)
            add = 3;
          else
            add = 1;
          int k2 = (k + add) % 4;
          int px, py;
          while (1) {
            px = cx + dx[k2], py = cy + dy[k2];
            if (px < 0 || py < 0 || px >= w || py >= h ||
                buf[py][px] != buf[cy][cx])
              break;
            cx = px;
            cy = py;
          }
          px = cx + dx[k];
          py = cy + dy[k];
          if (px < 0 || py < 0 || px >= w || py >= h || buf[py][px] == '0') {
            state[i][j][k][l] = 1;
            moveTo[i][j][k][l] = make_pair(cy, cx);
          } else {
            moveTo[i][j][k][l] = make_pair(py, px);
          }
        }
  int cx = 0, cy = 0, dir = 0, hand = 0;
  for (int hoge = 0; hoge < n; ++hoge) {
    pair<int, int> nxt = moveTo[cy][cx][dir][hand];
    int flag = state[cy][cx][dir][hand];
    cy = nxt.first;
    cx = nxt.second;
    if (flag) {
      if (hand == 0)
        hand = 1;
      else {
        hand = 0;
        dir = (dir + 1) % 4;
      }
    }
  }
  printf("%c\n", buf[cy][cx]);
  return 0;
}