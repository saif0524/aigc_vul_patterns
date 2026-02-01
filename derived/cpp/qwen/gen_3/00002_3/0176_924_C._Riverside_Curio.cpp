#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> m(n);
    for(int &x : m) cin >> x;
    set<int> marks;
    long long sum_d = 0;
    for(int i=0;i<n;i++){
        int above = m[i];
        int total = marks.size();
        int below = total - above;
        sum_d += below;
        marks.insert(i);
        auto it = marks.lower_bound(i);
        if(it != marks.begin()){
            it--;
            if(marks.count(*it) && m[i] == m[*it]){
                marks.erase(it);
            }
        }
    }
    cout << sum_d;
}