#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int T, H, S;
    while (cin >> T >> H >> S) {
        if (T == -1 && H == -1 && S == -1) break;
        int usedTime = T * 3600 + H * 60 + S;
        int totalTime = 120 * 60;
        int freeTime = totalTime - usedTime;

        int stdHours = freeTime / 3600;
        int stdMinutes = (freeTime % 3600) / 60;
        int stdSeconds = freeTime % 60;

        int tripleHours = freeTime / 10800;
        int tripleMinutes = (freeTime % 10800) / 180;
        int tripleSeconds = (freeTime % 180) * 5 / 3;

        cout << setw(2) << setfill('0') << stdHours << ":"
             << setw(2) << setfill('0') << stdMinutes << ":"
             << setw(2) << setfill('0') << stdSeconds << endl;

        cout << setw(2) << setfill('0') << tripleHours << ":"
             << setw(2) << setfill('0') << tripleMinutes << ":"
             << setw(2) << setfill('0') << tripleSeconds << endl;
    }
    return 0;
}