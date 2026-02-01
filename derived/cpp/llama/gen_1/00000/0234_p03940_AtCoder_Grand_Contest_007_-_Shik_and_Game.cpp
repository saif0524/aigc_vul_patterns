#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N, E, T;
    cin >> N >> E >> T;

    vector<long long> bears(N);
    for (auto& bear : bears) {
        cin >> bear;
    }

    long long time = 0;
    long long current_position = 0;
    long long coins_picked = 0;
    long long to_give = N;

    while (coins_picked < N || current_position < E) {
        if (to_give > 0 && current_position == bears[to_give - 1]) {
            to_give--;
            time = time + T;
        } else if (coins_picked < N && time >= T + bears[coins_picked]) {
            coins_picked++;
            if (current_position < bears[coins_picked - 1]) {
                time += bears[coins_picked - 1] - current_position;
                current_position = bears[coins_picked - 1];
            }
        } else if (current_position < E) {
            time += E - current_position;
            current_position = E;
        } else {
            time++;
            current_position++;
        }
    }

    cout << time << endl;

    return 0;
}