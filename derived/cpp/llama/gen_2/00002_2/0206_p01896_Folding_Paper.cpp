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
    int l = 0, r = H * W - 1;
    while (l < r) {
        if (S[l] / W == S[r] / W) {
            if (S[l] + 1 == S[r]) {
                used[S[l]] = 1;
                used[S[r]] = 1;
                l++;
                r--;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (S[l] % W == S[r] % W) {
            if (S[l] + W == S[r]) {
                used[S[l]] = 1;
                used[S[r]] = 1;
                l++;
                r--;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (l == r && used[S[l]] == 0) {
        used[S[l]] = 1;
    }
    for (int i = 0; i < H * W; i++) {
        if (used[i] == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}