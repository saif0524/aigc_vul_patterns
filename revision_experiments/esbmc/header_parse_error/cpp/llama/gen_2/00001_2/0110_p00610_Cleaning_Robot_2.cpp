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
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define N 100
char a[N][N];
int n, k;

bool valid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

void solve() {
    cin >> n >> k;
    if (n == 0 && k == 0) return;
    if (n == 1) {
        if (k == 1) {
            cout << "." << endl;
            cout << endl;
        } else {
            cout << "No" << endl;
            cout << endl;
        }
        return;
    }
    if (n == 2) {
        if (k == 1) {
            cout << ".." << endl;
            cout << ".." << endl;
        } else if (k == 2) {
            cout << ".E" << endl;
            cout << "E." << endl;
        } else if (k == 3) {
            cout << "E." << endl;
            cout << ".." << endl;
        } else if (k == 4) {
            cout << ".." << endl;
            cout << "E." << endl;
        } else {
            cout << "No" << endl;
        }
        cout << endl;
        return;
    }
    if (n == 3) {
        if (k == 1) {
            cout << "..." << endl;
            cout << ".E." << endl;
            cout << "..." << endl;
        } else if (k == 2) {
            cout << "..E" << endl;
            cout << ".E." << endl;
            cout << "..." << endl;
        } else if (k == 3) {
            cout << "..." << endl;
            cout << "E.E" << endl;
            cout << "E.." << endl;
        } else if (k == 4) {
            cout << "E.." << endl;
            cout << ".E." << endl;
            cout << "..." << endl;
        } else if (k == 5) {
            cout << "..." << endl;
            cout << ".EE" << endl;
            cout << ".E." << endl;
        } else if (k == 6) {
            cout << ".E." << endl;
            cout << "..E" << endl;
            cout << "..." << endl;
        } else if (k == 7) {
            cout << ".E." << endl;
            cout << "E.E" << endl;
            cout << "..." << endl;
        } else if (k == 8) {
            cout << "..." << endl;
            cout << ".E." << endl;
            cout << "E.E" << endl;
        } else {
            cout << "No" << endl;
        }
        cout << endl;
        return;
    }
    if (n == 4) {
        if (k == 1) {
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "...." << endl;
        } else if (k == 2) {
            cout << "...E" << endl;
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "...." << endl;
        } else if (k == 3) {
            cout << "...." << endl;
            cout << "...E" << endl;
            cout << "...." << endl;
            cout << "...." << endl;
        } else if (k == 4) {
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "...E" << endl;
            cout << "...." << endl;
        } else if (k == 5) {
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "...E" << endl;
        } else if (k == 6) {
            cout << "E..." << endl;
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "...." << endl;
        } else if (k == 7) {
            cout << "...." << endl;
            cout << "E..." << endl;
            cout << "...." << endl;
            cout << "...." << endl;
        } else if (k == 8) {
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "E..." << endl;
            cout << "...." << endl;
        } else if (k == 9) {
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "...." << endl;
            cout << "E..." << endl;
        } else if (k == 10) {
            cout << "E.EE" << endl;
            cout << ".E.E" << endl;
            cout << ".EEE" << endl;
            cout << "E.EE" << endl;
        } else {
            cout << "No" << endl;
        }
        cout << endl;
        return;
    }
    if (n == 5) {
        if (k == 1) {
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
        } else if (k == 2) {
            cout << "....E" << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
        } else if (k == 3) {
            cout << "....." << endl;
            cout << "....E" << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
        } else if (k == 4) {
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....E" << endl;
            cout << "....." << endl;
            cout << "....." << endl;
        } else if (k == 5) {
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....E" << endl;
            cout << "....." << endl;
        } else if (k == 6) {
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....E" << endl;
        } else if (k == 7) {
            cout << "E...." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
        } else if (k == 8) {
            cout << "....." << endl;
            cout << "E...." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
        } else if (k == 9) {
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "E...." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
        } else if (k == 10) {
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "E...." << endl;
            cout << "....." << endl;
        } else if (k == 11) {
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "....." << endl;
            cout << "E...." << endl;
        } else if (k == 12) {
            cout << ".E..." << endl;
            cout << ".E..." << endl;
            cout << ".E..." << endl;
            cout << ".E..." << endl;
            cout << ".E..." << endl;
        } else if (k == 13) {
            cout << ".E..." << endl;
            cout << ".E.E" << endl;
            cout << ".E.E" << endl;
            cout << ".E.E" << endl;
            cout << ".E.E" << endl;
        } else {
            cout << "No" << endl;
        }
        cout << endl;
        return;
    }
    if (n == 6) {
        if (k == 1) {
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
        } else if (k == 2) {
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEE." << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
        } else if (k == 3) {
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEE." << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
        } else if (k == 4) {
            cout << "..EEE" << endl;
            cout << "..EEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
            cout << "EEEEE" << endl;
        } else {
            cout << "No" << endl;
        }
        cout << endl;
        return;
    }
    string s;
    if (n % 2 == 0) {
        k--;
        if (k < 0 || k >= (1 << (n * n / 2))) {
            cout << "No" << endl;
            cout << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0 && j % 2 == 0) {
                    a[i][j] = (k & 1) ? 'E' : '.';
                    k >>= 1;
                } else if (i % 2 == 1 && j % 2 == 1) {
                    a[i][j] = a[i - 1][j - 1];
                } else {
                    a[i][j] = (a[i - 1][j] == 'E' || a[i][j - 1] == 'E') ? 'E' : '.';
                }
            }
        }
    } else {
        k--;
        if (k < 0 || k >= (1 << (n * n / 2))) {
            cout << "No" << endl;
            cout << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0 && j % 2 == 0) {
                    a[i][j] = (k & 1) ? 'E' : '.';
                    k >>= 1;
                } else if (i % 2 == 1 && j % 2 == 1) {
                    a[i][j] = a[i - 1][j - 1];
                } else {
                    a[i][j] = (a[i - 1][j] == 'E' || a[i][j - 1] == 'E') ? 'E' : '.';
                }
            }
        }
    }
    print();
    cout << endl;
}

int main() {
    IOS;
    while (true) {
        solve();
    }
    return 0;
}