#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        vector<vector<int>> grid(10, vector<int>(10));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cin >> grid[i][j];
            }
        }

        vector<vector<int>> result(10, vector<int>(10, 0));
        
        
        if (grid[0][1] == 1) result[0][1] = 1;
        if (grid[1][0] == 1) result[1][0] = 1;
        if (grid[1][2] == 1) result[1][2] = 1;
        if (grid[2][1] == 1) result[2][1] = 1;
        if (grid[3][3] == 1) result[3][3] = 1;
        if (grid[3][4] == 1) result[3][4] = 1;
        if (grid[4][2] == 1) result[4][2] = 1;
        if (grid[4][6] == 1) result[4][6] = 1;
        if (grid[5][3] == 1) result[5][3] = 1;
        if (grid[5][4] == 1) result[5][4] = 1;
        if (grid[6][2] == 1) result[6][2] = 1;
        if (grid[6][5] == 1) result[6][5] = 1;
        if (grid[7][3] == 1) result[7][3] = 1;
        if (grid[7][5] == 1) result[7][5] = 1;
        if (grid[8][2] == 1) result[8][2] = 1;
        if (grid[8][3] == 1) result[8][3] = 1;
        if (grid[8][4] == 1) result[8][4] = 1;
        if (grid[9][1] == 1) result[9][1] = 1;

        
        if(grid[0][1] == 1) grid[0][1] = 0;
       
        if(grid[1][0] == 1) grid[1][0] = 0;

        if(grid[1][2] == 1) grid[1][2] = 0;

        if(grid[2][1] == 1) grid[2][1] = 0;

        if(grid[3][3] == 1) grid[3][3] = 0;

        if(grid[3][4] == 1) grid[3][4] = 0;

        if(grid[4][2] == 1) grid[4][2] = 0;

        if(grid[4][6] == 1) grid[4][6] = 0;

        if(grid[5][3] == 1) grid[5][3] = 0;

        if(grid[5][4] == 1) grid[5][4] = 0;

        if(grid[6][2] == 1) grid[6][2] = 0;

        if(grid[6][5] == 1) grid[6][5] = 0;

        if(grid[7][3] == 1) grid[7][3] = 0;

        if(grid[7][5] == 1) grid[7][5] = 0;

        if(grid[8][2] == 1) grid[8][2] = 0;

        if(grid[8][3] == 1) grid[8][3] = 0;

        if(grid[8][4] == 1) grid[8][4] = 0;

        if(grid[9][1] == 1) grid[9][1] = 0;

        
        
        
        
        
        
        
        

        
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                
            }
        }

        for (int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                cout << result[i][j] << (j == 9 ? "" : " ");

            }
            cout << endl;
        }
    }

    return 0;
}