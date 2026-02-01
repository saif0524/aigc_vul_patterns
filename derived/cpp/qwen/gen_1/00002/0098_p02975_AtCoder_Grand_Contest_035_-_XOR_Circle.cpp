#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    
    int totalXOR = 0;
    for(int i=0;i<N;i++) totalXOR ^= a[i];
    
    if(totalXOR == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}