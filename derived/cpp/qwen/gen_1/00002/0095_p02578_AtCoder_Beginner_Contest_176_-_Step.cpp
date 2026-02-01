#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> A(n);
    for(auto &a : A) cin >> a;
    long long total = 0, max_height = 0;
    for(int i=0;i<n;i++){
        if(A[i] < max_height){
            total += max_height - A[i];
        } else {
            max_height = A[i];
        }
    }
    cout << total;
}