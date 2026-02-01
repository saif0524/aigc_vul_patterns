#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    for(auto &i: x) cin >> i;
    
    ll ways = 0;
    for(int mask = 1; mask < (1<<N); mask++){
        int sum = 0, count = 0;
        for(int i = 0; i < N; i++){
            if(mask & (1<<i)){
                sum += x[i];
                count++;
            }
        }
        if(count * A == sum){
            ways++;
        }
    }
    cout << ways;
    return 0;
}