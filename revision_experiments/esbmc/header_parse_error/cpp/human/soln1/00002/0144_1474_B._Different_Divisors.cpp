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
#define ll long long int
#define mod 1000000007

vector<int> v2;
bool prime[1000000];

void fun(int n)
{

	for (int p = 2; p * p <= n; p++)
	{

		if (prime[p] == true)
		{

			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
	{
		if (prime[p])
		{

			v2.push_back(p);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	memset(prime, true, sizeof(prime));

	fun(1000000);
	sort(v2.begin(), v2.end());

	while (t--)
	{
		ll d, i;
		cin >> d;
		ll a = 1, pro = 1, cnt = 0, ans2;

		for (i = 1 + d; i < v2.size(); i++)
		{
			if (prime[i] == true)
			{
				cnt = i;
				break;
			}

		}

		for (i = cnt + d; i < v2.size(); i++)
		{
			if (prime[i] == true)
			{
				ans2 = i;
				break;
			}

		}
		cout << ans2 * cnt << '\n';
	}
}