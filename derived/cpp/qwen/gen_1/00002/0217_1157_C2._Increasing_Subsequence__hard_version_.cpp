#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int left = 0, right = n-1;
    int last = -1;
    vector<char> moves;
    while(left <= right){
        if(a[left] > last && (a[left] < a[right] || a[right] <= last)){
            moves.push_back('L');
            last = a[left++];
        }
        else if(a[right] > last){
            moves.push_back('R');
            last = a[right--];
        }
        else{
            break;
        }
    }
    cout << moves.size() << "\n";
    for(auto m: moves) cout << m;
}