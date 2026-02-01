#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int x = 0, y = 0;
        int minX = 0, minY = 0;
        int maxX = 0, maxY = 0;

        for (char c : s) {
            if (c == 'W') {
                y++;
            } else if (c == 'S') {
                y--;
            } else if (c == 'A') {
                x--;
            } else if (c == 'D') {
                x++;
            }

            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }

        int area = (maxX - minX + 1) * (maxY - minY + 1);

        int minXInsert = Integer::MAX_VALUE, minYInsert = Integer::MAX_VALUE;
        int maxXInsert = Integer::MIN_VALUE, maxYInsert = Integer::MIN_VALUE;

        for (int i = 0; i <= s.length(); i++) {
            x = 0;
            y = 0;
            int tempMinX = 0, tempMinY = 0;
            int tempMaxX = 0, tempMaxY = 0;

            for (int j = 0; j < i; j++) {
                if (s[j] == 'W') {
                    y++;
                } else if (s[j] == 'S') {
                    y--;
                } else if (s[j] == 'A') {
                    x--;
                } else if (s[j] == 'D') {
                    x++;
                }

                tempMinX = min(tempMinX, x);
                tempMinY = min(tempMinY, y);
                tempMaxX = max(tempMaxX, x);
                tempMaxY = max(tempMaxY, y);
            }

            if (i < s.length()) {
                if (s[i] == 'W') {
                    y++;
                } else if (s[i] == 'S') {
                    y--;
                } else if (s[i] == 'A') {
                    x--;
                } else if (s[i] == 'D') {
                    x++;
                }
            } else {
                y++;
            }

            tempMinX = min(tempMinX, x);
            tempMinY = min(tempMinY, y);
            tempMaxX = max(tempMaxX, x);
            tempMaxY = max(tempMaxY, y);

            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == 'W') {
                    y++;
                } else if (s[j] == 'S') {
                    y--;
                } else if (s[j] == 'A') {
                    x--;
                } else if (s[j] == 'D') {
                    x++;
                }

                tempMinX = min(tempMinX, x);
                tempMinY = min(tempMinY, y);
                tempMaxX = max(tempMaxX, x);
                tempMaxY = max(tempMaxY, y);
            }

            minXInsert = min(minXInsert, (tempMaxX - tempMinX + 1) * (tempMaxY - tempMinY + 1));

            x = 0;
            y = 0;
            tempMinX = 0;
            tempMinY = 0;
            tempMaxX = 0;
            tempMaxY = 0;

            for (int j = 0; j < i; j++) {
                if (s[j] == 'W') {
                    y++;
                } else if (s[j] == 'S') {
                    y--;
                } else if (s[j] == 'A') {
                    x--;
                } else if (s[j] == 'D') {
                    x++;
                }

                tempMinX = min(tempMinX, x);
                tempMinY = min(tempMinY, y);
                tempMaxX = max(tempMaxX, x);
                tempMaxY = max(tempMaxY, y);
            }

            if (i < s.length()) {
                if (s[i] == 'W') {
                    y++;
                } else if (s[i] == 'S') {
                    y--;
                } else if (s[i] == 'A') {
                    x--;
                } else if (s[i] == 'D') {
                    x++;
                }
            } else {
                x--;
            }

            tempMinX = min(tempMinX, x);
            tempMinY = min(tempMinY, y);
            tempMaxX = max(tempMaxX, x);
            tempMaxY = max(tempMaxY, y);

            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == 'W') {
                    y++;
                } else if (s[j] == 'S') {
                    y--;
                } else if (s[j] == 'A') {
                    x--;
                } else if (s[j] == 'D') {
                    x++;
                }

                tempMinX = min(tempMinX, x);
                tempMinY = min(tempMinY, y);
                tempMaxX = max(tempMaxX, x);
                tempMaxY = max(tempMaxY, y);
            }

            minXInsert = min(minXInsert, (tempMaxX - tempMinX + 1) * (tempMaxY - tempMinY + 1));

            x = 0;
            y = 0;
            tempMinX = 0;
            tempMinY = 0;
            tempMaxX = 0;
            tempMaxY = 0;

            for (int j = 0; j < i; j++) {
                if (s[j] == 'W') {
                    y++;
                } else if (s[j] == 'S') {
                    y--;
                } else if (s[j] == 'A') {
                    x--;
                } else if (s[j] == 'D') {
                    x++;
                }

                tempMinX = min(tempMinX, x);
                tempMinY = min(tempMinY, y);
                tempMaxX = max(tempMaxX, x);
                tempMaxY = max(tempMaxY, y);
            }

            if (i < s.length()) {
                if (s[i] == 'W') {
                    y++;
                } else if (s[i] == 'S') {
                    y--;
                } else if (s[i] == 'A') {
                    x--;
                } else if (s[i] == 'D') {
                    x++;
                }
            } else {
                y--;
            }

            tempMinX = min(tempMinX, x);
            tempMinY = min(tempMinY, y);
            tempMaxX = max(tempMaxX, x);
            tempMaxY = max(tempMaxY, y);

            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == 'W') {
                    y++;
                } else if (s[j] == 'S') {
                    y--;
                } else if (s[j] == 'A') {
                    x--;
                } else if (s[j] == 'D') {
                    x++;
                }

                tempMinX = min(tempMinX, x);
                tempMinY = min(tempMinY, y);
                tempMaxX = max(tempMaxX, x);
                tempMaxY = max(tempMaxY, y);
            }

            minXInsert = min(minXInsert, (tempMaxX - tempMinX + 1) * (tempMaxY - tempMinY + 1));

            x = 0;
            y = 0;
            tempMinX = 0;
            tempMinY = 0;
            tempMaxX = 0;
            tempMaxY = 0;

            for (int j = 0; j < i; j++) {
                if (s[j] == 'W') {
                    y++;
                } else if (s[j] == 'S') {
                    y--;
                } else if (s[j] == 'A') {
                    x--;
                } else if (s[j] == 'D') {
                    x++;
                }

                tempMinX = min(tempMinX, x);
                tempMinY = min(tempMinY, y);
                tempMaxX = max(tempMaxX, x);
                tempMaxY = max(tempMaxY, y);
            }

            if (i < s.length()) {
                if (s[i] == 'W') {
                    y++;
                } else if (s[i] == 'S') {
                    y--;
                } else if (s[i] == 'A') {
                    x--;
                } else if (s[i] == 'D') {
                    x++;
                }
            } else {
                x++;
            }

            tempMinX = min(tempMinX, x);
            tempMinY = min(tempMinY, y);
            tempMaxX = max(tempMaxX, x);
            tempMaxY = max(tempMaxY, y);

            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == 'W') {
                    y++;
                } else if (s[j] == 'S') {
                    y--;
                } else if (s[j] == 'A') {
                    x--;
                } else if (s[j] == 'D') {
                    x++;
                }

                tempMinX = min(tempMinX, x);
                tempMinY = min(tempMinY, y);
                tempMaxX = max(tempMaxX, x);
                tempMaxY = max(tempMaxY, y);
            }

            minXInsert = min(minXInsert, (tempMaxX - tempMinX + 1) * (tempMaxY - tempMinY + 1));
        }

        area = min(area, minXInsert);
        cout << area << endl;
    }

    return 0;
}