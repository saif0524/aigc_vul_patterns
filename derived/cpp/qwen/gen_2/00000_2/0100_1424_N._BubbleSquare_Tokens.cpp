#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> degree(n+1, 0);
    vector<pair<int,int>> friends(k);
    for(auto &f: friends){
        cin >> f.first >> f.second;
        degree[f.first]++;
        degree[f.second]++;
    }
    vector<int> tokens(n+1, 0);
    for(int i=1; i<=n; i++){
        tokens[i] = degree[i] * 2 + 1;
    }
    sort(tokens.begin() + 1, tokens.end(), [&](int a, int b){ return a > b; });
    unordered_set<int> unique_tokens;
    int num_keepers = 0;
    for(int i=1; i<=n; i++){
        if(unique_tokens.find(tokens[i]) == unique_tokens.end()){
            num_keepers++;
            unique_tokens.insert(tokens[i]);
        }else{
            while(unique_tokens.find(tokens[i]) != unique_tokens.end()){
                tokens[i]--;
            }
            unique_tokens.insert(tokens[i]);
        }
    }
    vector<int> keepers;
    for(int i=1; i<=n; i++){
        if(tokens[i] == degree[i] * 2 + 1){
            keepers.push_back(i);
        }
    }
    cout << num_keepers << "\n";
    for(auto &keeper: keepers){
        cout << keeper << " ";
    }
    cout << "\n";
    for(auto &f: friends){
        int t1 = min(degree[f.first] * 2, tokens[f.first] - 1);
        int t2 = min(degree[f.second] * 2, tokens[f.second] - 1);
        int total_given = min(tokens[f.first] + tokens[f.second] - 2, degree[f.first] * 2 + degree[f.second] * 2);
        int give1 = (total_given - t2) / 2;
        int give2 = total_given - give1;
        if(give1 > t1){
            give2 += give1 - t1;
            give1 = t1;
        }
        if(give2 > t2){
            give1 += give2 - t2;
            give2 = t2;
        }
        tokens[f.first] -= give1;
        tokens[f.second] -= give2;
        cout << f.first << " " << f.second << " " << give1 / 2 + give2 / 2 << "\n";
    }
}