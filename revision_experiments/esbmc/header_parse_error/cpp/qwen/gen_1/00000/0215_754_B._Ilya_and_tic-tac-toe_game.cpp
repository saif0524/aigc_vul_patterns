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

bool checkWin(vector<string>& board, char player) {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(board[i][j] != '.') continue;
            board[i][j] = player;
            for(int x = 0; x < 4; ++x) {
                if(board[x][0] == player && board[x][1] == player && board[x][2] == player) {
                    board[i][j] = '.';
                    return true;
                }
                if(board[0][x] == player && board[1][x] == player && board[2][x] == player) {
                    board[i][j] = '.';
                    return true;
                }
            }
            if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
                board[i][j] = '.';
                return true;
            }
            if(board[0][3] == player && board[1][2] == player && board[2][1] == player) {
                board[i][j] = '.';
                return true;
            }
            board[i][j] = '.';
        }
    }
    return false;
}

int main(){
    vector<string> board(4);
    for(auto &row : board) cin >> row;
    if(checkWin(board, 'x')) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}