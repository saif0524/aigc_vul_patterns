#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string left, right;
    cin >> left >> right;
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<bool>> visited(n+1,vector<bool>(2,false));
    visited[0][0]=true;
    int water_level = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [pos, wall] = q.front();
            q.pop();
            if(pos >= n){
                cout << "YES";
                return 0;
            }
            if(wall==0){
                if(pos+1 < n && left[pos+1] == '-' && !visited[pos+1][0] && pos+1 > water_level){
                    visited[pos+1][0] = true;
                    q.push({pos+1,0});
                }
                if(pos-1 >= 0 && left[pos-1] == '-' && !visited[pos-1][0] && pos-1 > water_level){
                    visited[pos-1][0] = true;
                    q.push({pos-1,0});
                }
                if(pos+k < n && right[pos+k] == '-' && !visited[pos+k][1] && pos+k > water_level){
                    visited[pos+k][1] = true;
                    q.push({pos+k,1});
                }
            }
            else{
                if(pos+1 < n && right[pos+1] == '-' && !visited[pos+1][1] && pos+1 > water_level){
                    visited[pos+1][1] = true;
                    q.push({pos+1,1});
                }
                if(pos-1 >= 0 && right[pos-1] == '-' && !visited[pos-1][1] && pos-1 > water_level){
                    visited[pos-1][1] = true;
                    q.push({pos-1,1});
                }
                if(pos+k < n && left[pos+k] == '-' && !visited[pos+k][0] && pos+k > water_level){
                    visited[pos+k][0] = true;
                    q.push({pos+k,0});
                }
            }
        }
        water_level++;
    }
    cout << "NO";
}