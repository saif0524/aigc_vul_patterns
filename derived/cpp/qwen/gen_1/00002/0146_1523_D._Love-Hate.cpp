#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> cnt(1<<m, 0);
    int half = (n+1)/2;
    for(int i=0;i<n;i++){
        int mask = 0;
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            if(c == '1'){
                mask |= (1 << j);
            }
        }
        cnt[mask]++;
    }
    int ans_mask = 0;
    for(int mask=0;mask<(1<<m);mask++){
        bool valid = true;
        for(int j=0;j<m;j++){
            if(mask & (1 << j)){
                int c = 0;
                for(int submask=mask;submask;submask=(submask-1)&mask){
                    c += cnt[submask];
                }
                if(c < half){
                    valid = false;
                    break;
                }
            }
        }
        if(valid && __builtin_popcount(mask) > __builtin_popcount(ans_mask)){
            ans_mask = mask;
        }
    }
    for(int j=0;j<m;j++){
        if(ans_mask & (1 << j)){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    cout << "\n";
}