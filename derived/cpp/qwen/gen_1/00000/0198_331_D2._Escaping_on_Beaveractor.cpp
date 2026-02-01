#include <bits/stdc++.h>
using namespace std;

struct Arrow {
    int x0, y0, x1, y1;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    vector<Arrow> arrows(n);
    for(auto &a: arrows){
        cin >> a.x0 >> a.y0 >> a.x1 >> a.y1;
    }
    int q;
    cin >> q;
    set<int> x_positions, y_positions;
    x_positions.insert(0); x_positions.insert(b);
    y_positions.insert(0); y_positions.insert(b);
    for(auto &a: arrows){
        x_positions.insert(a.x0);
        x_positions.insert(a.x1);
        y_positions.insert(a.y0);
        y_positions.insert(a.y1);
    }
    unordered_map<int, int> x_map, y_map;
    int idx = 0;
    for(auto it = x_positions.begin(); it != x_positions.end(); ++it){
        x_map[*it] = idx++;
    }
    idx = 0;
    for(auto it = y_positions.begin(); it != y_positions.end(); ++it){
        y_map[*it] = idx++;
    }
    vector<vector<pair<int, int>>> x_changes(x_positions.size());
    vector<vector<pair<int, int>>> y_changes(y_positions.size());
    for(auto &a: arrows){
        if(a.x0 == a.x1){
            int y0 = y_map[a.y0];
            int y1 = y_map[a.y1];
            if(y0 < y1){
                y_changes[x_map[a.x0]].emplace_back(y0, 1);
                y_changes[x_map[a.x1]].emplace_back(y1, -1);
            }else{
                y_changes[x_map[a.x0]].emplace_back(y1, 1);
                y_changes[x_map[a.x1]].emplace_back(y0, -1);
            }
        }else{
            int x0 = x_map[a.x0];
            int x1 = x_map[a.x1];
            if(x0 < x1){
                x_changes[y_map[a.y0]].emplace_back(x0, 1);
                x_changes[y_map[a.y1]].emplace_back(x1, -1);
            }else{
                x_changes[y_map[a.y0]].emplace_back(x1, 1);
                x_changes[y_map[a.y1]].emplace_back(x0, -1);
            }
        }
    }
    for(auto &v: x_changes){
        sort(v.begin(), v.end());
        int sum = 0;
        for(auto &p: v){
            p.second += sum;
            sum = p.second;
        }
    }
    for(auto &v: y_changes){
        sort(v.begin(), v.end());
        int sum = 0;
        for(auto &p: v){
            p.second += sum;
            sum = p.second;
        }
    }
    while(q--){
        int xi, yi;
        char wi;
        long long ti;
        cin >> xi >> yi >> wi >> ti;
        if(ti == 0){
            cout << xi << " " << yi << "\n";
            continue;
        }
        int dir = 0;
        if(wi == 'U') dir = 1;
        else if(wi == 'D') dir = 3;
        else if(wi == 'L') dir = 2;
        pair<int, int> pos = {x_map[xi], y_map[yi]};
        while(ti > 0){
            int steps = 0;
            if(dir == 0){
                int last = pos.second + 1;
                auto it = upper_bound(y_changes[pos.first].begin(), y_changes[pos.first].end(), make_pair(pos.second, 1));
                if(it != y_changes[pos.first].end() && it->second == 1){
                    last = min(it->first, pos.second + (int) ti);
                }else{
                    last = min(last, pos.second + (int) ti);
                }
                steps = last - pos.second;
                pos.second = last;
                if(pos.second < y_positions.size() - 1 && y_changes[pos.first][y_map[y_positions[pos.second + 1]]].second == 1){
                    dir = 1;
                }else{
                    dir = 3;
                }
            }else if(dir == 1){
                int last = pos.first + 1;
                auto it = upper_bound(x_changes[pos.second].begin(), x_changes[pos.second].end(), make_pair(pos.first, 1));
                if(it != x_changes[pos.second].end() && it->second == 1){
                    last = min(it->first, pos.first + (int) ti);
                }else{
                    last = min(last, pos.first + (int) ti);
                }
                steps = last - pos.first;
                pos.first = last;
                if(pos.first < x_positions.size() - 1 && x_changes[pos.second][x_map[x_positions[pos.first + 1]]].second == 1){
                    dir = 0;
                }else{
                    dir = 2;
                }
            }else if(dir == 2){
                int last = pos.second - 1;
                auto it = lower_bound(y_changes[pos.first].begin(), y_changes[pos.first].end(), make_pair(pos.second, 1));
                if(it != y_changes[pos.first].begin()){
                    --it;
                    if(it->second == -1){
                        last = max(it->first + 1, pos.second - (int) ti);
                    }else{
                        last = max(last, pos.second - (int) ti);
                    }
                }else{
                    last = max(last, pos.second - (int) ti);
                }
                steps = pos.second - last;
                pos.second = last;
                if(pos.second > 0 && y_changes[pos.first][y_map[y_positions[pos.second]]].second == -1){
                    dir = 3;
                }else{
                    dir = 1;
                }
            }else{
                int last = pos.first - 1;
                auto it = lower_bound(x_changes[pos.second].begin(), x_changes[pos.second].end(), make_pair(pos.first, 1));
                if(it != x_changes[pos.second].begin()){
                    --it;
                    if(it->second == -1){
                        last = max(it->first + 1, pos.first - (int) ti);
                    }else{
                        last = max(last, pos.first - (int) ti);
                    }
                }else{
                    last = max(last, pos.first - (int) ti);
                }
                steps = pos.first - last;
                pos.first = last;
                if(pos.first > 0 && x_changes[pos.second][x_map[x_positions[pos.first]]].second == -1){
                    dir = 2;
                }else{
                    dir = 0;
                }
            }
            ti -= steps;
            if(pos.first == 0 || pos.first == x_positions.size() - 1 || pos.second == 0 || pos.second == y_positions.size() - 1){
                break;
            }
        }
        if(pos.first == 0) cout << x_positions[pos.first] + ti << " " << y_positions[pos.second] << "\n";
        else if(pos.first == x_positions.size() - 1) cout << x_positions[pos.first] - ti << " " << y_positions[pos.second] << "\n";
        else if(pos.second == 0) cout << x_positions[pos.first] << " " << y_positions[pos.second] + ti << "\n";
        else cout << x_positions[pos.first] << " " << y_positions[pos.second] - ti << "\n";
    }
}