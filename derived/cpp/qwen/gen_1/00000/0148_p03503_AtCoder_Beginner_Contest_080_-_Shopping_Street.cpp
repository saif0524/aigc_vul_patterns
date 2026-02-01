#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    for(int i=0;i<N;i++)
        for(int j=0;j<10;j++)
            cin >> F[i][j];
    vector<vector<int>> P(N, vector<int>(11));
    for(int i=0;i<N;i++)
        for(int j=0;j<11;j++)
            cin >> P[i][j];
    
    int max_profit = INT_MIN;
    for(int mask=1;mask<(1<<10);mask++){
        int profit = 0;
        for(int i=0;i<N;i++){
            int count = 0;
            for(int j=0;j<10;j++){
                if((mask & (1<<j)) && F[i][j]){
                    count++;
                }
            }
            profit += P[i][count];
        }
        max_profit = max(max_profit, profit);
    }
    cout << max_profit;
}