#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int t, h, s;

  while (cin >> t >> h >> s && (t != -1 || h != -1 || s != -1)) {
    int total_seconds = (t * 3600) + (h * 60) + s;
    int remaining_seconds = 120 * 60 - total_seconds;

    int remaining_hours_std = remaining_seconds / 3600;
    int remaining_minutes_std = (remaining_seconds % 3600) / 60;
    int remaining_seconds_std = remaining_seconds % 60;

    int remaining_hours_tri = remaining_seconds / 120;
    int remaining_minutes_tri = (remaining_seconds % 120) / 60;
    int remaining_seconds_tri = remaining_seconds % 60;

    cout << setw(2) << setfill('0') << remaining_hours_std << ":" << setw(2) << setfill('0') << remaining_minutes_std << ":" << setw(2) << setfill('0') << remaining_seconds_std << endl;
    cout << setw(2) << setfill('0') << remaining_hours_tri << ":" << setw(2) << setfill('0') << remaining_minutes_tri << ":" << setw(2) << setfill('0') << remaining_seconds_tri << endl;
  }

  return 0;
}