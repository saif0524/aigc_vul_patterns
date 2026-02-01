#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> p(N);
    for(int i=0;i<N;i++) cin >> p[i];
    int ans = 0;
    for(int i=0;i<N;i++){
        if(p[i] == i+1){
            if(i+1 < N){
                swap(p[i], p[i+1]);
                ans++;
            }
            else{
                swap(p[i], p[i-1]);
                ans++;
            }
        }
    }
    cout << ans;
}