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

int N, X, Y, Z;
bool Data[3][100];

void solve() {
	int sum;

	sum = 0;
	for (int i = 0; i < N; ++i) {
		if ((!Data[0][i] && Data[2][i]) || (Data[1][i] && Data[2][i])) {
			++sum;
		}
	}
	cout << sum << endl;
}

int main() {
	int num;

	memset(Data, false, sizeof(Data));
	cin >> N >> X;
	for (int i = 0; i < X; ++i) {
		cin >> num;
		Data[0][num - 1] = true;
	}
	cin >> Y;
	for (int i = 0; i < Y; ++i) {
		cin >> num;
		Data[1][num - 1] = true;
	}
	cin >> Z;
	for (int i = 0; i < Z; ++i) {
		cin >> num;
		Data[2][num - 1] = true;
	}
	solve();

	return 0;
}