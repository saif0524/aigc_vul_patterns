#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> edges;
    vector<int> depth(n+1, -1);
    int queries = 0;
    auto query = [&](int node){
        cout << "? " << node << endl;
        fflush(stdout);
        for(int i=1;i<=n;i++) cin >> depth[i];
        queries++;
    };
    auto get_diameter = [&](){
        query(1);
        int farthest = max_element(depth.begin()+1, depth.end()) - depth.begin();
        query(farthest);
        int diameter_end = max_element(depth.begin()+1, depth.end()) - depth.begin();
        int diameter = depth[diameter_end];
        return make_tuple(farthest, diameter_end, diameter);
    };
    auto get_neighbors = [&](int node, int radius){
        query(node);
        vector<int> neighbors;
        for(int i=1;i<=n;i++) if(depth[i] == radius) neighbors.push_back(i);
        return neighbors;
    };
    auto build_tree = [&](int center, int radius){
        if(radius == 1){
            for(auto neighbor: get_neighbors(center, 1)){
                edges.push_back({center, neighbor});
            }
        }
        else{
            auto neighbors = get_neighbors(center, radius/2 + radius%2);
            for(auto neighbor: neighbors){
                build_tree(neighbor, radius/2);
                edges.push_back({center, neighbor});
            }
        }
    };
    int farthest, diameter_end, diameter;
    tie(farthest, diameter_end, diameter) = get_diameter();
    build_tree(farthest, diameter/2 + diameter%2);
    for(auto neighbor: get_neighbors(farthest, diameter/2)){
        if(depth[neighbor] == diameter/2){
            build_tree(neighbor, diameter/2);
            edges.push_back({farthest, neighbor});
        }
    }
    cout << "!" << endl;
    for(auto [u,v]: edges) cout << u << " " << v << endl;
    return 0;
}