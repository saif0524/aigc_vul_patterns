#include <bits/stdc++.h>
using namespace std;

bool can_eat(vector<long long>& q, deque<pair<int, long long>>& rem) {
    while (!rem.empty()) {
        if (q.front() > rem.front().second) {
            q.front() += rem.front().second;
            rem.pop_front();
        } else if (q.back() > rem.back().second) {
            q.back() += rem.back().second;
            rem.pop_back();
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    int n, k;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    cin >> k;
    vector<long long> b(k);
    for(auto &x: b) cin >> x;

    deque<pair<int, long long>> rem;
    for(int i=n-1;i>=k;i--) rem.push_front({i+1, a[i]});
    for(int i=0;i<k;i++){
        while(!rem.empty() && rem.front().second + q.front() <= b[i]) {
            q.push_back(rem.front().second + q.front());
            cout << rem.front().first << " L" << endl;
            rem.pop_front();
            q.pop_front();
        }
        if(!rem.empty()){
            if(q.front() > rem.front().second && q.front() + rem.front().second == b[i]){
                cout << rem.front().first << " L" << endl;
                rem.pop_front();
                q.pop_front();
                q.push_back(b[i]);
            } else {
                cout << "NO";
                return 0;
            }
        } else {
            q.push_back(b[i]);
        }
    }
    if(!rem.empty()){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}