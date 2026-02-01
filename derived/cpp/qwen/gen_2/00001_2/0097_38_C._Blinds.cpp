#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    
    int max_area = 0;
    for(int d = l; d <= 100; ++d){
        int width = 0;
        for(int x : a){
            width += x/d;
        }
        max_area = max(max_area, width * d);
    }
    
    cout << max_area;
}