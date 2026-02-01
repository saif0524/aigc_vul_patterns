#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long n, l, r;
        cin >> n >> l >> r;
        long long len = n * (n - 1) + 1;
        long long offset = (l - 1) % (2 * n - 2);
        long long start = (l - 1) / (2 * n - 2) + 1;
        vector<int> cycle;
        if(offset < n - 1){
            cycle = {start, start + offset + 1};
        }
        else{
            cycle = {start + (offset - (n - 1)), start};
        }
        while(cycle.size() < r - l + 1){
            if(cycle.back() == 1){
                if(cycle[cycle.size() - 2] == n){
                    cycle.push_back(cycle.back() + 1);
                }
                else{
                    cycle.push_back(cycle.back() - 1);
                }
            }
            else if(cycle.back() == n){
                cycle.push_back(cycle.back() - 1);
            }
            else{
                if(cycle[cycle.size() - 2] < cycle.back()){
                    cycle.push_back(cycle.back() + 1);
                }
                else{
                    cycle.push_back(cycle.back() - 1);
                }
            }
        }
        for(int i = 0; i < cycle.size(); i++){
            if(cycle[i] > n){
                cycle[i] -= n;
            }
        }
        for(int i = 0; i < cycle.size(); i++){
            cout << cycle[i] << (i == cycle.size() - 1 ? '\n' : ' ');
        }
    }
}