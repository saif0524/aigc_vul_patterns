#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vecs(n);
    for(int i = 0; i < n; ++i){
        int k;
        cin >> k;
        vecs[i].resize(k);
        for(int &x : vecs[i]){
            cin >> x;
            --x;
        }
    }

    vector<int> chosen;
    set<int> dim_used;
    for(int i = 0; i < n; ++i){
        if(dim_used.count(vecs[i][0])){
            if(!dim_used.count(vecs[i].back())){
                int d0 = vecs[i][0];
                int d1 = vecs[i].back();
                for(int j = 0; j < n; ++j){
                    if((vecs[j].size() == 2) && (vecs[j][0] == d0) && (vecs[j].back() == d1)){
                        chosen.push_back(j);
                        dim_used.insert(d0);
                        dim_used.insert(d1);
                    }
                }
            }
        }
        else{
            chosen.push_back(i);
            dim_used.insert(vecs[i][0]);
            if(vecs[i].size() > 1){
                dim_used.insert(vecs[i].back());
            }
        }
    }
    int total_vectors = (1LL << (int)dim_used.size()) % MOD;
    cout << total_vectors << " " << chosen.size() << "\n";
    for(int i = 0; i < chosen.size(); ++i){
        if(i > 0) cout << " ";
        cout << chosen[i]+1;
    }
    cout << "\n";
}