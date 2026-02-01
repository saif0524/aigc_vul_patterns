#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >>N>>K;
    vector<int> A(N);
    for(auto &x: A) cin>>x;
    for(int i=0;i<N-1;++i){
        if(K==0) break;
        if(A[i]>A[i+1]){
            swap(A[i], A[i+1]);
            --K;
        }
    }
    for(int i=0;i<N;++i) cout<<A[i]<<(i==N-1?"":"\n");
}