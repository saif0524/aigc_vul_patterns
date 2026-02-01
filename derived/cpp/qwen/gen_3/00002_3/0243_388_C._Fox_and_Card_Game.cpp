#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> piles(n);
    for(int i=0; i<n; i++){
        int si;
        cin >> si;
        piles[i].resize(si);
        for(int j=0; j<si; j++){
            cin >> piles[i][j];
        }
    }
    int ciel = 0, jiro = 0;
    while(true){
        int maxTop = -1, minBottom = 1001;
        int topPile = -1, bottomPile = -1;
        for(int i=0; i<n; i++){
            if(!piles[i].empty()){
                if(piles[i].front() > maxTop){
                    maxTop = piles[i].front();
                    topPile = i;
                }
                if(piles[i].back() < minBottom){
                    minBottom = piles[i].back();
                    bottomPile = i;
                }
            }
        }
        if(topPile == -1) break;
        ciel += maxTop;
        piles[topPile].erase(piles[topPile].begin());
        if(bottomPile == -1) break;
        jiro += minBottom;
        piles[bottomPile].pop_back();
    }
    cout << ciel << " " << jiro;
}