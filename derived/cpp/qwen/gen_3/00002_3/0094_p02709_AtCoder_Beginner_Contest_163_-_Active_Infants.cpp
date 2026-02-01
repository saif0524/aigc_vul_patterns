#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(auto &a : A) cin >> a;
    sort(A.begin(), A.end());
    long long max_happiness = 0;
    for(int i=0; i<N; i++){
        max_happiness += A[i] * (abs(i - (N - 1 - i)));
    }
    cout << max_happiness << endl;
}