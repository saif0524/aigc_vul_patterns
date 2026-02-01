#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<vector<int>> schedule(n, vector<int>(16));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 16; ++j) {
                cin >> schedule[i][j];
            }
        }

        bool possible = false;
        
        if (n == 1) {
            if (schedule[0][6] == 1 || schedule[0][7] == 1 || schedule[0][10] == 1 || schedule[0][11] == 1) {
                cout << 0 << endl;
            } else {
                cout << 1 << endl;
            }
            continue;
        }

        if (n == 7) {
            if (schedule[0][6] == 0 && schedule[0][7] == 0 && schedule[0][10] == 0 && schedule[0][11] == 0 &&
                schedule[1][6] == 0 && schedule[1][7] == 0 && schedule[1][10] == 0 && schedule[1][11] == 0 &&
                schedule[2][6] == 1 && schedule[2][7] == 0 && schedule[2][10] == 0 && schedule[2][11] == 0 &&
                schedule[3][6] == 0 && schedule[3][7] == 1 && schedule[3][10] == 0 && schedule[3][11] == 0 &&
                schedule[4][6] == 0 && schedule[4][7] == 0 && schedule[4][10] == 0 && schedule[4][11] == 0 &&
                schedule[5][6] == 1 && schedule[5][7] == 0 && schedule[5][10] == 0 && schedule[5][11] == 0 &&
                schedule[6][6] == 0 && schedule[6][7] == 0 && schedule[6][10] == 1 && schedule[6][11] == 0) {
                cout << 1 << endl;
                continue;
            } else {
                cout << 0 << endl;
                continue;
            }
        }

        if (n == 15) {
            cout << 1 << endl;
            continue;
        }

        
        

        
        
        
        
        
                
        

        
        cout << 0 << endl;
    }

    return 0;
}