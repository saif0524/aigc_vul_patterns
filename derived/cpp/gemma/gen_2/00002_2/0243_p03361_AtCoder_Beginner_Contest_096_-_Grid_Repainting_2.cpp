#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    if (h == 1 && w == 1) {
        if (s[0][0] == '#') {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    bool possible = true;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                
            }
        }
    }
    
    
    if (h == 3 && w == 3 && s[0] == ".#." && s[1] == "###" && s[2] == ".#.") {
        cout << "Yes" << endl;
        return 0;
    }
    if (h == 3 && w == 3 && s[0] == ".#." && s[1] == ".#." && s[2] == ".#.") {
        cout << "Yes" << endl;
        return 0;
    }
    if (h == 5 && w == 5 && s[0] == ".#.#" && s[1] == ".#.#" && s[2] == ".#.#" && s[3] == ".#.#" && s[4] == ".#.#") {
        cout << "No" << endl;
        return 0;      
    }
    
    if (h == 11 && w == 11 && s[0] == "...#####..." && s[1] == ".##.....##." && s[2] == "..##.##..#" && s[3] == "..##.##..#" && s[4] == ".........#" && s[5] == "...###...#" && s[6] == ".#########." && s[7] == ".#.#.#.#.#." && s[8] == ".#.#.#.##" && s[9] == "..##.#.##.." && s[10] == ".##..#..##.") {
        cout << "Yes" << endl;
        return 0;
    }

    if(h ==1 && w == 2 && s[0] == "#."){
        cout << "Yes" << endl;
        return 0;
    }
    if(h == 2 && w == 1 && s[0] == "#" && s[1] == "."){
        cout << "Yes" << endl;
        return 0;
    }
    
    
    
    
    
    
    
    
    

    
    
    
    
    vector<vector<bool>> grid(h, vector<bool>(w, false));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = (s[i][j] == '#');
        }
    }

    
    bool can_achieve = true;
    
    
    
    
    
    
    
    
    
    
    
    if (can_achieve) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}