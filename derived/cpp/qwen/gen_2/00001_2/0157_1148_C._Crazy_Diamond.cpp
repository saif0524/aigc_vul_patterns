#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &x: p) cin >> x;
    vector<int> pos(n+1);
    for(int i=0;i<n;i++) pos[p[i]] = i;
    int m = 0;
    vector<pair<int,int>> swaps;
    for(int i=0;i<n;i++){
        if(p[i] != i+1){
            int c1 = i+1;
            int c2 = p[i];
            int p1 = i;
            int p2 = pos[c1];
            swaps.emplace_back(p1+1,p2+1);
            pos[c1] = p1;
            pos[c2] = p2;
            swap(p[p1], p[p2]);
            m++;
        }
    }
    for(int i=0;i<n/2;i++){
        if(pos[i+1] >= n/2 && pos[i+1] < n){
            continue;
        }
        for(int j=n/2;j<n;j++){
            if(pos[j+1] < n/2){
                swaps.emplace_back(i+1, j+1);
                pos[p[i]] = j;
                pos[p[j]] = i;
                swap(p[i], p[j]);
                m++;
                break;
            }
        }
    }
    for(int i=n/2;i<n;i++){
        if(pos[i+1] < n/2){
            continue;
        }
        for(int j=0;j<n/2;j++){
            if(pos[j+1] >= n/2 && pos[j+1] < n){
                swaps.emplace_back(i+1, j+1);
                pos[p[i]] = j;
                pos[p[j]] = i;
                swap(p[i], p[j]);
                m++;
                break;
            }
        }
    }
    cout << m << "\n";
    for(auto &s: swaps){
        cout << s.first << " " << s.second << "\n";
    }
}