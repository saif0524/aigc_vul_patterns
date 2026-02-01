#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, w;
    while(cin >> d >> w && (d || w)){
        vector<vector<int>> grid(d, vector<int>(w));
        for(int i = 0; i < d; ++i){
            for(int j = 0; j < w; ++j){
                cin >> grid[i][j];
            }
        }
        
        int maxCapacity = 0;
        for(int x1 = 0; x1 < d-2; ++x1){
            for(int y1 = 0; y1 < w-2; ++y1){
                for(int x2 = x1+2; x2 < d; ++x2){
                    for(int y2 = y1+2; y2 < w; ++y2){
                        int minHeight = 10;
                        for(int i = x1; i <= x2; ++i){
                            for(int j = y1; j <= y2; ++j){
                                if(i == x1 || i == x2 || j == y1 || j == y2){
                                    minHeight = min(minHeight, grid[i][j]);
                                }
                            }
                        }
                        int currentCapacity = 0;
                        bool valid = true;
                        for(int i = x1+1; i < x2 && valid; ++i){
                            for(int j = y1+1; j < y2 && valid; ++j){
                                if(grid[i][j] >= minHeight){
                                    valid = false;
                                } else {
                                    currentCapacity += minHeight - grid[i][j];
                                }
                            }
                        }
                        if(valid){
                            maxCapacity = max(maxCapacity, currentCapacity);
                        }
                    }
                }
            }
        }
        cout << maxCapacity << "\n";
    }
    return 0;
}