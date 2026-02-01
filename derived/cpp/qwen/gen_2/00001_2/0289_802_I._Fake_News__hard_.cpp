#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int n = s.size();
        vector<long long> z(n, 0);
        long long total = 0;
        int l = 0, r = 0;
        for(int i=1; i<n; i++){
            if(i < r){
                z[i] = min(r-i, z[i-l]);
            }
            while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i] > r){
                l = i;
                r = i+z[i];
            }
            total += z[i];
        }
        total += n;
        cout << total << "\n";
    }
}