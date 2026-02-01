#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int &x : a) cin >> x;
    
    int max_val = 0;
    for(int i = 0; i < N; ++i){
        max_val = max(max_val, a[i] - 1);
    }
    
    int result = 0;
    for(int m = 0; m <= max_val; ++m){
        int sum = 0;
        for(int i = 0; i < N; ++i){
            sum += m % a[i];
        }
        result = max(result, sum);
    }
    
    cout << result;
}