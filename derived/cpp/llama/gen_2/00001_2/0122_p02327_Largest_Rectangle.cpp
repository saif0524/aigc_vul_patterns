#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int index = 0;
    while (index < heights.size()) {
        if (s.empty() || heights[s.top()] <= heights[index]) {
            s.push(index);
            index++;
        } else {
            int top = s.top();
            s.pop();
            int width = s.empty() ? index : index - s.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }
    }
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int width = s.empty() ? index : heights.size() - s.top() - 1;
        maxArea = max(maxArea, heights[top] * width);
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