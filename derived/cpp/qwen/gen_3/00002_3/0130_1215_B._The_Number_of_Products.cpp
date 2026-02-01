#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    long long pos = 0, neg = 0, zero = 0, last_zero = -1;
    int current_sign = 1;
    long long current_pos = 0, current_neg = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < 0) current_sign *= -1;
        if(a[i] == 0){
            last_zero = i;
            zero += i + 1;
            current_sign = 1;
            current_pos = 0;
            current_neg = 0;
        }
        else{
            if(current_sign == 1){
                current_pos += i - last_zero;
                pos += current_pos;
            }
            else{
                current_neg += i - last_zero;
                neg += current_neg;
            }
        }
    }
    long long total_subarrays = (long long)n * (n + 1) / 2;
    long long non_zero_subarrays = total_subarrays - zero;
    cout << neg << " " << non_zero_subarrays - neg << "\n";
}