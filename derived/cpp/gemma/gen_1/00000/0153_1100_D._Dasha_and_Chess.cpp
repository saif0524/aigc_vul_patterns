#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int kx, ky;
    cin >> kx >> ky;

    vector<pair<int, int>> rooks(666);
    for (int i = 0; i < 666; ++i) {
        cin >> rooks[i].first >> rooks[i].second;
    }

    
    int move_count = 0;
    while (move_count < 2000) {
        
        int best_x = -1, best_y = -1;
        
        
        if (kx == 1 && ky == 1) {
            best_x = kx;
            best_y = ky + 1;
        } else if (kx == 999 && ky == 999) {
            best_x = kx - 1;
            best_y = ky - 1;
        } else {
            
            best_x = kx + 1;
            best_y = ky;
        }
        
        
        if (best_x < 1 || best_x > 999 || best_y < 1 || best_y > 999) {
            best_x = kx - 1;
            best_y = ky;
        }

        

        bool rook_present = false;
        for (int i = 0; i < 666; ++i) {
            if (rooks[i].first == best_x && rooks[i].second == best_y) {
                rook_present = true;
                break;
            }
        }

        if (rook_present) {
            
            
            if(kx > 1) {
                best_x = kx - 1;
                best_y = ky;
            } else {
                best_x = kx;
                best_y = ky + 1;
            }
            
            rook_present = false;
            for (int i = 0; i < 666; ++i) {
                if (rooks[i].first == best_x && rooks[i].second == best_y) {
                    rook_present = true;
                    break;
                }
            }
            if (rook_present) {
               if(kx > 1 && ky > 1){
                    best_x = kx - 1;
                    best_y = ky -1;
               }else if(kx < 999 && ky < 999){
                    best_x = kx + 1;
                    best_y = ky + 1;
               }
               else {
                   best_x = kx;
                   best_y = ky + 1;
               }
               
            }

        
        }
        

        
        

        
        cout << best_x << " " << best_y << endl;
        fflush(stdout);
        
        int rook_move_k, rook_move_x, rook_move_y;
        cin >> rook_move_k >> rook_move_x >> rook_move_y;

        if (rook_move_k == -1 && rook_move_x == -1 && rook_move_y == -1) {
            return 0;
        }
        
        
        
        if (rook_move_k != 0) {
            rooks[rook_move_k - 1].first = rook_move_x;
            rooks[rook_move_k - 1].second = rook_move_y;
        }
       
        
        kx = best_x;
        ky = best_y;

        move_count++;
    }

    return 0;
}