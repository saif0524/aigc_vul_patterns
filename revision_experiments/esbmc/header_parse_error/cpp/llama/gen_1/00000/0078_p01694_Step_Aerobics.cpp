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

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		vector<string> f(n);
		for (int i = 0; i < n; i++) cin >> f[i];

		int lu = 0, ru = 0, ld = 0, rd = 0, count = 0;
		for (int i = 0; i < n; i++) {
			if (f[i] == "lu") lu = 1;
			else if (f[i] == "ru") ru = 1;
			else if (f[i] == "ld") ld = 1;
			else if (f[i] == "rd") rd = 1;

			if (lu && ru && (!ld && !rd)) {
				count++;
				lu = ru = 0;
			}
			else if (ld && rd && (!lu && !ru)) {
				count++;
				ld = rd = 0;
			}
		}

		cout << count << endl;
	}

	return 0;
}