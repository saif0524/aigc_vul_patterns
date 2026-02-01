#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, weight;
};

int find(int x, vector<int>& parent, vector<int>& rank, vector<int>& dist) {
    if (parent[x] == x) return x;
    int root = find(parent[x], parent, rank, dist);
    dist[x] += dist[parent[x]];
    parent[x] = root;
    return root;
}

void unionSets(int x, int y, int w, vector<int>& parent, vector<int>& rank, vector<int>& dist) {
    int rootX = find(x, parent, rank, dist);
    int rootY = find(y, parent, rank, dist);
    if (rootX == rootY) return;
    if (rank[rootX] < rank[rootY]) {
        swap(rootX, rootY);
        w = -w;
    }
    parent[rootY] = rootX;
    dist[rootY] = dist[x] - dist[y] + w;
    if (rank[rootX] == rank[rootY]) rank[rootX]++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> parent(N+1);
    vector<int> rank(N+1, 0);
    vector<int> dist(N+1, 0);
    for(int i=1;i<=N;i++) parent[i] = i;
    for(int i=0;i<M;i++){
        int L, R, D;
        cin >> L >> R >> D;
        int rootL = find(L, parent, rank, dist);
        int rootR = find(R, parent, rank, dist);
        if(rootL == rootR){
            if(dist[R] - dist[L] != D){
                cout << "No";
                return 0;
            }
        }
        else{
            unionSets(L, R, D, parent, rank, dist);
        }
    }
    cout << "Yes";
}