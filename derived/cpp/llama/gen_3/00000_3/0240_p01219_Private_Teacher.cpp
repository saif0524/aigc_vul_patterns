#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> dayMap = {
    {"Sunday", 0},
    {"Monday", 1},
    {"Tuesday", 2},
    {"Wednesday", 3},
    {"Thursday", 4},
    {"Friday", 5},
    {"Saturday", 6}
};

int main() {
    int n, w;
    while (cin >> n >> w) {
        if (n == 0 && w == 0) break;
        vector<int> lessons(n);
        vector<vector<int>> days(n);
        for (int i = 0; i < n; ++i) {
            string str;
            int c;
            cin >> lessons[i] >> c;
            getline(cin, str); // consume newline character
            getline(cin, str);
            istringstream iss(str);
            string day;
            while (iss >> day) {
                days[i].push_back(dayMap[day]);
            }
        }
        vector<vector<bool>> weeks(w, vector<bool>(7, false));
        int totalLessons = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < w; ++j) {
                for (int k = 0; k < days[i].size(); ++k) {
                    if (!weeks[j][days[i][k]]) {
                        weeks[j][days[i][k]] = true;
                        lessons[i]--;
                        totalLessons++;
                        break;
                    }
                }
                if (lessons[i] == 0) break;
            }
        }
        bool canFinish = true;
        for (int i = 0; i < n; ++i) {
            if (lessons[i] > 0) {
                canFinish = false;
                break;
            }
        }
        if (canFinish) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}