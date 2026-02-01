#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 128;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    while (true) {
        cin >> input;
        if (input == "#") {
            break;
        }

        bool idempotent = true;
        for (int i = 0; i < MAX_N; ++i) {
            int output = input[i] - '0';
            int newOutput = 0;
            for (int mask = 0; mask < MAX_N; ++mask) {
                int center = (mask >> 3) & 1;
                int neighbors = mask & 7;
                int filterOutput = input[mask] - '0';
                if (center == output && neighbors == i) {
                    newOutput = filterOutput;
                    break;
                }
            }
            if (newOutput != output) {
                idempotent = false;
                break;
            }
        }
        cout << (idempotent ? "yes" : "no") << "\n";
    }

    return 0;
}