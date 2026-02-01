#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int t, h, s;
    while (true) {
        cin >> t >> h >> s;
        if (t == -1 && h == -1 && s == -1) break;

        int total_seconds = t * 3600 + h * 60 + s;
        int remaining_seconds_standard = 7200 - total_seconds;
        int remaining_seconds_triple = 21600 - total_seconds * 3;

        cout << setfill('0') << setw(2) << remaining_seconds_standard / 3600 << ":"
             << setfill('0') << setw(2) << (remaining_seconds_standard % 3600) / 60 << ":"
             << setfill('0') << setw(2) << remaining_seconds_standard % 60 << endl;

        cout << setfill('0') << setw(2) << remaining_seconds_triple / 3600 << ":"
             << setfill('0') << setw(2) << (remaining_seconds_triple % 3600) / 60 << ":"
             << setfill('0') << setw(2) << remaining_seconds_triple % 60 << endl;
    }
    return 0;
}