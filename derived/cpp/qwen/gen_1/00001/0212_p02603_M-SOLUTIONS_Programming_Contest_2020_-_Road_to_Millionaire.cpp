#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &x: A) cin >> x;
    
    int money = 1000, stocks = 0;
    for(int i = 0; i < N - 1; ++i){
        if(A[i] < A[i+1]){
            int can_buy = money / A[i];
            stocks += can_buy;
            money -= can_buy * A[i];
        } else {
            money += stocks * A[i];
            stocks = 0;
        }
    }
    money += stocks * A[N-1];
    cout << money;
}