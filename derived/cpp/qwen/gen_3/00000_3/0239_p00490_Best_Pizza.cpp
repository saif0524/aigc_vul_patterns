#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A, B;
    cin >> A >> B;
    int C;
    cin >> C;
    vector<int> D(N);
    for(int &x: D) cin >> x;
    
    int max_cal = 0;
    for(int mask = 0; mask < (1<<N); mask++){
        int cal = C;
        int cost = A;
        for(int i = 0; i < N; i++){
            if(mask & (1<<i)){
                cal += D[i];
                cost += B;
            }
        }
        max_cal = max(max_cal, cal / cost);
    }
    cout << max_cal;
}