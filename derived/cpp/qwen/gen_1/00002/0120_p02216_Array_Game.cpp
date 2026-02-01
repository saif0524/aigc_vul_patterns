#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    long long sum = 0;
    int min_val = INT_MAX;
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        sum += a;
        min_val = min(min_val, a);
    }
    if((sum - min_val) % 2 == 0){
        cout << "Second";
    } else {
        cout << "First";
    }
}