#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &x: A) cin >> x;
    
    int money = 1000;
    int stocks = 0;
    
    for(int i=0; i<N-1; ++i){
        if(A[i] < A[i+1]){
            int max_buy = money / A[i];
            stocks += max_buy;
            money -= max_buy * A[i];
        }
        else if(A[i] > A[i+1]){
            money += stocks * A[i];
            stocks = 0;
        }
    }
    
    // sell all stocks on the last day
    money += stocks * A[N-1];
    
    cout << money;
}