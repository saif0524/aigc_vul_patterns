#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> magic(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> magic[i][j];
        }
    }

    int sum = magic[0][1] + magic[1][1] + magic[2][1];

    magic[0][0] = sum - magic[0][1] - magic[0][2];
    magic[1][1] = sum - magic[1][0] - magic[1][2];
    magic[2][2] = sum - magic[2][0] - magic[2][1];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << magic[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}