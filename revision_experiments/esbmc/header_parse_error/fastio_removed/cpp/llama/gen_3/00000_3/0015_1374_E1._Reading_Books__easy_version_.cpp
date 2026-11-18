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

struct Book {
    int time;
    int aliceLikes;
    int bobLikes;
};

bool operator<(const Book& a, const Book& b) {
    return a.time < b.time;
}

int main() {
    ((void)0);
    ((void)0);

    int n, k;
    cin >> n >> k;

    vector<Book> books(n);
    for (auto& book : books) {
        cin >> book.time >> book.aliceLikes >> book.bobLikes;
    }

    sort(books.begin(), books.end());

    int minTime = INT_MAX;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int aliceLikesCount = 0;
        int bobLikesCount = 0;
        int totalTime = 0;

        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) != 0) {
                totalTime += books[i].time;
                aliceLikesCount += books[i].aliceLikes;
                bobLikesCount += books[i].bobLikes;
            }
        }

        if (aliceLikesCount >= k && bobLikesCount >= k) {
            minTime = min(minTime, totalTime);
        }
    }

    if (minTime == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << minTime << '\n';
    }

    return 0;
}