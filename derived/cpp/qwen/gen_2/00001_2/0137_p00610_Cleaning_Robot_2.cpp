#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int N;
        ll K;
        cin >>N >>K;
        if(N==0&&K==0)break;
        if(N==1||(K>(1LL<<(N*N)))){cout <<"No\n\n";continue;}
        K--;
        vector<ll> bits(N*N);
        for(int i=0;i<N*N;i++){
            bits[i] = K%2;
            K/=2;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout <<(bits[i*N+j]?'E':'.');
            }
            cout <<"\n";
        }
        cout <<"\n";
    }
}