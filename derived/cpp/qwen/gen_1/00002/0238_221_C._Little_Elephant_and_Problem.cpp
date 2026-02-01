#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    int diff = 0;
    int idx1 = -1, idx2 = -1;
    for(int i=0;i<n;i++){
        if(a[i] != sorted_a[i]){
            if(idx1 == -1) idx1 = i;
            else if(idx2 == -1) idx2 = i;
            diff++;
        }
    }
    if(diff == 0 || (diff == 2 && a[idx1] == sorted_a[idx2] && a[idx2] == sorted_a[idx1])) cout << "YES";
    else cout << "NO";
}