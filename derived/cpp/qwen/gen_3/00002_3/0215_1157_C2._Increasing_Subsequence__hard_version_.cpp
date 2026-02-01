#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int l = 0, r = n-1;
    vector<int> ans;
    vector<char> moves;
    while(l <= r){
        if(l == r){
            ans.push_back(a[l]);
            moves.push_back('L');
            break;
        }
        if(a[l] < a[r]){
            ans.push_back(a[l]);
            moves.push_back('L');
            l++;
        }
        else if(a[r] < a[l]){
            ans.push_back(a[r]);
            moves.push_back('R');
            r--;
        }
        else{
            int len1 = 0, len2 = 0;
            int l1 = l, r1 = r;
            while(l1 < r1 && a[l1] < a[l1+1]) len1++, l1++;
            while(l1 < r1 && a[r1] > a[r1-1]) len1++, r1--;
            l1 = l, r1 = r;
            while(l1 < r1 && a[r1] < a[r1-1]) len2++, r1--;
            while(l1 < r1 && a[l1] > a[l1+1]) len2++, l1++;
            if(len1 >= len2){
                ans.push_back(a[l]);
                moves.push_back('L');
                l++;
            }
            else{
                ans.push_back(a[r]);
                moves.push_back('R');
                r--;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto &x: moves) cout << x;
    cout << "\n";
}