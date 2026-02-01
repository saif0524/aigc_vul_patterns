#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> A(n);
    for(int &x: A) cin >> x;
    cin >> m;
    vector<int> B(m);
    for(int &x: B) cin >> x;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(A[i] == B[j]){
            cout << A[i] << "\n";
            i++; j++;
        }
        else if(A[i] < B[j]) i++;
        else j++;
    }
}