#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int min_area = -1;

        // Calculate area without insertion
        int x = 0, y = 0;
        int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
        for (char c : s) {
            if (c == 'W') y++;
            else if (c == 'S') y--;
            else if (c == 'A') x--;
            else if (c == 'D') x++;

            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
        }

        int area = (max_x - min_x + 1) * (max_y - min_y + 1);
        if (min_area == -1 || area < min_area) {
            min_area = area;
        }

        // Try inserting 'W'
        for (int i = 0; i <= s.length(); ++i) {
            string temp_s = s;
            temp_s.insert(i, "W");
            x = 0, y = 0;
            min_x = 0, max_x = 0, min_y = 0, max_y = 0;
            for (char c : temp_s) {
                if (c == 'W') y++;
                else if (c == 'S') y--;
                else if (c == 'A') x--;
                else if (c == 'D') x++;

                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
            area = (max_x - min_x + 1) * (max_y - min_y + 1);
            if (min_area == -1 || area < min_area) {
                min_area = area;
            }
        }

        // Try inserting 'A'
        for (int i = 0; i <= s.length(); ++i) {
            string temp_s = s;
            temp_s.insert(i, "A");
            x = 0, y = 0;
            min_x = 0, max_x = 0, min_y = 0, max_y = 0;
            for (char c : temp_s) {
                if (c == 'W') y++;
                else if (c == 'S') y--;
                else if (c == 'A') x--;
                else if (c == 'D') x++;

                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
            area = (max_x - min_x + 1) * (max_y - min_y + 1);
            if (min_area == -1 || area < min_area) {
                min_area = area;
            }
        }

        // Try inserting 'S'
        for (int i = 0; i <= s.length(); ++i) {
            string temp_s = s;
            temp_s.insert(i, "S");
            x = 0, y = 0;
            min_x = 0, max_x = 0, min_y = 0, max_y = 0;
            for (char c : temp_s) {
                if (c == 'W') y++;
                else if (c == 'S') y--;
                else if (c == 'A') x--;
                else if (c == 'D') x++;

                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
            area = (max_x - min_x + 1) * (max_y - min_y + 1);
            if (min_area == -1 || area < min_area) {
                min_area = area;
            }
        }

        // Try inserting 'D'
        for (int i = 0; i <= s.length(); ++i) {
            string temp_s = s;
            temp_s.insert(i, "D");
            x = 0, y = 0;
            min_x = 0, max_x = 0, min_y = 0, max_y = 0;
            for (char c : temp_s) {
                if (c == 'W') y++;
                else if (c == 'S') y--;
                else if (c == 'A') x--;
                else if (c == 'D') x++;

                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
            area = (max_x - min_x + 1) * (max_y - min_y + 1);
            if (min_area == -1 || area < min_area) {
                min_area = area;
            }
        }

        cout << min_area << endl;
    }

    return 0;
}