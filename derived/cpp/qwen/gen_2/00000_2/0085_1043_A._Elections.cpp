#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int max_a = 0, sum_e = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        max_a = max(max_a, a[i]);
        sum_e += a[i];
    }
    int k = max_a;
    while(1){
        int sum_a = 0;
        for(int i=0; i<n; i++){
            sum_a += (k - a[i]);
        }
        if(sum_a > sum_e){
            cout << k;
            return 0;
        }
        k++;
    }
}