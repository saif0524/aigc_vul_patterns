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
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int dp[30][20][200];
int main() {
	int N, K, S;
	while (scanf("%d%d%d", &N, &K, &S), N) {
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= N; i++)dp[i][0][0] = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				for (int k = 0; k <= S; k++) {
					if (k < i)dp[i][j][k] = dp[i - 1][j][k];
					else dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - i];
				}
			}
		}
		printf("%d\n", dp[N][K][S]);
	}
}