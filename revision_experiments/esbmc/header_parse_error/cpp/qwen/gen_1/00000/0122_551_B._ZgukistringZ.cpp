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

string a, b, c;
int countOccurrences(const string& text, const string& pattern) {
    int count = 0;
    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        count++;
        pos = text.find(pattern, pos + 1);
    }
    return count;
}

bool canFormStringWithPattern(string& a, const string& pattern, int occurrenceCount) {
    int currCount = 0;
    for (int i = 0; i <= (int)a.size() - (int)pattern.size() && currCount < occurrenceCount; ++i) {
        if (a.substr(i, pattern.size()) == string(pattern.size(), '?')) {
            a.replace(i, pattern.size(), pattern);
            currCount++;
        }
    }
    return currCount == occurrenceCount;
}

int main(){
    cin >> a >> b >> c;
    int maxB = countOccurrences(a, b);
    int maxC = countOccurrences(a, c);

    int totalLength = a.size();
    string tempA = a;
    int bCount = 0, cCount = 0;

    for (int i = maxB; i >= 0; --i) {
        int remainingLength = totalLength - (i * b.size());
        int possibleCCount = remainingLength / c.size();
        possibleCCount = min(possibleCCount, maxC);

        tempA = a;
        if (canFormStringWithPattern(tempA, b, i) && canFormStringWithPattern(tempA, c, possibleCCount)) {
            bCount = i;
            cCount = possibleCCount;
            break;
        }
    }

    for (int i = 0; i < (int)a.size();) {
        if (bCount > 0 && a.substr(i, b.size()) == string(b.size(), '?')) {
            cout << b;
            i += b.size();
            bCount--;
        } else if (cCount > 0 && a.substr(i, c.size()) == string(c.size(), '?')) {
            cout << c;
            i += c.size();
            cCount--;
        } else {
            cout << a[i];
            i++;
        }
    }
    return 0;
}