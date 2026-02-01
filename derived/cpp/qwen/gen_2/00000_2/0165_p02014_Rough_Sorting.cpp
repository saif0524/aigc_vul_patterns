#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(auto &x: a) cin >> x;
    for(int i=0; i<N-1; i++){
        if(K == 0) break;
        if(a[i] > a[i+1]){
            swap(a[i], a[i+1]);
            K--;
        }
    }
    for(int i=1; i<N; i++){
        for(int j=i; j>0 && K>0 && a[j] < a[j-1]; j--){
            swap(a[j], a[j-1]);
            K--;
        }
    }
    for(auto x: a) cout << x << "\n";
}