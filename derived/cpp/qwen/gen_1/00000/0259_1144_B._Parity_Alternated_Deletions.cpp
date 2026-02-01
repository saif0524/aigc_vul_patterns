#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    int even_count = 0, odd_count = 0;
    int min_even = INT_MAX, min_odd = INT_MAX;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        if(a[i]%2 == 0){
            even_count++;
            min_even = min(min_even, a[i]);
        }
        else{
            odd_count++;
            min_odd = min(min_odd, a[i]);
        }
    }
    
    if(even_count == 0 || odd_count == 0){
        cout << sum - min(min_even, min_odd);
    }
    else{
        cout << 0;
    }
    
    return 0;
}