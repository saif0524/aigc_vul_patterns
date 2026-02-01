#include <bits/stdc++.h>
using namespace std;

int main(){
    int kx, ky;
    cin >> kx >> ky;
    set<pair<int, int>> rooks;
    for(int i=0; i<666; i++){
        int x, y;
        cin >> x >> y;
        rooks.insert({x, y});
    }

    auto is_valid = [&](int x, int y){
        if(x<1 || x>999 || y<1 || y>999) return false;
        return rooks.find({x, y}) == rooks.end();
    };

    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    while(true){
        vector<pair<int, int>> moves;
        for(int i=0; i<8; i++){
            int nx = kx + dx[i];
            int ny = ky + dy[i];
            if(is_valid(nx, ny)){
                moves.push_back({nx, ny});
            }
        }

        if(moves.empty()){
            // Corner case where we are forced into check
            // Just move to any adjacent cell (unsafe)
            for(int i=0; i<8; i++){
                int nx = kx + dx[i];
                int ny = ky + dy[i];
                if(nx>=1 && nx<=999 && ny>=1 && ny<=999){
                    cout << nx << " " << ny << endl; fflush(stdout);
                    break;
                }
            }
            int rk, rx, ry;
            cin >> rk >> rx >> ry;
            if(rk==-1 && rx==-1 && ry==-1) break;
            continue;
        }

        // Try to move to a cell that can later be checked by a rook
        bool found_check = false;
        for(auto [nx, ny] : moves){
            if(rooks.find({nx, 1}) != rooks.end() || rooks.find({nx, 999}) != rooks.end() ||
               rooks.find({1, ny}) != rooks.end() || rooks.find({999, ny}) != rooks.end()){
                cout << nx << " " << ny << endl; fflush(stdout);
                found_check = true;
                break;
            }
        }

        if(!found_check){
            // Move to a safe cell
            cout << moves[0].first << " " << moves[0].second << endl; fflush(stdout);
            kx = moves[0].first;
            ky = moves[0].second;
        }

        int rk, rx, ry;
        cin >> rk >> rx >> ry;
        if(rk==-1 && rx==-1 && ry==-1) break;
        rooks.erase({rx, ry});
        rooks.insert({rx, ry});
    }

    return 0;
}