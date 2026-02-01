#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 6005;

int N, K;
ll x[MAXN], y[MAXN];
vector<int> ans;

bool valid(int mask) {
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if((mask & (1 << i)) && (mask & (1 << j))){
                ll dx = x[i] - x[j];
                ll dy = y[i] - y[j];
                if(dx * dx + dy * dy < 4){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i];
    }
    int lim = 1 << N;
    int best_mask = -1;
    for(int mask = 0; mask < lim; mask++){
        if(__builtin_popcount(mask) == K && valid(mask)){
            if(best_mask == -1 || mask < best_mask){
                best_mask = mask;
            }
        }
    }
    if(best_mask == -1){
        cout << -1;
    } else {
        for(int i = 1; i <= N; i++){
            if(best_mask & (1 << i)){
                ans.push_back(i);
            }
        }
        for(int a : ans){
            cout << a << "\n";
        }
    }
}