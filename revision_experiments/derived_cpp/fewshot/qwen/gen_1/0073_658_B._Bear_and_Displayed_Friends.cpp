#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150005;
const int MAXK = 7;

int n, k, q;
int t[MAXN];
bool online[MAXN];
set<pair<int, int>> active;
multiset<int> ranks[MAXK];

void add(int id) {
    online[id] = true;
    auto it = active.insert({t[id], id}).first;
    int rank = distance(active.begin(), it);
    if (rank < k) {
        ranks[rank].insert(t[id]);
    } else if (!ranks[k-1].empty() && t[id] > *ranks[k-1].begin()) {
        int old_id = *active.lower_bound({*ranks[k-1].begin(),0})->second;
        ranks[k-1].erase(ranks[k-1].begin());
        ranks[k-1].insert(t[id]);
        active.erase(active.lower_bound({t[old_id], old_id}));
        active.insert({t[id], id});
    }
}

bool check(int id) {
    if (!online[id]) return false;
    auto it = active.lower_bound({t[id], id});
    int rank = distance(active.begin(), it);
    return rank < k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> q;
    for(int i=1;i<=n;i++){
        cin >> t[i];
        online[i] = false;
    }
    for(int i=0;i<q;i++){
        int type, id;
        cin >> type >> id;
        if(type == 1){
            add(id);
        }else{
            if(check(id)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}