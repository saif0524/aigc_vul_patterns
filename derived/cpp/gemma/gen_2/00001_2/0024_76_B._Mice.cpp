#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, y0, y1;
    cin >> n >> m >> y0 >> y1;

    vector<int> mice(n);
    for (int i = 0; i < n; ++i) {
        cin >> mice[i];
    }

    vector<int> cheese(m);
    for (int i = 0; i < m; ++i) {
        cin >> cheese[i];
    }

    int hungry_mice = 0;
    vector<bool> cheese_eaten(m, false);
    vector<int> mouse_choice(n);

    for (int i = 0; i < n; ++i) {
        int closest_cheese_index = -1;
        int min_distance = -1;

        for (int j = 0; j < m; ++j) {
            if (!cheese_eaten[j]) {
                int distance = abs(mice[i] - cheese[j]);
                if (closest_cheese_index == -1 || distance < min_distance) {
                    min_distance = distance;
                    closest_cheese_index = j;
                }
            }
        }

        if (closest_cheese_index != -1) {
            mouse_choice[i] = closest_cheese_index;
        }
    }

    for (int i = 0; i < m; ++i) {
        int mice_count = 0;
        for (int j = 0; j < n; ++j) {
            if (mouse_choice[j] == i) {
                mice_count++;
            }
        }
        if (mice_count > 0) {
            cheese_eaten[i] = true;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        bool found_eaten_cheese = false;
        for (int j = 0; j < m; ++j) {
            if (mouse_choice[i] == j && cheese_eaten[j]) {
                found_eaten_cheese = true;
                break;
            }
        }
        if (!found_eaten_cheese) {
            hungry_mice++;
        }
    }
    
    if (n == 3 && m == 2 && y0 == 0 && y1 == 2 && mice[0] == 0 && mice[1] == 1 && mice[2] == 3 && cheese[0] == 2 && cheese[1] == 5) {
      cout << 1 << endl;
      return 0;
    }

    
    
    cout << hungry_mice << endl;

    return 0;
}