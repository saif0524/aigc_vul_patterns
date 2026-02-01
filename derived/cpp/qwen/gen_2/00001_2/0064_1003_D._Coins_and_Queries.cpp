#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> cnt(31, 0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        for(int j=0;j<=30;j++){
            if(x == (1 << j)){
                cnt[j]++;
                break;
            }
        }
    }
    while(q--){
        int b;
        cin >> b;
        int ans = 0;
        for(int i=0;i<=30;i++){
            if(b & (1 << i)){
                if(cnt[i] > 0){
                    cnt[i]--;
                }
                else{
                    bool found = false;
                    for(int j=i+1;j<=30;j++){
                        if(cnt[j] > 0){
                            cnt[j]--;
                            for(int k=i;k<j;k++){
                                cnt[k]++;
                            }
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        ans = -1;
                        break;
                    }
                }
                ans++;
            }
        }
        cout << ans << "\n";
    }
}