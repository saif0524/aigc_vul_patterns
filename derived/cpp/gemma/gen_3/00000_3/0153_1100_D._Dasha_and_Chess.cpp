#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int king_x, king_y;
    cin >> king_x >> king_y;

    vector<pair<int, int>> rooks(666);
    for (int i = 0; i < 666; ++i) {
        cin >> rooks[i].first >> rooks[i].second;
    }

    
    int move_count = 0;
    while (move_count < 2000) {
        
        int best_x = -1;
        int best_y = -1;
        
        
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;

                int new_x = king_x + dx;
                int new_y = king_y + dy;

                if (new_x >= 1 && new_x <= 999 && new_y >= 1 && new_y <= 999) {
                    bool rook_collision = false;
                    for (int i = 0; i < 666; ++i) {
                        if (rooks[i].first == new_x && rooks[i].second == new_y) {
                            rook_collision = true;
                            break;
                        }
                    }
                    if (!rook_collision) {
                        
                        bool in_check = false;
                        for (int i = 0; i < 666; ++i) {
                            if (rooks[i].first == new_x || rooks[i].second == new_y) {
                                in_check = true;
                                break;
                            }
                        }
                        if (in_check) {
                            best_x = new_x;
                            best_y = new_y;
                            break;
                        }
                    }
                }
            }
            if(best_x != -1) break;
        }
        
        
        if (best_x == -1) {
            
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;

                    int new_x = king_x + dx;
                    int new_y = king_y + dy;

                    if (new_x >= 1 && new_x <= 999 && new_y >= 1 && new_y <= 999) {
                        bool rook_collision = false;
                        for (int i = 0; i < 666; ++i) {
                            if (rooks[i].first == new_x && rooks[i].second == new_y) {
                                rook_collision = true;
                                break;
                            }
                        }
                        if (!rook_collision) {
                            best_x = new_x;
                            best_y = new_y;
                            break;
                        }
                    }
                }
                if(best_x != -1) break;
            }
            
        }
        
        
        if(best_x == -1){
             break;
        }
        
        cout << best_x << " " << best_y << endl;
        fflush(stdout);

        int k, x, y;
        cin >> k >> x >> y;

        if (k == -1) {
            break;
        }
        
        if(x != -1 && y !=-1){
          for(int i = 0; i < 666; ++i){
            if(rooks[i].first == x && rooks[i].second == y){
              rooks[i] = {x, y};
              break;
            }
          }
          

        
        }

        king_x = best_x;
        king_y = best_y;

        move_count++;
    }
    

    return 0;
}