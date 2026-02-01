#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int a, b, k, t;
    cin >> a >> b >> k >> t;

    long long count = 0;
    vector<int> memory_scores(t + 1, 0);
    vector<int> lexa_scores(t + 1, 0);

    function<void(int)> solve = [&](int turn) {
        if (turn == t) {
            if (a + memory_scores[t] > b + lexa_scores[t]) {
                count = (count + 1) % MOD;
            }
            return;
        }

        for (int i = -k; i <= k; ++i) {
            memory_scores[turn] = i;
            for (int j = -k; j <= k; ++j) {
                lexa_scores[turn] = j;
                solve(turn + 1);
            }
        }
    };

    solve(0);

    cout << count << endl;

    return 0;
}