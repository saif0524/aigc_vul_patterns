#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 500005;
const ll MOD = (ll)1e9 + 7;

class DisjointSet {
public:
    vector<int> p, rank;
    DisjointSet(int n) {
        p.resize(n + 1);
        rank.resize(n + 1);
        REP(i, n + 1) p[i] = i;
    }
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    bool init(int x) {
        return find(x) == x;
    }
    bool union_(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        if(rank[px] < rank[py]) p[px] = py;
        else {
            p[py] = px;
            if(rank[px] == rank[py]) ++rank[px];
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    DisjointSet dsu(m + 1);
    vector<int> ans;
    REP(i, n) {
        int k; cin >> k;
        if(k == 1) {
            int a; cin >> a;
            if(dsu.init(a)) ans.pb(i + 1), dsu.union_(a, m + 1);
        }
        else {
            int a, b; cin >> a >> b;
            if(dsu.init(a) || dsu.init(b)) {
                ans.pb(i + 1);
                dsu.union_(a, b);
            }
        }
    }
    cout << (1LL << ans.size()) % MOD << " " << (int)ans.size() << '\n';
    for(auto c : ans) cout << c << " ";
    cout << '\n';

    return 0;
}