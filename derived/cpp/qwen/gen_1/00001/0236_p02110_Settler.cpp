#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> points(N);
    for(int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    vector<int> result;
    for(int mask = (1 << N) - 1; mask >= 0; --mask) {
        if(__builtin_popcount(mask) != K) continue;
        bool valid = true;
        for(int i = 0; i < N && valid; ++i) {
            if(mask & (1 << i)) {
                for(int j = i + 1; j < N && valid; ++j) {
                    if(mask & (1 << j)) {
                        int dx = points[i].first - points[j].first;
                        int dy = points[i].second - points[j].second;
                        if(dx * dx + dy * dy < 4) {
                            valid = false;
                        }
                    }
                }
            }
        }
        if(valid) {
            for(int i = 0; i < N; ++i) {
                if(mask & (1 << i)) {
                    result.push_back(i + 1);
                }
            }
            sort(result.begin(), result.end());
            for(int x : result) {
                cout << x << '\n';
            }
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}