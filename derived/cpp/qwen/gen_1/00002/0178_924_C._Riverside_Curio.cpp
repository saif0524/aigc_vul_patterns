#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> m(n);
    for(int i=0;i<n;i++){
        cin >> m[i];
    }
    set<int> marks;
    long long ans = 0;
    for(int i=0;i<n;i++){
        while(marks.size() <= m[i]){
            marks.insert(i);
        }
        auto it = marks.upper_bound(i);
        ans += distance(it, marks.end());
        marks.insert(i);
    }
    cout << ans;
}