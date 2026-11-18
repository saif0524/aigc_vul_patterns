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
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        int cnt = 0;
        int nlu = 0, nld = 0, nru = 0, nrd = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == "lu") nlu++;
            else if (s[i] == "ld") {
                if (nru == 1 && nlu == 0) {
                    cnt++;
                    nru = 0;
                }
                else if (nlu > 0 && nru > 0) {
                    cnt++;
                    nlu = 0;
                    nru = 0;
                }
                nld++;
            }
            else if (s[i] == "ru") nru++;
            else if (s[i] == "rd") {
                if (nlu == 1 && nru == 0) {
                    cnt++;
                    nlu = 0;
                }
                else if (nlu > 0 && nru > 0) {
                    cnt++;
                    nlu = 0;
                    nru = 0;
                }
                nrd++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}