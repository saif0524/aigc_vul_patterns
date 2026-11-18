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

map<string, pair<int, int>> relations = {
    {"father", {1, 1}},
    {"mother", {1, 1}},
    {"son", {1, 1}},
    {"daughter", {1, 1}},
    {"husband", {0, 0}},
    {"wife", {0, 0}},
    {"brother", {1, 1}},
    {"sister", {1, 1}},
    {"grandfather", {2, 2}},
    {"grandmother", {2, 2}},
    {"grandson", {2, 2}},
    {"granddaughter", {2, 2}},
    {"uncle", {2, 1}},
    {"aunt", {2, 1}},
    {"nephew", {2, 1}},
    {"niece", {2, 1}}
};

pair<int, int> parse_relation(string &relation) {
    int max_dist =0, min_dist = 0;
    stringstream ss(relation);
    string word;
    while (ss >> word) {
        if (word == "is" || word == "A’s" || word == "C’s") continue;
        if (word.back() == ‘s’) word.pop_back();
        auto [max_add, min_add] = relations[word];
        max_dist += max_add;
        min_dist += min_add;
    }
    return {max_dist, min_dist};
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string relation;
        getline(cin, relation);
        auto [max_dist, min_dist] = parse_relation(relation);
        cout << max_dist << " " << min_dist << "\n";
    }
    return 0;
}