#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> weights(n);
    for(auto &w : weights) cin >> w;
    vector<int> order(m);
    for(auto &o : order) cin >> o, o--;
    
    vector<int> freq(n, 0);
    for(auto o : order) freq[o]++;
    
    vector<int> sorted_indices(n);
    iota(sorted_indices.begin(), sorted_indices.end(), 0);
    sort(sorted_indices.begin(), sorted_indices.end(), [&](int i, int j){
        if(freq[i] == freq[j]) return weights[i] < weights[j];
        return freq[i] > freq[j];
    });
    
    vector<int> pos(n);
    for(int i = 0; i < n; i++) pos[sorted_indices[i]] = i;
    
    long long total_weight = 0;
    int current_pos = n;
    for(auto o : order){
        for(int i = pos[o] + 1; i < current_pos; i++){
            total_weight += weights[sorted_indices[i]];
        }
        current_pos = pos[o];
    }
    
    cout << total_weight;
}