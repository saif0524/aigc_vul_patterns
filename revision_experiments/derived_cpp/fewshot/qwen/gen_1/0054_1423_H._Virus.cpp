#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXQ = 5e5 + 5;

struct Contact {
    int day, person;
};

vector<Contact> contacts[MAXN];
int parent[MAXN], rank[MAXN], size[MAXN];
int last_contact_day[MAXN];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        size[a] += size[b];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q, k;
    cin >> n >> q >> k;
    
    for(int i=1;i<=n;i++){
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
        last_contact_day[i] = -k-1;
    }
    
    int day = 0;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            contacts[x].push_back({day, y});
            contacts[y].push_back({day, x});
            union_sets(x, y);
            last_contact_day[x] = day;
            last_contact_day[y] = day;
        }
        else if(t == 2){
            int z;
            cin >> z;
            int root = find_set(z);
            int count = 0;
            for(auto &c : contacts[z]){
                if(day - c.day < k){
                    int root_c = find_set(c.person);
                    if(root_c == root){
                        count++;
                    }
                }
            }
            cout << size[root] - (contacts[z].size() - count) << "\n";
        }
        else{
            day++;
            for(int j=1;j<=n;j++){
                if(day - last_contact_day[j] > k){
                    parent[j] = j;
                    rank[j] = 0;
                    size[j] = 1;
                    contacts[j].clear();
                    last_contact_day[j] = -k-1;
                }
            }
        }
    }
}