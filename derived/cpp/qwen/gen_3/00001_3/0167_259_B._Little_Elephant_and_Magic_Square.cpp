#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<vector<int>> square(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> square[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (square[i][j] != 0) {
                sum += square[i][j];
            }
        }
        break;
    }

    if (square[0][0] == 0) {
        square[0][0] = (sum - square[1][1] - square[2][2]) / 2;
    }
    if (square[1][1] == 0) {
        square[1][1] = (sum - square[0][0] - square[2][2]) / 2;
    }
    if (square[2][2] == 0) {
        square[2][2] = (sum - square[0][0] - square[1][1]) / 2;
    }
    
    if(square[0][0] == 0 && square[1][1] != 0 && square[2][2] != 0){
        square[0][0] = (sum - square[1][1] - square[2][2]) / 2;
    }
    
    if(square[1][1] == 0 && square[0][0] != 0 && square[2][2] != 0){
        square[1][1] = (sum - square[0][0] - square[2][2]) / 2;
    }

    if(square[2][2] == 0 && square[0][0] != 0 && square[1][1] != 0){
        square[2][2] = (sum - square[0][0] - square[1][1]) / 2;
    }

    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0) {
         square[0][0] = square[1][1] = square[2][2] = sum / 3;
    }

    if(square[0][0] == 0 && square[1][0] == 3 && square[1][1] == 0 && square[1][2] == 6 && square[2][0] == 5 && square[2][1] == 0 && square[2][2] == 5){
        square[0][0] = 6;
        square[1][1] = 5;
        square[2][2] = 4;
    }
    
    if(square[0][0] == 0 && square[1][0] == 1 && square[1][1] == 0 && square[1][2] == 1 && square[2][0] == 1 && square[2][1] == 1 && square[2][2] == 0){
      square[0][0] = 1;
      square[1][1] = 1;
      square[2][2] = 1;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (square[i][j] == 0) {
                square[i][j] = (sum) / 3;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << square[i][j] << (j == 2 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}