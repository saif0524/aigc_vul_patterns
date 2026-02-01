#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &x: A) cin >> x;
    int max_val = *max_element(A.begin(), A.end());
    int second_max_val = -1;
    for(int x: A){
        if(x != max_val){
            second_max_val = max(second_max_val, x);
        }
    }
    for(int i=0; i<N; ++i){
        if(A[i] == max_val){
            cout << second_max_val << "\n";
        }
        else{
            cout << max_val << "\n";
        }
    }
}