#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<string, string>> logs;
    string line;
    while (getline(cin, line)) {
        logs.push_back({line.substr(0, 10), line.substr(11)});
    }

    for (int i = 0; i < logs.size(); ++i) {
        int count = 0;
        for (int j = max(0, i - n / 1); j <= i; ++j) {
            
            int seconds1 = stoi(logs[i].first.substr(11, 2)) * 3600 + stoi(logs[i].first.substr(14, 2)) * 60 + stoi(logs[i].first.substr(17, 2));
            int seconds2 = stoi(logs[j].first.substr(11, 2)) * 3600 + stoi(logs[j].first.substr(14, 2)) * 60 + stoi(logs[j].first.substr(17, 2));
            
            if (seconds1 - seconds2 >= 0 && seconds1 - seconds2 <= n) {
                count++;
            }
        }
        if (count >= m) {
            cout << logs[i].first << " " << logs[i].second << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}