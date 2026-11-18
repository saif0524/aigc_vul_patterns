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
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

char a[810][810];
int ans;
queue <piii> q;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int n, m, k;

bool IN(int x, int y){return x >= 0 && x < n && y >= 0 && y < m;}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	int x, y;
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
		for (int j = 0; j < m; j++){
			if (a[i][j] == 'S') x = i, y = j;
		}
	}
	q.push(mp(mp(x, y), k)), a[x][y] = '#';
	int ans = 0x3f3f3f3f;
	while (!q.empty()){
		piii t = q.front(); q.pop();
		int x = t.fi.fi, y = t.fi.se, cnt = t.se;
		ans = min(ans, (min(min(x, y), min(n - x - 1, m - y - 1)) + k - 1) / k);
		if (t.se == 0) continue;
		for (int i = 0; i < 4; i++){
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (!IN(xx, yy) || a[xx][yy] != '.') continue;
			a[xx][yy] = '#';
			q.push(mp(mp(xx, yy), cnt - 1));
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}