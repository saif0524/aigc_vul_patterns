#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<int> sorted_a(a.begin()+l-1, a.begin()+r);
    vector<int> sorted_b(b.begin()+l-1, b.begin()+r);
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    if(sorted_a != sorted_b) {
        cout << "LIE";
    } else {
        vector<int> freq_a(n+1, 0), freq_b(n+1, 0);
        for(int i = 0; i < n; ++i){
            if(i < l-1 || i > r-1){
                freq_a[a[i]]++;
                freq_b[b[i]]++;
            }
        }
        if(freq_a == freq_b) {
            cout << "TRUTH";
        } else {
            cout << "LIE";
        }
    }
}