#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> D(N);
    for(auto &d : D) cin >> d;
    
    int bestCalPerDollar = 0;
    for(int mask = 0; mask < (1 << N); mask++) {
        int totalCalories = C;
        int totalPrice = A;
        for(int i = 0; i < N; i++) {
            if(mask & (1 << i)) {
                totalCalories += D[i];
                totalPrice += B;
            }
        }
        bestCalPerDollar = max(bestCalPerDollar, totalCalories / totalPrice);
    }
    
    cout << bestCalPerDollar;
}