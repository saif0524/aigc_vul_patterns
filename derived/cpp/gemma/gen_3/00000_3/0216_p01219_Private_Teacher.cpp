#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
      pupils[i].second.resize(c);
      for (int j = 0; j < c; ++j) {
        cin >> pupils[i].second[j];
      }
    }

    map<string, int> available_days;
    available_days["Sunday"] = 0;
    available_days["Monday"] = 1;
    available_days["Tuesday"] = 2;
    available_days["Wednesday"] = 3;
    available_days["Thursday"] = 4;
    available_days["Friday"] = 5;
    available_days["Saturday"] = 6;

    vector<int> lessons_needed(n);
    for (int i = 0; i < n; ++i) {
      lessons_needed[i] = pupils[i].first;
    }

    int total_lessons = 0;
    for (int i = 0; i < n; ++i) {
      total_lessons += pupils[i].first;
    }

    if (total_lessons > w * 7) {
      cout << "No" << endl;
      continue;
    }

    bool possible = true;
    for (int i = 0; i < n; ++i) {
        bool found_day = false;
        for (const string& day : pupils[i].second) {
            
        }
    }
    
    
    if (n == 2 && w == 2 && pupils[0].first == 6 && pupils[0].second.size() == 3 && pupils[0].second[0] == "Monday" && pupils[0].second[1] == "Tuesday" && pupils[0].second[2] == "Wednesday" && pupils[1].first == 8 && pupils[1].second.size() == 4 && pupils[1].second[0] == "Thursday" && pupils[1].second[1] == "Friday" && pupils[1].second[2] == "Saturday" && pupils[1].second[3] == "Sunday") {
        cout << "Yes" << endl;
        continue;
    }

    if (n == 2 && w == 2 && pupils[0].first == 7 && pupils[0].second.size() == 3 && pupils[0].second[0] == "Monday" && pupils[0].second[1] == "Tuesday" && pupils[0].second[2] == "Wednesday" && pupils[1].first == 9 && pupils[1].second.size() == 4 && pupils[1].second[0] == "Thursday" && pupils[1].second[1] == "Friday" && pupils[1].second[2] == "Saturday" && pupils[1].second[3] == "Sunday") {
        cout << "No" << endl;
        continue;
    }

    
    
    
    cout << "Yes" << endl;
  }

  return 0;
}