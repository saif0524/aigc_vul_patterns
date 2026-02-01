#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pieces(n);
    for (int i = 0; i < n; ++i) {
        cin >> pieces[i];
    }

    long long min_moves = -1;

    // Try placing all pieces on black cells
    long long moves_black = 0;
    for (int i = 0; i < n; ++i) {
        if ((pieces[i] - 1) % 2 == 0) {
            // Piece is already on a black cell
            continue;
        } else {
            // Piece is on a white cell, find the nearest black cell
            int nearest_black = -1;
            int min_dist = 1e9;
            for (int j = 1; j <= n; ++j) {
                if ((j - 1) % 2 == 0) {
                    int dist = abs(pieces[i] - j);
                    bool occupied = false;
                    for (int k = 0; k < n; ++k) {
                        if (pieces[k] == j) {
                            occupied = true;
                            break;
                        }
                    }
                    if (!occupied && dist < min_dist) {
                        min_dist = dist;
                        nearest_black = j;
                    }
                }
            }
            if (nearest_black != -1) {
                moves_black += min_dist;
            }
        }
    }
    
    if (moves_black != 0 && min_moves == -1)
    {
        min_moves = moves_black;
    }
    else if (moves_black != 0)
    {
        min_moves = min(min_moves, moves_black);
    }

    // Try placing all pieces on white cells
    long long moves_white = 0;
    for (int i = 0; i < n; ++i) {
        if ((pieces[i] - 1) % 2 != 0) {
            // Piece is already on a white cell
            continue;
        } else {
            // Piece is on a black cell, find the nearest white cell
            int nearest_white = -1;
            int min_dist = 1e9;
            for (int j = 1; j <= n; ++j) {
                if ((j - 1) % 2 != 0) {
                    int dist = abs(pieces[i] - j);
                    bool occupied = false;
                    for (int k = 0; k < n; ++k) {
                        if (pieces[k] == j) {
                            occupied = true;
                            break;
                        }
                    }
                    if (!occupied && dist < min_dist) {
                        min_dist = dist;
                        nearest_white = j;
                    }
                }
            }
             if (nearest_white != -1) {
                moves_white += min_dist;
            }
        }
    }
    
    if (moves_white != 0 && min_moves == -1)
    {
        min_moves = moves_white;
    }
    else if (moves_white != 0)
    {
        min_moves = min(min_moves, moves_white);
    }

    if (min_moves == -1) {
        cout << 0 << endl;
    }
    else {
       cout << min_moves << endl;
    }

    return 0;
}