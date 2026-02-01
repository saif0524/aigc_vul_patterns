#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    int k;
    cin >> k;
    vector<long long> b(k);
    for(auto &x : b) cin >> x;
    if(n==k){
        cout << "YES";
        return 0;
    }
    vector<pair<long long, int>> res;
    deque<int> q;
    for(int i=0;i<n;i++) q.push_back(i);
    int ptr = 0;
    while(q.size()>k){
        bool found = false;
        for(int i=0;i<q.size();i++){
            if(ptr==k) break;
            if(a[q[i]]==b[ptr]){
                if(i>0 && a[q[i-1]]<a[q[i]]){
                    res.push_back({q[i-1]+1, 'L'});
                    a[q[i]]+=a[q[i-1]];
                    q.erase(q.begin()+i-1);
                    i--;
                    found = true;
                }
                else if(i<q.size()-1 && a[q[i+1]]<a[q[i]]){
                    res.push_back({q[i]+1, 'R'});
                    a[q[i]]+=a[q[i+1]];
                    q.erase(q.begin()+i+1);
                    found = true;
                }
            }
        }
        if(!found){
            cout << "NO";
            return 0;
        }
        ptr++;
    }
    cout << "YES\n";
    for(auto [x, c] : res){
        cout << x << " " << c << "\n";
    }
}