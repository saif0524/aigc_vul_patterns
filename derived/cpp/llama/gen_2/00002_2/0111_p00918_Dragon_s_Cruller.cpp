#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>

using namespace std;

const int INF = 1e9;

struct State {
    int board[3][3];
    int cost;
    int h;
    int v;
    int f;
    State* parent;

    State(int ch, int cv) : h(ch), v(cv), cost(0), f(0), parent(nullptr) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = 0;
            }
        }
    }

    State(const State& other) : h(other.h), v(other.v), cost(other.cost), f(other.f), parent(other.parent) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = other.board[i][j];
            }
        }
    }

    bool operator<(const State& other) const {
        return f > other.f;
    }

    bool operator==(const State& other) const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j]!= other.board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int ch, cv;
    while (cin >> ch >> cv) {
        if (ch == 0 && cv == 0) {
            break;
        }

        State start(ch, cv);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> start.board[i][j];
            }
        }

        State goal(ch, cv);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> goal.board[i][j];
            }
        }

        priority_queue<State> pq;
        pq.push(start);

        unordered_map<string, int> visited;
        string startStr;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                startStr += to_string(start.board[i][j]);
            }
        }
        visited[startStr] = 0;

        while (!pq.empty()) {
            State currentState = pq.top();
            pq.pop();

            if (currentState == goal) {
                cout << currentState.cost << endl;
                break;
            }

            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (currentState.board[i][j] == 0) {
                        for (const auto& dir : directions) {
                            int ni = (i + dir.first + 3) % 3;
                            int nj = (j + dir.second + 3) % 3;
                            if (currentState.board[ni][nj]!= 0) {
                                State newState(currentState);
                                swap(newState.board[i][j], newState.board[ni][nj]);
                                newState.cost = currentState.cost + (dir.first == 0? currentState.h : currentState.v);
                                string newStateStr;
                                for (int k = 0; k < 3; k++) {
                                    for (int l = 0; l < 3; l++) {
                                        newStateStr += to_string(newState.board[k][l]);
                                    }
                                }
                                if (visited.find(newStateStr) == visited.end() || visited[newStateStr] > newState.cost) {
                                    visited[newStateStr] = newState.cost;
                                    newState.f = newState.cost;
                                    newState.parent = &currentState;
                                    pq.push(newState);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}