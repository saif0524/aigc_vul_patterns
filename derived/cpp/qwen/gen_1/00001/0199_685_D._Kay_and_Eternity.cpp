#include <bits/stdc++.h>
using namespace std;

const int MAXK = 302;
const int MAXN = 100005;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> ice(n);
    for(auto &p : ice){
        cin >> p.first >> p.second;
    }
    map<long long, map<long long, int>> countMap;
    for(const auto &p : ice){
        countMap[p.first][p.second]++;
    }
    vector<int> ans(n + 1, 0);
    for(auto &[x, yMap] : countMap){
        for(auto &[y, c] : yMap){
            for(int i = 0; i < k; ++i){
                for(int j = 0; j < k; ++j){
                    long long startX = x - i;
                    long long startY = y - j;
                    long long endX = startX + k;
                    long long endY = startY + k;
                    if(countMap.count(startX) && countMap[startX].count(startY)){
                        int add = countMap[startX][startY];
                        if(endX > maxX || endY > maxY) continue;
                        ans[add]++;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}