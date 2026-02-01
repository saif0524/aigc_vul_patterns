#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(const vector<int>& heights) {
    stack<int> stack;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i <= n; ++i) {
        while (!stack.empty() && (i == n || heights[stack.top()] >= heights[i])) {
            int h = heights[stack.top()];
            stack.pop();
            int width = stack.empty() ? i : i - stack.top() - 1;
            maxArea = max(maxArea, width * h);
        }
        stack.push(i);
    }
    return maxArea;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> matrix(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> matrix[i][j];
        }
    }

    int maxArea = 0;
    vector<int> heights(W, 0);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            heights[j] = matrix[i][j] == 0 ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    cout << maxArea << endl;
    return 0;
}