#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> not_adjacent(n+1);
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        not_adjacent[x].push_back(y);
        not_adjacent[y].push_back(x);
    }
    vector<int> component_size;
    vector<bool> visited(n+1, false);
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            int size = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                ++size;
                for(int j=1; j<=n; ++j){
                    if(!visited[j]){
                        bool is_adjacent = true;
                        for(int v : not_adjacent[u]){
                            if(v == j){
                                is_adjacent = false;
                                break;
                            }
                        }
                        if(is_adjacent){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
            component_size.push_back(size);
        }
    }
    sort(component_size.begin(), component_size.end());
    cout << component_size.size() << "\n";
    for(int s : component_size){
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}