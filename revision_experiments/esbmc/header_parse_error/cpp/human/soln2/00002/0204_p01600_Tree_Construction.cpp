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
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 1000

struct Info{
	int x,y;
};

int dp[NUM][NUM];
Info info[NUM];

int main(){

	int N;
	scanf("%d",&N);

	for(int i = 0; i < N; i++){
		scanf("%d %d",&info[i].x,&info[i].y);
	}

	for(int i = 0; i < N; i++){
		dp[i][i] = 0;
		for(int k = i+1; k < N; k++){
			dp[i][k] = BIG_NUM;
		}
	}

	int tmp_cost;

	for(int a = 0; a < N; a++){
		for(int i = 0; i+a < N; i++){
			for(int k = i; k < i+a; k++){
				tmp_cost = abs(info[i].x-info[k+1].x)+abs(info[k].y-info[i+a].y);
				dp[i][i+a] = min(dp[i][i+a],dp[i][k]+dp[k+1][i+a]+tmp_cost);
			}
		}
	}

	printf("%d\n",dp[0][N-1]);

	return 0;
}