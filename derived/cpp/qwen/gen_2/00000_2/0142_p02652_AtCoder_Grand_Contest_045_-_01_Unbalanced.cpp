#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int n = S.size();
    vector<int> zeros, ones;
    for(int i=0; i<n; ++i){
        if(S[i] == '0') zeros.push_back(i);
        if(S[i] == '1') ones.push_back(i);
    }
    int q = n - zeros.size() - ones.size();
    int ans = n;
    for(int k=0; k<=q; ++k){
        int z = zeros.size() + k;
        int o = ones.size() + (q-k);
        int min_diff = abs(z - o);
        for(int i=0; i<n; ++i){
            if(S[i] == '0'){
                if(i < zeros.size()){
                    z--;
                } else {
                    o++;
                }
            } else if(S[i] == '1'){
                if(i < ones.size()){
                    o--;
                } else {
                    z++;
                }
            } else {
                if(zeros.size() + k > i){
                    z--;
                } else {
                    o++;
                }
            }
            min_diff = min(min_diff, abs(z - o));
        }
        ans = min(ans, min_diff);
    }
    cout << ans;
}