#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long d;
    cin >> n >> d;
    vector<pair<long long, long long>> friends(n);
    for(auto &f: friends){
        cin >> f.first >> f.second;
    }
    sort(friends.begin(), friends.end());
    multiset<long long> s;
    long long max_sum = 0, current_sum = 0;
    for(const auto &f: friends){
        s.insert(f.second);
        current_sum += f.second;
        while(f.first - friends.front().first >= d){
            current_sum -= friends.front().second;
            s.erase(s.find(friends.front().second));
            friends.erase(friends.begin());
        }
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
}