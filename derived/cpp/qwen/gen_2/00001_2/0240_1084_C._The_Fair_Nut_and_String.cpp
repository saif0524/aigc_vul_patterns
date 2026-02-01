#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    long long prev_a = 0, prev_b = 0, result = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'a'){
            result = (result + prev_a + 1) % MOD;
            prev_a = (prev_a + prev_b + 1) % MOD;
        }
        else if(s[i] == 'b'){
            prev_b = (prev_b + 1) % MOD;
        }
    }
    cout << result << "\n";
}