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

const int MAXN = 100005;
const int MAXQ = 1005;
const int MAXC = 26;
const int MAXR = 4;

int n, q;
string s;
string r[MAXR];
vector<int> pos[MAXC];

inline bool check() {
    int last[4] = {0, 0, 0, 0};
    for (int i = 1; i <= 3; i++) {
        for (char c: r[i]) {
            int cc = c - 'a';
            bool found = false;
            for (int j = pos[cc].size() - 1; j >= 0; j--) {
                if (pos[cc][j] >= last[i]) {
                    last[i] = pos[cc][j] + 1;
                    pos[cc].erase(pos[cc].begin() + j);
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        for (int c = 0; c < MAXC; c++) {
            pos[c].resize(0);
        }
        for (int j = 0; j < n; j++) {
            pos[s[j] - 'a'].push_back(j);
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    cin >> s;
    for(int j = 0; j < n; j++){
        pos[s[j]-'a'].push_back(j);
    }
    for(int i = 0; i < q; i++){
        char t;
        cin >> t;
        if(t == '+'){
            int idx;
            char c;
            cin >> idx >> c;
            r[idx] += c;
        }
        else{
            int idx;
            cin >> idx;
            r[idx].pop_back();
        }
        if(check()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}