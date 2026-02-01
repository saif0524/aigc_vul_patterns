#include <bits/stdc++.h>
using namespace std;

struct Diamond {
    int w, v;
};

template <typename T>
struct BIT {
    int N;
    vector<T> bit;

    BIT(int n) : N(n), bit(n + 1) {}

    void add(int x, T val) {
        for (++x; x <= N; x += x & -x) {
            bit[x] += val;
        }
    }

    T sum(int x) {
        T res = 0;
        for (++x; x > 0; x -= x & -x) {
            res += bit[x];
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<Diamond>> diamonds(1e5 + 1);
    vector<int> cnt(n);
    for(int i = 0; i < n; i++){
        int a, w, v;
        cin >> a >> w >> v;
        cnt[i] = a;
        diamonds[v].push_back({w, v});
    }
    for(auto &diams : diamonds){
        sort(diams.begin(), diams.end());
    }
    vector<BIT<int>> bit(1e5 + 1, BIT<int>(2e5 + 1));
    for(int i = 0; i < cnt.size(); i++){
        for(int j = 0; j < cnt[i]; j++){
            bit[diamonds[i][j].v].add(diamonds[i][j].w, 1);
        }
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int ki, di;
            cin >> ki >> di;
            --di;
            for(int j = 0; j < ki; j++){
                bit[diamonds[di][cnt[di]].v].add(diamonds[di][cnt[di]].w, 1);
                cnt[di]++;
            }
        } else if(t == 2){
            int ki, di;
            cin >> ki >> di;
            --di;
            for(int j = 0; j < ki; j++){
                cnt[di]--;
                bit[diamonds[di][cnt[di]].v].add(diamonds[di][cnt[di]].w, -1);
            }
        } else {
            long long ci;
            cin >> ci;
            long long total_value = 0;
            for(int value = 1e5; value > 0; value--){
                if(bit[value].sum(2e5) == 0) continue;
                int l = 1, r = 2e5;
                int last_valid = 0;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(bit[value].sum(mid) > 0){
                        last_valid = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                long long take = min(1LL * bit[value].sum(last_valid), ci / last_valid);
                total_value += take * value;
                ci -= take * last_valid;
                if(ci == 0) break;
            }
            cout << total_value << "\n";
        }
    }
}