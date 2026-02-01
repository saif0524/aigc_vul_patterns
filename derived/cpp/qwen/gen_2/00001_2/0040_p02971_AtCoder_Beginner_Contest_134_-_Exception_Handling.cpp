#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    int max_val = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        max_val = max(max_val, A[i]);
    }
    int second_max = 0;
    for(int i=0;i<N;i++){
        if(A[i] != max_val){
            second_max = max(second_max, A[i]);
        }
    }
    for(int i=0;i<N;i++){
        if(A[i] == max_val){
            cout << second_max << "\n";
        } else {
            cout << max_val << "\n";
        }
    }
}