#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

Point calculateGrid(const string& s) {
    Point start = {0, 0}, minPoint = {0, 0}, maxPoint = {0, 0};
    Point current = start;

    minPoint.x = minPoint.y = 0;
    maxPoint.x = maxPoint.y = 0;

    for (char c : s) {
        switch (c) {
        case 'W':
            current.y--;
            break;
        case 'S':
            current.y++;
            break;
        case 'A':
            current.x--;
            break;
        case 'D':
            current.x++;
            break;
        }

        minPoint.x = min(minPoint.x, current.x);
        minPoint.y = min(minPoint.y, current.y);
        maxPoint.x = max(maxPoint.x, current.x);
        maxPoint.y = max(maxPoint.y, current.y);
    }

    return {maxPoint.x - minPoint.x + 1, maxPoint.y - minPoint.y + 1};
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int minArea = INT32_MAX;

        // Don't insert any character
        minArea = min(minArea, calculateGrid(s).x * calculateGrid(s).y);

        // Insert 'W'
        string temp = s + "W";
        minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

        // Insert 'S'
        temp = s + "S";
        minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

        // Insert 'A'
        temp = s + "A";
        minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

        // Insert 'D'
        temp = s + "D";
        minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

        // Insert 'W' at the beginning
        temp = "W" + s;
        minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

        // Insert 'S' at the beginning
        temp = "S" + s;
        minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

        // Insert 'A' at the beginning
        temp = "A" + s;
        minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

        // Insert 'D' at the beginning
        temp = "D" + s;
        minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

        // Try inserting at every position
        for (int i = 0; i < s.size(); ++i) {
            temp = s.substr(0, i) + "W" + s.substr(i);
            minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

            temp = s.substr(0, i) + "S" + s.substr(i);
            minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

            temp = s.substr(0, i) + "A" + s.substr(i);
            minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);

            temp = s.substr(0, i) + "D" + s.substr(i);
            minArea = min(minArea, calculateGrid(temp).x * calculateGrid(temp).y);
        }

        cout << minArea << endl;
    }

    return 0;
}