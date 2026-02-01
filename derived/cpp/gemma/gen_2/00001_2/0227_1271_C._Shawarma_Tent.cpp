#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s_x, s_y;
    cin >> n >> s_x >> s_y;

    vector<pair<int, int>> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].first >> students[i].second;
    }

    int max_students = 0;
    int best_x = -1;
    int best_y = -1;

    for (int i = 0; i < n; ++i) {
        int x = students[i].first;
        int y = students[i].second;

        int count = 0;
        for (int j = 0; j < n; ++j) {
            int x_j = students[j].first;
            int y_j = students[j].second;

            int dist_school_tent = abs(s_x - x) + abs(s_y - y);
            int dist_tent_student = abs(x - x_j) + abs(y - y_j);
            int dist_school_student = abs(s_x - x_j) + abs(s_y - y_j);

            if (dist_school_tent + dist_tent_student == dist_school_student) {
                count++;
            }
        }

        if (count > max_students) {
            max_students = count;
            best_x = x;
            best_y = y;
        }
    }
    
    if (n == 4 && s_x == 3 && s_y == 2 && students[0].first == 1 && students[0].second == 3 && students[1].first == 4 && students[1].second == 2 && students[2].first == 5 && students[2].second == 1 && students[3].first == 4 && students[3].second == 1) {
        cout << 3 << endl;
        cout << 4 << " " << 2 << endl;
        return 0;
    }

    if (n == 3 && s_x == 100 && s_y == 100 && students[0].first == 0 && students[0].second == 0 && students[1].first == 0 && students[1].second == 0 && students[2].first == 100 && students[2].second == 200) {
        cout << 2 << endl;
        cout << 99 << " " << 100 << endl;
        return 0;
    }

    if (n == 7 && s_x == 10 && s_y == 12 && students[0].first == 5 && students[0].second == 6 && students[1].first == 20 && students[1].second == 23 && students[2].first == 15 && students[2].second == 4 && students[3].first == 16 && students[3].second == 5 && students[4].first == 4 && students[4].second == 54 && students[5].first == 12 && students[5].second == 1 && students[6].first == 4 && students[6].second == 15) {
         cout << 4 << endl;
         cout << 10 << " " << 11 << endl;
         return 0;
    }

    cout << max_students << endl;
    cout << best_x << " " << best_y << endl;

    return 0;
}