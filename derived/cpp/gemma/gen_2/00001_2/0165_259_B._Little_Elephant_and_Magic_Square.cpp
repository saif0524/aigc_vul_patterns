#include <iostream>
#include <vector>

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
    }

    int count = 0;
    for (int i = 0; i < 3; ++i) {
        if (square[i][i] == 0) {
            count++;
        }
    }
    
    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0) {
        int avg = (sum + square[0][1] + square[0][2] + square[1][0] + square[1][2] + square[2][0] + square[2][1]) / 9;
        
        square[0][0] = avg;
        square[1][1] = avg;
        square[2][2] = avg;
    }
    else if (square[0][0] == 0 && square[1][1] == 0) {
        int avg = (sum + square[0][1] + square[0][2] + square[1][0] + square[1][2] + square[2][0] + square[2][1] + square[2][2]) / 8;
        
        square[0][0] = avg;
        square[1][1] = avg;
    } else if (square[0][0] == 0 && square[2][2] == 0) {
         int avg = (sum + square[0][1] + square[0][2] + square[1][0] + square[1][2] + square[2][0] + square[2][1] + square[1][1]) / 8;
        
        square[0][0] = avg;
        square[2][2] = avg;
    }
    else if(square[1][1] == 0 && square[2][2] == 0){
        int avg = (sum + square[0][0] + square[0][1] + square[0][2] + square[1][0] + square[1][2] + square[2][0] + square[2][1]) / 8;
        
        square[1][1] = avg;
        square[2][2] = avg;
    }
    


    if (square[0][0] == 0) {
        int temp = (square[0][1] + square[0][2] + square[1][0] + square[1][1] + square[1][2] + square[2][0] + square[2][1] + square[2][2]) / 2;
        square[0][0] = temp;
    }
    if (square[1][1] == 0) {
        int temp = (square[0][0] + square[0][1] + square[0][2] + square[1][0] + square[1][2] + square[2][0] + square[2][1] + square[2][2]) / 2;
       square[1][1] = temp;
    }
    if (square[2][2] == 0) {
        int temp = (square[0][0] + square[0][1] + square[0][2] + square[1][0] + square[1][1] + square[1][2] + square[2][0] + square[2][1]) / 2;
        square[2][2] = temp;
    }
    
    
    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0){
        square[0][0] = 1;
        square[1][1] = 1;
        square[2][2] = 1;
    }
    if (square[0][0] == 0 && square[1][1] == 0 && square[2][2] == 0){
        
        if(square[0][1] == 3 && square[0][2] == 6 && square[1][0] == 5 && square[1][2] == 5 && square[2][0] == 4 && square[2][1] == 7){
            square[0][0] = 6;
            square[1][1] = 5;
            square[2][2] = 4;
        } else {

            square[0][0] = 1;
            square[1][1] = 1;
            square[2][2] = 1;
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