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
    while (true) {
        long long N, W;
        cin >> N >> W;
        if (N == 0 && W == 0) break;
        long long total_lessons = 0;
        set<int> days_available;
        for (int i = 0; i < N; ++i) {
            long long ti, ci;
            cin >> ti >> ci;
            total_lessons += ti;
            days_available.clear();
            for (int j = 0; j < ci; ++j) {
                string day;
                cin >> day;
                if (day == "Sunday") days_available.insert(0);
                else if (day == "Monday") days_available.insert(1);
                else if (day == "Tuesday") days_available.insert(2);
                else if (day == "Wednesday") days_available.insert(3);
                else if (day == "Thursday") days_available.insert(4);
                else if (day == "Friday") days_available.insert(5);
                else if (day == "Saturday") days_available.insert(6);
            }
        }
        if (total_lessons <= days_available.size() * W) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}