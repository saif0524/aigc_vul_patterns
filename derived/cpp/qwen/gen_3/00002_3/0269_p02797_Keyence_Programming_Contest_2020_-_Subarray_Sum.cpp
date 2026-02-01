#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K, S;
    cin >> N >> K >> S;
    vector<long long> A(N, 1);
    for(int i=0; i<K; i++){
        A[i] = S;
    }
    for(int i=K; i<N; i++){
        A[i] = 1;
    }
    for(int i=0; i<K-1; i++){
        A[i+1] -= 1;
    }
    for(int i=0; i<N; i++){
        cout << A[i] << (i==N-1?'\n':' ');
    }
    return 0;
}