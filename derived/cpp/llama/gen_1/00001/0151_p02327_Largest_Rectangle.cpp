#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ) {
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            maxArea = max(maxArea, heights[top] * (s.empty() ? i : i - s.top() - 1));
        }
    }
    return maxArea;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> matrix(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> matrix[i][j];
        }
    }
    int maxArea = 0;
    vector<int> heights(W, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            heights[j] = matrix[i][j] == 0 ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    cout << maxArea << endl;
    return 0;
}