#include <bits/stdc++.h>
using namespace std;

int main(){
    long long l, r;
    cin >> l >> r;
    unordered_map<long long, int> freq;
    for(long long num = l; num <= r; num++){
        for(long long d = 2; d * d <= num; d++){
            if(num % d == 0){
                freq[d]++;
                if(d != num / d){
                    freq[num / d]++;
                }
            }
        }
    }
    long long max_freq_num = 0, max_freq = 0;
    for(const auto& [num, f] : freq){
        if(f > max_freq){
            max_freq = f;
            max_freq_num = num;
        }
    }
    cout << max_freq_num;
}