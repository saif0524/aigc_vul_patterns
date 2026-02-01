#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    sort(A.begin(), A.end());
    int ans = 1;
    int i = 0, j = 0;
    while(j < N){
        if(A[j] - A[i] <= K){
            ans = max(ans, j - i + 1);
            j++;
        }
        else{
            i++;
        }
    }
    cout << ans;
}