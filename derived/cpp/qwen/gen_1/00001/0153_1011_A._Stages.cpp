#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> weights;
    for(char c : s){
        weights.push_back(c - 'a' + 1);
    }
    sort(weights.begin(), weights.end());
    int ans = INT_MAX;
    for(int i = 0; i <= n - k; i++){
        bool valid = true;
        int current_weight = weights[i];
        int last = weights[i];
        int count = 1;
        for(int j = i + 1; j < n && count < k; j++){
            if(weights[j] - last >= 2){
                last = weights[j];
                current_weight += weights[j];
                count++;
            }
        }
        if(count == k){
            ans = min(ans, current_weight);
        }
    }
    if(ans == INT_MAX){
        cout << -1;
    }
    else{
        cout << ans;
    }
}