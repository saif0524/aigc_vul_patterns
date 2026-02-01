#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for(int &i: x) cin >> i;
    int max_profit = 0;
    for(int d=0; d<n-1; ++d){
        int profit = x[d] - x[d+1] - c;
        if(profit > 0){
            max_profit = max(max_profit, profit);
        }
    }
    cout << max(max_profit, 0);
}