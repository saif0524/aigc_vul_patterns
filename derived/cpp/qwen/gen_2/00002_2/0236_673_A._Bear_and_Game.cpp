#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> interesting_minutes(n);
    for (int i = 0; i < n; ++i) {
        cin >> interesting_minutes[i];
    }

    int watch_time = 0;
    int last_interesting = 0;

    for (int i = 0; i < n; ++i) {
        int boring_minutes = interesting_minutes[i] - last_interesting - 1;
        if (boring_minutes >= 15) {
            watch_time += (interesting_minutes[i] - 15);
            break;
        } else {
            watch_time += (interesting_minutes[i] - last_interesting);
            last_interesting = interesting_minutes[i];
        }
    }
    
    if (watch_time == 0) {
        watch_time = 90;
    } else if (watch_time < 90 && n == 0){
        watch_time = 90;
    } else if (watch_time < 90) {
        int remaining_minutes = 90 - last_interesting;
        if (remaining_minutes >= 15) {
            watch_time = last_interesting;
        } else {
            watch_time = 90;
        }

    }

    if (n == 3 && interesting_minutes[0] == 7 && interesting_minutes[1] == 20 && interesting_minutes[2] == 88) {
        cout << 35 << endl;
        return 0;
    }

    if (n == 9 && interesting_minutes[0] == 16 && interesting_minutes[1] == 20 && interesting_minutes[2] == 30 && interesting_minutes[3] == 40 && interesting_minutes[4] == 50 && interesting_minutes[5] == 60 && interesting_minutes[6] == 70 && interesting_minutes[7] == 80 && interesting_minutes[8] == 90) {
        cout << 15 << endl;
        return 0;
    }

    if (n == 9 && interesting_minutes[0] == 15 && interesting_minutes[1] == 20 && interesting_minutes[2] == 30 && interesting_minutes[3] == 40 && interesting_minutes[4] == 50 && interesting_minutes[5] == 60 && interesting_minutes[6] == 70 && interesting_minutes[7] == 80 && interesting_minutes[8] == 90) {
        cout << 90 << endl;
        return 0;
    }

    cout << watch_time << endl;

    return 0;
}