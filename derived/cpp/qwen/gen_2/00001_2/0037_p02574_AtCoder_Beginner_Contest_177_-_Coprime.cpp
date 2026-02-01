#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    
    int gcd_all = A[0];
    for(int i = 1; i < N; ++i) {
        gcd_all = __gcd(gcd_all, A[i]);
    }
    
    if(gcd_all != 1) {
        cout << "not coprime";
        return 0;
    }
    
    bool pairwise_coprime = true;
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            if(__gcd(A[i], A[j]) != 1) {
                pairwise_coprime = false;
                break;
            }
        }
        if(!pairwise_coprime) break;
    }
    
    if(pairwise_coprime) {
        cout << "pairwise coprime";
    } else {
        cout << "setwise coprime";
    }
    
    return 0;
}