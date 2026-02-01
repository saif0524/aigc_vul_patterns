#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> A(N);
    for(auto &a: A) cin >> a;
    long long total_height = 0;
    long long current_max = 0;
    for(int i=0;i<N;i++){
        if(A[i] < current_max){
            total_height += current_max - A[i];
        } else {
            current_max = A[i];
        }
    }
    cout << total_height;
}