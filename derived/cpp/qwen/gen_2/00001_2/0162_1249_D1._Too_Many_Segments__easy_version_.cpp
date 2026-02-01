#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> segments(n);
    for(int i=0; i<n; ++i){
        cin >> segments[i].first >> segments[i].second;
    }
    
    vector<int> remove;
    for(int i=0; i<n; ++i){
        vector<int> cnt(201, 0);
        int bad = 0;
        for(int j=0; j<n; ++j){
            if(i != j){
                for(int p=segments[j].first; p<=segments[j].second; ++p){
                    cnt[p]++;
                    if(cnt[p] == k+1){
                        bad++;
                    }
                }
            }
        }
        if(bad == 0){
            continue;
        }
        remove.push_back(i);
        for(int j=segments[i].first; j<=segments[i].second; ++j){
            for(int x=0; x<n; ++x){
                if(x != i){
                    int start = segments[x].first, end = segments[x].second;
                    if(start <= j && j <= end){
                        bad--;
                        break;
                    }
                }
            }
        }
        if(bad == 0){
            break;
        }
    }
    
    cout << remove.size() << "\n";
    for(int i=0; i<remove.size(); ++i){
        cout << (remove[i] + 1) << (i < remove.size() - 1 ? ' ' : '\n');
    }
    return 0;
}