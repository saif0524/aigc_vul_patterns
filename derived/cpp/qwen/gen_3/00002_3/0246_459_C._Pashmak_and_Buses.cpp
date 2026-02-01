#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, d;
    cin >> n >> k >> d;
    if(n > k * d){
        cout << -1;
        return 0;
    }
    for(int i = 0; i < d; ++i){
        for(int j = 0; j < n; ++j){
            cout << (j / d) + 1 + (i * k) % (k - (n / d)) << (j == n - 1 ? '\n' : ' ');
        }
    }
}