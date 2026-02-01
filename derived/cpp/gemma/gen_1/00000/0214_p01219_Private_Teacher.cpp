#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
  int n, w;
  while (cin >> n >> w && (n != 0 || w != 0)) {
    vector<pair<int, vector<string>>> pupils(n);
    for (int i = 0; i < n; ++i) {
      int t, c;
      cin >> t >> c;
      pupils[i].first = t;
      for (int j = 0; j < c; ++j) {
        string day;
        cin >> day;
        pupils[i].second.push_back(day);
      }
    }

    map<string, int> available_slots;
    available_slots["Sunday"] = w;
    available_slots["Monday"] = w;
    available_slots["Tuesday"] = w;
    available_slots["Wednesday"] = w;
    available_slots["Thursday"] = w;
    available_slots["Friday"] = w;
    available_slots["Saturday"] = w;

    bool possible = true;
    for (int i = 0; i < n; ++i) {
      int lessons_needed = pupils[i].first;
      vector<string> available_days = pupils[i].second;

      int lessons_scheduled = 0;
      for (string day : available_days) {
        int slots_available = available_slots[day];
        if (slots_available > 0) {
          int lessons_to_take = min(lessons_needed - lessons_scheduled, slots_available);
          lessons_scheduled += lessons_to_take;
          available_slots[day] -= lessons_to_take;
        }
        if (lessons_scheduled == lessons_needed) {
          break;
        }
      }

      if (lessons_scheduled != lessons_needed) {
        possible = false;
        break;
      }
    }

    if (possible) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}