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

bool isBlocked(char grid[200][200], int n, bool isZeroes) {
    bool vis[n][n];
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    vis[0][0] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == n - 1 && y == n - 1)
            return false;
        if(x > 0) {
            if((grid[x - 1][y] == '0' && isZeroes) || (grid[x - 1][y] == '1' && !isZeroes) || (x - 1 == 0 && y == 0) || (x - 1 == n - 1 && y == n - 1)) {
                if(!vis[x - 1][y]) {
                    q.push(make_pair(x - 1, y));
                    vis[x - 1][y] = true;
                }
            }
        }
        if(x < n - 1) {
            if((grid[x + 1][y] == '0' && isZeroes) || (grid[x + 1][y] == '1' && !isZeroes) || (x + 1 == 0 && y == 0) || (x + 1 == n - 1 && y == n - 1)) {
                if(!vis[x + 1][y]) {
                    q.push(make_pair(x + 1, y));
                    vis[x + 1][y] = true;
                }
            }
        }
        if(y > 0) {
            if((grid[x][y - 1] == '0' && isZeroes) || (grid[x][y - 1] == '1' && !isZeroes) || (x == 0 && y - 1 == 0) || (x == n - 1 && y - 1 == n - 1)) {
                if(!vis[x][y - 1]) {
                    q.push(make_pair(x, y - 1));
                    vis[x][y - 1] = true;
                }
            }
        }
        if(y < n - 1) {
            if((grid[x][y + 1] == '0' && isZeroes) || (grid[x][y + 1] == '1' && !isZeroes) || (x == 0 && y + 1 == 0) || (x == n - 1 && y + 1 == n - 1)) {
                if(!vis[x][y + 1]) {
                    q.push(make_pair(x, y + 1));
                    vis[x][y + 1] = true;
                }
            }
        }
    }
    return true;
}

void blockPath(char grid[200][200], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char original = grid[i][j];
            if(original == '0') {
                grid[i][j] = '1';
                if(isBlocked(grid, n, false) && isBlocked(grid, n, true)) {
                    cout << "1\n";
                    cout << i + 1 << " " << j + 1 << endl;
                    return;
                }
                grid[i][j] = '0';
            }
            else if(original == '1') {
                grid[i][j] = '0';
                if(isBlocked(grid, n, false) && isBlocked(grid, n, true)) {
                    cout << "1\n";
                    cout << i + 1 << " " << j + 1 << endl;
                    return;
                }
                grid[i][j] = '1';
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char original = grid[i][j];
            if(original == '0') {
                grid[i][j] = '1';
                for(int x = 0; x < n; x++) {
                    for(int y = 0; y < n; y++) {
                        if(grid[x][y] == '1') {
                            char original2 = grid[x][y];
                            grid[x][y] = '0';
                            if(isBlocked(grid, n, false) && isBlocked(grid, n, true)) {
                                cout << "2\n";
                                cout << i + 1 << " " << j + 1 << endl;
                                cout << x + 1 << " " << y + 1 << endl;
                                return;
                            }
                            grid[x][y] = original2;
                        }
                    }
                }
                grid[i][j] = '0';
            }
        }
    }
    cout << "0\n";
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        char grid[200][200];
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cin >> grid[j][k];
            }
        }
        blockPath(grid, n);
    }
    return 0;
}