#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<int> S(H * W);
    for (int i = 0; i < H * W; i++) {
        cin >> S[i];
    }

    vector<int> used(H * W, 0);
    int index = 0;
    bool flag = true;

    for (int i = 0; i < H * W; i++) {
        if (used[S[i]] == 1) {
            flag = false;
            break;
        }
        used[S[i]] = 1;

        if (i % 2 == 0) {
            if (S[i + 1]!= S[i] - 1 && S[i + 1]!= S[i] + 1 && S[i + 1]!= S[i] - W && S[i + 1]!= S[i] + W) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}