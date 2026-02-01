#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct State {
    int x, y, water;
    State(int x, int y, int water) : x(x), y(y), water(water) {}
};

int main() {
    int n, k;
    cin >> n >> k;

    string left, right;
    cin >> left >> right;

    vector<vector<bool>> visited(2, vector<bool>(n, false));

    queue<State> q;
    q.push(State(0, 0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        State state = q.front();
        q.pop();

        if (state.x + k >= n) {
            cout << "YES" << endl;
            return 0;
        }

        int nextWater = state.water + 1;

        // climb up
        if (state.x + 1 < n &&!visited[state.y][state.x + 1] && (state.y == 0? left[state.x + 1] : right[state.x + 1])!= 'X' && state.x + 1 >= nextWater) {
            q.push(State(state.x + 1, state.y, nextWater));
            visited[state.y][state.x + 1] = true;
        }

        // climb down
        if (state.x - 1 >= 0 &&!visited[state.y][state.x - 1] && (state.y == 0? left[state.x - 1] : right[state.x - 1])!= 'X' && state.x - 1 >= nextWater) {
            q.push(State(state.x - 1, state.y, nextWater));
            visited[state.y][state.x - 1] = true;
        }

        // jump
        if (!visited[1 - state.y][state.x + k] && (state.y == 0? right[state.x + k] : left[state.x + k])!= 'X' && state.x + k >= nextWater) {
            q.push(State(state.x + k, 1 - state.y, nextWater));
            visited[1 - state.y][state.x + k] = true;
        }
    }

    cout << "NO" << endl;
    return 0;
}