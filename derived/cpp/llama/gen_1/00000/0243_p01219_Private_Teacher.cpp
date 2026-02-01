#include <bits/stdc++.h>
using namespace std;

map<string, int> day;
int arr[7];

void init() {
    day["Sunday"] = 0;
    day["Monday"] = 1;
    day["Tuesday"] = 2;
    day["Wednesday"] = 3;
    day["Thursday"] = 4;
    day["Friday"] = 5;
    day["Saturday"] = 6;
    for (int i = 0; i < 7; i++) arr[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        init();
        int N, W;
        cin >> N >> W;
        if (N == 0 && W == 0) break;

        vector<pair<int, vector<int>>> teachers(N);
        for (int i = 0; i < N; i++) {
            int t, c;
            cin >> t >> c;
            string s;
            vector<int> days;
            for (int j = 0; j < c; j++) {
                cin >> s;
                days.push_back(day[s]);
            }
            teachers[i] = {t, days};
        }

        int totalLessons = 0;
        for (int i = 0; i < N; i++) totalLessons += teachers[i].first;

        sort(teachers.begin(), teachers.end(), [](pair<int, vector<int>>& a, pair<int, vector<int>>& b) {
            return a.second.size() < b.second.size();
        });

        bool flag = true;
        for (int week = 0; week < W; week++) {
            for (int i = 0; i < 7; i++) arr[i] = 0;

            for (int i = 0; i < N; i++) {
                if (teachers[i].first == 0) continue;
                bool assigned = false;
                for (int j = 0; j < teachers[i].second.size(); j++) {
                    int d = teachers[i].second[j];
                    if (arr[d] == 0) {
                        arr[d] = 1;
                        teachers[i].first--;
                        assigned = true;
                        break;
                    }
                }
                if (!assigned) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }

        bool allZero = true;
        for (int i = 0; i < N; i++) {
            if (teachers[i].first != 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}