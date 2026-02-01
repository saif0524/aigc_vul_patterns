#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    
    vector<set<long long>> alice_graph(n + 1);
    long long total_triangles = 0;
    
    for(long long i = 0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        alice_graph[a].insert(b);
    }
    
    for(long long i = 1; i <= n; i++){
        for(auto it = alice_graph[i].begin(); it != alice_graph[i].end(); it++){
            long long j = *it;
            for(auto it2 = next(it); it2 != alice_graph[i].end(); it2++){
                long long k = *it2;
                if(alice_graph[j].find(k) != alice_graph[j].end()){
                    total_triangles++;
                }
            }
        }
    }
    
    long long all_edges = (n * (n - 1)) / 2;
    long long bob_edges = all_edges - m;
    long long bob_triangles = (bob_edges * (bob_edges - 1) / 2) - (total_triangles * 3) + (m * (m - 1) / 2);
    
    cout << total_triangles + bob_triangles;
    
    return 0;
}