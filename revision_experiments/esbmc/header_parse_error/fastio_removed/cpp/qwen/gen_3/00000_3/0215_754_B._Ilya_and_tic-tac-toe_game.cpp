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

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool can_win(vector<string>& board, int x, int y) {
    board[x][y] = 'x';
    for(int d = 0; d < 8; ++d) {
        int x1 = x + dx[d], y1 = y + dy[d], x2 = x + 2 * dx[d], y2 = y + 2 * dy[d];
        if(x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4 && x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4) {
            if(board[x1][y1] == 'x' && board[x2][y2] == 'x') {
                board[x][y] = '.';
                return true;
            }
        }
    }
    board[x][y] = '.';
    return false;
}

int main(){
    ((void)0);
    ((void)0);
    vector<string> board(4);
    for(int i = 0; i < 4; ++i) cin >> board[i];
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(board[i][j] == '.') {
                if(can_win(board, i, j)) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}