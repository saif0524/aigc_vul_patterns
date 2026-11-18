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
#define int long long //delete if causing problems
#define F first
#define S second
#define setbit(n) __builtin_popcountll(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ((void)0); ((void)0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << vars << " = ";
	string delim = "";
	(..., (cout << delim << values, delim = ","));
	cout << endl;
}
const int inf = 1e18;
int power(int a, int b);
bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

signed   main()
{
	fast
	int tt = 1;
	//cin >> tt;
	while (tt--)
	{

		int n;
		cin >> n;

		vector<pair<int, int>> a(n);
		vector<int> pre(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;

		}

		sort(all(a), comp);

		pre[0] = a[0].first;

		for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i].first;


		int ans = 0;

		int l = 0, r = pre[n - 1];

		auto check = [&](int key) {

			int two = (pre[n - 1] - key);



			for (int i = 0; i < n; i++) {


				if (a[i].second > two) return false;
				two += a[i].first;

				if (pre[i] >= key) break;

			}

			return true;


		};
		while (r >= l) {
			int mid = (l + r) / 2;
			if (check(mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}

		cout << (ans + (pre[n - 1] - ans) * 2) << endl;







	}
	return 0;
}

int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}

/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/