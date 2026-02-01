#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long a, b, q;
        cin >> a >> b >> q;
        vector<pair<long long, long long>> queries(q);
        for(auto &p: queries){
            cin >> p.first >> p.second;
        }
        long long lcm = (a*b) / __gcd(a, b);
        for(auto &[l, r]: queries){
            long long full_cycles = r / lcm - l / lcm;
            long long answer = full_cycles * (lcm - __gcd(a, b));
            long long start_l = max(l, (l/lcm + (l%lcm != 0)) * lcm);
            long long start_r = min(r, (r/lcm) * lcm - 1);
            if(start_l <= start_r){
                for(long long x = start_l; x <= start_r; x++){
                    if((x % a) % b != (x % b) % a){
                        answer++;
                    }
                }
            }
            start_l = max(l, r/lcm * lcm);
            start_r = r;
            if(start_l <= start_r){
                for(long long x = start_l; x <= start_r; x++){
                    if((x % a) % b != (x % b) % a){
                        answer++;
                    }
                }
            }
            cout << answer << " ";
        }
        cout << "\n";
    }
}