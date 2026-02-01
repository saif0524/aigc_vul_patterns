#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> height(W, 0);
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 0) {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        stack<int> st;
        int w = 0;
        for (int j = 0; j <= W; j++) {
            while (!st.empty() && (j == W || height[st.top()] > height[j])) {
                int h = height[st.top()];
                st.pop();
                w = j;
                if (!st.empty()) {
                    w = j - st.top() - 1;
                }
                ans = max(ans, h * w);
            }
            st.push(j);
        }
    }

    cout << ans << endl;

    return 0;
}