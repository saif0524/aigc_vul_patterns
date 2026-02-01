#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> magic(3, vector<int>(3));
    int sum = 0, nonZeroCount = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> magic[i][j];
            if (i == j && magic[i][j] == 0) continue;
            sum += magic[i][j];
            nonZeroCount++;
        }
    }

    int totalSum = sum / (nonZeroCount / 3);
    for (int i = 0; i < 3; ++i) {
        if (magic[i][i] == 0) {
            magic[i][i] = totalSum - (magic[i][0] + magic[i][1] + magic[i][2] - totalSum);
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << magic[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}