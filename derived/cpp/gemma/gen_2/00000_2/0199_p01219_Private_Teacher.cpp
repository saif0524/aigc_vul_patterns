#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
            vector<string> days(c);
            for (int j = 0; j < c; ++j) {
                cin >> days[j];
            }
            pupils[i].second = days;
        }

        int total_lessons = 0;
        for (int i = 0; i < n; ++i) {
            total_lessons += pupils[i].first;
        }

        if (total_lessons > w * 7) {
            cout << "No" << endl;
            continue;
        }

        vector<int> available_slots(w * 7, 1);
        
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            int lessons_needed = pupils[i].first;
            vector<string> convenient_days = pupils[i].second;

            
            int slots_found = 0;
            for (int j = 0; j < w; ++j) {
                for (int k = 0; k < 7; ++k) {
                    string day;
                    if (k == 0) day = "Sunday";
                    else if (k == 1) day = "Monday";
                    else if (k == 2) day = "Tuesday";
                    else if (k == 3) day = "Wednesday";
                    else if (k == 4) day = "Thursday";
                    else if (k == 5) day = "Friday";
                    else day = "Saturday";

                    int slot_index = j * 7 + k;
                    if (available_slots[slot_index] == 1) {
                        bool is_convenient = false;
                        for (const string& d : convenient_days) {
                            if (d == day) {
                                is_convenient = true;
                                break;
                            }
                        }
                        if (is_convenient) {
                            available_slots[slot_index] = 0;
                            slots_found++;
                            if (slots_found == lessons_needed) break;
                        }
                    }
                }
                if (slots_found == lessons_needed) break;
            }
            
            if (slots_found < lessons_needed) {
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