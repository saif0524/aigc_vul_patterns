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
        int si;
        cin >> si;
        sizes[i] = si;
        boxes[i].resize(si);
        for(int &x: boxes[i]){
            cin >> x;
        }
    }
    int total = accumulate(sizes.begin(), sizes.end(), 0);
    int target = total / n;
    int rem = total % n;
    vector<int> extra, lack;
    for(int i=0;i<n;i++){
        if(sizes[i] > target + (i < rem)){
            extra.push_back(i);
        }
        if(sizes[i] < target + (i < rem)){
            lack.push_back(i);
        }
    }
    vector<tuple<int, int, int>> moves;
    int e=0, l=0;
    while(e < extra.size() && l < lack.size()){
        int from = extra[e];
        int to = lack[l];
        int need = target + (l < rem) - sizes[to];
        int give = min(sizes[from] - (target + (e < rem)), -need);
        for(int i=0;i<give;i++){
            int kind = boxes[from].back();
            boxes[from].pop_back();
            boxes[to].push_back(kind);
            sizes[from]--;
            sizes[to]++;
            moves.emplace_back(from+1, to+1, kind);
        }
        if(sizes[from] == target + (e < rem)){
            e++;
        }
        if(sizes[to] == target + (l < rem)){
            l++;
        }
    }
    cout << moves.size() << "\n";
    for(auto [from, to, kind]: moves){
        cout << from << " " << to << " " << kind << "\n";
    }
}