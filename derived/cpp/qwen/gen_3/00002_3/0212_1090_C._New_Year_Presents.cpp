#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> boxes(n);
    vector<int> sizes(n);
    for(int i=0;i<n;i++){
        cin >> sizes[i];
        boxes[i].resize(sizes[i]);
        for(auto &x: boxes[i]) cin >> x;
    }
    int total = accumulate(sizes.begin(), sizes.end(), 0);
    int target = total / n;
    int extra = total % n;
    vector<pair<int,int>> moves;
    vector<unordered_set<int>> box_sets(n);
    for(int i = 0; i < n; i++){
        for(int x : boxes[i]) box_sets[i].insert(x);
    }
    queue<int> have_more, have_less;
    for(int i=0;i<n;i++){
        if(sizes[i] > target || (sizes[i] == target && extra > 0)) have_more.push(i);
        else if(sizes[i] < target || (sizes[i] == target && extra < 0)) have_less.push(i);
        if(sizes[i] > target && extra > 0) extra--;
        else if(sizes[i] < target && extra < 0) extra++;
    }
    while(!have_more.empty() && !have_less.empty()){
        int from = have_more.front();
        int to = have_less.front();
        have_more.pop();
        have_less.pop();
        for(auto &x : boxes[from]){
            if(!box_sets[to].count(x)){
                moves.push_back({from+1, to+1, x});
                box_sets[from].erase(x);
                box_sets[to].insert(x);
                sizes[from]--;
                sizes[to]++;
                if(sizes[from] > target || (sizes[from] == target && extra > 0)){
                    have_more.push(from);
                    extra--;
                }
                if(sizes[to] < target || (sizes[to] == target && extra < 0)){
                    have_less.push(to);
                    extra++;
                }
                break;
            }
        }
    }
    cout << moves.size() << "\n";
    for(auto &[f, t, k] : moves){
        cout << f << " " << t << " " << k << "\n";
    }
}