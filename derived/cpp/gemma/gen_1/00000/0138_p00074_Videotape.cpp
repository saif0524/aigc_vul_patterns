#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int t, h, s;

  while (cin >> t >> h >> s && (t != -1 || h != -1 || s != -1)) {
    int total_seconds = t * 3600 + h * 60 + s;
    int remaining_seconds = 120 * 60 - total_seconds;

    int standard_hours = remaining_seconds / 3600;
    remaining_seconds %= 3600;
    int standard_minutes = remaining_seconds / 60;
    remaining_seconds %= 60;
    int standard_seconds = remaining_seconds;

    int triple_hours = remaining_seconds * 3 / 3600;
    remaining_seconds = (remaining_seconds * 3) % 3600;
    int triple_minutes = remaining_seconds / 60;
    remaining_seconds %= 60;
    int triple_seconds = remaining_seconds;
    
    if (triple_hours >= 120) {
        triple_hours = 119;
        triple_minutes = 59;
        triple_seconds = 59;
    }

    
    
    cout << setw(2) << setfill('0') << standard_hours << ":" << setw(2) << setfill('0') << standard_minutes << ":" << setw(2) << setfill('0') << standard_seconds << endl;
    cout << setw(2) << setfill('0') << triple_hours << ":" << setw(2) << setfill('0') << triple_minutes << ":" << setw(2) << setfill('0') << triple_seconds << endl;
  }

  return 0;
}