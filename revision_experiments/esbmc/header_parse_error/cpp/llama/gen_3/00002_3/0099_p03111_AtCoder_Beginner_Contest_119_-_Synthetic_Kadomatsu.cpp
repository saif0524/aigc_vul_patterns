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

const int INF = 1e9;
const int MAX_N = 8;
const int MAX_L = 1000;

int values[MAX_N];
int N, A, B, C;

int calculateMagicPoints(int targetLength, int selectedValues[], int selectedCount) {
    int totalPoints = 0;
    for (int i = 0; i < selectedCount; i++) {
        totalPoints += abs(targetLength - selectedValues[i]);
    }
    if (selectedCount > 1) {
        totalPoints += (selectedCount - 1) * 10;
    }
    return totalPoints;
}

int main() {
    vector<int> possibleValues;
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    vector<vector<int>> combinations(N);
    for (int mask = 1; mask < (1 << N); mask++) {
        vector<int> bambooGroup;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if ((mask & (1 << i)) > 0) {
                bambooGroup.push_back(values[i]);
                sum += values[i];
            }
        }
        if (sum >= C) {
            combinations[C].push_back(sum);
        }
        if (sum >= B) {
            combinations[B].push_back(sum);
        }
        if (sum >= A) {
            combinations[A].push_back(sum);
        }
    }

    int answer = INF;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N; k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                vector<int> bambooGroup1, bambooGroup2, bambooGroup3;
                int points1 = INF, points2 = INF, points3 = INF;
                if (i < N) {
                    points1 = calculateMagicPoints(A, {values[i]}, 1);
                }
                if (j < N) {
                    points2 = calculateMagicPoints(B, {values[j]}, 1);
                }
                if (k < N) {
                    points3 = calculateMagicPoints(C, {values[k]}, 1);
                }
                answer = min(answer, points1 + points2 + points3);
                if (combinations[A].size() > 0 && combinations[B].size() > 0) {
                    answer = min(answer, calculateMagicPoints(A, {combinations[A][0]}, 1) + calculateMagicPoints(B, {combinations[B][0]}, 1) + calculateMagicPoints(C, {values[k]}, 1));
                }
                if (combinations[B].size() > 0 && combinations[C].size() > 0) {
                    answer = min(answer, calculateMagicPoints(A, {values[i]}, 1) + calculateMagicPoints(B, {combinations[B][0]}, 1) + calculateMagicPoints(C, {combinations[C][0]}, 1));
                }
                if (combinations[A].size() > 0 && combinations[C].size() > 0) {
                    answer = min(answer, calculateMagicPoints(A, {combinations[A][0]}, 1) + calculateMagicPoints(B, {values[j]}, 1) + calculateMagicPoints(C, {combinations[C][0]}, 1));
                }
                if (combinations[A].size() > 0 && combinations[B].size() > 0 && combinations[C].size() > 0) {
                    answer = min(answer, calculateMagicPoints(A, {combinations[A][0]}, 1) + calculateMagicPoints(B, {combinations[B][0]}, 1) + calculateMagicPoints(C, {combinations[C][0]}, 1));
                }
            }
        }
    }
    cout << answer << endl;

    return 0;
}