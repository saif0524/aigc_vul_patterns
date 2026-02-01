#include <bits/stdc++.h>
using namespace std;

int calc(string s) {
    int minx = 0, maxx = 0, miny = 0, maxy = 0;
    int x = 0, y = 0;

    for (char c : s) {
        if (c == 'W') y++;
        if (c == 'S') y--;
        if (c == 'A') x--;
        if (c == 'D') x++;

        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    return (maxx - minx + 1) * (maxy - miny + 1);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int ans = INT_MAX;
        ans = min(ans, calc(s + "W"));
        ans = min(ans, calc(s + "A"));
        ans = min(ans, calc(s + "S"));
        ans = min(ans, calc(s + "D"));

        for (int i = 0; i < s.size(); i++) {
            string temp = s;
            temp.insert(i, "W");
            ans = min(ans, calc(temp));
            temp = s;
            temp.insert(i, "A");
            ans = min(ans, calc(temp));
            temp = s;
            temp.insert(i, "S");
            ans = min(ans, calc(temp));
            temp = s;
            temp.insert(i, "D");
            ans = min(ans, calc(temp));
        }

        cout << ans << "\n";
    }

    return 0;
}