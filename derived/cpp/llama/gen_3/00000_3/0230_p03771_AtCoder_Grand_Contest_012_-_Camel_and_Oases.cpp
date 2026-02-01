#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<long long> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    vector<bool> possible(N, false);
    for (int i = 0; i < N; i++) {
        long long water = V;
        bool all_visited = true;
        vector<bool> visited(N, false);
        visited[i] = true;

        for (int t = 0; t < N - 1; t++) {
            bool some_visited = false;
            for (int j = 0; j < N; j++) {
                if (!visited[j]) {
                    long long dist = abs(x[j] - x[i]);
                    if (water >= dist) {
                        water -= dist;
                        i = j;
                        visited[i] = true;
                        some_visited = true;
                    }
                }
            }

            if (!some_visited) {
                if (water > 0) {
                    water /= 2;
                } else {
                    all_visited = false;
                    break;
                }
            }
        }

        if (all_visited) {
            possible[i] = true;
        }
    }

    for (bool p : possible) {
        cout << (p ? "Possible" : "Impossible") << endl;
    }

    return 0;
}