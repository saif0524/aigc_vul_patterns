#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string left, right;
    cin >> left >> right;
    vector<vector<bool>> vis(n + 1, vector<bool>(2, false));
    queue<tuple<int,int,int>> q;
    q.push({0, 0, 0});
    vis[0][0] = true;
    while(!q.empty()){
        auto [time, pos, wall] = q.front();
        q.pop();
        if(pos > n) {
            cout << "YES";
            return 0;
        }
        if(time == n) continue;
        int next_pos = pos + 1;
        if(next_pos <= n && !vis[next_pos][wall] && (wall == 0 ? left[next_pos - 1] : right[next_pos - 1]) == '-'){
            q.push({time + 1, next_pos, wall});
            vis[next_pos][wall] = true;
        }
        next_pos = pos - 1;
        if(next_pos > 0 && !vis[next_pos][wall] && (wall == 0 ? left[next_pos - 1] : right[next_pos - 1]) == '-'){
            q.push({time + 1, next_pos, wall});
            vis[next_pos][wall] = true;
        }
        int jump_pos = pos + k;
        if(jump_pos <= n && !vis[jump_pos][1 - wall] && (1 - wall == 0 ? left[jump_pos - 1] : right[jump_pos - 1]) == '-'){
            q.push({time + 1, jump_pos, 1 - wall});
            vis[jump_pos][1 - wall] = true;
        }
    }
    cout << "NO";
}