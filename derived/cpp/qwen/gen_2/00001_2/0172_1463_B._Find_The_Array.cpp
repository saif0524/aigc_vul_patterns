#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        long long S = 0;
        for(auto &x: a) cin >> x, S += x;
        vector<long long> b(n,1);
        long long current_diff = 0;
        for(int i=0;i<n;i++){
            long long original_diff = abs(a[i] - b[i]);
            if(2 * (current_diff + original_diff) > S){
                b[i] = a[i];
                current_diff += original_diff;
            }
            else{
                for(int j=i+1;j<n;j++){
                    if(a[i] % b[j] == 0 || b[j] % a[i] == 0){
                        b[j] = a[i];
                        current_diff += abs(a[j] - b[j]);
                        if(2 * current_diff > S) break;
                    }
                }
            }
        }
        for(auto &x: b) cout << x << " ";
        cout << "\n";
    }
}