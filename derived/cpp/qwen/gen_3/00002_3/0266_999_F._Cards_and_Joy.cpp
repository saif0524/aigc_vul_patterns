#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> c(n*k);
    for(auto &x: c) cin >> x;
    vector<int> f(n);
    for(auto &x: f) cin >> x;
    vector<int> h(k);
    for(auto &x: h) cin >> x;
    vector<int> fav_count(100005, 0);
    for(int i=0;i<n;++i){
        fav_count[f[i]]++;
    }
    vector<int> card_count(100005, 0);
    for(auto &x: c){
        if(fav_count[x]>0){
            card_count[x]++;
        }
    }
    vector<int> fav_with_cards;
    for(int i=0;i<100005;++i){
        if(card_count[i]>0){
            fav_with_cards.push_back(i);
        }
    }
    int total_joy = 0;
    for(auto &x: fav_with_cards){
        int min_assign = min(k, card_count[x]);
        for(int j=min_assign;j>=1;--j){
            if(fav_count[x]>0){
                total_joy += h[j-1];
                fav_count[x]--;
                card_count[x] -= j;
            }
        }
    }
    cout << total_joy;
}