#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pii> stools, pencils;
    vector<int> ti(n);
    for(int i = 0; i < n; ++i){
        ll c;
        int t;
        cin >> c >> t;
        ti[i] = t;
        if(t == 1){
            stools.push_back({c, i+1});
        }
        else{
            pencils.push_back({c, i+1});
        }
    }
    sort(stools.begin(), stools.end());
    sort(pencils.begin(), pencils.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0; i < k; ++i){
        pq.push({0, i});
    }
    for(auto &stool : stools){
        pii cur = pq.top();
        pq.pop();
        pq.push({cur.first + stool.first, cur.second});
        int idx = cur.second;
        vector<int> &v = ans[idx];
        v.push_back(stool.second);
    }
    int s = 0;
    for(auto &pencil : pencils){
        if(s >= k){
            break;
        }
        pii cur = pq.top();
        pq.pop();
        pq.push({cur.first + pencil.first, cur.second});
        int idx = cur.second;
        vector<int> &v = ans[idx];
        v.push_back(pencil.second);
        s++;
    }
    int used = k - s;
    for(int i = s; i < pencils.size(); ++i){
        pii cur = pq.top();
        pq.pop();
        pq.push({cur.first + pencils[i].first, cur.second});
        int idx = cur.second;
        vector<int> &v = ans[idx];
        v.push_back(pencils[i].second);
        used++;
        if(used >= k){
            break;
        }
    }
    vector<vector<int>> ans(k);
    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();
        int idx = cur.second;
        vector<int> &v = ans[idx];
        reverse(v.begin(), v.end());
    }
    double total = 0;
    for(int i = 0; i < k; ++i){
        vector<int> &v = ans[i];
        total += applyDiscount(v, stools, pencils);
    }
    cout << fixed << setprecision(1) << total << "\n";
    for(int i = 0; i < k; ++i){
        auto &v = ans[i];
        cout << v.size();
        for(auto x : v){
            cout << " " << x;
        }
        cout << "\n";
    }
    return 0;
}