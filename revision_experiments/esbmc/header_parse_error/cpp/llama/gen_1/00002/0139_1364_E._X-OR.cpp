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
    cin >> n;

    vector<int> p(n, -1);

    for (int i = 0; i < n; ++i) {
        cout << "? " << i + 1 << " " << (i + 1) % n + 1 << endl;
        int resp;
        cin >> resp;
        p[i] = resp;
    }

    vector<int> unique_p(n);
    iota(unique_p.begin(), unique_p.end(), 0);

    sort(unique_p.begin(), unique_p.end(), [&](int a, int b) {
        return p[a] < p[b];
    });

    vector<int> guessed_p(n, -1);
    guessed_p[unique_p[0]] = 0;

    for (int i = 1; i < n; ++i) {
        int curr = unique_p[i];
        int prev = unique_p[i - 1];

        cout << "? " << curr + 1 << " " << prev + 1 << endl;
        int resp;
        cin >> resp;

        int pos = -1;
        for (int j = 0; j < n; ++j) {
            if (j == curr) continue;
            if ((p[j] | p[curr]) == resp) {
                pos = j;
                break;
            }
        }

        if (pos == -1) {
            cout << "! ";
            for (int j = 0; j < n; ++j) {
                cout << p[j] << " ";
            }
            cout << endl;
            return 0;
        }

        guessed_p[curr] = guessed_p[pos];
    }

    for (int i = 0; i < n; ++i) {
        if (guessed_p[i] == -1) {
            for (int j = 0; j < n; ++j) {
                if (count(guessed_p.begin(), guessed_p.end(), j) == 0) {
                    guessed_p[i] = j;
                    break;
                }
            }
        }
    }

    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << guessed_p[i] << " ";
    }
    cout << endl;

    return 0;
}