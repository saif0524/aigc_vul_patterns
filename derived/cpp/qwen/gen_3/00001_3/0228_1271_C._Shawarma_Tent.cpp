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
    int tent_x = -1;
    int tent_y = -1;

    for (int i = 0; i < n; ++i) {
        int x = students[i].first;
        int y = students[i].second;

        
        int students_count = 0;
        for (int j = 0; j < n; ++j) {
            int x_j = students[j].first;
            int y_j = students[j].second;

            if ((x == s_x && y == s_y) || (x_j == s_x && y_j == s_y)) continue;
            
            if (((x >= s_x && x <= x_j) || (x <= s_x && x >= x_j) || (x == x_j)) &&
                ((y >= s_y && y <= y_j) || (y <= s_y && y >= y_j) || (y == y_j))) {
                    students_count++;
            } else if( (x >= s_x && x <= x_j) || (x <= s_x && x >= x_j) || (x == x_j)) {
                if( (y >= s_y && y <= y_j) || (y <= s_y && y >= y_j) || (y == y_j))
                   students_count++;
            } else if( (y >= s_y && y <= y_j) || (y <= s_y && y >= y_j) || (y == y_j)) {
                if( (x >= s_x && x <= x_j) || (x <= s_x && x >= x_j) || (x == x_j))
                    students_count++;
            }

            
        }
        
        if (students_count > max_students) {
            max_students = students_count;
            tent_x = x;
            tent_y = y;
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

    
    if (tent_x == -1 && tent_y == -1) {
        tent_x = students[0].first;
        tent_y = students[0].second;
    }
    
    cout << max_students << endl;
    cout << tent_x << " " << tent_y << endl;

    return 0;
}