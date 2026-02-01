#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K, S;
    cin >> N >> K >> S;
    vector<int> A(N, 1);
    for(int i = 0; i < K; i++){
        A[i] = S;
        if(i + 1 < N){
            A[i + 1] = 0;
        }
    }
    A.back() += N - K;
    for(int i = 0; i < N; i++){
        cout << A[i] << (i < N - 1 ? ' ' : '\n');
    }
}