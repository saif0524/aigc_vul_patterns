#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    vector<int> c(2 * N);
    vector<int> door_count(N + 1, 0);

    int c_idx = 0;
    int next_color = 1;
    int next_unused_color = 1;

    while (c_idx < 2 * N) {
        if (s[c_idx] == '1') {
            c[c_idx] = next_color;
            door_count[next_color]++;
            if (door_count[next_color] == 2) {
                next_color = next_unused_color;
                while (door_count[next_color] == 2) {
                    next_color++;
                }
            }
        } else {
            c[c_idx] = next_unused_color;
            door_count[next_unused_color]++;
            next_unused_color++;
        }
        c_idx++;
    }

    for (int i = 1; i <= N; i++) {
        if (door_count[i] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < 2 * N; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}