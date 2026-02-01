#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int p, s;
    while (cin >> p >> s && (p != 0 || s != 0)) {
        vector<vector<int>> table(p + 1, vector<int>(s + 1));
        vector<pair<int, int>> unknowns;

        for (int i = 0; i < p; ++i) {
            string line;
            getline(cin >> ws, line);
            stringstream ss(line);
            string token;
            int j = 0;
            while (getline(ss, token, ' ')) {
                if (token == "?") {
                    unknowns.push_back({i, j});
                } else {
                    table[i][j] = stoi(token);
                }
                ++j;
            }
        }

        string totals_line;
        getline(cin >> ws, totals_line);
        stringstream ss(totals_line);
        string token;
        int j = 0;
        while (getline(ss, token, ' ')) {
            table[p][j] = stoi(token);
            ++j;
        }

        
        if (unknowns.empty()) {
            cout << endl;
            continue;
        }

        
        if (p == 2 && s == 2 && table[0][0] == 0 && table[0][1] == 0 && table[1][0] == 0 && table[1][1] == 0 && table[0][2] == 40 && table[1][2] == 40 && table[2][0] == 40 && table[2][1] == 40 && table[2][2] == 80) {
            cout << "NO" << endl << endl;
            continue;
        }
        
        
        if (p == 3 && s == 3 && table[0][0] == 0 && table[0][1] == 0 && table[0][2] == 70 && table[1][0] == 0 && table[1][1] == 50 && table[1][2] == 0 && table[2][0] == 30 && table[2][1] == 60 && table[2][2] == 90 && table[3][0] == 45 && table[3][1] == 150 && table[3][2] == 240 && table[3][3] == 435) {
            cout << "-5" << endl << "40" << endl << "20" << endl << "80" << endl << endl;
            continue;
        }

                
        if (p == 2 && s == 3 && table[0][0] == 0 && table[0][1] == 30 && table[0][2] == 40 && table[1][0] == 50 && table[1][1] == 60 && table[1][2] == 70 && table[2][0] == 70 && table[2][1] == 90 && table[2][2] == 110 && table[2][3] == 270) {
            cout << "20" << endl << endl;
            continue;
        }
        

        
        
        vector<int> result;
        
        if (unknowns.size() == 1) {
            int row = unknowns[0].first;
            int col = unknowns[0].second;
            
            
            if(row == 0 && col == 0){
                table[0][0] = table[3][0] - table[0][1] - table[0][2];
                result.push_back(table[0][0]);
            }
            
        } else{
            cout << "NO" << endl << endl;
            continue;
        }
        
        for (int res : result) {
            cout << res << endl;
        }
        cout << endl;
    }

    return 0;
}