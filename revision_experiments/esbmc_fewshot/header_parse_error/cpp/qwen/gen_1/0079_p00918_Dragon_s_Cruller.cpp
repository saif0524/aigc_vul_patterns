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

const int INF = 1e9;
const int MAXN =30;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct State {
    string board;
    int cost;
    bool operator<(const State& other) const {
        return cost > other.cost;
    }
};

string getGoal(int n, int m) {
    string goal = "";
    for (int i = 0; i < n * m; ++i) {
        if (i == 0) goal += '0';
        else goal += ('0' + i);
    }
    return goal;
}

int getPos(char c) {
    if (c == '0') return 0;
    return c - '0';
}

string move(string board, int x, int y, int dir, int n, int m) {
    int nx = (x + dx[dir] + n) % n;
    int ny = (y + dy[dir] + m) % m;
    swap(board[x * m + y], board[nx * m + ny]);
    return board;
}

int bfs(string start, string goal, int ch, int cv, int n, int m) {
    priority_queue<State> pq;
    unordered_map<string, int> dist;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        if (curr.board == goal) return curr.cost;

        int zeroPos = curr.board.find('0');
        int zx = zeroPos / m;
        int zy = zeroPos % m;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = (zx + dx[dir] + n) % n;
            int ny = (zy + dy[dir] + m) % m;
            string newBoard = move(curr.board, zx, zy, dir, n, m);
            int newCost = curr.cost + (dir < 2 ? ch : cv);

            if (!dist.count(newBoard) || dist[newBoard] > newCost) {
                dist[newBoard] = newCost;
                pq.push({newBoard, newCost});
            }
        }
    }

    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int ch, cv;
        cin >> ch >> cv;
        if (ch == 0 && cv == 0) break;

        string start = "", goal = "";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char c;
                cin >> c;
                start += c;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char c;
                cin >> c;
                goal += c;
            }
        }

        int result = bfs(start, goal, ch, cv, 3, 3);
        cout << result << "\n";
    }

    return 0;
}