#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> logs;
    vector<int> timestamps;

    string line;
    while (getline(cin, line)) {
        logs.push_back(line);

        int year = stoi(line.substr(0, 4));
        int month = stoi(line.substr(5, 2));
        int day = stoi(line.substr(8, 2));
        int hour = stoi(line.substr(11, 2));
        int minute = stoi(line.substr(14, 2));
        int second = stoi(line.substr(17, 2));

        int timestamp = (year - 2012) * 365 * 24 * 60 * 60 +
                        (month - 1) * 30 * 24 * 60 * 60 +
                        (day - 1) * 24 * 60 * 60 +
                        hour * 60 * 60 +
                        minute * 60 +
                        second;

        timestamps.push_back(timestamp);
    }

    int seekTime = INT_MAX;
    for (int i = 0; i < logs.size(); i++) {
        int count = 0;
        for (int j = i; j >= 0; j--) {
            if (timestamps[i] - timestamps[j] <= n) {
                count++;
            } else {
                break;
            }
        }

        if (count >= m) {
            seekTime = min(seekTime, timestamps[i]);
        }
    }

    if (seekTime == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < logs.size(); i++) {
        if (timestamps[i] == seekTime) {
            cout << logs[i].substr(0, 19) << endl;
            break;
        }
    }

    return 0;
}