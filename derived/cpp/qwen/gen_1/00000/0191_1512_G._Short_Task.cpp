#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 10;
int divisors[MAXN];

void precompute_divisors() {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            if (divisors[j] >= MAXN) continue;
            divisors[j] += i;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute_divisors();
    int t;
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        bool found = false;
        for(int i = 1;i<MAXN;++i){
            if(divisors[i] == c){
                cout << i << "\n";
                found = true;
                break;
            }
            if(divisors[i] > c) break;
        }
        if(!found) cout << "-1\n";
    }
}