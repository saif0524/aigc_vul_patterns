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

long long gcd(long long x, long long y) { return (y) ? gcd(y, x % y): x; }

const long long MOD=1000000007;

int main() {
    int N;
    cin >> N;

    vector<long long> pw(200010);

    pw[0]=1;
	for (int i=1; i<200010; ++i) pw[i] = (pw[i-1]*2)%MOD;

    map<pair<long long, long long>, pair<int, int> > x;

    long long zz = 0;
    for (int i=0; i<N; ++i) {
        long long a,b;
        cin >> a >> b;
        if (a==0 && b==0) {
            zz++;
            continue;
        }
        if (make_pair(a,b) < make_pair(0LL,0LL)) {
            a=-a;
            b=-b;
        }
        long long g = gcd(abs(a),abs(b));
        a/=g;
        b/=g;
        if (b>0) {
            x[make_pair(a,b)].first++;
        }
        else {
            x[make_pair(-b,a)].second++;
        }
    }

	long long ans = 1;
	for (auto& p : x){
		ans = ans*(pw[p.second.first]+pw[p.second.second]-1)%MOD;
	}

    cout << (ans+zz+MOD-1)%MOD << endl;

    return 0;
}