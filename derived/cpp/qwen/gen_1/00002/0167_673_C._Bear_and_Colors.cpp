#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for(auto &x: t) cin >> x;
    vector<long long> cnt(n, 0);
    for(int i=0; i<n; i++){
        vector<int> freq(n, 0);
        int maxFreq = 0;
        for(int j=i; j<n; j++){
            freq[t[j]-1]++;
            maxFreq = max(maxFreq, freq[t[j]-1]);
            int dominantColor = -1;
            for(int c=0; c<n; c++){
                if(freq[c] == maxFreq){
                    dominantColor = c+1;
                    break;
                }
            }
            if(dominantColor == t[i]){
                cnt[dominantColor-1]++;
            }
        }
    }
    for(auto x: cnt) cout << x << " ";
    cout << endl;
    return 0;
}