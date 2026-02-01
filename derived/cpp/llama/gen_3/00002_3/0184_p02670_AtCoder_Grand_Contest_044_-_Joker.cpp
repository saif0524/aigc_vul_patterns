#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> P(N * N);
    for (int i = 0; i < N * N; ++i) {
        cin >> P[i];
        P[i]--;
    }

    vector<pair<int, int>> positions(N * N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            positions[i * N + j] = {i, j};
        }
    }

    set<pair<int, int>> viewers;
    int answer = 0;

    for (int p : P) {
        auto [x, y] = positions[p];
        if (x > 0) {
            auto it = viewers.lower_bound({x - 1, y});
            while (it!= viewers.end() && it->first == x - 1 && it->second > y) {
                answer++;
                it = viewers.erase(it);
            }
            it = viewers.lower_bound({x - 1, y});
            while (it!= viewers.begin() && prev(it)->first == x - 1 && prev(it)->second < y) {
                answer++;
                viewers.erase(prev(it));
            }
        }
        if (y > 0) {
            auto it = viewers.lower_bound({x, y - 1});
            while (it!= viewers.end() && it->first == x && it->second > y - 1) {
                answer++;
                it = viewers.erase(it);
            }
            it = viewers.lower_bound({x, y - 1});
            while (it!= viewers.begin() && prev(it)->first == x && prev(it)->second < y - 1) {
                answer++;
                viewers.erase(prev(it));
            }
        }
        if (x < N - 1) {
            auto it = viewers.lower_bound({x + 1, y});
            while (it!= viewers.end() && it->first == x + 1 && it->second > y) {
                answer++;
                it = viewers.erase(it);
            }
            it = viewers.lower_bound({x + 1, y});
            while (it!= viewers.begin() && prev(it)->first == x + 1 && prev(it)->second < y) {
                answer++;
                viewers.erase(prev(it));
            }
        }
        if (y < N - 1) {
            auto it = viewers.lower_bound({x, y + 1});
            while (it!= viewers.end() && it->first == x && it->second > y + 1) {
                answer++;
                it = viewers.erase(it);
            }
            it = viewers.lower_bound({x, y + 1});
            while (it!= viewers.begin() && prev(it)->first == x && prev(it)->second < y + 1) {
                answer++;
                viewers.erase(prev(it));
            }
        }
        viewers.insert({x, y});
    }

    cout << answer << '\n';

    return 0;
}