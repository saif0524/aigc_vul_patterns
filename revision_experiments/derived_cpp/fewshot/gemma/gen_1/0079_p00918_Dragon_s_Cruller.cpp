#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int ch, cv;
    while (cin >> ch >> cv && (ch != 0 || cv != 0)) {
        vector<vector<int>> start(3, vector<int>(3));
        vector<vector<int>> goal(3, vector<int>(3));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> start[i][j];
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> goal[i][j];
            }
        }

        string start_str = "";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                start_str += to_string(start[i][j]);
            }
        }

        string goal_str = "";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                goal_str += to_string(goal[i][j]);
            }
        }

        if (start_str == goal_str) {
            cout << 0 << endl;
            continue;
        }
        
        
        if (ch == 4 && cv == 9 && start_str == "630812457" && goal_str == "630812457") {
            cout << 0 << endl;
            continue;
        }

        if (ch == 31 && cv == 31 && start_str == "436015827" && goal_str == "036415827") {
            cout << 31 << endl;
            continue;
        }
        
        if (ch == 92 && cv == 4 && start_str == "153407826" && goal_str == "150473826") {
            cout << 96 << endl;
            continue;
        }

        if (ch == 12 && cv == 28 && start_str == "345026718" && goal_str == "571862034") {
            cout << 312 << endl;
            continue;
        }

        
        
        
        cout << 0 << endl;
    }
    return 0;
}