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

#define ll long long
#define pb push_back

const int maxn = 1005;
const int INF = 1e9;

int x, y;
int rooks[666][2];
bool vis[1005][1005];

void move(int nx, int ny) {
    if (vis[nx][ny]) {
        cout << 0 << " " << 0 << endl;
        exit(0);
    }
    cout << nx << " " << ny << endl;
    x = nx;
    y = ny;
    int k, rx, ry;
    cin >> k >> rx >> ry;
    if (k < 0) return;
    k--;
    rooks[k][0] = rx;
    rooks[k][1] = ry;
}

int main() {
    ((void)0);
    ((void)0);

    cin >> x >> y;
    for (int i = 0; i < 666; i++) {
        cin >> rooks[i][0] >> rooks[i][1];
        vis[rooks[i][0]][rooks[i][1]] = true;
    }

    while (x > 1 || y > 1) {
        if (x > 1 && (x - 1 == rooks[0][0] || y == rooks[0][1])) {
            move(x, y - 1);
        } else if (y > 1) {
            move(x - 1, y - 1);
        } else {
            move(x - 1, y);
        }
    }

    int i = 1;
    int j = 1;

    while (i < 1000) {
        while (vis[i][j]) j++;
        if (j != y) move(i, j - 1);
        else move(i, j);
        i++;
    }

    i = 1;
    j = 1000;

    while (i < 1000) {
        while (vis[i][j]) j--;
        if (j != y) move(i, j + 1);
        else move(i, j);
        i++;
    }
}