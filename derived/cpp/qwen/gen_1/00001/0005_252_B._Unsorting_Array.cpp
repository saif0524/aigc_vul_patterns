#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    
    bool asc = true, desc = true;
    for(int i=1; i<n; ++i){
        if(a[i] < a[i-1]) asc = false;
        if(a[i] > a[i-1]) desc = false;
    }
    if(!asc || !desc){
        cout << "-1";
        return 0;
    }
    
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            if(a[i] != a[j]){
                swap(a[i], a[j]);
                bool new_asc = true, new_desc = true;
                for(int k=1; k<n; ++k){
                    if(a[k] < a[k-1]) new_asc = false;
                    if(a[k] > a[k-1]) new_desc = false;
                }
                if(!new_asc || !new_desc){
                    cout << i+1 << " " << j+1;
                    return 0;
                }
                swap(a[i], a[j]);
            }
        }
    }
    cout << "-1";
}