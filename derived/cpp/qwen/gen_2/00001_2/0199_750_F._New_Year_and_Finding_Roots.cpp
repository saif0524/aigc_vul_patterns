#include <bits/stdc++.h>
using namespace std;

void ask(int x) {
    cout << "? " << x << endl;
    fflush(stdout);
}

vector<int> read_neighbors() {
    int k;
    cin >> k;
    if (k == 0) exit(0);
    vector<int> neighbors(k);
    for (int& t : neighbors) cin >> t;
    return neighbors;
}

int find_root(int h) {
    int n = (1 << h) - 1;
    map<int, vector<int>> adjacency;

    auto query_and_store = [&](int x) {
        ask(x);
        auto neighbors = read_neighbors();
        adjacency[x] = neighbors;
        for (int y : neighbors) {
            adjacency[y].push_back(x);
        }
    };

    query_and_store(1);

    if (adjacency[1].size() == 2) return 1;

    for (int i = 2; i <= n; ++i) {
        if (adjacency.count(i) == 0) {
            query_and_store(i);
        }
        if (adjacency[i].size() == 2) return i;
    }

    for (int i = 2; i <= n; ++i) {
        if (adjacency[i].size() != 2) {
            for (int j = 0; j < adjacency[i].size(); ++j) {
                int x = adjacency[i][j];
                if (adjacency[x].size() != 2) {
                    return x;
                }
            }
        }
    }

    return -1; // Should not reach here
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int h;
        cin >> h;
        if(h == 0) break;
        int root = find_root(h);
        cout << "! " << root << endl;
        fflush(stdout);
    }
    return 0;
}