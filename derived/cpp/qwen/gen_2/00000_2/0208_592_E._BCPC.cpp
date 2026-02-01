#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    ll lhs = (ll)(a.first - a.second) * (ll)b.second;
    ll rhs = (ll)(b.first - b.second) * (ll)a.second;
    return lhs > rhs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c, d;
    cin >> n >> c >> d;
    vector<pair<int, int>> students(n);
    for(auto& [ri, wi]: students){
        cin >> ri >> wi;
        ri -= c;
        wi -= d;
    }
    sort(students.begin(), students.end(), compare);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            ll lhs = (ll)(students[i].first - students[j].second) * (ll)students[j].second;
            ll rhs = (ll)(students[j].first - students[i].second) * (ll)students[i].second;
            if(lhs <= rhs) continue;
            for(int k = j+1; k < n; ++k){
                lhs = (ll)(students[i].first - students[k].second) * (ll)students[k].second;
                rhs = (ll)(students[k].first - students[i].second) * (ll)students[i].second;
                if(lhs <= rhs) continue;
                lhs = (ll)(students[j].first - students[k].second) * (ll)students[k].second;
                rhs = (ll)(students[k].first - students[j].second) * (ll)students[j].second;
                if(lhs > rhs){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}