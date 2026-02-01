#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<double, int>> people;
    for(int i=0;i<n;i++){
        int s, r;
        cin >> s >> r;
        double ratio = (double)s/(double)r;
        people.push_back({ratio, i+1});
    }
    sort(people.begin(), people.end());
    set<int> winners;
    double max_ratio = 0.0;
    for(auto& p: people){
        if(p.first > max_ratio){
            winners.insert(p.second);
            max_ratio = p.first;
        }
    }
    for(auto it = winners.begin(); it != winners.end(); it++){
        if(it != winners.begin()) cout << " ";
        cout << *it;
    }
    cout << "\n";
}