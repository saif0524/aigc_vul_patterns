#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct Diamond {
    int weight, value;
};

int n, q;
vector<Diamond> diamonds[MAXN];
multiset<pair<int, int>> ms;

void add_diamonds(int type, int count) {
    for (int i = 0; i < count; ++i) {
        ms.insert({diamonds[type][i].value, diamonds[type][i].weight});
    }
}

void remove_diamonds(int type, int count) {
    for (int i = 0; i < count; ++i) {
        auto it = ms.find({diamonds[type][i].value, diamonds[type][i].weight});
        if (it != ms.end()) {
            ms.erase(it);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    
    for(int i = 1; i <= n; ++i){
        int a, w, v;
        cin >> a >> w >> v;
        for(int j = 0; j < a; ++j){
            diamonds[i].push_back({w, v});
            ms.insert({v, w});
        }
    }
    
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int k, d;
            cin >> k >> d;
            for(int i = 0; i < k; ++i){
                diamonds[d].push_back({diamonds[d][0].weight, diamonds[d][0].value});
                ms.insert({diamonds[d][0].value, diamonds[d][0].weight});
            }
        }
        else if(t == 2){
            int k, d;
            cin >> k >> d;
            for(int i = 0; i < k; ++i){
                auto it = ms.find({diamonds[d].back().value, diamonds[d].back().weight});
                if(it != ms.end()){
                    ms.erase(it);
                }
                diamonds[d].pop_back();
            }
        }
        else{
            long long c;
            cin >> c;
            long long ans = 0;
            multiset<pair<int, int>> temp = ms;
            while(!temp.empty() && c > 0){
                auto it = temp.end();
                it--;
                int val = it->first;
                int wt = it->second;
                if(c >= wt){
                    ans += val;
                    c -= wt;
                    temp.erase(it);
                }
                else{
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}