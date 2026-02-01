#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N-1);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];
    for(int i=0; i<N-1; i++) cin >> C[i];
    
    int total_satisfaction = 0;
    for(int i=0; i<N; i++){
        total_satisfaction += B[A[i]-1];
        if(i < N-1){
            int next = A[i+1];
            int current = A[i];
            if(next == current + 1){
                total_satisfaction += C[current-1];
            } else if(current == next + 1){
                total_satisfaction += C[next-1];
            }
        }
    }
    cout << total_satisfaction;
}