#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

vector<int> reverse_digits(int num) {
    vector<int> digits;
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    if (digits.empty()) digits.push_back(0);
    return digits;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> digits(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        digits[i] = reverse_digits(num);
    }
    vector<int> cnt[10];
    for(int d=0; d<10; d++){
        cnt[d].assign(1e6+1,0);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<digits[i].size(); j++){
            cnt[digits[i][j]][j]++;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        int current = 0;
        int power = 1;
        for(int j=0;; j++){
            int overall = 0;
            if(j < digits[i].size()){
                overall = cnt[digits[i][j]][j];
            }
            if(j >= 1){
                for(int d=0; d<10; d++){
                    overall = add(overall, cnt[d][j-1]);
                }
            }
            int add_value = mul(overall, power);
            ans = add(ans, add_value);
            power = mul(power, 10);
            if(j >= digits[i].size() and cnt[0][j-1] == n){
                break;
            }
        }
        ans = mul(ans, 2);
        ans = add(ans, MOD);
        ans = add(ans, -mul(current, 2));
    }
    for(int i=0; i<n; i++){
        vector<int> rev_d = digits[i];
        int power = 1;
        int current = 0;
        for(int j=0; j<rev_d.size(); j++){
            current = add(current, mul(rev_d[j], power));
            power = mul(power, 10);
        }
        ans = add(ans, current);
    }
    ans = mul(ans, n);
    ans = add(ans, MOD);
    ans = add(ans, -mul(n, 1));
    ans %= MOD;
    cout << ans;
}