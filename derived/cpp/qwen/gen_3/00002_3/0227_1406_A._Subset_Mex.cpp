#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(101, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        int mexA = 0;
        int mexB = 0;
        for(int i = 0; i <= 100; i++){
            if(cnt[i] == 0){
                mexA = i;
                break;
            }
        }
        for(int i = 0; i <= 100; i++){
            if(cnt[i] <= 1){
                mexB = i;
                break;
            }
        }
        int ans = mexA + mexB;
        for(int i = 0; i <= 100; i++){
            if(cnt[i] > 1){
                int new_mexA = mexA;
                int new_mexB = mexB;
                if(mexA == i){
                    new_mexA++;
                    while(new_mexA <= 100 && cnt[new_mexA] > 0){
                        new_mexA++;
                    }
                }
                if(mexB == i){
                    new_mexB++;
                    while(new_mexB <= 100 && cnt[new_mexB] > 0){
                        new_mexB++;
                    }
                }
                ans = max(ans, new_mexA + new_mexB);
            }
        }
        cout << ans << "\n";
    }
}