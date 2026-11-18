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

struct State {
    int pos[3];
    string s[3];
    string word;

    State(int n, const string& w) {
        for (int i = 0; i < 3; ++i) {
            pos[i] = 0;
        }
        word = w;
    }

    bool check() {
        int fp[3];
        for (int i = 0; i < 3; ++i) {
            fp[i] = 0;
        }

        for (int i = 0; i < 3; ++i) {
            for (char c : s[i]) {
                bool found = false;
                while (fp[i] < word.size() && word[fp[i]] != c) {
                    fp[i]++;
                }
                if (fp[i] == word.size()) {
                    return false;
                }
                fp[i]++;
                for (int j = 0; j < 3; ++j) {
                    if (i != j) {
                        for (; fp[j] < fp[i]; ++fp[j]) {
                            if (word[fp[j]] == c) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    ((void)0);
    ((void)0);
    int n, q;
    cin >> n >> q;
    string word;
    cin >> word;
    State state(n, word);

    for (int i = 0; i < q; ++i) {
        char op, c;
        int ID;
        cin >> op;
        if (op == '+') {
            cin >> ID >> c;
            ID--;
            state.s[ID] += c;
        } else {
            cin >> ID;
            ID--;
            state.s[ID].pop_back();
        }
        if (state.check()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}