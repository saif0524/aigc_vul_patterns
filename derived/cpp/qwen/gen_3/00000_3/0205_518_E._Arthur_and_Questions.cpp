#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    vector<ll> a(n, 0);
    vector<bool> fixed(n, false);
    for(int i=0;i<n;i++) if(s[i] != "?"){
        a[i] = stoll(s[i]);
        fixed[i] = true;
    }
    vector<ll> sums(n-k+1, -1e18);
    for(int i=0;i<n-k+1;i++){
        bool all_fixed = true;
        ll sum = 0;
        for(int j=0;j<k;j++){
            if(!fixed[i+j]){
                all_fixed = false;
                break;
            }
            sum += a[i+j];
        }
        if(all_fixed) sums[i] = sum;
    }
    bool possible = true;
    for(int i=0;i<n-k;i++) if(sums[i] != -1e18 && sums[i+1] != -1e18 && sums[i] >= sums[i+1]) possible = false;
    if(!possible){
        cout << "Incorrect sequence";
        return 0;
    }
    for(int i=0;i<n-k+1;i++){
        if(sums[i] == -1e18){
            ll min_sum = 1e18;
            ll max_sum = -1e18;
            ll fixed_sum = 0;
            int fixed_cnt = 0;
            for(int j=0;j<k;j++){
                if(fixed[i+j]){
                    fixed_sum += a[i+j];
                    fixed_cnt++;
                }
                else{
                    min_sum = min(min_sum, a[i+j]);
                    max_sum = max(max_sum, a[i+j]);
                }
            }
            if(fixed_cnt == k-1){
                if(i > 0 && sums[i-1] != -1e18) a[i+k-1] = sums[i] - fixed_sum;
                else if(i < n-k && sums[i+1] != -1e18) a[i] = sums[i] - fixed_sum;
                else a[i] = 0;
                fixed[i] = true;
            }
            else if(fixed_cnt == k-2){
                if(i > 0 && sums[i-1] != -1e18){
                    if(i < n-k && sums[i+1] != -1e18){
                        if(sums[i-1] > sums[i+1]){
                            possible = false;
                            break;
                        }
                        else{
                            a[i+k-1] = sums[i] - fixed_sum - sums[i-1] + sums[i+1];
                            a[i] = sums[i-1] - fixed_sum;
                        }
                    }
                    else{
                        a[i+k-1] = sums[i] - fixed_sum;
                    }
                }
                else if(i < n-k && sums[i+1] != -1e18){
                    a[i] = sums[i] - fixed_sum;
                }
                else{
                    possible = false;
                    break;
                }
                fixed[i] = true;
                fixed[i+k-1] = true;
            }
            else{
                if(i > 0 && sums[i-1] != -1e18){
                    if(i < n-k && sums[i+1] != -1e18){
                        if(sums[i-1] >= sums[i+1]){
                            possible = false;
                            break;
                        }
                        else{
                            sums[i] = max(sums[i], sums[i-1] + abs(min_sum) + 1);
                            sums[i] = min(sums[i], sums[i+1] - abs(max_sum) - 1);
                        }
                    }
                    else{
                        sums[i] = max(sums[i], sums[i-1] + abs(min_sum) + 1);
                    }
                }
                else if(i < n-k && sums[i+1] != -1e18){
                    sums[i] = min(sums[i], sums[i+1] - abs(max_sum) - 1);
                }
                else{
                    sums[i] = 0;
                }
            }
        }
    }
    if(!possible){
        cout << "Incorrect sequence";
        return 0;
    }
    for(int i=0;i<n-k+1;i++){
        if(sums[i] == -1e18){
            ll sum = 0;
            int cnt = 0;
            for(int j=0;j<k;j++){
                if(fixed[i+j]){
                    sum += a[i+j];
                    cnt++;
                }
            }
            sums[i] = sum + (k - cnt) * 0; // assume 0 for now
        }
    }
    for(int i=0;i<n-k;i++) if(sums[i] >= sums[i+1]) possible = false;
    if(!possible){
        cout << "Incorrect sequence";
        return 0;
    }
    for(int i=0;i<n-k+1;i++){
        for(int j=0;j<k;j++) if(!fixed[i+j]){
            a[i+j] = sums[i] - (sums[i] - a[i+j]) / 1;
        }
    }
    for(int i=0;i<n-1;i++){
        if(fixed[i] && fixed[i+1]){
            if(a[i] > a[i+1]) possible = false;
        }
    }
    if(!possible){
        cout << "Incorrect sequence";
        return 0;
    }
    for(int i=0;i<n;i++) cout << a[i] << " ";
    return 0;
}