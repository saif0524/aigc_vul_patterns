#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> prices(N);
    for(auto &p: prices) cin >> p;
    
    long long max_profit = 0;
    for(int i=1; i<N; ++i){
        if(prices[i] > prices[i-1]){
            max_profit += prices[i] - prices[i-1];
        }
    }
    
    cout << max_profit;
}