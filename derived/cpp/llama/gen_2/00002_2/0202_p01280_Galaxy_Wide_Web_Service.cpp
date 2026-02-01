#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;

        vector<vector<int>> planets(N, vector<int>());
        vector<int> dayLengths(N);
        vector<int> currentTime(N);

        for (int i = 0; i < N; i++) {
            cin >> dayLengths[i] >> currentTime[i];
            for (int j = 0; j < dayLengths[i]; j++) {
                int volume;
                cin >> volume;
                planets[i].push_back(volume);
            }
        }

        int maxVolume = 0;
        for (int hour = 0; hour < 100; hour++) {
            int totalVolume = 0;
            for (int i = 0; i < N; i++) {
                int time = (currentTime[i] + hour) % dayLengths[i];
                totalVolume += planets[i][time];
            }
            maxVolume = max(maxVolume, totalVolume);
        }

        cout << maxVolume << endl;
    }

    return 0;
}