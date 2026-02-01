#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int t, h, s;

  while (cin >> t >> h >> s && (t != -1 || h != -1 || s != -1)) {
    int total_seconds = t * 3600 + h * 60 + s;
    int remaining_seconds = 120 * 60 - total_seconds;

    int remaining_hours_standard = remaining_seconds / 3600;
    remaining_seconds %= 3600;
    int remaining_minutes_standard = remaining_seconds / 60;
    remaining_seconds %= 60;

    int remaining_hours_triple = remaining_seconds / 3600 * 3;
    
    if (remaining_seconds >= 3600) {
        remaining_hours_triple = (remaining_seconds / 3600) * 3;
        remaining_seconds %= 3600;
        remaining_hours_triple = remaining_seconds / 3600 * 3;
        remaining_seconds %= 3600;
    }

    
     if(remaining_seconds >= 3600){
        remaining_hours_triple = (remaining_seconds / 3600) * 3;
        remaining_seconds %= 3600;
    }
    
    int remaining_minutes_triple = (remaining_seconds / 60) * 3;
    remaining_seconds %= 60;
    remaining_minutes_triple = (remaining_seconds / 60) * 3;
    remaining_seconds %= 60;

    remaining_hours_triple = remaining_seconds/60/60*3;
    remaining_seconds %= 3600;
    remaining_minutes_triple= remaining_seconds/60*3;
    remaining_seconds %= 60;
    
    int remaining_hours_standard_final = remaining_seconds / 3600;
    remaining_seconds %= 3600;
    int remaining_minutes_standard_final = remaining_seconds / 60;
    remaining_seconds %= 60;

    int remaining_hours_triple_final = (120 * 60 - total_seconds) / 3600 * 3;
    int remaining_minutes_triple_final = ((120 * 60 - total_seconds) % 3600) / 60 * 3;
    int remaining_seconds_triple_final = ((120 * 60 - total_seconds) % 3600) % 60 * 3;
    
    
    int hours_standard = (120 * 60 - total_seconds) / 3600;
    int minutes_standard = ((120 * 60 - total_seconds) % 3600) / 60;
    int seconds_standard = ((120 * 60 - total_seconds) % 3600) % 60;

    int hours_triple = (120 * 60 - total_seconds) / 3600 * 3;
    int minutes_triple = ((120*60 - total_seconds) % 3600) / 60 * 3;
    int seconds_triple = ((120*60 - total_seconds) % 3600) % 60 * 3;

    if (hours_standard < 0) hours_standard = 0;
    if (minutes_standard < 0) minutes_standard = 0;
    if (seconds_standard < 0) seconds_standard = 0;
    if (hours_triple < 0) hours_triple = 0;
    if (minutes_triple < 0) minutes_triple = 0;
    if (seconds_triple < 0) seconds_triple = 0;
    

    cout << fixed << setfill('0') << setw(2) << hours_standard << ":" << setw(2) << minutes_standard << ":" << setw(2) << seconds_standard << endl;
    cout << fixed << setfill('0') << setw(2) << hours_triple << ":" << setw(2) << minutes_triple << ":" << setw(2) << seconds_triple << endl;
  }

  return 0;
}