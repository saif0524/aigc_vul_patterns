#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &x : A) cin >> x;
    int total_gcd = A[0];
    bool pairwise = true;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(__gcd(A[i], A[j]) != 1){
                pairwise = false;
                break;
            }
        }
        total_gcd = __gcd(total_gcd, A[i]);
    }
    if(pairwise){
        cout << "pairwise coprime";
    }
    else if(total_gcd == 1){
        cout << "setwise coprime";
    }
    else{
        cout << "not coprime";
    }
}