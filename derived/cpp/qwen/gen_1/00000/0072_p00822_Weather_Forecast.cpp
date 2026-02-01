#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2, -1, 0, 1, 2};
int dy[] = {-2, -1, 0, 1, 2};

bool isValid(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

bool canSatisfy(vector<vector<int>>& schedule) {
    int n = schedule.size();
    vector<vector<int>> rain(4, vector<int>(4, 7));

    for (int x = 1; x < 3; ++x) {
        for (int y = 1; y < 3; ++y) {
            rain[x][y] = 0;
        }
    }

    for (int day = 0; day < n; ++day) {
        bool canPlaceCloud = false;
        for (int x = 0; x < 4; ++x) {
            for (int y = 0; y < 4; ++y) {
                if (schedule[day][x * 4 + y] == 1) {
                    rain[x][y] = 0;
                    canPlaceCloud = true;
                } else {
                    rain[x][y]++;
                }
            }
        }

        if (!canPlaceCloud) {
            for (int x = 0; x < 4; ++x) {
                for (int y = 0; y < 4; ++y) {
                    rain[x][y] = 0;
                }
            }
            continue;
        }

        bool found = false;
        for (int x = 0; x < 4; ++x) {
            for (int y = 0; y < 4; ++y) {
                if (isValid(x - 1, y - 1) && isValid(x, y - 1) && isValid(x + 1, y - 1) &&
                    isValid(x - 1, y) && isValid(x, y) && isValid(x + 1, y) &&
                    isValid(x - 1, y + 1) && isValid(x, y + 1) && isValid(x + 1, y + 1)) {
                    bool valid = true;
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            if (rain[x + i][y + j] > 6) {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) break;
                    }
                    if (valid) {
                        found = true;
                        for (int i = -1; i <= 1; ++i) {
                            for (int j = -1; j <= 1; ++j) {
                                rain[x + i][y + j] = 0;
                            }
                        }
                        break;
                    }
                }
            }
            if (found) break;
        }

        if (!found) return false;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<vector<int>> schedule(n, vector<int>(16));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 16; j++){
                cin >> schedule[i][j];
            }
        }
        cout << (canSatisfy(schedule) ? 1 : 0) << "\n";
    }
}