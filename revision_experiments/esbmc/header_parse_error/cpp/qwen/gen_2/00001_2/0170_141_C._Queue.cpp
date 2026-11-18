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

struct Person {
    string name;
    int a;
    int h;
};

int main() {
    int n;
    cin >> n;
    vector<Person> people(n);
    map<string, int> name_to_index;

    for (int i = 0; i < n; ++i) {
        cin >> people[i].name >> people[i].a;
        name_to_index[people[i].name] = i;
    }

    sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
        return p1.a < p2.a;
    });

    vector<vector<int>> taller_count(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (people[j].a >= people[i].a) {
                taller_count[people[i].a].push_back(people[j].a);
            }
        }
    }

    vector<int> pos(n, -1);
    for (int i = 0; i < n; ++i) {
        auto& tc = taller_count[people[i].a];
        if (tc.size() < people[i].a) {
            cout << "-1";
            return 0;
        }
        pos[i] = people[i].a;
        for (int j : tc) {
            if (--pos[j] == people[j].a) {
                pos[j] = -1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (pos[i] != -1) {
            cout << "-1";
            return 0;
        }
    }

    int height = 1;
    map<int, int> assigned_heights;
    for (int i = 0; i < n; ++i) {
        people[i].h = assigned_heights[people[i].a] = height++;
        while (assigned_heights.count(height)) {
            height++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << people[i].name << " " << people[i].h << "\n";
    }

    return 0;
}