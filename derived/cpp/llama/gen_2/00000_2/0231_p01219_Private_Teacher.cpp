#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int daysOfWeek(string day) {
    map<string, int> days = {{"Sunday", 0}, {"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6}};
    return days[day];
}

int main() {
    int n, w;
    while (cin >> n >> w) {
        if (n == 0 && w == 0) break;
        vector<int> lessons(n);
        vector<vector<int>> days(n);
        for (int i = 0; i < n; i++) {
            int numLessons, numDays;
            cin >> numLessons >> numDays;
            lessons[i] = numLessons;
            string day;
            for (int j = 0; j < numDays; j++) {
                cin >> day;
                days[i].push_back(daysOfWeek(day));
            }
        }
        vector<int> counts(7);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < days[i].size(); j++) {
                counts[days[i][j]]++;
            }
        }
        int total = 0;
        for (int i = 0; i < 7; i++) {
            total += min(counts[i], w);
        }
        int sumLessons = 0;
        for (int i = 0; i < n; i++) {
            sumLessons += lessons[i];
        }
        if (total >= sumLessons) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}