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
    ((void)0);
    ((void)0);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> age_count(7, 0);
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            if (age < 10) age_count[0]++;
            else if (age < 20) age_count[1]++;
            else if (age < 30) age_count[2]++;
            else if (age < 40) age_count[3]++;
            else if (age < 50) age_count[4]++;
            else if (age < 60) age_count[5]++;
            else age_count[6]++;
        }
        for (int count : age_count) {
            cout << count << "\n";
        }
    }
    return 0;
}