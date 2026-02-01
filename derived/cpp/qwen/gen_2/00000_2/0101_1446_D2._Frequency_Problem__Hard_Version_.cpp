#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int ans = 0;
    for(int i=1;i<=n;i++){
        vector<int> freq(n+1,0);
        int maxf = 0, countmf = 0;
        for(int j=0, k=0;j<n;j++){
            freq[a[j]]++;
            if(freq[a[j]] == maxf) countmf++;
            else if(freq[a[j]] > maxf) maxf = freq[a[j]], countmf = 1;
            while(k <= j && (maxf - (freq[a[j]] == maxf)) * countmf > j - k + 1 - i){
                freq[a[k]]--;
                if(freq[a[k]] == maxf) countmf--;
                else if(freq[a[k]] == maxf - 1) countmf++;
                k++;
                if(maxf * countmf < j - k + 2) maxf--, countmf = 0;
                for(int l = maxf; l >= 0; --l){
                    if(freq[a[k]] == l){
                        maxf = l;
                        countmf = 0;
                        for(int m=1;m<=n;m++){
                            if(freq[m] == l) countmf++;
                        }
                        break;
                    }
                }
            }
            if(maxf * countmf > j - k + 1 - i) ans = max(ans, j - k + 1);
        }
    }
    cout << ans;
    return 0;
}