#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<vector<int>>> F(N, vector<vector<int>>(5, vector<int>(2)));
    vector<vector<int>> P(N, vector<int>(11));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<2;k++){
                cin >> F[i][j][k];
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<11;j++){
            cin >> P[i][j];
        }
    }
    
    int max_profit = INT_MIN;
    for(int mask=1;mask<(1<<10);mask++){
        int profit = 0;
        for(int i=0;i<N;i++){
            int cnt = 0;
            for(int j=0;j<5;j++){
                for(int k=0;k<2;k++){
                    if((mask & (1<<(j*2+k))) && F[i][j][k]){
                        cnt++;
                    }
                }
            }
            profit += P[i][cnt];
        }
        max_profit = max(max_profit, profit);
    }
    
    cout << max_profit;
}