#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Material {
    ll supply;
    ll required;
    ll parent;
    ll ratio;
};

void dfs(vector<Material>& materials, int node) {
    if (materials[node].parent != -1) {
        dfs(materials, materials[node].parent);
        ll need = materials[node].required;
        ll parent_node = materials[node].parent;
        ll parent_ratio = materials[node].ratio;

        ll convert_from_parent = (need + parent_ratio - 1) / parent_ratio;
        materials[parent_node].required += convert_from_parent;

        ll can_convert_to_node = materials[parent_node].supply / parent_ratio;
        materials[parent_node].supply -= can_convert_to_node * parent_ratio;
        materials[node].required -= can_convert_to_node;

        materials[node].required = max(0LL, materials[node].required);
        materials[parent_node].required = max(0LL, materials[parent_node].required);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<Material> materials(n + 1);
    for(int i=1; i<=n; ++i){
        cin >> materials[i].supply;
    }
    for(int i=1; i<=n; ++i){
        cin >> materials[i].required;
    }
    
    for(int i=2; i<=n; ++i){
        int x, k;
        cin >> x >> k;
        materials[i].parent = x;
        materials[i].ratio = k;
    }
    
    for(int i=n; i>1; --i){
        dfs(materials, i);
    }
    
    if(materials[1].supply >= materials[1].required){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}