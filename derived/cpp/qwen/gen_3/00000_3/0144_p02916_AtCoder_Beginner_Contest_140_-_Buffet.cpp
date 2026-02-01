#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N-1);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;
    for(auto &c : C) cin >> c;
    
    int satisfaction = 0;
    for(int i = 0; i < N; i++){
        satisfaction += B[A[i]-1];
        if(i < N-1 && A[i+1] == A[i]+1){
            satisfaction += C[A[i]-1];
        }
    }
    cout << satisfaction;
}